FONT_DIGIT_COUNT                    equ 10
FONT_DIGIT_ROWS                     equ 5
FONT_DIGIT_COLUMNS                  equ 3
FONT_DIGIT_ADVANCE_CELLS            equ FONT_DIGIT_COLUMNS + 1
FONT_DIGIT_TWO_DIGITS_CELLS         equ FONT_DIGIT_ADVANCE_CELLS + FONT_DIGIT_COLUMNS
FONT_DIGIT_LEFT_COLUMN_BIT          equ 100b
FONT_DIGIT_ROW_MASK                 equ 111b
FONT_TEXT_FIRST_CHAR                equ 32
FONT_TEXT_LAST_CHAR                 equ 90
FONT_TEXT_GLYPH_COUNT               equ FONT_TEXT_LAST_CHAR - FONT_TEXT_FIRST_CHAR + 1
FONT_TEXT_ROWS                      equ 7
FONT_TEXT_COLUMNS                   equ 5
FONT_TEXT_LEFT_COLUMN_BIT           equ 10000b
FONT_TEXT_ROW_MASK                  equ 11111b
FONT_TEXT_ADVANCE_CELLS             equ FONT_TEXT_COLUMNS + 1
FONT_TEXT_LINE_CELLS                equ FONT_TEXT_ROWS + 2
TEXT_NEWLINE_CHAR                   equ 10
TEXT_RAINBOW_HUE_PER_CHAR           equ 2
TEXT_WAVE_PHASE_PER_CHAR            equ 5
TEXT_WAVE_DIVISOR                   equ 4
TEXT_SCRATCH_BYTES                  equ 64
TEXT_NUMBER_MAX                     equ 999
TEXT_DRAW_PUSHED_REGISTER_COUNT     equ 8
TEXT_DRAW_FRAME_BYTES               equ CALL_ARG6 + 32
TEXT_DRAW_LOCAL_COLOR               equ CALL_ARG6
TEXT_DRAW_LOCAL_SCALE               equ CALL_ARG6 + 4
TEXT_DRAW_LOCAL_LINE_LEFT           equ CALL_ARG6 + 8
TEXT_DRAW_LOCAL_GLYPH_COLOR         equ CALL_ARG6 + 12
TEXT_DRAW_LOCAL_CHAR_INDEX          equ CALL_ARG6 + 16
TEXT_DRAW_ARG5                      equ TEXT_DRAW_FRAME_BYTES + 8 * TEXT_DRAW_PUSHED_REGISTER_COUNT + CALLEE_ARG5
SCORE_DIGIT_DRAW_PUSHED_REGISTER_COUNT equ 7
SCORE_DIGIT_DRAW_ARG5               equ FRAME_6_ARGS_ODD_PUSHES_BYTES + 8 * SCORE_DIGIT_DRAW_PUSHED_REGISTER_COUNT + CALLEE_ARG5
SCORE_DECIMAL_BASE                  equ 10
SCORE_CELL_PX                       equ 4
SCORE_POP_CELL_PX                   equ 5
SCORE_TOP_PX                        equ 12

.const
font_digit_rows_3x5                 BYTE 111b, 101b, 101b, 101b, 111b
                                    BYTE 010b, 110b, 010b, 010b, 111b
                                    BYTE 111b, 001b, 111b, 100b, 111b
                                    BYTE 111b, 001b, 111b, 001b, 111b
                                    BYTE 101b, 101b, 111b, 001b, 001b
                                    BYTE 111b, 100b, 111b, 001b, 111b
                                    BYTE 111b, 100b, 111b, 101b, 111b
                                    BYTE 111b, 001b, 001b, 001b, 001b
                                    BYTE 111b, 101b, 111b, 101b, 111b
                                    BYTE 111b, 101b, 111b, 001b, 111b
font_digit_rows_3x5_end             LABEL BYTE
.ERRNZ (font_digit_rows_3x5_end - font_digit_rows_3x5) - FONT_DIGIT_COUNT * FONT_DIGIT_ROWS

