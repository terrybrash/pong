option casemap:none

EXTERN GetModuleHandleA:PROC
EXTERN LoadCursorA:PROC
EXTERN RegisterClassExA:PROC
EXTERN AdjustWindowRect:PROC
EXTERN CreateWindowExA:PROC
EXTERN GetDC:PROC
EXTERN PeekMessageA:PROC
EXTERN TranslateMessage:PROC
EXTERN DispatchMessageA:PROC
EXTERN DefWindowProcA:PROC
EXTERN PostQuitMessage:PROC
EXTERN DestroyWindow:PROC
EXTERN StretchDIBits:PROC
EXTERN QueryPerformanceFrequency:PROC
EXTERN QueryPerformanceCounter:PROC
EXTERN DwmFlush:PROC
EXTERN Sleep:PROC
EXTERN ExitProcess:PROC

CS_OWNDC                            equ 00000020h
IDC_ARROW                           equ 32512
WS_CAPTION                          equ 00C00000h
WS_SYSMENU                          equ 00080000h
WS_MINIMIZEBOX                      equ 00020000h
WS_VISIBLE                          equ 10000000h
CW_USEDEFAULT                       equ 80000000h
PM_REMOVE                           equ 1
WM_DESTROY                          equ 0002h
WM_KILLFOCUS                        equ 0008h
WM_QUIT                             equ 0012h
WM_KEYDOWN                          equ 0100h
WM_KEYUP                            equ 0101h
KEYDOWN_LPARAM_WAS_DOWN_BIT         equ 30
VK_TAB                              equ 09h
VK_ESCAPE                           equ 1Bh
VK_SPACE                            equ 20h
VK_UP                               equ 26h
VK_DOWN                             equ 28h
VK_S                                equ 53h
VK_W                                equ 57h
VIRTUAL_KEY_COUNT                   equ 256
BI_RGB                              equ 0
DIB_RGB_COLORS                      equ 0
SRCCOPY                             equ 00CC0020h
DWM_FLUSH_FAILED_SLEEP_MS           equ 1

CALL_SHADOW_BYTES                   equ 32
CALL_ARG5                           equ 32
CALL_ARG6                           equ 40
CALL_ARG7                           equ 48
CALL_ARG8                           equ 56
CALL_ARG9                           equ 64
CALL_ARG10                          equ 72
CALL_ARG11                          equ 80
CALL_ARG12                          equ 88
CALL_ARG13                          equ 96
CALL_FRAME_BYTES_NO_PUSHES          equ CALL_SHADOW_BYTES + 8
MAIN_ENTRY_FRAME_BYTES              equ CALL_ARG12 + 16
FRAME_PRESENT_FRAME_BYTES           equ CALL_ARG13 + 8

SCREEN_WIDTH_PX                     equ 320
SCREEN_HEIGHT_PX                    equ 240
WINDOW_SCALE                        equ 3
WINDOW_CLIENT_WIDTH_PX              equ SCREEN_WIDTH_PX * WINDOW_SCALE
WINDOW_CLIENT_HEIGHT_PX             equ SCREEN_HEIGHT_PX * WINDOW_SCALE
WINDOW_STYLE                        equ WS_CAPTION OR WS_SYSMENU OR WS_MINIMIZEBOX OR WS_VISIBLE

SIM_TICKS_PER_SEC                   equ 120
SIM_TICKS_BEHIND_MAX                equ 8

COLOR_BACKGROUND_BGRA               equ 000A0A0Ah
COLOR_FOREGROUND_BGRA               equ 00E8E8E8h
CENTER_LINE_WIDTH_PX                equ 2
CENTER_LINE_DASH_PX                 equ 8
CENTER_LINE_PERIOD_PX               equ 16

FONT_DIGIT_COUNT                    equ 10
FONT_DIGIT_ROWS                     equ 5
FONT_DIGIT_COLUMNS                  equ 3
SCORE_DECIMAL_BASE                  equ 10
SCORE_CELL_PX                       equ 4
SCORE_DIGIT_WIDTH_PX                equ FONT_DIGIT_COLUMNS * SCORE_CELL_PX
SCORE_DIGIT_ADVANCE_PX              equ SCORE_DIGIT_WIDTH_PX + SCORE_CELL_PX
SCORE_TWO_DIGITS_WIDTH_PX           equ SCORE_DIGIT_ADVANCE_PX + SCORE_DIGIT_WIDTH_PX
SCORE_TOP_PX                        equ 12
SCORE_CENTER_FROM_SCREEN_CENTER_PX  equ 40

