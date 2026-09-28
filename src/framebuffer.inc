EXTERN StretchDIBits:PROC

BI_RGB                              equ 0
DIB_RGB_COLORS                      equ 0
SRCCOPY                             equ 00CC0020h
WINDOW_SCALE                        equ 3
WINDOW_CLIENT_WIDTH_PX              equ SCREEN_WIDTH_PX * WINDOW_SCALE
WINDOW_CLIENT_HEIGHT_PX             equ SCREEN_HEIGHT_PX * WINDOW_SCALE
FRAME_PRESENT_FRAME_BYTES           equ CALL_ARG13 + 8
SCREEN_FLASH_LEVEL_MAX              equ 100
.ERRE SCREEN_FLASH_LEVEL_MAX LE LERP_LEVEL_FULL
SCREEN_DARKEN_LEVEL                 equ 96
CHROMA_OFFSET_MAX_PX                equ 4
CHROMA_TICKS_PER_PX                 equ 3
CHROMA_ROW_PADDING_PX               equ 8
.ERRE CHROMA_ROW_PADDING_PX GE CHROMA_OFFSET_MAX_PX
ZOOM_MAX_PX                         equ 16
LINE_COORDINATE_LIMIT_PX            equ 4096
FRAMEBUFFER_LINE_DRAW_PUSHED_REGISTER_COUNT equ 5
FRAMEBUFFER_LINE_DRAW_ARG5          equ 8 * FRAMEBUFFER_LINE_DRAW_PUSHED_REGISTER_COUNT + CALLEE_ARG5
FRAMEBUFFER_ELLIPSE_SHADE_PUSHED_REGISTER_COUNT equ 5
FRAMEBUFFER_ELLIPSE_SHADE_ARG5      equ 8 * FRAMEBUFFER_ELLIPSE_SHADE_PUSHED_REGISTER_COUNT + CALLEE_ARG5

BITMAPINFOHEADER STRUCT
    biSize                          DWORD ?
    biWidth                         DWORD ?
    biHeight                        DWORD ?
    biPlanes                        WORD ?
    biBitCount                      WORD ?
    biCompression                   DWORD ?
    biSizeImage                     DWORD ?
    biXPelsPerMeter                 DWORD ?
    biYPelsPerMeter                 DWORD ?
    biClrUsed                       DWORD ?
    biClrImportant                  DWORD ?
BITMAPINFOHEADER ENDS
.ERRNZ SIZEOF BITMAPINFOHEADER - 40

PALETTE_LUT_CHANNEL_BITS            equ 5
PALETTE_LUT_CHANNEL_LEVELS          equ 1 SHL PALETTE_LUT_CHANNEL_BITS
PALETTE_LUT_ENTRY_COUNT             equ PALETTE_LUT_CHANNEL_LEVELS * PALETTE_LUT_CHANNEL_LEVELS * PALETTE_LUT_CHANNEL_LEVELS
PALETTE_LUT_LEVEL_TO_CHANNEL_SHIFT  equ 8 - PALETTE_LUT_CHANNEL_BITS
PALETTE_LUT_LEVEL_CENTER            equ 1 SHL (PALETTE_LUT_LEVEL_TO_CHANNEL_SHIFT - 1)
PALETTE_LUT_CHANNEL_MASK            equ PALETTE_LUT_CHANNEL_LEVELS - 1
PALETTE_LUT_RED_MASK                equ PALETTE_LUT_CHANNEL_MASK SHL (2 * PALETTE_LUT_CHANNEL_BITS)
PALETTE_LUT_GREEN_MASK              equ PALETTE_LUT_CHANNEL_MASK SHL PALETTE_LUT_CHANNEL_BITS
PALETTE_LUT_RED_SHIFT               equ 16 + PALETTE_LUT_LEVEL_TO_CHANNEL_SHIFT - 2 * PALETTE_LUT_CHANNEL_BITS
PALETTE_LUT_GREEN_SHIFT             equ 8 + PALETTE_LUT_LEVEL_TO_CHANNEL_SHIFT - PALETTE_LUT_CHANNEL_BITS
.ERRNZ PALETTE_LUT_RED_SHIFT - 9
.ERRNZ PALETTE_LUT_GREEN_SHIFT - 6
PALETTE_DISTANCE_RED_WEIGHT         equ 3
PALETTE_DISTANCE_GREEN_WEIGHT       equ 4
PALETTE_DISTANCE_BLUE_WEIGHT        equ 2
DITHER_ROW_COUNT                    equ 4
DITHER_AMPLITUDE_SHIFT              equ 2
DITHER_CHANNELS                     equ 00010101h
PIXEL_RGB_MASK                      equ 00FFFFFFh