font_text_rows_5x7                  BYTE 00000b, 00000b, 00000b, 00000b, 00000b, 00000b, 00000b
                                    BYTE 00100b, 00100b, 00100b, 00100b, 00100b, 00000b, 00100b
                                    BYTE 01010b, 01010b, 00000b, 00000b, 00000b, 00000b, 00000b
                                    BYTE 01010b, 01010b, 11111b, 01010b, 11111b, 01010b, 01010b
                                    BYTE 00100b, 01111b, 10100b, 01110b, 00101b, 11110b, 00100b
                                    BYTE 11000b, 11001b, 00010b, 00100b, 01000b, 10011b, 00011b
                                    BYTE 01100b, 10010b, 10100b, 01000b, 10101b, 10010b, 01101b
                                    BYTE 00100b, 00100b, 01000b, 00000b, 00000b, 00000b, 00000b
                                    BYTE 00010b, 00100b, 01000b, 01000b, 01000b, 00100b, 00010b
                                    BYTE 01000b, 00100b, 00010b, 00010b, 00010b, 00100b, 01000b
                                    BYTE 00000b, 10001b, 01010b, 00100b, 01010b, 10001b, 00000b
                                    BYTE 00000b, 00100b, 00100b, 11111b, 00100b, 00100b, 00000b
                                    BYTE 00000b, 00000b, 00000b, 00000b, 01100b, 00100b, 01000b
                                    BYTE 00000b, 00000b, 00000b, 11111b, 00000b, 00000b, 00000b
                                    BYTE 00000b, 00000b, 00000b, 00000b, 00000b, 01100b, 01100b
                                    BYTE 00000b, 00001b, 00010b, 00100b, 01000b, 10000b, 00000b
                                    BYTE 01110b, 10001b, 10011b, 10101b, 11001b, 10001b, 01110b
                                    BYTE 00100b, 01100b, 00100b, 00100b, 00100b, 00100b, 01110b
                                    BYTE 01110b, 10001b, 00001b, 00010b, 00100b, 01000b, 11111b
                                    BYTE 11111b, 00010b, 00100b, 00010b, 00001b, 10001b, 01110b
                                    BYTE 00010b, 00110b, 01010b, 10010b, 11111b, 00010b, 00010b
                                    BYTE 11111b, 10000b, 11110b, 00001b, 00001b, 10001b, 01110b
                                    BYTE 00110b, 01000b, 10000b, 11110b, 10001b, 10001b, 01110b
                                    BYTE 11111b, 00001b, 00010b, 00100b, 01000b, 01000b, 01000b
                                    BYTE 01110b, 10001b, 10001b, 01110b, 10001b, 10001b, 01110b
                                    BYTE 01110b, 10001b, 10001b, 01111b, 00001b, 00010b, 01100b
                                    BYTE 00000b, 01100b, 01100b, 00000b, 01100b, 01100b, 00000b
                                    BYTE 00000b, 01100b, 01100b, 00000b, 01100b, 00100b, 01000b
                                    BYTE 00010b, 00100b, 01000b, 10000b, 01000b, 00100b, 00010b
                                    BYTE 00000b, 00000b, 11111b, 00000b, 11111b, 00000b, 00000b
                                    BYTE 01000b, 00100b, 00010b, 00001b, 00010b, 00100b, 01000b
                                    BYTE 01110b, 10001b, 00001b, 00010b, 00100b, 00000b, 00100b
                                    BYTE 01110b, 10001b, 00001b, 01101b, 10101b, 10101b, 01110b
                                    BYTE 01110b, 10001b, 10001b, 11111b, 10001b, 10001b, 10001b
                                    BYTE 11110b, 10001b, 10001b, 11110b, 10001b, 10001b, 11110b
                                    BYTE 01110b, 10001b, 10000b, 10000b, 10000b, 10001b, 01110b
                                    BYTE 11100b, 10010b, 10001b, 10001b, 10001b, 10010b, 11100b
                                    BYTE 11111b, 10000b, 10000b, 11110b, 10000b, 10000b, 11111b
                                    BYTE 11111b, 10000b, 10000b, 11110b, 10000b, 10000b, 10000b
                                    BYTE 01110b, 10001b, 10000b, 10111b, 10001b, 10001b, 01111b
                                    BYTE 10001b, 10001b, 10001b, 11111b, 10001b, 10001b, 10001b
                                    BYTE 01110b, 00100b, 00100b, 00100b, 00100b, 00100b, 01110b
                                    BYTE 00111b, 00010b, 00010b, 00010b, 00010b, 10010b, 01100b
                                    BYTE 10001b, 10010b, 10100b, 11000b, 10100b, 10010b, 10001b
                                    BYTE 10000b, 10000b, 10000b, 10000b, 10000b, 10000b, 11111b
                                    BYTE 10001b, 11011b, 10101b, 10101b, 10001b, 10001b, 10001b
                                    BYTE 10001b, 10001b, 11001b, 10101b, 10011b, 10001b, 10001b
                                    BYTE 01110b, 10001b, 10001b, 10001b, 10001b, 10001b, 01110b
                                    BYTE 11110b, 10001b, 10001b, 11110b, 10000b, 10000b, 10000b
                                    BYTE 01110b, 10001b, 10001b, 10001b, 10101b, 10010b, 01101b
                                    BYTE 11110b, 10001b, 10001b, 11110b, 10100b, 10010b, 10001b
                                    BYTE 01111b, 10000b, 10000b, 01110b, 00001b, 00001b, 11110b
                                    BYTE 11111b, 00100b, 00100b, 00100b, 00100b, 00100b, 00100b
                                    BYTE 10001b, 10001b, 10001b, 10001b, 10001b, 10001b, 01110b
                                    BYTE 10001b, 10001b, 10001b, 10001b, 10001b, 01010b, 00100b
                                    BYTE 10001b, 10001b, 10001b, 10101b, 10101b, 10101b, 01010b
                                    BYTE 10001b, 10001b, 01010b, 00100b, 01010b, 10001b, 10001b
                                    BYTE 10001b, 10001b, 10001b, 01010b, 00100b, 00100b, 00100b
                                    BYTE 11111b, 00001b, 00010b, 00100b, 01000b, 10000b, 11111b