MATCH_WINNING_SCORE                 equ 11
SERVE_WAIT_TICKS                    equ SIM_TICKS_PER_SEC

MATCH_MODE_SERVE_WAIT               equ 0
MATCH_MODE_RALLY                    equ 1
MATCH_MODE_OVER                     equ 2
MATCH_MODE_COUNT                    equ 3

SERVE_SIDE_LEFT                     equ 0
SERVE_SIDE_RIGHT                    equ 1
SERVE_SIDE_COUNT                    equ 2

PADDLE_RIGHT_MODE_CPU               equ 0
PADDLE_RIGHT_MODE_KEYBOARD          equ 1
PADDLE_RIGHT_MODE_COUNT             equ 2

assert_below_unsigned MACRO value, limit
    LOCAL assert_below_unsigned_ok
    cmp value, limit
    jb assert_below_unsigned_ok
    ud2
assert_below_unsigned_ok:
ENDM

assert_above_zero_signed MACRO value
    LOCAL assert_above_zero_signed_ok
    cmp value, 0
    jg assert_above_zero_signed_ok
    ud2
assert_above_zero_signed_ok:
ENDM

assert_not_zero MACRO value
    LOCAL assert_not_zero_ok
    test value, value
    jnz assert_not_zero_ok
    ud2
assert_not_zero_ok:
ENDM

frame_alignment_check MACRO pushed_register_count, frame_bytes
    .ERRNZ (8 + 8 * pushed_register_count + frame_bytes) MOD 16, <frame breaks the 16 byte stack alignment at a call>
    .ERRE frame_bytes GE CALL_SHADOW_BYTES, <frame has no room for the call shadow space>
ENDM

WNDCLASSEXA STRUCT
    cbSize                          DWORD ?
    style                           DWORD ?
    lpfnWndProc                     QWORD ?
    cbClsExtra                      DWORD ?
    cbWndExtra                      DWORD ?
    hInstance                       QWORD ?
    hIcon                           QWORD ?
    hCursor                         QWORD ?
    hbrBackground                   QWORD ?
    lpszMenuName                    QWORD ?
    lpszClassName                   QWORD ?
    hIconSm                         QWORD ?
WNDCLASSEXA ENDS
.ERRNZ SIZEOF WNDCLASSEXA - 80

MSG STRUCT
    hwnd                            QWORD ?
    message                         DWORD ?
    message_padding                 DWORD ?
    wParam                          QWORD ?
    lParam                          QWORD ?
    time                            DWORD ?
    pt_x                            DWORD ?
    pt_y                            DWORD ?
    lPrivate                        DWORD ?
MSG ENDS
.ERRNZ SIZEOF MSG - 48

RECT STRUCT
    left                            DWORD ?
    top                             DWORD ?
    right                           DWORD ?
    bottom                          DWORD ?
RECT ENDS
.ERRNZ SIZEOF RECT - 16

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

.const
ALIGN 16
float_sign_mask_x4                  DWORD 4 DUP (80000000h)
float_abs_mask_x4                   DWORD 4 DUP (7FFFFFFFh)
field_half_width_px                 REAL4 160.0
field_half_height_px                REAL4 120.0
paddle_right_center_x_px            REAL4 142.0
paddle_half_width_px                REAL4 2.0
paddle_half_height_px               REAL4 16.0
paddle_player_speed_px_per_tick     REAL4 2.0
paddle_cpu_speed_px_per_tick        REAL4 1.4
ball_half_size_px                   REAL4 2.0
ball_serve_speed_px_per_tick        REAL4 1.5
ball_speed_max_px_per_tick          REAL4 3.5
ball_speed_gain_per_paddle_hit      REAL4 1.06
ball_serve_slopes                   REAL4 -0.6, -0.3, 0.3, 0.6
BALL_SERVE_SLOPE_COUNT              equ LENGTHOF ball_serve_slopes
.ERRNZ BALL_SERVE_SLOPE_COUNT AND (BALL_SERVE_SLOPE_COUNT - 1)
paddle_cpu_aim_offsets_px           REAL4 -12.0, -6.0, 6.0, 12.0
PADDLE_CPU_AIM_OFFSET_COUNT         equ LENGTHOF paddle_cpu_aim_offsets_px
.ERRNZ PADDLE_CPU_AIM_OFFSET_COUNT AND (PADDLE_CPU_AIM_OFFSET_COUNT - 1)
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