.const
ALIGN 16
pixel_red_mask_x4                   DWORD 4 DUP (00FF0000h)
pixel_green_mask_x4                 DWORD 4 DUP (0000FF00h)
pixel_blue_mask_x4                  DWORD 4 DUP (000000FFh)
pixel_rgb_mask_x4                   DWORD 4 DUP (PIXEL_RGB_MASK)
dither_add_rows                     DWORD 0, (1 SHR DITHER_AMPLITUDE_SHIFT) * DITHER_CHANNELS, 0, (5 SHR DITHER_AMPLITUDE_SHIFT) * DITHER_CHANNELS
                                    DWORD (9 SHR DITHER_AMPLITUDE_SHIFT) * DITHER_CHANNELS, 0, (13 SHR DITHER_AMPLITUDE_SHIFT) * DITHER_CHANNELS, 0
                                    DWORD 0, (7 SHR DITHER_AMPLITUDE_SHIFT) * DITHER_CHANNELS, 0, (3 SHR DITHER_AMPLITUDE_SHIFT) * DITHER_CHANNELS
                                    DWORD (15 SHR DITHER_AMPLITUDE_SHIFT) * DITHER_CHANNELS, 0, (11 SHR DITHER_AMPLITUDE_SHIFT) * DITHER_CHANNELS, 0
dither_sub_rows                     DWORD (15 SHR DITHER_AMPLITUDE_SHIFT) * DITHER_CHANNELS, 0, (11 SHR DITHER_AMPLITUDE_SHIFT) * DITHER_CHANNELS, 0
                                    DWORD 0, (7 SHR DITHER_AMPLITUDE_SHIFT) * DITHER_CHANNELS, 0, (3 SHR DITHER_AMPLITUDE_SHIFT) * DITHER_CHANNELS
                                    DWORD (9 SHR DITHER_AMPLITUDE_SHIFT) * DITHER_CHANNELS, 0, (13 SHR DITHER_AMPLITUDE_SHIFT) * DITHER_CHANNELS, 0
                                    DWORD 0, (1 SHR DITHER_AMPLITUDE_SHIFT) * DITHER_CHANNELS, 0, (5 SHR DITHER_AMPLITUDE_SHIFT) * DITHER_CHANNELS

.data
framebuffer_bitmap_info             BITMAPINFOHEADER <SIZEOF BITMAPINFOHEADER, SCREEN_WIDTH_PX, -SCREEN_HEIGHT_PX, 1, 32, BI_RGB>

.data?
ALIGN 16
framebuffer_bgra                    DWORD SCREEN_PIXEL_COUNT DUP (?)
chroma_row_bgra                     DWORD SCREEN_WIDTH_PX + 2 * CHROMA_ROW_PADDING_PX DUP (?)
palette_lut                         BYTE PALETTE_LUT_ENTRY_COUNT DUP (?)
window_dc                           QWORD ?
screen_impact_frames_left           DWORD ?

.code

color_scale PROC
    assert_below_unsigned edx, COLOR_LEVEL_FULL + 1
    movd xmm0, ecx
    pxor xmm1, xmm1
    punpcklbw xmm0, xmm1
    movd xmm2, edx
    pshuflw xmm2, xmm2, 0
    pmullw xmm0, xmm2
    psrlw xmm0, COLOR_LEVEL_SHIFT
    packuswb xmm0, xmm1
    movd eax, xmm0
    ret