font_text_rows_5x7_end              LABEL BYTE
.ERRNZ (font_text_rows_5x7_end - font_text_rows_5x7) - FONT_TEXT_GLYPH_COUNT * FONT_TEXT_ROWS

.data?
text_scratch                        BYTE TEXT_SCRATCH_BYTES DUP (?)

.code

score_draw PROC
    push rbx
    push rsi
    push rdi
    push r12
    push r13
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 5, FRAME_6_ARGS_ODD_PUSHES_BYTES
    assert_below_unsigned ecx, SCORE_MAX + 1
    assert_above_zero_signed r9d
    mov esi, edx
    mov edi, r8d
    mov r12d, r9d
    mov eax, r12d
    sub eax, SCORE_CELL_PX
    imul eax, eax, FONT_DIGIT_ROWS
    sar eax, 1
    mov r13d, SCORE_TOP_PX
    sub r13d, eax
    mov eax, ecx
    xor edx, edx
    mov ecx, SCORE_DECIMAL_BASE
    div ecx
    mov ebx, edx
    test eax, eax
    jz score_draw_one_digit
    mov ecx, eax
    imul edx, r12d, FONT_DIGIT_TWO_DIGITS_CELLS
    sar edx, 1
    neg edx
    add edx, esi
    mov r8d, r13d
    mov r9d, r12d
    mov dword ptr [rsp + CALL_ARG5], edi
    call score_digit_draw
    imul edx, r12d, FONT_DIGIT_TWO_DIGITS_CELLS
    sar edx, 1
    neg edx
    add edx, esi
    imul eax, r12d, FONT_DIGIT_ADVANCE_CELLS
    add edx, eax
    jmp score_draw_ones_digit
score_draw_one_digit:
    imul edx, r12d, FONT_DIGIT_COLUMNS
    sar edx, 1
    neg edx
    add edx, esi
score_draw_ones_digit:
    mov ecx, ebx
    mov r8d, r13d
    mov r9d, r12d
    mov dword ptr [rsp + CALL_ARG5], edi
    call score_digit_draw
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop r13
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
score_draw ENDP

score_digit_draw PROC
    push rbx
    push rsi
    push rdi
    push r12
    push r13
    push r14
    push r15
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check SCORE_DIGIT_DRAW_PUSHED_REGISTER_COUNT, FRAME_6_ARGS_ODD_PUSHES_BYTES
    assert_below_unsigned ecx, FONT_DIGIT_COUNT
    mov eax, dword ptr [rsp + SCORE_DIGIT_DRAW_ARG5]
    mov dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5], eax
    mov r12d, edx
    mov edi, r8d
    mov r13d, r9d
    imul eax, ecx, FONT_DIGIT_ROWS
    lea rbx, font_digit_rows_3x5
    add rbx, rax
    lea r14, [rbx + FONT_DIGIT_ROWS]