.data
window_class_name                   BYTE "pong", 0
window_title                        BYTE "Pong    W S or Up Down: move    Tab: 2 players    Space: new match    Esc: quit", 0
window_class                        WNDCLASSEXA <SIZEOF WNDCLASSEXA, CS_OWNDC>
window_outer_rect                   RECT <0, 0, WINDOW_CLIENT_WIDTH_PX, WINDOW_CLIENT_HEIGHT_PX>
framebuffer_bitmap_info             BITMAPINFOHEADER <SIZEOF BITMAPINFOHEADER, SCREEN_WIDTH_PX, -SCREEN_HEIGHT_PX, 1, 32, BI_RGB>
window_message                      MSG <>

.data?
ALIGN 16
framebuffer_bgra                    DWORD SCREEN_WIDTH_PX * SCREEN_HEIGHT_PX DUP (?)
window_dc                           QWORD ?
qpc_counts_per_sec                  QWORD ?
qpc_counts_per_tick                 QWORD ?
qpc_frame_last                      QWORD ?
qpc_frame_now                       QWORD ?
qpc_sim_behind_counts               QWORD ?
match_mode                          DWORD ?
match_serve_side                    DWORD ?
match_serve_wait_ticks_elapsed      DWORD ?
score_left                          DWORD ?
score_right                         DWORD ?
paddle_right_mode                   DWORD ?
paddle_left_center_y_px             REAL4 ?
paddle_right_center_y_px            REAL4 ?
paddle_cpu_aim_offset_px            REAL4 ?
ball_center_x_px                    REAL4 ?
ball_center_y_px                    REAL4 ?
ball_vel_x_px_per_tick              REAL4 ?
ball_vel_y_px_per_tick              REAL4 ?
ball_speed_px_per_tick              REAL4 ?
key_is_down_by_virtual_key          BYTE VIRTUAL_KEY_COUNT DUP (?)

.code

main_entry PROC
    sub rsp, MAIN_ENTRY_FRAME_BYTES
    frame_alignment_check 0, MAIN_ENTRY_FRAME_BYTES

    xor ecx, ecx
    call GetModuleHandleA
    assert_not_zero rax
    mov window_class.hInstance, rax

    xor ecx, ecx
    mov edx, IDC_ARROW
    call LoadCursorA
    assert_not_zero rax
    mov window_class.hCursor, rax

    lea rax, window_proc
    mov window_class.lpfnWndProc, rax
    lea rax, window_class_name
    mov window_class.lpszClassName, rax
    lea rcx, window_class
    call RegisterClassExA
    assert_not_zero eax

    lea rcx, window_outer_rect
    mov edx, WINDOW_STYLE
    xor r8d, r8d
    call AdjustWindowRect
    assert_not_zero eax

    xor ecx, ecx
    lea rdx, window_class_name
    lea r8, window_title
    mov r9d, WINDOW_STYLE
    mov dword ptr [rsp + CALL_ARG5], CW_USEDEFAULT
    mov dword ptr [rsp + CALL_ARG6], CW_USEDEFAULT
    mov eax, window_outer_rect.right
    sub eax, window_outer_rect.left
    mov dword ptr [rsp + CALL_ARG7], eax
    mov eax, window_outer_rect.bottom
    sub eax, window_outer_rect.top
    mov dword ptr [rsp + CALL_ARG8], eax
    mov qword ptr [rsp + CALL_ARG9], 0
    mov qword ptr [rsp + CALL_ARG10], 0
    mov rax, window_class.hInstance
    mov qword ptr [rsp + CALL_ARG11], rax
    mov qword ptr [rsp + CALL_ARG12], 0
    call CreateWindowExA
    assert_not_zero rax

    mov rcx, rax
    call GetDC
    assert_not_zero rax
    mov window_dc, rax

    lea rcx, qpc_counts_per_sec
    call QueryPerformanceFrequency
    mov rax, qpc_counts_per_sec
    xor edx, edx
    mov ecx, SIM_TICKS_PER_SEC
    div rcx
    assert_not_zero rax
    mov qpc_counts_per_tick, rax
    lea rcx, qpc_frame_last
    call QueryPerformanceCounter