color_scale ENDP

color_lerp PROC
    assert_below_unsigned r8d, COLOR_LEVEL_FULL + 1
    movd xmm0, ecx
    movd xmm1, edx
    pxor xmm2, xmm2
    punpcklbw xmm0, xmm2
    punpcklbw xmm1, xmm2
    psubw xmm1, xmm0
    shr r8d, COLOR_LEVEL_SHIFT - LERP_LEVEL_SHIFT
    movd xmm3, r8d
    pshuflw xmm3, xmm3, 0
    pmullw xmm1, xmm3
    psraw xmm1, LERP_LEVEL_SHIFT
    paddw xmm0, xmm1
    packuswb xmm0, xmm2
    movd eax, xmm0
    ret
color_lerp ENDP

palette_lut_build PROC
    push rbx
    push rsi
    push rdi
    push r12
    push r13
    push r14
    lea rdi, palette_lut
    lea r12, palette_sweetie16_bgra
    xor ebx, ebx
palette_lut_build_entry:
    mov r8d, ebx
    shr r8d, 2 * PALETTE_LUT_CHANNEL_BITS
    and r8d, PALETTE_LUT_CHANNEL_MASK
    shl r8d, PALETTE_LUT_LEVEL_TO_CHANNEL_SHIFT
    add r8d, PALETTE_LUT_LEVEL_CENTER
    mov r9d, ebx
    shr r9d, PALETTE_LUT_CHANNEL_BITS
    and r9d, PALETTE_LUT_CHANNEL_MASK
    shl r9d, PALETTE_LUT_LEVEL_TO_CHANNEL_SHIFT
    add r9d, PALETTE_LUT_LEVEL_CENTER
    mov r10d, ebx
    and r10d, PALETTE_LUT_CHANNEL_MASK
    shl r10d, PALETTE_LUT_LEVEL_TO_CHANNEL_SHIFT
    add r10d, PALETTE_LUT_LEVEL_CENTER
    mov r13d, 7FFFFFFFh
    xor r14d, r14d
    xor esi, esi
palette_lut_build_color:
    mov ecx, dword ptr [r12 + rsi * 4]
    mov eax, ecx
    shr eax, 16
    and eax, 0FFh
    sub eax, r8d
    imul eax, eax
    imul eax, eax, PALETTE_DISTANCE_RED_WEIGHT
    mov edx, ecx
    shr edx, 8
    and edx, 0FFh
    sub edx, r9d
    imul edx, edx
    imul edx, edx, PALETTE_DISTANCE_GREEN_WEIGHT
    add eax, edx
    and ecx, 0FFh
    sub ecx, r10d
    imul ecx, ecx
    imul ecx, ecx, PALETTE_DISTANCE_BLUE_WEIGHT
    add eax, ecx
    cmp eax, r13d
    jae palette_lut_build_color_next
    mov r13d, eax
    mov r14d, esi
palette_lut_build_color_next:
    inc esi
    cmp esi, PALETTE_COLOR_COUNT
    jb palette_lut_build_color
    mov byte ptr [rdi + rbx], r14b
    inc ebx
    cmp ebx, PALETTE_LUT_ENTRY_COUNT
    jb palette_lut_build_entry
    pop r14
    pop r13
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
palette_lut_build ENDP

framebuffer_palette_quantize PROC
    push rbx
    push rsi
    push rdi
    push r12
    lea rsi, framebuffer_bgra
    lea rdi, palette_lut
    lea r12, palette_sweetie16_bgra
    xor ebx, ebx
framebuffer_palette_quantize_row:
    mov eax, ebx
    and eax, DITHER_ROW_COUNT - 1
    shl eax, 4
    lea rcx, dither_add_rows
    movdqa xmm4, xmmword ptr [rcx + rax]
    lea rcx, dither_sub_rows
    movdqa xmm5, xmmword ptr [rcx + rax]
    mov r8d, SCREEN_WIDTH_PX / 4