score_digit_draw_row:
    movzx esi, byte ptr [rbx]
    mov r15d, r12d
score_digit_draw_cell:
    test esi, FONT_DIGIT_ROW_MASK
    jz score_digit_draw_row_next
    test esi, FONT_DIGIT_LEFT_COLUMN_BIT
    jz score_digit_draw_cell_next
    mov ecx, r15d
    mov edx, edi
    mov r8d, r13d
    mov r9d, r13d
    mov eax, dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5]
    mov dword ptr [rsp + CALL_ARG5], eax
    call framebuffer_rect_fill
score_digit_draw_cell_next:
    add r15d, r13d
    shl esi, 1
    jmp score_digit_draw_cell
score_digit_draw_row_next:
    add edi, r13d
    inc rbx
    cmp rbx, r14
    jb score_digit_draw_row
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop r15
    pop r14
    pop r13
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
score_digit_draw ENDP

text_width_px PROC
    xor eax, eax
text_width_px_count:
    movzx r8d, byte ptr [rcx + rax]
    test r8d, r8d
    jz text_width_px_counted
    cmp r8d, TEXT_NEWLINE_CHAR
    je text_width_px_counted
    inc eax
    jmp text_width_px_count
text_width_px_counted:
    imul eax, eax, FONT_TEXT_ADVANCE_CELLS
    sub eax, FONT_TEXT_ADVANCE_CELLS - FONT_TEXT_COLUMNS
    imul eax, edx
    ret
text_width_px ENDP

text_draw_centered PROC
    xor eax, eax
text_draw_centered_count:
    movzx r10d, byte ptr [rcx + rax]
    test r10d, r10d
    jz text_draw_centered_counted
    cmp r10d, TEXT_NEWLINE_CHAR
    je text_draw_centered_counted
    inc eax
    jmp text_draw_centered_count
text_draw_centered_counted:
    imul eax, eax, FONT_TEXT_ADVANCE_CELLS
    sub eax, FONT_TEXT_ADVANCE_CELLS - FONT_TEXT_COLUMNS
    imul eax, dword ptr [rsp + CALLEE_ARG5]
    sar eax, 1
    sub edx, eax
    jmp text_draw
text_draw_centered ENDP

text_draw PROC
    push rbx
    push rbp
    push rsi
    push rdi
    push r12
    push r13
    push r14
    push r15
    sub rsp, TEXT_DRAW_FRAME_BYTES
    frame_alignment_check TEXT_DRAW_PUSHED_REGISTER_COUNT, TEXT_DRAW_FRAME_BYTES
    mov eax, dword ptr [rsp + TEXT_DRAW_ARG5]
    assert_above_zero_signed eax
    mov dword ptr [rsp + TEXT_DRAW_LOCAL_SCALE], eax
    mov dword ptr [rsp + TEXT_DRAW_LOCAL_COLOR], r9d
    mov dword ptr [rsp + TEXT_DRAW_LOCAL_LINE_LEFT], edx
    mov dword ptr [rsp + TEXT_DRAW_LOCAL_CHAR_INDEX], 0
    mov rsi, rcx
    mov r13d, edx
    mov r14d, r8d

text_draw_char:
    movzx eax, byte ptr [rsi]
    inc rsi
    test eax, eax
    jz text_draw_done
    cmp eax, TEXT_NEWLINE_CHAR
    jne text_draw_glyph
    mov r13d, dword ptr [rsp + TEXT_DRAW_LOCAL_LINE_LEFT]
    imul eax, dword ptr [rsp + TEXT_DRAW_LOCAL_SCALE], FONT_TEXT_LINE_CELLS
    add r14d, eax
    jmp text_draw_char