main_frame:
    lea rcx, window_message
    xor edx, edx
    xor r8d, r8d
    xor r9d, r9d
    mov dword ptr [rsp + CALL_ARG5], PM_REMOVE
    call PeekMessageA
    test eax, eax
    jz main_sim_catch_up_begin
    cmp window_message.message, WM_QUIT
    je main_exit
    lea rcx, window_message
    call TranslateMessage
    lea rcx, window_message
    call DispatchMessageA
    jmp main_frame

main_sim_catch_up_begin:
    lea rcx, qpc_frame_now
    call QueryPerformanceCounter
    mov rax, qpc_frame_now
    mov rcx, rax
    sub rax, qpc_frame_last
    mov qpc_frame_last, rcx
    add rax, qpc_sim_behind_counts
    mov rcx, qpc_counts_per_tick
    imul rcx, rcx, SIM_TICKS_BEHIND_MAX
    cmp rax, rcx
    cmova rax, rcx
    mov qpc_sim_behind_counts, rax

main_sim_catch_up:
    mov rax, qpc_sim_behind_counts
    cmp rax, qpc_counts_per_tick
    jb main_sim_caught_up
    sub rax, qpc_counts_per_tick
    mov qpc_sim_behind_counts, rax
    call game_tick
    jmp main_sim_catch_up

main_sim_caught_up:
    call frame_render
    call frame_present
    call DwmFlush
    test eax, eax
    jz main_frame
    mov ecx, DWM_FLUSH_FAILED_SLEEP_MS
    call Sleep
    jmp main_frame

main_exit:
    mov rcx, window_message.wParam
    call ExitProcess
main_entry ENDP

window_proc PROC
    cmp edx, WM_KEYDOWN
    je window_proc_key_down
    cmp edx, WM_KEYUP
    je window_proc_key_up
    cmp edx, WM_KILLFOCUS
    je window_proc_focus_lost
    cmp edx, WM_DESTROY
    je window_proc_destroy
    jmp DefWindowProcA

window_proc_key_down:
    assert_below_unsigned r8, VIRTUAL_KEY_COUNT
    lea rax, key_is_down_by_virtual_key
    mov byte ptr [rax + r8], 1
    bt r9, KEYDOWN_LPARAM_WAS_DOWN_BIT
    jc window_proc_handled
    cmp r8d, VK_ESCAPE
    je window_proc_escape
    cmp r8d, VK_TAB
    je window_proc_tab
    cmp r8d, VK_SPACE
    je window_proc_space
    jmp window_proc_handled

window_proc_escape:
    sub rsp, CALL_FRAME_BYTES_NO_PUSHES
    frame_alignment_check 0, CALL_FRAME_BYTES_NO_PUSHES
    call DestroyWindow
    add rsp, CALL_FRAME_BYTES_NO_PUSHES
    jmp window_proc_handled

window_proc_tab:
    assert_below_unsigned paddle_right_mode, PADDLE_RIGHT_MODE_COUNT
    xor paddle_right_mode, PADDLE_RIGHT_MODE_CPU XOR PADDLE_RIGHT_MODE_KEYBOARD
    jmp window_proc_handled

window_proc_space:
    cmp match_mode, MATCH_MODE_OVER
    jne window_proc_handled
    mov score_left, 0
    mov score_right, 0
    mov match_serve_side, SERVE_SIDE_LEFT
    mov match_serve_wait_ticks_elapsed, 0
    mov match_mode, MATCH_MODE_SERVE_WAIT
    jmp window_proc_handled

window_proc_key_up:
    assert_below_unsigned r8, VIRTUAL_KEY_COUNT
    lea rax, key_is_down_by_virtual_key
    mov byte ptr [rax + r8], 0
    jmp window_proc_handled

window_proc_focus_lost:
    push rdi
    lea rdi, key_is_down_by_virtual_key
    mov ecx, VIRTUAL_KEY_COUNT
    xor eax, eax
    rep stosb
    pop rdi
    jmp window_proc_handled