framebuffer_palette_quantize_four_pixels:
    movdqa xmm0, xmmword ptr [rsi]
    paddusb xmm0, xmm4
    psubusb xmm0, xmm5
    mov r9d, 4
framebuffer_palette_quantize_pixel:
    movd eax, xmm0
    mov ecx, eax
    shr ecx, PALETTE_LUT_RED_SHIFT
    and ecx, PALETTE_LUT_RED_MASK
    mov edx, eax
    shr edx, PALETTE_LUT_GREEN_SHIFT
    and edx, PALETTE_LUT_GREEN_MASK
    or ecx, edx
    shr eax, PALETTE_LUT_LEVEL_TO_CHANNEL_SHIFT
    and eax, PALETTE_LUT_CHANNEL_MASK
    or ecx, eax
    movzx eax, byte ptr [rdi + rcx]
    mov eax, dword ptr [r12 + rax * 4]
    mov dword ptr [rsi], eax
    add rsi, 4
    psrldq xmm0, 4
    dec r9d
    jnz framebuffer_palette_quantize_pixel
    dec r8d
    jnz framebuffer_palette_quantize_four_pixels
    inc ebx
    cmp ebx, SCREEN_HEIGHT_PX
    jb framebuffer_palette_quantize_row
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
framebuffer_palette_quantize ENDP

framebuffer_invert PROC
    lea rcx, framebuffer_bgra
    mov edx, SCREEN_PIXEL_COUNT / 4
    movdqa xmm1, xmmword ptr pixel_rgb_mask_x4
framebuffer_invert_four_pixels:
    movdqa xmm0, xmmword ptr [rcx]
    pxor xmm0, xmm1
    movdqa xmmword ptr [rcx], xmm0
    add rcx, 16
    dec edx
    jnz framebuffer_invert_four_pixels
    ret
framebuffer_invert ENDP

framebuffer_rows_fill PROC
    push rdi
    assert_below_unsigned edx, SCREEN_HEIGHT_PX + 1
    assert_below_unsigned r8d, SCREEN_HEIGHT_PX + 1
    cmp edx, r8d
    jae framebuffer_rows_fill_done
    imul eax, edx, SCREEN_WIDTH_PX
    lea rdi, framebuffer_bgra
    lea rdi, [rdi + rax * 4]
    mov eax, r8d
    sub eax, edx
    imul eax, eax, SCREEN_WIDTH_PX
    mov edx, ecx
    mov ecx, eax
    mov eax, edx
    rep stosd
framebuffer_rows_fill_done:
    pop rdi
    ret
framebuffer_rows_fill ENDP

framebuffer_lerp_toward PROC
    assert_below_unsigned edx, LERP_LEVEL_FULL + 1
    pxor xmm3, xmm3
    movd xmm5, ecx
    punpcklbw xmm5, xmm3
    punpcklqdq xmm5, xmm5
    movd xmm4, edx
    pshuflw xmm4, xmm4, 0
    punpcklqdq xmm4, xmm4
    lea rcx, framebuffer_bgra
    mov edx, SCREEN_PIXEL_COUNT / 4
framebuffer_lerp_toward_four_pixels:
    movdqa xmm0, xmmword ptr [rcx]
    movdqa xmm1, xmm0
    pxor xmm3, xmm3
    punpcklbw xmm0, xmm3
    punpckhbw xmm1, xmm3
    movdqa xmm2, xmm5
    psubw xmm2, xmm0
    pmullw xmm2, xmm4
    psraw xmm2, LERP_LEVEL_SHIFT
    paddw xmm0, xmm2
    movdqa xmm2, xmm5
    psubw xmm2, xmm1
    pmullw xmm2, xmm4
    psraw xmm2, LERP_LEVEL_SHIFT
    paddw xmm1, xmm2
    packuswb xmm0, xmm1
    movdqa xmmword ptr [rcx], xmm0
    add rcx, 16
    dec edx
    jnz framebuffer_lerp_toward_four_pixels
    ret