text_draw_glyph:
    sub eax, FONT_TEXT_FIRST_CHAR
    assert_below_unsigned eax, FONT_TEXT_GLYPH_COUNT
    imul eax, eax, FONT_TEXT_ROWS
    lea rbx, font_text_rows_5x7
    add rbx, rax
    lea r12, [rbx + FONT_TEXT_ROWS]
    mov edi, r14d
    mov eax, dword ptr [rsp + TEXT_DRAW_LOCAL_COLOR]
    cmp eax, TEXT_COLOR_RAINBOW
    jne text_draw_glyph_color_ready
    imul eax, dword ptr [rsp + TEXT_DRAW_LOCAL_CHAR_INDEX], TEXT_RAINBOW_HUE_PER_CHAR
    mov ecx, effects_ticks
    shr ecx, 1
    add eax, ecx
    rainbow_color_from_eax ecx
    mov dword ptr [rsp + TEXT_DRAW_LOCAL_GLYPH_COLOR], ecx
    imul eax, dword ptr [rsp + TEXT_DRAW_LOCAL_CHAR_INDEX], TEXT_WAVE_PHASE_PER_CHAR
    add eax, effects_ticks
    triangle_wave_from_eax
    sub eax, TRIANGLE_WAVE_PERIOD_TICKS / 4
    imul eax, dword ptr [rsp + TEXT_DRAW_LOCAL_SCALE]
    cdq
    mov ecx, TEXT_WAVE_DIVISOR
    idiv ecx
    add edi, eax
    jmp text_draw_row
text_draw_glyph_color_ready:
    mov dword ptr [rsp + TEXT_DRAW_LOCAL_GLYPH_COLOR], eax
text_draw_row:
    movzx ebp, byte ptr [rbx]
    mov r15d, r13d
text_draw_cell:
    test ebp, FONT_TEXT_ROW_MASK
    jz text_draw_row_next
    test ebp, FONT_TEXT_LEFT_COLUMN_BIT
    jz text_draw_cell_next
    mov ecx, r15d
    mov edx, edi
    mov r8d, dword ptr [rsp + TEXT_DRAW_LOCAL_SCALE]
    mov r9d, r8d
    mov eax, dword ptr [rsp + TEXT_DRAW_LOCAL_GLYPH_COLOR]
    mov dword ptr [rsp + CALL_ARG5], eax
    call framebuffer_rect_fill
text_draw_cell_next:
    add r15d, dword ptr [rsp + TEXT_DRAW_LOCAL_SCALE]
    shl ebp, 1
    jmp text_draw_cell
text_draw_row_next:
    add edi, dword ptr [rsp + TEXT_DRAW_LOCAL_SCALE]
    inc rbx
    cmp rbx, r12
    jb text_draw_row
    imul eax, dword ptr [rsp + TEXT_DRAW_LOCAL_SCALE], FONT_TEXT_ADVANCE_CELLS
    add r13d, eax
    inc dword ptr [rsp + TEXT_DRAW_LOCAL_CHAR_INDEX]
    jmp text_draw_char

text_draw_done:
    add rsp, TEXT_DRAW_FRAME_BYTES
    pop r15
    pop r14
    pop r13
    pop r12
    pop rdi
    pop rsi
    pop rbp
    pop rbx
    ret
text_draw ENDP

text_append_string PROC
text_append_string_char:
    mov al, byte ptr [rdx]
    mov byte ptr [rcx], al
    test al, al
    jz text_append_string_done
    inc rcx
    inc rdx
    jmp text_append_string_char
text_append_string_done:
    mov rax, rcx
    ret
text_append_string ENDP

text_append_number PROC
    assert_below_unsigned edx, TEXT_NUMBER_MAX + 1
    mov eax, edx
    mov r8d, SCORE_DECIMAL_BASE
    cmp eax, SCORE_DECIMAL_BASE * SCORE_DECIMAL_BASE
    jb text_append_number_tens_check
    xor edx, edx
    mov r9d, SCORE_DECIMAL_BASE * SCORE_DECIMAL_BASE
    div r9d
    add al, '0'
    mov byte ptr [rcx], al
    inc rcx
    mov eax, edx
    jmp text_append_number_tens
text_append_number_tens_check:
    cmp eax, SCORE_DECIMAL_BASE
    jb text_append_number_ones
text_append_number_tens:
    xor edx, edx
    div r8d
    add al, '0'
    mov byte ptr [rcx], al
    inc rcx
    mov eax, edx
text_append_number_ones:
    add al, '0'
    mov byte ptr [rcx], al
    inc rcx
    mov byte ptr [rcx], 0
    mov rax, rcx
    ret
text_append_number ENDP