window_proc_destroy:
    sub rsp, CALL_FRAME_BYTES_NO_PUSHES
    xor ecx, ecx
    call PostQuitMessage
    add rsp, CALL_FRAME_BYTES_NO_PUSHES

window_proc_handled:
    xor eax, eax
    ret
window_proc ENDP

game_tick PROC
    sub rsp, CALL_FRAME_BYTES_NO_PUSHES
    call paddle_left_tick
    call paddle_right_tick

    mov eax, match_mode
    assert_below_unsigned eax, MATCH_MODE_COUNT
    cmp eax, MATCH_MODE_SERVE_WAIT
    je game_tick_serve_wait
    cmp eax, MATCH_MODE_RALLY
    je game_tick_rally
    jmp game_tick_done

game_tick_serve_wait:
    xorps xmm0, xmm0
    movss ball_center_x_px, xmm0
    movss ball_center_y_px, xmm0
    inc match_serve_wait_ticks_elapsed
    cmp match_serve_wait_ticks_elapsed, SERVE_WAIT_TICKS
    jb game_tick_done

    rdtsc
    and eax, BALL_SERVE_SLOPE_COUNT - 1
    lea rcx, ball_serve_slopes
    movss xmm1, dword ptr [rcx + rax * 4]
    movss xmm0, ball_serve_speed_px_per_tick
    movss ball_speed_px_per_tick, xmm0
    mulss xmm1, xmm0
    movss ball_vel_y_px_per_tick, xmm1
    mov eax, match_serve_side
    assert_below_unsigned eax, SERVE_SIDE_COUNT
    cmp eax, SERVE_SIDE_RIGHT
    je game_tick_serve_launch
    xorps xmm0, xmmword ptr float_sign_mask_x4
game_tick_serve_launch:
    movss ball_vel_x_px_per_tick, xmm0
    mov match_mode, MATCH_MODE_RALLY
    jmp game_tick_done

game_tick_rally:
    call ball_tick

game_tick_done:
    add rsp, CALL_FRAME_BYTES_NO_PUSHES
    ret
game_tick ENDP

paddle_left_tick PROC
    sub rsp, CALL_FRAME_BYTES_NO_PUSHES
    lea rcx, key_is_down_by_virtual_key
    movzx eax, byte ptr [rcx + VK_S]
    movzx edx, byte ptr [rcx + VK_W]
    cmp paddle_right_mode, PADDLE_RIGHT_MODE_CPU
    jne paddle_left_tick_move
    or al, byte ptr [rcx + VK_DOWN]
    or dl, byte ptr [rcx + VK_UP]
paddle_left_tick_move:
    sub eax, edx
    cvtsi2ss xmm0, eax
    mulss xmm0, paddle_player_speed_px_per_tick
    addss xmm0, paddle_left_center_y_px
    call paddle_center_y_clamp
    movss paddle_left_center_y_px, xmm0
    add rsp, CALL_FRAME_BYTES_NO_PUSHES
    ret
paddle_left_tick ENDP

paddle_right_tick PROC
    sub rsp, CALL_FRAME_BYTES_NO_PUSHES
    mov eax, paddle_right_mode
    assert_below_unsigned eax, PADDLE_RIGHT_MODE_COUNT
    cmp eax, PADDLE_RIGHT_MODE_KEYBOARD
    je paddle_right_tick_keyboard

    xorps xmm0, xmm0
    cmp match_mode, MATCH_MODE_RALLY
    jne paddle_right_tick_cpu_step
    comiss xmm0, ball_vel_x_px_per_tick
    jae paddle_right_tick_cpu_step
    movss xmm0, ball_center_y_px
    subss xmm0, paddle_cpu_aim_offset_px
paddle_right_tick_cpu_step:
    subss xmm0, paddle_right_center_y_px
    movss xmm1, paddle_cpu_speed_px_per_tick
    minss xmm0, xmm1
    xorps xmm1, xmmword ptr float_sign_mask_x4
    maxss xmm0, xmm1
    jmp paddle_right_tick_move

paddle_right_tick_keyboard:
    lea rcx, key_is_down_by_virtual_key
    movzx eax, byte ptr [rcx + VK_DOWN]
    movzx edx, byte ptr [rcx + VK_UP]
    sub eax, edx
    cvtsi2ss xmm0, eax
    mulss xmm0, paddle_player_speed_px_per_tick