framebuffer_lerp_toward ENDP

framebuffer_chromatic_split PROC
    push rsi
    push rdi
    assert_above_zero_signed ecx
    assert_below_unsigned ecx, CHROMA_OFFSET_MAX_PX + 1
    movdqa xmm3, xmmword ptr pixel_red_mask_x4
    movdqa xmm4, xmmword ptr pixel_green_mask_x4
    movdqa xmm5, xmmword ptr pixel_blue_mask_x4
    shl ecx, 2
    lea r8, framebuffer_bgra
    mov r9d, SCREEN_HEIGHT_PX
framebuffer_chromatic_split_row:
    mov rsi, r8
    lea rdi, chroma_row_bgra
    add rdi, CHROMA_ROW_PADDING_PX * 4
    mov edx, SCREEN_WIDTH_PX / 4
framebuffer_chromatic_split_copy:
    movdqa xmm0, xmmword ptr [rsi]
    movdqu xmmword ptr [rdi], xmm0
    add rsi, 16
    add rdi, 16
    dec edx
    jnz framebuffer_chromatic_split_copy
    lea rsi, chroma_row_bgra
    add rsi, CHROMA_ROW_PADDING_PX * 4
    mov rdi, r8
    mov edx, SCREEN_WIDTH_PX / 4
framebuffer_chromatic_split_combine:
    movdqu xmm0, xmmword ptr [rsi + rcx]
    pand xmm0, xmm3
    movdqu xmm1, xmmword ptr [rsi]
    pand xmm1, xmm4
    por xmm0, xmm1
    mov rax, rsi
    sub rax, rcx
    movdqu xmm1, xmmword ptr [rax]
    pand xmm1, xmm5
    por xmm0, xmm1
    movdqa xmmword ptr [rdi], xmm0
    add rsi, 16
    add rdi, 16
    dec edx
    jnz framebuffer_chromatic_split_combine
    add r8, SCREEN_WIDTH_PX * 4
    dec r9d
    jnz framebuffer_chromatic_split_row
    pop rdi
    pop rsi
    ret
framebuffer_chromatic_split ENDP

framebuffer_rect_fill PROC
    assert_not_negative_signed r8d
    assert_not_negative_signed r9d
    mov r10d, dword ptr [rsp + CALLEE_ARG5]
    assert_bits_clear r10d, COLOR_ALPHA_MASK
    add ecx, screen_shake_offset_x_px
    add edx, screen_shake_offset_y_px
    push rdi
    add r8d, ecx
    add r9d, edx
    xor eax, eax
    test ecx, ecx
    cmovl ecx, eax
    test edx, edx
    cmovl edx, eax
    mov eax, SCREEN_WIDTH_PX
    cmp r8d, eax
    cmovg r8d, eax
    mov eax, SCREEN_HEIGHT_PX
    cmp r9d, eax
    cmovg r9d, eax
    sub r8d, ecx
    jle framebuffer_rect_fill_done
    cmp edx, r9d
    jge framebuffer_rect_fill_done
    mov r11d, ecx
framebuffer_rect_fill_row:
    imul eax, edx, SCREEN_WIDTH_PX
    add eax, r11d
    lea rdi, framebuffer_bgra
    lea rdi, [rdi + rax * 4]
    mov ecx, r8d
    mov eax, r10d
    rep stosd
    inc edx
    cmp edx, r9d
    jl framebuffer_rect_fill_row
framebuffer_rect_fill_done:
    pop rdi
    ret
framebuffer_rect_fill ENDP