paddle_right_tick_move:
    addss xmm0, paddle_right_center_y_px
    call paddle_center_y_clamp
    movss paddle_right_center_y_px, xmm0
    add rsp, CALL_FRAME_BYTES_NO_PUSHES
    ret
paddle_right_tick ENDP

paddle_center_y_clamp PROC
    movss xmm1, field_half_height_px
    subss xmm1, paddle_half_height_px
    minss xmm0, xmm1
    xorps xmm1, xmmword ptr float_sign_mask_x4
    maxss xmm0, xmm1
    ret
paddle_center_y_clamp ENDP

ball_tick PROC
    sub rsp, CALL_FRAME_BYTES_NO_PUSHES
    movss xmm0, ball_center_x_px
    addss xmm0, ball_vel_x_px_per_tick
    movss ball_center_x_px, xmm0
    movss xmm0, ball_center_y_px
    addss xmm0, ball_vel_y_px_per_tick
    movss ball_center_y_px, xmm0

    movss xmm1, field_half_height_px
    subss xmm1, ball_half_size_px
    comiss xmm0, xmm1
    jbe ball_tick_top_wall
    movss ball_center_y_px, xmm1
    movss xmm2, ball_vel_y_px_per_tick
    orps xmm2, xmmword ptr float_sign_mask_x4
    movss ball_vel_y_px_per_tick, xmm2
    jmp ball_tick_paddles
ball_tick_top_wall:
    xorps xmm1, xmmword ptr float_sign_mask_x4
    comiss xmm0, xmm1
    jae ball_tick_paddles
    movss ball_center_y_px, xmm1
    movss xmm2, ball_vel_y_px_per_tick
    andps xmm2, xmmword ptr float_abs_mask_x4
    movss ball_vel_y_px_per_tick, xmm2

ball_tick_paddles:
    movss xmm0, paddle_right_center_x_px
    xorps xmm0, xmmword ptr float_sign_mask_x4
    movss xmm1, paddle_left_center_y_px
    call ball_paddle_bounce
    movss xmm0, paddle_right_center_x_px
    movss xmm1, paddle_right_center_y_px
    call ball_paddle_bounce

    movss xmm0, ball_center_x_px
    movss xmm1, field_half_width_px
    addss xmm1, ball_half_size_px
    comiss xmm0, xmm1
    ja ball_tick_left_scores
    xorps xmm1, xmmword ptr float_sign_mask_x4
    comiss xmm0, xmm1
    jb ball_tick_right_scores
    jmp ball_tick_done

ball_tick_left_scores:
    inc score_left
    mov eax, score_left
    mov match_serve_side, SERVE_SIDE_RIGHT
    jmp ball_tick_point_scored
ball_tick_right_scores:
    inc score_right
    mov eax, score_right
    mov match_serve_side, SERVE_SIDE_LEFT
ball_tick_point_scored:
    assert_below_unsigned eax, MATCH_WINNING_SCORE + 1
    mov match_serve_wait_ticks_elapsed, 0
    mov match_mode, MATCH_MODE_SERVE_WAIT
    cmp eax, MATCH_WINNING_SCORE
    jb ball_tick_done
    mov match_mode, MATCH_MODE_OVER

ball_tick_done:
    add rsp, CALL_FRAME_BYTES_NO_PUSHES
    ret
ball_tick ENDP

ball_paddle_bounce PROC
    movss xmm2, ball_vel_x_px_per_tick
    mulss xmm2, xmm0
    xorps xmm3, xmm3
    comiss xmm2, xmm3
    jbe ball_paddle_bounce_done

    movss xmm4, paddle_half_width_px
    addss xmm4, ball_half_size_px
    movss xmm2, ball_center_x_px
    subss xmm2, xmm0
    andps xmm2, xmmword ptr float_abs_mask_x4
    comiss xmm2, xmm4
    ja ball_paddle_bounce_done

    movss xmm5, paddle_half_height_px
    addss xmm5, ball_half_size_px
    movss xmm2, ball_center_y_px
    subss xmm2, xmm1
    movaps xmm3, xmm2
    andps xmm3, xmmword ptr float_abs_mask_x4
    comiss xmm3, xmm5
    ja ball_paddle_bounce_done

    divss xmm2, xmm5
    movss xmm3, ball_speed_px_per_tick
    mulss xmm3, ball_speed_gain_per_paddle_hit
    minss xmm3, ball_speed_max_px_per_tick
    movss ball_speed_px_per_tick, xmm3
    mulss xmm2, xmm3
    movss ball_vel_y_px_per_tick, xmm2

    movaps xmm2, xmm0
    andps xmm2, xmmword ptr float_sign_mask_x4
    xorps xmm2, xmmword ptr float_sign_mask_x4
    orps xmm3, xmm2
    movss ball_vel_x_px_per_tick, xmm3
    orps xmm4, xmm2
    addss xmm4, xmm0
    movss ball_center_x_px, xmm4

    rdtsc
    and eax, PADDLE_CPU_AIM_OFFSET_COUNT - 1
    lea rcx, paddle_cpu_aim_offsets_px
    movss xmm2, dword ptr [rcx + rax * 4]
    movss paddle_cpu_aim_offset_px, xmm2

ball_paddle_bounce_done:
    ret
ball_paddle_bounce ENDP

frame_render PROC
    push rbx
    push rdi
    sub rsp, CALL_FRAME_BYTES_NO_PUSHES
    frame_alignment_check 2, CALL_FRAME_BYTES_NO_PUSHES

    lea rdi, framebuffer_bgra
    mov ecx, SCREEN_WIDTH_PX * SCREEN_HEIGHT_PX
    mov eax, COLOR_BACKGROUND_BGRA
    rep stosd

    mov ebx, (CENTER_LINE_PERIOD_PX - CENTER_LINE_DASH_PX) / 2
frame_render_center_line_dash:
    mov ecx, (SCREEN_WIDTH_PX - CENTER_LINE_WIDTH_PX) / 2
    mov edx, ebx
    mov r8d, CENTER_LINE_WIDTH_PX
    mov r9d, CENTER_LINE_DASH_PX
    call framebuffer_rect_fill
    add ebx, CENTER_LINE_PERIOD_PX
    cmp ebx, SCREEN_HEIGHT_PX
    jb frame_render_center_line_dash

    mov ecx, score_left
    mov edx, SCREEN_WIDTH_PX / 2 - SCORE_CENTER_FROM_SCREEN_CENTER_PX
    call score_draw
    mov ecx, score_right
    mov edx, SCREEN_WIDTH_PX / 2 + SCORE_CENTER_FROM_SCREEN_CENTER_PX
    call score_draw

    movss xmm0, paddle_right_center_x_px
    xorps xmm0, xmmword ptr float_sign_mask_x4
    movss xmm1, paddle_left_center_y_px
    movss xmm2, paddle_half_width_px
    movss xmm3, paddle_half_height_px
    call framebuffer_rect_fill_field
    movss xmm0, paddle_right_center_x_px
    movss xmm1, paddle_right_center_y_px
    movss xmm2, paddle_half_width_px
    movss xmm3, paddle_half_height_px
    call framebuffer_rect_fill_field

    cmp match_mode, MATCH_MODE_OVER
    je frame_render_done
    movss xmm0, ball_center_x_px
    movss xmm1, ball_center_y_px
    movss xmm2, ball_half_size_px
    movaps xmm3, xmm2
    call framebuffer_rect_fill_field

frame_render_done:
    add rsp, CALL_FRAME_BYTES_NO_PUSHES
    pop rdi
    pop rbx
    ret
frame_render ENDP

score_draw PROC
    push rbx
    push rsi
    sub rsp, CALL_FRAME_BYTES_NO_PUSHES
    frame_alignment_check 2, CALL_FRAME_BYTES_NO_PUSHES
    assert_below_unsigned ecx, MATCH_WINNING_SCORE + 1

    mov esi, edx
    mov eax, ecx
    xor edx, edx
    mov ecx, SCORE_DECIMAL_BASE
    div ecx
    mov ebx, edx
    test eax, eax
    jz score_draw_one_digit
    mov ecx, eax
    lea edx, [rsi - SCORE_TWO_DIGITS_WIDTH_PX / 2]
    call score_digit_draw
    lea edx, [rsi - SCORE_TWO_DIGITS_WIDTH_PX / 2 + SCORE_DIGIT_ADVANCE_PX]
    jmp score_draw_ones_digit