framebuffer_line_draw PROC
    push rbx
    push rsi
    push rdi
    push r12
    push r13
    mov r10d, dword ptr [rsp + FRAMEBUFFER_LINE_DRAW_ARG5]
    assert_bits_clear r10d, COLOR_ALPHA_MASK
    add ecx, screen_shake_offset_x_px
    add r8d, screen_shake_offset_x_px
    add edx, screen_shake_offset_y_px
    add r9d, screen_shake_offset_y_px
    mov eax, ecx
    and eax, r8d
    js framebuffer_line_draw_done
    mov eax, edx
    and eax, r9d
    js framebuffer_line_draw_done
    cmp ecx, SCREEN_WIDTH_PX
    jl framebuffer_line_draw_x_visible
    cmp r8d, SCREEN_WIDTH_PX
    jge framebuffer_line_draw_done
framebuffer_line_draw_x_visible:
    cmp edx, SCREEN_HEIGHT_PX
    jl framebuffer_line_draw_y_visible
    cmp r9d, SCREEN_HEIGHT_PX
    jge framebuffer_line_draw_done
framebuffer_line_draw_y_visible:
    mov r11d, r8d
    sub r11d, ecx
    mov esi, 1
    jns framebuffer_line_draw_dx_ready
    neg r11d
    mov esi, -1
framebuffer_line_draw_dx_ready:
    mov r12d, r9d
    sub r12d, edx
    mov edi, 1
    jns framebuffer_line_draw_dy_ready
    neg r12d
    mov edi, -1
framebuffer_line_draw_dy_ready:
    neg r12d
    lea r13d, [r11 + r12]
    lea rbx, framebuffer_bgra
framebuffer_line_draw_pixel:
    cmp ecx, SCREEN_WIDTH_PX
    jae framebuffer_line_draw_step_check
    cmp edx, SCREEN_HEIGHT_PX
    jae framebuffer_line_draw_step_check
    imul eax, edx, SCREEN_WIDTH_PX
    add eax, ecx
    mov dword ptr [rbx + rax * 4], r10d
framebuffer_line_draw_step_check:
    cmp ecx, r8d
    jne framebuffer_line_draw_step
    cmp edx, r9d
    je framebuffer_line_draw_done
framebuffer_line_draw_step:
    lea eax, [r13 + r13]
    cmp eax, r12d
    jl framebuffer_line_draw_step_y
    add r13d, r12d
    add ecx, esi
framebuffer_line_draw_step_y:
    cmp eax, r11d
    jg framebuffer_line_draw_pixel
    add r13d, r11d
    add edx, edi
    jmp framebuffer_line_draw_pixel
framebuffer_line_draw_done:
    pop r13
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
framebuffer_line_draw ENDP

framebuffer_ellipse_shade PROC
    push rbx
    push rsi
    push rdi
    push r12
    push r13
    mov eax, dword ptr [rsp + FRAMEBUFFER_ELLIPSE_SHADE_ARG5]
    assert_below_unsigned eax, COLOR_LEVEL_FULL + 1
    test r8d, r8d
    jle framebuffer_ellipse_shade_done
    test r9d, r9d
    jle framebuffer_ellipse_shade_done
    add ecx, screen_shake_offset_x_px
    add edx, screen_shake_offset_y_px
    movd xmm4, eax
    pshuflw xmm4, xmm4, 0
    pxor xmm5, xmm5
    mov r12d, ecx
    mov r13d, edx
    cvtsi2ss xmm3, r9d
    mov ebx, r9d
    neg ebx
framebuffer_ellipse_shade_row:
    cmp ebx, r9d
    jg framebuffer_ellipse_shade_done
    lea edx, [r13 + rbx]
    cmp edx, SCREEN_HEIGHT_PX
    jae framebuffer_ellipse_shade_row_next
    cvtsi2ss xmm0, ebx
    divss xmm0, xmm3
    mulss xmm0, xmm0
    movss xmm1, float_one
    subss xmm1, xmm0
    maxss xmm1, float_zero
    sqrtss xmm1, xmm1
    cvtsi2ss xmm2, r8d
    mulss xmm1, xmm2
    cvtss2si eax, xmm1
    mov esi, r12d
    sub esi, eax
    mov edi, r12d
    add edi, eax
    xor eax, eax
    test esi, esi
    cmovl esi, eax
    mov eax, SCREEN_WIDTH_PX - 1
    cmp edi, eax
    cmovg edi, eax
    imul eax, edx, SCREEN_WIDTH_PX
    lea r10, framebuffer_bgra
    lea r10, [r10 + rax * 4]