score_draw_one_digit:
    lea edx, [rsi - SCORE_DIGIT_WIDTH_PX / 2]
score_draw_ones_digit:
    mov ecx, ebx
    call score_digit_draw

    add rsp, CALL_FRAME_BYTES_NO_PUSHES
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
    sub rsp, CALL_SHADOW_BYTES
    frame_alignment_check 5, CALL_SHADOW_BYTES
    assert_below_unsigned ecx, FONT_DIGIT_COUNT

    mov edi, edx
    lea r12, font_digit_rows_3x5
    imul eax, ecx, FONT_DIGIT_ROWS
    add r12, rax
    xor ebx, ebx
score_digit_draw_row:
    movzx r13d, byte ptr [r12 + rbx]
    xor esi, esi
score_digit_draw_cell:
    mov eax, FONT_DIGIT_COLUMNS - 1
    sub eax, esi
    bt r13d, eax
    jnc score_digit_draw_cell_next
    imul ecx, esi, SCORE_CELL_PX
    add ecx, edi
    imul edx, ebx, SCORE_CELL_PX
    add edx, SCORE_TOP_PX
    mov r8d, SCORE_CELL_PX
    mov r9d, SCORE_CELL_PX
    call framebuffer_rect_fill
score_digit_draw_cell_next:
    inc esi
    cmp esi, FONT_DIGIT_COLUMNS
    jb score_digit_draw_cell
    inc ebx
    cmp ebx, FONT_DIGIT_ROWS
    jb score_digit_draw_row

    add rsp, CALL_SHADOW_BYTES
    pop r13
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
score_digit_draw ENDP

framebuffer_rect_fill_field PROC
    addss xmm0, field_half_width_px
    addss xmm1, field_half_height_px
    movaps xmm4, xmm0
    subss xmm4, xmm2
    addss xmm0, xmm2
    movaps xmm5, xmm1
    subss xmm5, xmm3
    addss xmm1, xmm3
    cvtss2si ecx, xmm4
    cvtss2si r8d, xmm0
    sub r8d, ecx
    cvtss2si edx, xmm5
    cvtss2si r9d, xmm1
    sub r9d, edx
    jmp framebuffer_rect_fill
framebuffer_rect_fill_field ENDP

framebuffer_rect_fill PROC
    assert_above_zero_signed r8d
    assert_above_zero_signed r9d
    push rdi
    lea r10d, [rcx + r8]
    lea r11d, [rdx + r9]
    xor eax, eax
    test ecx, ecx
    cmovl ecx, eax
    test edx, edx
    cmovl edx, eax
    mov eax, SCREEN_WIDTH_PX
    cmp r10d, eax
    cmovg r10d, eax
    mov eax, SCREEN_HEIGHT_PX
    cmp r11d, eax
    cmovg r11d, eax
    sub r10d, ecx
    jle framebuffer_rect_fill_done
    cmp edx, r11d
    jge framebuffer_rect_fill_done

    mov r8d, ecx
    mov r9d, r10d
framebuffer_rect_fill_row:
    imul eax, edx, SCREEN_WIDTH_PX
    add eax, r8d
    lea rdi, framebuffer_bgra
    lea rdi, [rdi + rax * 4]
    mov ecx, r9d
    mov eax, COLOR_FOREGROUND_BGRA
    rep stosd
    inc edx
    cmp edx, r11d
    jl framebuffer_rect_fill_row

framebuffer_rect_fill_done:
    pop rdi
    ret
framebuffer_rect_fill ENDP

frame_present PROC
    sub rsp, FRAME_PRESENT_FRAME_BYTES
    frame_alignment_check 0, FRAME_PRESENT_FRAME_BYTES
    mov rcx, window_dc
    xor edx, edx
    xor r8d, r8d
    mov r9d, WINDOW_CLIENT_WIDTH_PX
    mov dword ptr [rsp + CALL_ARG5], WINDOW_CLIENT_HEIGHT_PX
    mov dword ptr [rsp + CALL_ARG6], 0
    mov dword ptr [rsp + CALL_ARG7], 0
    mov dword ptr [rsp + CALL_ARG8], SCREEN_WIDTH_PX
    mov dword ptr [rsp + CALL_ARG9], SCREEN_HEIGHT_PX
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

END