framebuffer_ellipse_shade_pixel:
    cmp esi, edi
    jg framebuffer_ellipse_shade_row_next
    movd xmm0, dword ptr [r10 + rsi * 4]
    punpcklbw xmm0, xmm5
    pmullw xmm0, xmm4
    psrlw xmm0, COLOR_LEVEL_SHIFT
    packuswb xmm0, xmm5
    movd dword ptr [r10 + rsi * 4], xmm0
    inc esi
    jmp framebuffer_ellipse_shade_pixel
framebuffer_ellipse_shade_row_next:
    inc ebx
    jmp framebuffer_ellipse_shade_row
framebuffer_ellipse_shade_done:
    pop r13
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
framebuffer_ellipse_shade ENDP

frame_post_effects PROC
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 0, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    mov eax, screen_flash_ticks_left
    test eax, eax
    jz frame_post_effects_chroma
    imul eax, eax, SCREEN_FLASH_LEVEL_MAX
    xor edx, edx
    div screen_flash_duration_ticks
    mov edx, eax
    mov ecx, screen_flash_color_bgra
    call framebuffer_lerp_toward
frame_post_effects_chroma:
    mov eax, screen_chroma_ticks_left
    test eax, eax
    jz frame_post_effects_impact
    add eax, CHROMA_TICKS_PER_PX - 1
    xor edx, edx
    mov ecx, CHROMA_TICKS_PER_PX
    div ecx
    mov ecx, CHROMA_OFFSET_MAX_PX
    cmp eax, ecx
    cmova eax, ecx
    mov ecx, eax
    call framebuffer_chromatic_split
frame_post_effects_impact:
    cmp screen_impact_frames_left, 0
    je frame_post_effects_quantize
    dec screen_impact_frames_left
    call framebuffer_invert
frame_post_effects_quantize:
    call framebuffer_palette_quantize
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    ret
frame_post_effects ENDP

frame_present PROC
    sub rsp, FRAME_PRESENT_FRAME_BYTES
    frame_alignment_check 0, FRAME_PRESENT_FRAME_BYTES
    xor eax, eax
    mov ecx, screen_zoom_ticks_left
    test ecx, ecx
    jz frame_present_zoom_ready
    imul eax, ecx, ZOOM_MAX_PX
    xor edx, edx
    div screen_zoom_duration_ticks
frame_present_zoom_ready:
    mov dword ptr [rsp + CALL_ARG6], eax
    mov ecx, SCREEN_WIDTH_PX
    sub ecx, eax
    sub ecx, eax
    mov dword ptr [rsp + CALL_ARG8], ecx
    imul eax, eax, 3
    shr eax, 2
    mov dword ptr [rsp + CALL_ARG7], eax
    mov ecx, SCREEN_HEIGHT_PX
    sub ecx, eax
    sub ecx, eax
    mov dword ptr [rsp + CALL_ARG9], ecx
    mov rcx, window_dc
    xor edx, edx
    xor r8d, r8d
    mov r9d, WINDOW_CLIENT_WIDTH_PX
    mov dword ptr [rsp + CALL_ARG5], WINDOW_CLIENT_HEIGHT_PX
    lea rax, framebuffer_bgra
    mov qword ptr [rsp + CALL_ARG10], rax
    lea rax, framebuffer_bitmap_info
    mov qword ptr [rsp + CALL_ARG11], rax
    mov dword ptr [rsp + CALL_ARG12], DIB_RGB_COLORS
    mov dword ptr [rsp + CALL_ARG13], SRCCOPY
    call StretchDIBits
    add rsp, FRAME_PRESENT_FRAME_BYTES
    ret
frame_present ENDP
