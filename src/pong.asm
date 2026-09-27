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
EXTERN PlaySoundA:PROC
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
VK_RETURN                           equ 0Dh
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
SND_ASYNC                           equ 0001h
SND_NODEFAULT                       equ 0002h
SND_MEMORY                          equ 0004h
SOUND_PLAY_FLAGS                    equ SND_ASYNC OR SND_NODEFAULT OR SND_MEMORY
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
CALLEE_ARG5                         equ 40
CALLEE_ARG6                         equ 48
FRAME_4_ARGS_EVEN_PUSHES_BYTES      equ CALL_SHADOW_BYTES + 8
FRAME_4_ARGS_ODD_PUSHES_BYTES       equ CALL_SHADOW_BYTES
FRAME_6_ARGS_EVEN_PUSHES_BYTES      equ CALL_ARG6 + 16
FRAME_6_ARGS_ODD_PUSHES_BYTES       equ CALL_ARG6 + 8
MAIN_ENTRY_FRAME_BYTES              equ CALL_ARG12 + 16
FRAME_PRESENT_FRAME_BYTES           equ CALL_ARG13 + 8
TEXT_DRAW_FRAME_BYTES               equ CALL_ARG6 + 16
TEXT_DRAW_LOCAL_COLOR               equ CALL_ARG6
TEXT_DRAW_LOCAL_SCALE               equ CALL_ARG6 + 4
TEXT_DRAW_LOCAL_LINE_LEFT           equ CALL_ARG6 + 8
TEXT_DRAW_PUSHED_REGISTER_COUNT     equ 8
TEXT_DRAW_ARG5                      equ TEXT_DRAW_FRAME_BYTES + 8 * TEXT_DRAW_PUSHED_REGISTER_COUNT + CALLEE_ARG5

SCREEN_WIDTH_PX                     equ 320
SCREEN_HEIGHT_PX                    equ 240
SCREEN_PIXEL_COUNT                  equ SCREEN_WIDTH_PX * SCREEN_HEIGHT_PX
WINDOW_SCALE                        equ 3
WINDOW_CLIENT_WIDTH_PX              equ SCREEN_WIDTH_PX * WINDOW_SCALE
WINDOW_CLIENT_HEIGHT_PX             equ SCREEN_HEIGHT_PX * WINDOW_SCALE
WINDOW_STYLE                        equ WS_CAPTION OR WS_SYSMENU OR WS_MINIMIZEBOX OR WS_VISIBLE

SIM_TICKS_PER_SEC                   equ 120
SIM_TICKS_BEHIND_MAX                equ 8

COLOR_BACKGROUND_BGRA               equ 000A0A10h
COLOR_CENTER_LINE_BGRA              equ 00404050h
COLOR_WHITE_BGRA                    equ 00F0F0F0h
COLOR_TEXT_BRIGHT_BGRA              equ 00D0D0E0h
COLOR_TEXT_DIM_BGRA                 equ 00808090h
COLOR_CARD_BORDER_BGRA              equ 00383848h
COLOR_CARD_PANEL_BGRA               equ 00101018h
COLOR_CARD_PANEL_SELECTED_BGRA      equ 001A1A2Ah
COLOR_LEVEL_SHIFT                   equ 8
COLOR_LEVEL_FULL                    equ 1 SHL COLOR_LEVEL_SHIFT
CENTER_LINE_WIDTH_PX                equ 2
CENTER_LINE_DASH_PX                 equ 8
CENTER_LINE_PERIOD_PX               equ 16

FONT_DIGIT_COUNT                    equ 10
FONT_DIGIT_ROWS                     equ 5
FONT_DIGIT_COLUMNS                  equ 3
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
TEXT_SCALE_SMALL                    equ 1
TEXT_SCALE_LARGE                    equ 2
TEXT_SCALE_HUGE                     equ 3

SCORE_DECIMAL_BASE                  equ 10
SCORE_CELL_PX                       equ 4
SCORE_DIGIT_WIDTH_PX                equ FONT_DIGIT_COLUMNS * SCORE_CELL_PX
SCORE_DIGIT_ADVANCE_PX              equ SCORE_DIGIT_WIDTH_PX + SCORE_CELL_PX
SCORE_TWO_DIGITS_WIDTH_PX           equ SCORE_DIGIT_ADVANCE_PX + SCORE_DIGIT_WIDTH_PX
SCORE_TOP_PX                        equ 12
SCORE_CENTER_FROM_SCREEN_CENTER_PX  equ 40
SCORE_FLASH_TICKS                   equ 84
SCORE_FLASH_BLINK_BIT_MASK          equ 8

MATCH_WINNING_SCORE                 equ 11
SERVE_WAIT_TICKS                    equ 90
SERVE_BLINK_BIT_MASK                equ 16
POINT_SCORED_TICKS                  equ 84
OVER_CONFETTI_PERIOD_TICKS          equ 16
.ERRNZ OVER_CONFETTI_PERIOD_TICKS AND (OVER_CONFETTI_PERIOD_TICKS - 1)
OVER_TITLE_TOP_PX                   equ 92
OVER_PROMPT_TOP_PX                  equ 128

MATCH_MODE_SERVE_WAIT               equ 0
MATCH_MODE_RALLY                    equ 1
MATCH_MODE_POINT_SCORED             equ 2
MATCH_MODE_UPGRADE_CHOOSE           equ 3
MATCH_MODE_UPGRADE_TAKEN            equ 4
MATCH_MODE_OVER                     equ 5
MATCH_MODE_COUNT                    equ 6

SIDE_LEFT                           equ 0
SIDE_RIGHT                          equ 1
SIDE_COUNT                          equ 2
SIDE_FLIP                           equ SIDE_LEFT XOR SIDE_RIGHT

PADDLE_RIGHT_MODE_CPU               equ 0
PADDLE_RIGHT_MODE_KEYBOARD          equ 1
PADDLE_RIGHT_MODE_COUNT             equ 2
PADDLE_FLASH_TICKS                  equ 10

UPGRADE_KIND_LONG_PADDLE            equ 0
UPGRADE_KIND_QUICK_PADDLE           equ 1
UPGRADE_KIND_POWER_HIT              equ 2
UPGRADE_KIND_SHARP_ANGLE            equ 3
UPGRADE_KIND_SHIELD                 equ 4
UPGRADE_KIND_SHRINK_FOE             equ 5
UPGRADE_KIND_COUNT                  equ 6
UPGRADE_OFFER_COUNT                 equ 3
.ERRE UPGRADE_KIND_COUNT GE UPGRADE_OFFER_COUNT
UPGRADE_INPUT_DELAY_TICKS           equ 24
UPGRADE_CPU_CURSOR_MOVE_TICK        equ 50
UPGRADE_CPU_TAKE_TICK               equ 100
UPGRADE_TAKEN_TICKS                 equ 40
UPGRADE_TAKEN_BLINK_BIT_MASK        equ 4
UPGRADE_TITLE_TOP_PX                equ 40
UPGRADE_PROMPT_TOP_PX               equ 224
UPGRADE_CARD_LEFT_PX                equ 36
UPGRADE_CARD_WIDTH_PX               equ 248
UPGRADE_CARD_HEIGHT_PX              equ 46
UPGRADE_CARD_TOP_PX                 equ 56
UPGRADE_CARD_PITCH_PX               equ 54
UPGRADE_CARD_BORDER_PX              equ 2
UPGRADE_CARD_SELECTED_SHIFT_PX      equ 6
UPGRADE_CARD_TEXT_INSET_PX          equ 10
UPGRADE_CARD_NAME_TOP_INSET_PX      equ 9
UPGRADE_CARD_DESCRIPTION_TOP_INSET_PX equ 30
UPGRADE_CARD_PIP_SIZE_PX            equ 5
UPGRADE_CARD_PIP_PITCH_PX           equ 7
UPGRADE_CARD_PIP_RIGHT_INSET_PX     equ 14
UPGRADE_CARD_PIP_TOP_INSET_PX       equ 10
UPGRADE_CARD_PIPS_MAX               equ 10
UPGRADE_CARD_SLIDE_TICKS            equ 18
UPGRADE_CARD_SLIDE_STAGGER_TICKS    equ 5
.ERRE UPGRADE_CARD_LEFT_PX + UPGRADE_CARD_SLIDE_TICKS * UPGRADE_CARD_SLIDE_TICKS GE SCREEN_WIDTH_PX
UPGRADE_CARD_PULSE_PERIOD_TICKS     equ 32
UPGRADE_CARD_PULSE_LEVEL_MIN        equ 160
UPGRADE_CARD_PULSE_LEVEL_PER_TICK   equ 6
.ERRE UPGRADE_CARD_PULSE_LEVEL_MIN + UPGRADE_CARD_PULSE_LEVEL_PER_TICK * UPGRADE_CARD_PULSE_PERIOD_TICKS / 2 LE COLOR_LEVEL_FULL

HIT_STOP_PADDLE_TICKS               equ 3
HIT_STOP_SHIELD_TICKS               equ 8
BACKGROUND_FLASH_TICKS              equ 10
BACKGROUND_FLASH_LEVEL_PER_TICK     equ 7
SCREEN_SHAKE_PADDLE_HIT_TICKS       equ 10
SCREEN_SHAKE_POINT_TICKS            equ 36
SCREEN_SHAKE_SHIELD_TICKS           equ 24

PARTICLE_COUNT_MAX                  equ 256
.ERRNZ PARTICLE_COUNT_MAX AND (PARTICLE_COUNT_MAX - 1)
PARTICLE_LIFE_MIN_TICKS             equ 16
PARTICLE_LIFE_RANDOM_TICKS          equ 28
PARTICLE_LEVEL_PER_LIFE_TICK        equ 6
PARTICLE_PADDLE_HIT_COUNT           equ 12
PARTICLE_WALL_HIT_COUNT             equ 5
PARTICLE_SHIELD_COUNT               equ 24
PARTICLE_POINT_COUNT                equ 48
PARTICLE_CONFETTI_COUNT             equ 20

BALL_TRAIL_LENGTH                   equ 8
.ERRNZ BALL_TRAIL_LENGTH AND (BALL_TRAIL_LENGTH - 1)
BALL_TRAIL_LEVEL_PER_STEP           equ 18

SOUND_SAMPLE_RATE_HZ                equ 22050
SOUND_AMPLITUDE                     equ 34
SOUND_SILENCE_LEVEL                 equ 128
SOUND_PHASE_STEP_PER_HZ             equ 194783
.ERRE SOUND_PHASE_STEP_PER_HZ * SOUND_SAMPLE_RATE_HZ LE 0FFFFFFFFh
.ERRE (SOUND_PHASE_STEP_PER_HZ + 1) * SOUND_SAMPLE_RATE_HZ GT 0FFFFFFFFh

RANDOM_LCG_MULTIPLIER               equ 1664525
RANDOM_LCG_INCREMENT                equ 1013904223
RANDOM_UNIT_FLOAT_DROPPED_BITS      equ 8

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

assert_not_negative_signed MACRO value
    LOCAL assert_not_negative_signed_ok
    cmp value, 0
    jge assert_not_negative_signed_ok
    ud2
assert_not_negative_signed_ok:
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

match_mode_set MACRO new_mode
    mov match_mode, new_mode
    mov match_mode_ticks, 0
ENDM

counter_down_to_zero MACRO counter
    LOCAL counter_down_to_zero_done
    cmp counter, 0
    je counter_down_to_zero_done
    dec counter
counter_down_to_zero_done:
ENDM

player_address_load MACRO player_reg64, side_reg32
    imul r11d, side_reg32, SIZEOF PLAYER
    lea player_reg64, players
    add player_reg64, r11
ENDM

upgrade_level MACRO player_reg64, kind
    EXITM <dword ptr [player_reg64 + PLAYER.upgrade_level_by_kind + 4 * (kind)]>
ENDM

side_color_load MACRO color_reg32, side_reg64
    lea r11, side_color_bgra
    mov color_reg32, dword ptr [r11 + side_reg64 * 4]
ENDM

paddle_center_x_load MACRO xmm_reg, side_reg32
    LOCAL paddle_center_x_load_done
    movss xmm_reg, paddle_right_center_x_px
    cmp side_reg32, SIDE_RIGHT
    je paddle_center_x_load_done
    xorps xmm_reg, xmmword ptr float_sign_mask_x4
paddle_center_x_load_done:
ENDM

paddle_center_y_clamp MACRO xmm_reg, xmm_temp, player_reg64
    movss xmm_temp, field_half_height_px
    subss xmm_temp, (PLAYER PTR [player_reg64]).paddle_half_height_px
    minss xmm_reg, xmm_temp
    xorps xmm_temp, xmmword ptr float_sign_mask_x4
    maxss xmm_reg, xmm_temp
ENDM

random_next_to_eax MACRO
    imul eax, random_state, RANDOM_LCG_MULTIPLIER
    add eax, RANDOM_LCG_INCREMENT
    mov random_state, eax
ENDM

random_below_to_eax MACRO limit_reg32
    random_next_to_eax
    mul limit_reg32
    mov eax, edx
ENDM

random_unit_float_to MACRO xmm_reg
    random_next_to_eax
    shr eax, RANDOM_UNIT_FLOAT_DROPPED_BITS
    cvtsi2ss xmm_reg, eax
    mulss xmm_reg, random_unit_float_scale
ENDM

random_signed_unit_float_to MACRO xmm_reg
    random_unit_float_to xmm_reg
    addss xmm_reg, xmm_reg
    subss xmm_reg, float_one
ENDM

sound_define MACRO sound_name, duration_ms, start_hz, end_hz
    sound_name&_SAMPLE_COUNT equ SOUND_SAMPLE_RATE_HZ * duration_ms / 1000
    sound_name&_START_HZ equ start_hz
    sound_name&_END_HZ equ end_hz
    ALIGN 4
    sound_name WAVE_HEADER <>
    BYTE sound_name&_SAMPLE_COUNT DUP (?)
ENDM

sound_synthesize_call MACRO sound_name
    lea rcx, sound_name
    mov edx, sound_name&_SAMPLE_COUNT
    mov r8d, sound_name&_START_HZ
    mov r9d, sound_name&_END_HZ
    call sound_synthesize
ENDM

sound_play_call MACRO sound_name
    lea rcx, sound_name
    call sound_play
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

WAVE_HEADER STRUCT
    riff_tag                        BYTE "RIFF"
    riff_size_bytes                 DWORD ?
    wave_tag                        BYTE "WAVE"
    format_tag                      BYTE "fmt "
    format_size_bytes               DWORD 16
    format_pcm                      WORD 1
    channel_count                   WORD 1
    sample_rate_hz                  DWORD SOUND_SAMPLE_RATE_HZ
    byte_rate                       DWORD SOUND_SAMPLE_RATE_HZ
    block_align_bytes               WORD 1
    bits_per_sample                 WORD 8
    data_tag                        BYTE "data"
    data_size_bytes                 DWORD ?
WAVE_HEADER ENDS
.ERRNZ SIZEOF WAVE_HEADER - 44
WAVE_HEADER_RIFF_SIZE_WITHOUT_DATA  equ SIZEOF WAVE_HEADER - 8

PLAYER STRUCT
    paddle_center_y_px              REAL4 ?
    paddle_half_height_px           REAL4 ?
    paddle_half_height_shown_px     REAL4 ?
    paddle_speed_px_per_tick        REAL4 ?
    paddle_flash_ticks_left         DWORD ?
    score                           DWORD ?
    score_flash_ticks_left          DWORD ?
    upgrade_level_by_kind           DWORD UPGRADE_KIND_COUNT DUP (?)
PLAYER ENDS

PARTICLE STRUCT
    pos_x_px                        REAL4 ?
    pos_y_px                        REAL4 ?
    vel_x_px_per_tick               REAL4 ?
    vel_y_px_per_tick               REAL4 ?
    life_ticks_left                 DWORD ?
    color_bgra                      DWORD ?
PARTICLE ENDS

.const
ALIGN 16
float_sign_mask_x4                  DWORD 4 DUP (80000000h)
float_abs_mask_x4                   DWORD 4 DUP (7FFFFFFFh)
pixel_rgb_quarter_mask_x4           DWORD 4 DUP (003F3F3Fh)
float_one                           REAL4 1.0
random_unit_float_scale             REAL4 5.9604645e-8
field_half_width_px                 REAL4 160.0
field_half_height_px                REAL4 120.0
paddle_right_center_x_px            REAL4 142.0
paddle_half_width_px                REAL4 2.0
paddle_flash_half_width_extra_px    REAL4 1.0
paddle_half_height_base_px          REAL4 16.0
paddle_half_height_per_long_level_px REAL4 4.0
paddle_half_height_per_shrink_level_px REAL4 3.0
paddle_half_height_min_px           REAL4 6.0
paddle_half_height_max_px           REAL4 44.0
paddle_half_height_shown_ease_per_tick REAL4 0.2
paddle_speed_base_px_per_tick       REAL4 2.0
paddle_speed_per_quick_level_px_per_tick REAL4 0.5
paddle_speed_max_px_per_tick        REAL4 4.5
paddle_cpu_speed_factor             REAL4 0.7
paddle_cpu_aim_offset_fractions     REAL4 -0.7, -0.35, 0.35, 0.7
PADDLE_CPU_AIM_OFFSET_COUNT         equ LENGTHOF paddle_cpu_aim_offset_fractions
ball_half_size_px                   REAL4 2.0
ball_serve_speed_px_per_tick        REAL4 1.6
ball_speed_gain_per_paddle_hit      REAL4 1.06
ball_speed_add_per_power_level_px_per_tick REAL4 0.3
ball_speed_cap_base_px_per_tick     REAL4 3.5
ball_speed_cap_per_power_level_px_per_tick REAL4 0.5
ball_speed_cap_max_px_per_tick      REAL4 6.0
ball_bounce_slope_per_sharp_level   REAL4 0.4
ball_bounce_slope_max               REAL4 2.2
ball_serve_slopes                   REAL4 -0.6, -0.3, 0.3, 0.6
BALL_SERVE_SLOPE_COUNT              equ LENGTHOF ball_serve_slopes
ball_heat_levels_per_px_per_tick    REAL4 2.1
ball_trail_half_size_per_step_px    REAL4 0.2222
shield_line_center_x_px             REAL4 157.0
shield_line_half_width_px           REAL4 1.0
screen_shake_paddle_hit_px          REAL4 1.2
screen_shake_point_px               REAL4 4.0
screen_shake_shield_px              REAL4 3.0
particle_drag_per_tick              REAL4 0.93
particle_half_size_px               REAL4 1.0
particle_paddle_hit_speed_px_per_tick REAL4 1.3
particle_paddle_hit_spread_px_per_tick REAL4 1.0
particle_wall_hit_spread_px_per_tick REAL4 0.7
particle_shield_speed_px_per_tick   REAL4 1.6
particle_shield_spread_px_per_tick  REAL4 1.2
particle_point_speed_px_per_tick    REAL4 2.2
particle_point_spread_px_per_tick   REAL4 2.2
particle_confetti_spread_px_per_tick REAL4 1.5
confetti_spread_x_px                REAL4 130.0
confetti_spread_y_px                REAL4 90.0
side_color_bgra                     DWORD 0040C8FFh, 00FF7040h
.ERRNZ LENGTHOF side_color_bgra - SIDE_COUNT
ball_heat_color_bgra                DWORD 00F0F0F0h, 00FFE070h, 00FFA040h, 00FF4838h
BALL_HEAT_COLOR_COUNT               equ LENGTHOF ball_heat_color_bgra

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
                                    BYTE 00000b, 00100b, 10101b, 01110b, 10101b, 00100b, 00000b
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

text_upgrade_long_paddle_name       BYTE "LONG PADDLE", 0
text_upgrade_long_paddle_description BYTE "YOUR PADDLE GETS LONGER", 0
text_upgrade_quick_paddle_name      BYTE "QUICK PADDLE", 0
text_upgrade_quick_paddle_description BYTE "YOUR PADDLE MOVES FASTER", 0
text_upgrade_power_hit_name         BYTE "POWER HIT", 0
text_upgrade_power_hit_description  BYTE "YOUR HITS MAKE THE BALL FASTER", 0
text_upgrade_sharp_angle_name       BYTE "SHARP ANGLE", 0
text_upgrade_sharp_angle_description BYTE "YOUR HITS GO AT STEEPER ANGLES", 0
text_upgrade_shield_name            BYTE "SHIELD", 0
text_upgrade_shield_description     BYTE "A WALL BEHIND YOU STOPS ONE GOAL", 0
text_upgrade_shrink_foe_name        BYTE "SHRINK FOE", 0
text_upgrade_shrink_foe_description BYTE "THE OTHER PADDLE GETS SHORTER", 0
text_upgrade_title_you              BYTE "YOU LOST THE POINT. PICK AN UPGRADE", 0
text_upgrade_title_cpu              BYTE "CPU LOST THE POINT. IT PICKS AN UPGRADE", 0
text_upgrade_title_left             BYTE "LEFT LOST THE POINT. PICK AN UPGRADE", 0
text_upgrade_title_right            BYTE "RIGHT LOST THE POINT. PICK AN UPGRADE", 0
text_upgrade_prompt                 BYTE "YOUR PADDLE KEYS: MOVE    SPACE OR ENTER: TAKE", 0
text_over_title_you                 BYTE "YOU WIN!", 0
text_over_title_cpu                 BYTE "CPU WINS!", 0
text_over_title_left                BYTE "LEFT WINS!", 0
text_over_title_right               BYTE "RIGHT WINS!", 0
text_over_prompt                    BYTE "SPACE OR ENTER: NEW MATCH", 0

ALIGN 8
upgrade_name_texts                  QWORD text_upgrade_long_paddle_name, text_upgrade_quick_paddle_name, text_upgrade_power_hit_name, text_upgrade_sharp_angle_name, text_upgrade_shield_name, text_upgrade_shrink_foe_name
.ERRNZ LENGTHOF upgrade_name_texts - UPGRADE_KIND_COUNT
upgrade_description_texts           QWORD text_upgrade_long_paddle_description, text_upgrade_quick_paddle_description, text_upgrade_power_hit_description, text_upgrade_sharp_angle_description, text_upgrade_shield_description, text_upgrade_shrink_foe_description
.ERRNZ LENGTHOF upgrade_description_texts - UPGRADE_KIND_COUNT
upgrade_title_texts                 QWORD text_upgrade_title_you, text_upgrade_title_cpu, text_upgrade_title_left, text_upgrade_title_right
.ERRNZ LENGTHOF upgrade_title_texts - PADDLE_RIGHT_MODE_COUNT * SIDE_COUNT
over_title_texts                    QWORD text_over_title_you, text_over_title_cpu, text_over_title_left, text_over_title_right
.ERRNZ LENGTHOF over_title_texts - PADDLE_RIGHT_MODE_COUNT * SIDE_COUNT

.data
window_class_name                   BYTE "pong", 0
window_title                        BYTE "Pong    W S or Up Down: move    Tab: 2 players    Esc: quit", 0
window_class                        WNDCLASSEXA <SIZEOF WNDCLASSEXA, CS_OWNDC>
window_outer_rect                   RECT <0, 0, WINDOW_CLIENT_WIDTH_PX, WINDOW_CLIENT_HEIGHT_PX>
framebuffer_bitmap_info             BITMAPINFOHEADER <SIZEOF BITMAPINFOHEADER, SCREEN_WIDTH_PX, -SCREEN_HEIGHT_PX, 1, 32, BI_RGB>
window_message                      MSG <>
sound_define sound_paddle_hit, 50, 440, 620
sound_define sound_wall_hit, 30, 250, 250
sound_define sound_point_scored, 420, 720, 110
sound_define sound_shield_block, 110, 180, 900
sound_define sound_menu_move, 25, 880, 880
sound_define sound_menu_take, 200, 480, 1100

.data?
ALIGN 16
framebuffer_bgra                    DWORD SCREEN_PIXEL_COUNT DUP (?)
window_dc                           QWORD ?
qpc_counts_per_sec                  QWORD ?
qpc_counts_per_tick                 QWORD ?
qpc_frame_last                      QWORD ?
qpc_frame_now                       QWORD ?
qpc_sim_behind_counts               QWORD ?
players                             PLAYER SIDE_COUNT DUP (<>)
particles                           PARTICLE PARTICLE_COUNT_MAX DUP (<>)
match_mode                          DWORD ?
match_mode_ticks                    DWORD ?
match_point_loser_side              DWORD ?
paddle_right_mode                   DWORD ?
paddle_cpu_aim_offset_fraction      REAL4 ?
ball_center_x_px                    REAL4 ?
ball_center_y_px                    REAL4 ?
ball_vel_x_px_per_tick              REAL4 ?
ball_vel_y_px_per_tick              REAL4 ?
ball_speed_px_per_tick              REAL4 ?
ball_trail_x_px                     REAL4 BALL_TRAIL_LENGTH DUP (?)
ball_trail_y_px                     REAL4 BALL_TRAIL_LENGTH DUP (?)
ball_trail_next_index               DWORD ?
ball_trail_count                    DWORD ?
upgrade_offer_kinds                 DWORD UPGRADE_OFFER_COUNT DUP (?)
upgrade_offer_cursor                DWORD ?
hit_stop_ticks_left                 DWORD ?
screen_shake_strength_px            REAL4 ?
screen_shake_ticks_left             DWORD ?
screen_shake_duration_ticks         DWORD ?
screen_shake_offset_x_px            DWORD ?
screen_shake_offset_y_px            DWORD ?
background_flash_ticks_left         DWORD ?
particle_next_index                 DWORD ?
random_state                        DWORD ?
key_is_down_by_virtual_key          BYTE VIRTUAL_KEY_COUNT DUP (?)
key_was_pressed_by_virtual_key      BYTE VIRTUAL_KEY_COUNT DUP (?)

.code

main_entry PROC
    sub rsp, MAIN_ENTRY_FRAME_BYTES
    frame_alignment_check 0, MAIN_ENTRY_FRAME_BYTES

    rdtsc
    mov random_state, eax
    sound_synthesize_call sound_paddle_hit
    sound_synthesize_call sound_wall_hit
    sound_synthesize_call sound_point_scored
    sound_synthesize_call sound_shield_block
    sound_synthesize_call sound_menu_move
    sound_synthesize_call sound_menu_take

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
    lea rax, key_was_pressed_by_virtual_key
    mov byte ptr [rax + r8], 1
    cmp r8d, VK_ESCAPE
    jne window_proc_handled
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 0, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    call DestroyWindow
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
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
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    xor ecx, ecx
    call PostQuitMessage
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES

window_proc_handled:
    xor eax, eax
    ret
window_proc ENDP

game_tick PROC
    push rbx
    push rdi
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 2, FRAME_4_ARGS_EVEN_PUSHES_BYTES

    lea rbx, key_was_pressed_by_virtual_key
    cmp byte ptr [rbx + VK_TAB], 0
    je game_tick_effects
    assert_below_unsigned paddle_right_mode, PADDLE_RIGHT_MODE_COUNT
    xor paddle_right_mode, PADDLE_RIGHT_MODE_CPU XOR PADDLE_RIGHT_MODE_KEYBOARD

game_tick_effects:
    call players_stats_update
    call effects_tick
    cmp hit_stop_ticks_left, 0
    je game_tick_mode
    dec hit_stop_ticks_left
    jmp game_tick_done

game_tick_mode:
    inc match_mode_ticks
    mov eax, match_mode
    assert_below_unsigned eax, MATCH_MODE_COUNT
    cmp eax, MATCH_MODE_SERVE_WAIT
    je game_tick_serve_wait
    cmp eax, MATCH_MODE_RALLY
    je game_tick_rally
    cmp eax, MATCH_MODE_POINT_SCORED
    je game_tick_point_scored
    cmp eax, MATCH_MODE_UPGRADE_CHOOSE
    je game_tick_upgrade_choose
    cmp eax, MATCH_MODE_UPGRADE_TAKEN
    je game_tick_upgrade_taken
    jmp game_tick_over

game_tick_serve_wait:
    call paddles_tick
    xorps xmm0, xmm0
    movss ball_center_x_px, xmm0
    movss ball_center_y_px, xmm0
    movss xmm0, ball_serve_speed_px_per_tick
    movss ball_speed_px_per_tick, xmm0
    cmp match_mode_ticks, SERVE_WAIT_TICKS
    jb game_tick_done
    call ball_serve
    jmp game_tick_done

game_tick_rally:
    call paddles_tick
    call ball_tick
    jmp game_tick_done

game_tick_point_scored:
    call paddles_tick
    cmp match_mode_ticks, POINT_SCORED_TICKS
    jb game_tick_done
    mov ecx, match_point_loser_side
    xor ecx, SIDE_FLIP
    player_address_load rax, ecx
    cmp (PLAYER PTR [rax]).score, MATCH_WINNING_SCORE
    jb game_tick_point_scored_offer
    match_mode_set MATCH_MODE_OVER
    jmp game_tick_done
game_tick_point_scored_offer:
    call upgrade_offer_roll
    match_mode_set MATCH_MODE_UPGRADE_CHOOSE
    jmp game_tick_done

game_tick_upgrade_choose:
    call upgrade_choose_tick
    jmp game_tick_done

game_tick_upgrade_taken:
    cmp match_mode_ticks, UPGRADE_TAKEN_TICKS
    jb game_tick_done
    match_mode_set MATCH_MODE_SERVE_WAIT
    jmp game_tick_done

game_tick_over:
    call paddles_tick
    call over_tick

game_tick_done:
    lea rdi, key_was_pressed_by_virtual_key
    mov ecx, VIRTUAL_KEY_COUNT
    xor eax, eax
    rep stosb
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    pop rdi
    pop rbx
    ret
game_tick ENDP

players_stats_update PROC
    xor r8d, r8d
players_stats_update_side:
    mov r9d, r8d
    xor r9d, SIDE_FLIP
    player_address_load rcx, r8d
    player_address_load rdx, r9d
    cvtsi2ss xmm0, upgrade_level(rcx, UPGRADE_KIND_LONG_PADDLE)
    mulss xmm0, paddle_half_height_per_long_level_px
    addss xmm0, paddle_half_height_base_px
    cvtsi2ss xmm1, upgrade_level(rdx, UPGRADE_KIND_SHRINK_FOE)
    mulss xmm1, paddle_half_height_per_shrink_level_px
    subss xmm0, xmm1
    maxss xmm0, paddle_half_height_min_px
    minss xmm0, paddle_half_height_max_px
    movss (PLAYER PTR [rcx]).paddle_half_height_px, xmm0
    cvtsi2ss xmm0, upgrade_level(rcx, UPGRADE_KIND_QUICK_PADDLE)
    mulss xmm0, paddle_speed_per_quick_level_px_per_tick
    addss xmm0, paddle_speed_base_px_per_tick
    minss xmm0, paddle_speed_max_px_per_tick
    movss (PLAYER PTR [rcx]).paddle_speed_px_per_tick, xmm0
    inc r8d
    cmp r8d, SIDE_COUNT
    jb players_stats_update_side
    ret
players_stats_update ENDP

effects_tick PROC
    mov eax, screen_shake_ticks_left
    test eax, eax
    jz effects_tick_shake_still
    cvtsi2ss xmm1, eax
    cvtsi2ss xmm2, screen_shake_duration_ticks
    divss xmm1, xmm2
    mulss xmm1, screen_shake_strength_px
    random_signed_unit_float_to xmm0
    mulss xmm0, xmm1
    cvtss2si eax, xmm0
    mov screen_shake_offset_x_px, eax
    random_signed_unit_float_to xmm0
    mulss xmm0, xmm1
    cvtss2si eax, xmm0
    mov screen_shake_offset_y_px, eax
    dec screen_shake_ticks_left
    jmp effects_tick_particles
effects_tick_shake_still:
    mov screen_shake_offset_x_px, 0
    mov screen_shake_offset_y_px, 0

effects_tick_particles:
    lea rcx, particles
    mov edx, PARTICLE_COUNT_MAX
    movss xmm2, particle_drag_per_tick
effects_tick_particle:
    cmp (PARTICLE PTR [rcx]).life_ticks_left, 0
    je effects_tick_particle_next
    dec (PARTICLE PTR [rcx]).life_ticks_left
    movss xmm0, (PARTICLE PTR [rcx]).vel_x_px_per_tick
    mulss xmm0, xmm2
    movss (PARTICLE PTR [rcx]).vel_x_px_per_tick, xmm0
    addss xmm0, (PARTICLE PTR [rcx]).pos_x_px
    movss (PARTICLE PTR [rcx]).pos_x_px, xmm0
    movss xmm0, (PARTICLE PTR [rcx]).vel_y_px_per_tick
    mulss xmm0, xmm2
    movss (PARTICLE PTR [rcx]).vel_y_px_per_tick, xmm0
    addss xmm0, (PARTICLE PTR [rcx]).pos_y_px
    movss (PARTICLE PTR [rcx]).pos_y_px, xmm0
effects_tick_particle_next:
    add rcx, SIZEOF PARTICLE
    dec edx
    jnz effects_tick_particle

    lea rcx, players
    mov edx, SIDE_COUNT
    movss xmm2, paddle_half_height_shown_ease_per_tick
effects_tick_player:
    counter_down_to_zero <(PLAYER PTR [rcx]).paddle_flash_ticks_left>
    counter_down_to_zero <(PLAYER PTR [rcx]).score_flash_ticks_left>
    movss xmm0, (PLAYER PTR [rcx]).paddle_half_height_px
    movss xmm1, (PLAYER PTR [rcx]).paddle_half_height_shown_px
    subss xmm0, xmm1
    mulss xmm0, xmm2
    addss xmm0, xmm1
    movss (PLAYER PTR [rcx]).paddle_half_height_shown_px, xmm0
    add rcx, SIZEOF PLAYER
    dec edx
    jnz effects_tick_player

    counter_down_to_zero background_flash_ticks_left
    ret
effects_tick ENDP

paddles_tick PROC
    lea rcx, key_is_down_by_virtual_key
    lea r8, players[SIZEOF PLAYER * SIDE_LEFT]
    movzx eax, byte ptr [rcx + VK_S]
    movzx edx, byte ptr [rcx + VK_W]
    cmp paddle_right_mode, PADDLE_RIGHT_MODE_CPU
    jne paddles_tick_left_move
    or al, byte ptr [rcx + VK_DOWN]
    or dl, byte ptr [rcx + VK_UP]
paddles_tick_left_move:
    sub eax, edx
    cvtsi2ss xmm0, eax
    mulss xmm0, (PLAYER PTR [r8]).paddle_speed_px_per_tick
    addss xmm0, (PLAYER PTR [r8]).paddle_center_y_px
    paddle_center_y_clamp xmm0, xmm1, r8
    movss (PLAYER PTR [r8]).paddle_center_y_px, xmm0

    lea r8, players[SIZEOF PLAYER * SIDE_RIGHT]
    mov eax, paddle_right_mode
    assert_below_unsigned eax, PADDLE_RIGHT_MODE_COUNT
    cmp eax, PADDLE_RIGHT_MODE_KEYBOARD
    je paddles_tick_right_keyboard

    xorps xmm0, xmm0
    cmp match_mode, MATCH_MODE_RALLY
    jne paddles_tick_right_cpu_step
    comiss xmm0, ball_vel_x_px_per_tick
    jae paddles_tick_right_cpu_step
    movss xmm1, paddle_cpu_aim_offset_fraction
    mulss xmm1, (PLAYER PTR [r8]).paddle_half_height_px
    movss xmm0, ball_center_y_px
    subss xmm0, xmm1
paddles_tick_right_cpu_step:
    subss xmm0, (PLAYER PTR [r8]).paddle_center_y_px
    movss xmm1, (PLAYER PTR [r8]).paddle_speed_px_per_tick
    mulss xmm1, paddle_cpu_speed_factor
    minss xmm0, xmm1
    xorps xmm1, xmmword ptr float_sign_mask_x4
    maxss xmm0, xmm1
    jmp paddles_tick_right_move

paddles_tick_right_keyboard:
    movzx eax, byte ptr [rcx + VK_DOWN]
    movzx edx, byte ptr [rcx + VK_UP]
    sub eax, edx
    cvtsi2ss xmm0, eax
    mulss xmm0, (PLAYER PTR [r8]).paddle_speed_px_per_tick

paddles_tick_right_move:
    addss xmm0, (PLAYER PTR [r8]).paddle_center_y_px
    paddle_center_y_clamp xmm0, xmm1, r8
    movss (PLAYER PTR [r8]).paddle_center_y_px, xmm0
    ret
paddles_tick ENDP

ball_serve PROC
    mov ecx, BALL_SERVE_SLOPE_COUNT
    random_below_to_eax ecx
    lea rcx, ball_serve_slopes
    movss xmm1, dword ptr [rcx + rax * 4]
    movss xmm0, ball_serve_speed_px_per_tick
    movss ball_speed_px_per_tick, xmm0
    mulss xmm1, xmm0
    movss ball_vel_y_px_per_tick, xmm1
    mov eax, match_point_loser_side
    assert_below_unsigned eax, SIDE_COUNT
    cmp eax, SIDE_RIGHT
    je ball_serve_launch
    xorps xmm0, xmmword ptr float_sign_mask_x4
ball_serve_launch:
    movss ball_vel_x_px_per_tick, xmm0
    mov ball_trail_count, 0
    match_mode_set MATCH_MODE_RALLY
    ret
ball_serve ENDP

ball_tick PROC
    push rbx
    push rsi
    sub rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 2, FRAME_6_ARGS_EVEN_PUSHES_BYTES

    movss xmm0, ball_center_x_px
    addss xmm0, ball_vel_x_px_per_tick
    movss ball_center_x_px, xmm0
    movss xmm1, ball_center_y_px
    addss xmm1, ball_vel_y_px_per_tick
    movss ball_center_y_px, xmm1

    mov eax, ball_trail_next_index
    lea rcx, ball_trail_x_px
    movss dword ptr [rcx + rax * 4], xmm0
    lea rcx, ball_trail_y_px
    movss dword ptr [rcx + rax * 4], xmm1
    inc eax
    and eax, BALL_TRAIL_LENGTH - 1
    mov ball_trail_next_index, eax
    cmp ball_trail_count, BALL_TRAIL_LENGTH
    jae ball_tick_walls
    inc ball_trail_count

ball_tick_walls:
    movss xmm2, field_half_height_px
    subss xmm2, ball_half_size_px
    movaps xmm3, xmm1
    andps xmm3, xmmword ptr float_abs_mask_x4
    comiss xmm3, xmm2
    jbe ball_tick_paddles
    movaps xmm3, xmm1
    andps xmm3, xmmword ptr float_sign_mask_x4
    orps xmm2, xmm3
    movss ball_center_y_px, xmm2
    movss xmm4, ball_vel_y_px_per_tick
    andps xmm4, xmmword ptr float_abs_mask_x4
    xorps xmm3, xmmword ptr float_sign_mask_x4
    orps xmm4, xmm3
    movss ball_vel_y_px_per_tick, xmm4
    mov dword ptr [rsp + CALL_ARG5], PARTICLE_WALL_HIT_COUNT
    mov dword ptr [rsp + CALL_ARG6], COLOR_WHITE_BGRA
    movss xmm0, ball_center_x_px
    movss xmm1, ball_center_y_px
    xorps xmm2, xmm2
    movss xmm3, particle_wall_hit_spread_px_per_tick
    call particles_spawn_burst
    sound_play_call sound_wall_hit

ball_tick_paddles:
    mov ecx, SIDE_LEFT
    call ball_paddle_bounce
    mov ecx, SIDE_RIGHT
    call ball_paddle_bounce

    mov ebx, SIDE_LEFT
    xorps xmm0, xmm0
    comiss xmm0, ball_vel_x_px_per_tick
    ja ball_tick_shield_side_known
    mov ebx, SIDE_RIGHT
ball_tick_shield_side_known:
    player_address_load rsi, ebx
    cmp upgrade_level(rsi, UPGRADE_KIND_SHIELD), 0
    je ball_tick_goals
    movss xmm1, shield_line_center_x_px
    subss xmm1, shield_line_half_width_px
    subss xmm1, ball_half_size_px
    movss xmm0, ball_center_x_px
    andps xmm0, xmmword ptr float_abs_mask_x4
    comiss xmm0, xmm1
    jb ball_tick_goals
    dec upgrade_level(rsi, UPGRADE_KIND_SHIELD)
    movss xmm0, ball_center_x_px
    andps xmm0, xmmword ptr float_sign_mask_x4
    orps xmm1, xmm0
    movss ball_center_x_px, xmm1
    movss xmm0, ball_vel_x_px_per_tick
    xorps xmm0, xmmword ptr float_sign_mask_x4
    movss ball_vel_x_px_per_tick, xmm0
    mov hit_stop_ticks_left, HIT_STOP_SHIELD_TICKS
    movss xmm0, screen_shake_shield_px
    mov ecx, SCREEN_SHAKE_SHIELD_TICKS
    call screen_shake_start
    side_color_load eax, rbx
    mov dword ptr [rsp + CALL_ARG6], eax
    mov dword ptr [rsp + CALL_ARG5], PARTICLE_SHIELD_COUNT
    movss xmm2, particle_shield_speed_px_per_tick
    movss xmm0, ball_vel_x_px_per_tick
    andps xmm0, xmmword ptr float_sign_mask_x4
    orps xmm2, xmm0
    movss xmm0, ball_center_x_px
    movss xmm1, ball_center_y_px
    movss xmm3, particle_shield_spread_px_per_tick
    call particles_spawn_burst
    sound_play_call sound_shield_block
    jmp ball_tick_done

ball_tick_goals:
    movss xmm0, ball_center_x_px
    movss xmm1, field_half_width_px
    addss xmm1, ball_half_size_px
    comiss xmm0, xmm1
    ja ball_tick_right_lost
    xorps xmm1, xmmword ptr float_sign_mask_x4
    comiss xmm0, xmm1
    jae ball_tick_done
    mov ecx, SIDE_LEFT
    call point_score
    jmp ball_tick_done
ball_tick_right_lost:
    mov ecx, SIDE_RIGHT
    call point_score

ball_tick_done:
    add rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    pop rsi
    pop rbx
    ret
ball_tick ENDP

ball_paddle_bounce PROC
    push rbx
    push rsi
    sub rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 2, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    mov ebx, ecx
    assert_below_unsigned ebx, SIDE_COUNT
    player_address_load rsi, ebx
    paddle_center_x_load xmm0, ebx

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

    movss xmm5, (PLAYER PTR [rsi]).paddle_half_height_px
    addss xmm5, ball_half_size_px
    movss xmm2, ball_center_y_px
    subss xmm2, (PLAYER PTR [rsi]).paddle_center_y_px
    movaps xmm3, xmm2
    andps xmm3, xmmword ptr float_abs_mask_x4
    comiss xmm3, xmm5
    ja ball_paddle_bounce_done

    divss xmm2, xmm5
    cvtsi2ss xmm3, upgrade_level(rsi, UPGRADE_KIND_SHARP_ANGLE)
    mulss xmm3, ball_bounce_slope_per_sharp_level
    addss xmm3, float_one
    minss xmm3, ball_bounce_slope_max
    mulss xmm2, xmm3

    cvtsi2ss xmm1, upgrade_level(rsi, UPGRADE_KIND_POWER_HIT)
    movss xmm3, ball_speed_px_per_tick
    mulss xmm3, ball_speed_gain_per_paddle_hit
    movaps xmm5, xmm1
    mulss xmm5, ball_speed_add_per_power_level_px_per_tick
    addss xmm3, xmm5
    mulss xmm1, ball_speed_cap_per_power_level_px_per_tick
    addss xmm1, ball_speed_cap_base_px_per_tick
    minss xmm1, ball_speed_cap_max_px_per_tick
    minss xmm3, xmm1
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

    mov ecx, PADDLE_CPU_AIM_OFFSET_COUNT
    random_below_to_eax ecx
    lea rcx, paddle_cpu_aim_offset_fractions
    movss xmm0, dword ptr [rcx + rax * 4]
    movss paddle_cpu_aim_offset_fraction, xmm0

    mov (PLAYER PTR [rsi]).paddle_flash_ticks_left, PADDLE_FLASH_TICKS
    mov hit_stop_ticks_left, HIT_STOP_PADDLE_TICKS
    movss xmm0, screen_shake_paddle_hit_px
    mov ecx, SCREEN_SHAKE_PADDLE_HIT_TICKS
    call screen_shake_start

    side_color_load eax, rbx
    mov dword ptr [rsp + CALL_ARG6], eax
    mov dword ptr [rsp + CALL_ARG5], PARTICLE_PADDLE_HIT_COUNT
    movss xmm2, particle_paddle_hit_speed_px_per_tick
    movss xmm0, ball_vel_x_px_per_tick
    andps xmm0, xmmword ptr float_sign_mask_x4
    orps xmm2, xmm0
    movss xmm0, ball_center_x_px
    movss xmm1, ball_center_y_px
    movss xmm3, particle_paddle_hit_spread_px_per_tick
    call particles_spawn_burst
    sound_play_call sound_paddle_hit

ball_paddle_bounce_done:
    add rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    pop rsi
    pop rbx
    ret
ball_paddle_bounce ENDP

point_score PROC
    push rbx
    push rsi
    sub rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 2, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    mov ebx, ecx
    assert_below_unsigned ebx, SIDE_COUNT
    mov match_point_loser_side, ebx
    xor ecx, SIDE_FLIP
    player_address_load rsi, ecx
    inc (PLAYER PTR [rsi]).score
    mov eax, (PLAYER PTR [rsi]).score
    assert_below_unsigned eax, MATCH_WINNING_SCORE + 1
    mov (PLAYER PTR [rsi]).score_flash_ticks_left, SCORE_FLASH_TICKS
    mov background_flash_ticks_left, BACKGROUND_FLASH_TICKS
    mov ball_trail_count, 0
    match_mode_set MATCH_MODE_POINT_SCORED

    movss xmm0, screen_shake_point_px
    mov ecx, SCREEN_SHAKE_POINT_TICKS
    call screen_shake_start

    mov eax, ebx
    xor eax, SIDE_FLIP
    side_color_load eax, rax
    mov dword ptr [rsp + CALL_ARG6], eax
    mov dword ptr [rsp + CALL_ARG5], PARTICLE_POINT_COUNT
    movss xmm2, particle_point_speed_px_per_tick
    movss xmm0, ball_center_x_px
    andps xmm0, xmmword ptr float_sign_mask_x4
    xorps xmm0, xmmword ptr float_sign_mask_x4
    orps xmm2, xmm0
    movss xmm0, ball_center_x_px
    movss xmm1, ball_center_y_px
    movss xmm3, particle_point_spread_px_per_tick
    call particles_spawn_burst
    sound_play_call sound_point_scored

    add rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    pop rsi
    pop rbx
    ret
point_score ENDP

upgrade_offer_roll PROC
    .ERRNZ UPGRADE_OFFER_COUNT - 3
    mov ecx, UPGRADE_KIND_COUNT
    random_below_to_eax ecx
    mov r8d, eax
upgrade_offer_roll_second:
    random_below_to_eax ecx
    cmp eax, r8d
    je upgrade_offer_roll_second
    mov r9d, eax
upgrade_offer_roll_third:
    random_below_to_eax ecx
    cmp eax, r8d
    je upgrade_offer_roll_third
    cmp eax, r9d
    je upgrade_offer_roll_third
    lea rcx, upgrade_offer_kinds
    mov dword ptr [rcx], r8d
    mov dword ptr [rcx + 4], r9d
    mov dword ptr [rcx + 8], eax
    mov upgrade_offer_cursor, 0
    ret
upgrade_offer_roll ENDP

upgrade_choose_tick PROC
    push rbx
    sub rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 1, FRAME_4_ARGS_ODD_PUSHES_BYTES
    cmp match_mode_ticks, UPGRADE_INPUT_DELAY_TICKS
    jb upgrade_choose_tick_done
    mov eax, match_point_loser_side
    assert_below_unsigned eax, SIDE_COUNT
    cmp eax, SIDE_RIGHT
    jne upgrade_choose_tick_human
    cmp paddle_right_mode, PADDLE_RIGHT_MODE_CPU
    je upgrade_choose_tick_cpu

upgrade_choose_tick_human:
    lea rbx, key_was_pressed_by_virtual_key
    cmp eax, SIDE_RIGHT
    je upgrade_choose_tick_right_keys
    movzx ecx, byte ptr [rbx + VK_W]
    movzx edx, byte ptr [rbx + VK_S]
    cmp paddle_right_mode, PADDLE_RIGHT_MODE_CPU
    jne upgrade_choose_tick_keys_read
    or cl, byte ptr [rbx + VK_UP]
    or dl, byte ptr [rbx + VK_DOWN]
    jmp upgrade_choose_tick_keys_read
upgrade_choose_tick_right_keys:
    movzx ecx, byte ptr [rbx + VK_UP]
    movzx edx, byte ptr [rbx + VK_DOWN]
upgrade_choose_tick_keys_read:
    mov eax, upgrade_offer_cursor
    sub eax, ecx
    add eax, edx
    jns upgrade_choose_tick_cursor_not_negative
    add eax, UPGRADE_OFFER_COUNT
upgrade_choose_tick_cursor_not_negative:
    cmp eax, UPGRADE_OFFER_COUNT
    jb upgrade_choose_tick_cursor_wrapped
    sub eax, UPGRADE_OFFER_COUNT
upgrade_choose_tick_cursor_wrapped:
    cmp eax, upgrade_offer_cursor
    je upgrade_choose_tick_take_check
    mov upgrade_offer_cursor, eax
    sound_play_call sound_menu_move
upgrade_choose_tick_take_check:
    movzx eax, byte ptr [rbx + VK_SPACE]
    or al, byte ptr [rbx + VK_RETURN]
    jz upgrade_choose_tick_done
    call upgrade_take
    jmp upgrade_choose_tick_done

upgrade_choose_tick_cpu:
    cmp match_mode_ticks, UPGRADE_CPU_CURSOR_MOVE_TICK
    jne upgrade_choose_tick_cpu_take_check
    mov ecx, UPGRADE_OFFER_COUNT
    random_below_to_eax ecx
    mov upgrade_offer_cursor, eax
    sound_play_call sound_menu_move
upgrade_choose_tick_cpu_take_check:
    cmp match_mode_ticks, UPGRADE_CPU_TAKE_TICK
    jb upgrade_choose_tick_done
    call upgrade_take

upgrade_choose_tick_done:
    add rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    pop rbx
    ret
upgrade_choose_tick ENDP

upgrade_take PROC
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 0, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    mov eax, upgrade_offer_cursor
    assert_below_unsigned eax, UPGRADE_OFFER_COUNT
    lea rcx, upgrade_offer_kinds
    mov eax, dword ptr [rcx + rax * 4]
    assert_below_unsigned eax, UPGRADE_KIND_COUNT
    mov ecx, match_point_loser_side
    player_address_load rdx, ecx
    inc dword ptr [rdx + PLAYER.upgrade_level_by_kind + rax * 4]
    match_mode_set MATCH_MODE_UPGRADE_TAKEN
    sound_play_call sound_menu_take
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    ret
upgrade_take ENDP

over_tick PROC
    sub rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 0, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    lea rax, key_was_pressed_by_virtual_key
    movzx ecx, byte ptr [rax + VK_SPACE]
    or cl, byte ptr [rax + VK_RETURN]
    jnz over_tick_new_match
    test match_mode_ticks, OVER_CONFETTI_PERIOD_TICKS - 1
    jnz over_tick_done
    mov eax, match_point_loser_side
    xor eax, SIDE_FLIP
    side_color_load eax, rax
    mov dword ptr [rsp + CALL_ARG6], eax
    mov dword ptr [rsp + CALL_ARG5], PARTICLE_CONFETTI_COUNT
    random_signed_unit_float_to xmm0
    mulss xmm0, confetti_spread_x_px
    random_signed_unit_float_to xmm1
    mulss xmm1, confetti_spread_y_px
    xorps xmm2, xmm2
    movss xmm3, particle_confetti_spread_px_per_tick
    call particles_spawn_burst
    jmp over_tick_done
over_tick_new_match:
    call match_new
over_tick_done:
    add rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    ret
over_tick ENDP

match_new PROC
    push rdi
    lea rdi, players
    mov ecx, SIZEOF players
    xor eax, eax
    rep stosb
    pop rdi
    mov match_point_loser_side, SIDE_LEFT
    match_mode_set MATCH_MODE_SERVE_WAIT
    ret
match_new ENDP

particles_spawn_burst PROC
    mov r8d, dword ptr [rsp + CALLEE_ARG5]
    mov r9d, dword ptr [rsp + CALLEE_ARG6]
    assert_above_zero_signed r8d
particles_spawn_burst_one:
    mov ecx, particle_next_index
    lea r10d, [rcx + 1]
    and r10d, PARTICLE_COUNT_MAX - 1
    mov particle_next_index, r10d
    imul ecx, ecx, SIZEOF PARTICLE
    lea r10, particles
    add r10, rcx
    movss (PARTICLE PTR [r10]).pos_x_px, xmm0
    movss (PARTICLE PTR [r10]).pos_y_px, xmm1
    random_signed_unit_float_to xmm4
    mulss xmm4, xmm3
    addss xmm4, xmm2
    movss (PARTICLE PTR [r10]).vel_x_px_per_tick, xmm4
    random_signed_unit_float_to xmm4
    mulss xmm4, xmm3
    movss (PARTICLE PTR [r10]).vel_y_px_per_tick, xmm4
    mov ecx, PARTICLE_LIFE_RANDOM_TICKS
    random_below_to_eax ecx
    add eax, PARTICLE_LIFE_MIN_TICKS
    mov (PARTICLE PTR [r10]).life_ticks_left, eax
    mov (PARTICLE PTR [r10]).color_bgra, r9d
    dec r8d
    jnz particles_spawn_burst_one
    ret
particles_spawn_burst ENDP

screen_shake_start PROC
    mov eax, screen_shake_ticks_left
    test eax, eax
    jz screen_shake_start_set
    cvtsi2ss xmm1, eax
    cvtsi2ss xmm2, screen_shake_duration_ticks
    divss xmm1, xmm2
    mulss xmm1, screen_shake_strength_px
    comiss xmm0, xmm1
    jbe screen_shake_start_done
screen_shake_start_set:
    movss screen_shake_strength_px, xmm0
    mov screen_shake_ticks_left, ecx
    mov screen_shake_duration_ticks, ecx
screen_shake_start_done:
    ret
screen_shake_start ENDP

sound_synthesize PROC
    push rbx
    push rsi
    push rdi
    assert_above_zero_signed edx
    lea eax, [rdx + WAVE_HEADER_RIFF_SIZE_WITHOUT_DATA]
    mov (WAVE_HEADER PTR [rcx]).riff_size_bytes, eax
    mov (WAVE_HEADER PTR [rcx]).data_size_bytes, edx
    lea rdi, [rcx + SIZEOF WAVE_HEADER]
    mov esi, edx
    xor ebx, ebx
    xor r10d, r10d
    sub r9d, r8d
sound_synthesize_sample:
    mov eax, r9d
    imul eax, ebx
    cdq
    idiv esi
    add eax, r8d
    imul eax, eax, SOUND_PHASE_STEP_PER_HZ
    add r10d, eax
    mov eax, esi
    sub eax, ebx
    imul eax, eax, SOUND_AMPLITUDE
    xor edx, edx
    div esi
    mov r11d, SOUND_SILENCE_LEVEL
    test r10d, r10d
    js sound_synthesize_high
    sub r11d, eax
    jmp sound_synthesize_store
sound_synthesize_high:
    add r11d, eax
sound_synthesize_store:
    mov byte ptr [rdi + rbx], r11b
    inc ebx
    cmp ebx, esi
    jb sound_synthesize_sample
    pop rdi
    pop rsi
    pop rbx
    ret
sound_synthesize ENDP

sound_play PROC
    xor edx, edx
    mov r8d, SOUND_PLAY_FLAGS
    jmp PlaySoundA
sound_play ENDP

frame_render PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_6_ARGS_ODD_PUSHES_BYTES

    mov eax, COLOR_BACKGROUND_BGRA
    mov edx, background_flash_ticks_left
    test edx, edx
    jz frame_render_clear
    imul edx, edx, BACKGROUND_FLASH_LEVEL_PER_TICK
    mov eax, match_point_loser_side
    xor eax, SIDE_FLIP
    side_color_load ecx, rax
    call color_scale
frame_render_clear:
    lea rdi, framebuffer_bgra
    mov ecx, SCREEN_PIXEL_COUNT
    rep stosd

    mov ebx, (CENTER_LINE_PERIOD_PX - CENTER_LINE_DASH_PX) / 2
frame_render_center_line_dash:
    mov ecx, (SCREEN_WIDTH_PX - CENTER_LINE_WIDTH_PX) / 2
    mov edx, ebx
    mov r8d, CENTER_LINE_WIDTH_PX
    mov r9d, CENTER_LINE_DASH_PX
    mov dword ptr [rsp + CALL_ARG5], COLOR_CENTER_LINE_BGRA
    call framebuffer_rect_fill
    add ebx, CENTER_LINE_PERIOD_PX
    cmp ebx, SCREEN_HEIGHT_PX
    jb frame_render_center_line_dash

    xor ebx, ebx
frame_render_side:
    player_address_load rsi, ebx
    cmp upgrade_level(rsi, UPGRADE_KIND_SHIELD), 0
    je frame_render_side_score
    side_color_load eax, rbx
    mov dword ptr [rsp + CALL_ARG5], eax
    movss xmm0, shield_line_center_x_px
    cmp ebx, SIDE_RIGHT
    je frame_render_side_shield_x
    xorps xmm0, xmmword ptr float_sign_mask_x4
frame_render_side_shield_x:
    xorps xmm1, xmm1
    movss xmm2, shield_line_half_width_px
    movss xmm3, field_half_height_px
    call framebuffer_rect_fill_field

frame_render_side_score:
    mov edi, COLOR_WHITE_BGRA
    test (PLAYER PTR [rsi]).score_flash_ticks_left, SCORE_FLASH_BLINK_BIT_MASK
    jz frame_render_side_score_draw
    side_color_load edi, rbx
frame_render_side_score_draw:
    mov ecx, (PLAYER PTR [rsi]).score
    mov edx, SCREEN_WIDTH_PX / 2 + SCORE_CENTER_FROM_SCREEN_CENTER_PX
    cmp ebx, SIDE_RIGHT
    je frame_render_side_score_x
    mov edx, SCREEN_WIDTH_PX / 2 - SCORE_CENTER_FROM_SCREEN_CENTER_PX
frame_render_side_score_x:
    mov r8d, edi
    call score_draw

    side_color_load edi, rbx
    paddle_center_x_load xmm0, ebx
    movss xmm1, (PLAYER PTR [rsi]).paddle_center_y_px
    movss xmm2, paddle_half_width_px
    movss xmm3, (PLAYER PTR [rsi]).paddle_half_height_shown_px
    cmp (PLAYER PTR [rsi]).paddle_flash_ticks_left, 0
    je frame_render_side_paddle_draw
    mov edi, COLOR_WHITE_BGRA
    addss xmm2, paddle_flash_half_width_extra_px
frame_render_side_paddle_draw:
    mov dword ptr [rsp + CALL_ARG5], edi
    call framebuffer_rect_fill_field
    inc ebx
    cmp ebx, SIDE_COUNT
    jb frame_render_side

    mov eax, match_mode
    cmp eax, MATCH_MODE_RALLY
    je frame_render_ball
    cmp eax, MATCH_MODE_SERVE_WAIT
    jne frame_render_overlay
    test match_mode_ticks, SERVE_BLINK_BIT_MASK
    jnz frame_render_overlay
frame_render_ball:
    movss xmm0, ball_speed_px_per_tick
    subss xmm0, ball_serve_speed_px_per_tick
    mulss xmm0, ball_heat_levels_per_px_per_tick
    cvttss2si eax, xmm0
    xor ecx, ecx
    test eax, eax
    cmovs eax, ecx
    mov ecx, BALL_HEAT_COLOR_COUNT - 1
    cmp eax, ecx
    cmovg eax, ecx
    lea rcx, ball_heat_color_bgra
    mov ebx, dword ptr [rcx + rax * 4]
    mov ecx, ebx
    call ball_trail_draw
    mov dword ptr [rsp + CALL_ARG5], ebx
    movss xmm0, ball_center_x_px
    movss xmm1, ball_center_y_px
    movss xmm2, ball_half_size_px
    movaps xmm3, xmm2
    call framebuffer_rect_fill_field

frame_render_overlay:
    mov eax, match_mode
    cmp eax, MATCH_MODE_UPGRADE_CHOOSE
    je frame_render_upgrade_screen
    cmp eax, MATCH_MODE_UPGRADE_TAKEN
    je frame_render_upgrade_screen
    cmp eax, MATCH_MODE_OVER
    jne frame_render_particles
    call over_screen_draw
    jmp frame_render_particles
frame_render_upgrade_screen:
    call upgrade_screen_draw
frame_render_particles:
    call particles_draw

    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
frame_render ENDP

ball_trail_draw PROC
    push rbx
    push rsi
    push rdi
    push r12
    sub rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 4, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    mov r12d, ecx
    mov esi, ball_trail_count
    assert_below_unsigned esi, BALL_TRAIL_LENGTH + 1
    xor ebx, ebx
ball_trail_draw_step:
    cmp ebx, esi
    jae ball_trail_draw_done
    mov eax, ball_trail_next_index
    sub eax, ebx
    dec eax
    and eax, BALL_TRAIL_LENGTH - 1
    mov edi, eax
    mov edx, BALL_TRAIL_LENGTH
    sub edx, ebx
    imul edx, edx, BALL_TRAIL_LEVEL_PER_STEP
    mov ecx, r12d
    call color_scale
    mov dword ptr [rsp + CALL_ARG5], eax
    mov eax, BALL_TRAIL_LENGTH
    sub eax, ebx
    cvtsi2ss xmm2, eax
    mulss xmm2, ball_trail_half_size_per_step_px
    movaps xmm3, xmm2
    lea rcx, ball_trail_x_px
    movss xmm0, dword ptr [rcx + rdi * 4]
    lea rcx, ball_trail_y_px
    movss xmm1, dword ptr [rcx + rdi * 4]
    call framebuffer_rect_fill_field
    inc ebx
    jmp ball_trail_draw_step
ball_trail_draw_done:
    add rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
ball_trail_draw ENDP

particles_draw PROC
    push rbx
    push rsi
    sub rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 2, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    lea rbx, particles
    mov esi, PARTICLE_COUNT_MAX
particles_draw_one:
    mov edx, (PARTICLE PTR [rbx]).life_ticks_left
    test edx, edx
    jz particles_draw_next
    imul edx, edx, PARTICLE_LEVEL_PER_LIFE_TICK
    mov eax, COLOR_LEVEL_FULL
    cmp edx, eax
    cmova edx, eax
    mov ecx, (PARTICLE PTR [rbx]).color_bgra
    call color_scale
    mov dword ptr [rsp + CALL_ARG5], eax
    movss xmm0, (PARTICLE PTR [rbx]).pos_x_px
    movss xmm1, (PARTICLE PTR [rbx]).pos_y_px
    movss xmm2, particle_half_size_px
    movaps xmm3, xmm2
    call framebuffer_rect_fill_field
particles_draw_next:
    add rbx, SIZEOF PARTICLE
    dec esi
    jnz particles_draw_one
    add rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    pop rsi
    pop rbx
    ret
particles_draw ENDP

upgrade_screen_draw PROC
    push rbx
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 1, FRAME_6_ARGS_ODD_PUSHES_BYTES
    call framebuffer_darken

    mov eax, paddle_right_mode
    imul eax, eax, SIDE_COUNT
    add eax, match_point_loser_side
    lea rcx, upgrade_title_texts
    mov rcx, qword ptr [rcx + rax * 8]
    mov edx, SCREEN_WIDTH_PX / 2
    mov r8d, UPGRADE_TITLE_TOP_PX
    mov r9d, COLOR_WHITE_BGRA
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_SMALL
    call text_draw_centered

    cmp match_mode, MATCH_MODE_UPGRADE_CHOOSE
    jne upgrade_screen_draw_cards
    cmp match_point_loser_side, SIDE_RIGHT
    jne upgrade_screen_draw_prompt
    cmp paddle_right_mode, PADDLE_RIGHT_MODE_CPU
    je upgrade_screen_draw_cards
upgrade_screen_draw_prompt:
    lea rcx, text_upgrade_prompt
    mov edx, SCREEN_WIDTH_PX / 2
    mov r8d, UPGRADE_PROMPT_TOP_PX
    mov r9d, COLOR_TEXT_DIM_BGRA
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_SMALL
    call text_draw_centered

upgrade_screen_draw_cards:
    xor ebx, ebx
upgrade_screen_draw_card:
    mov ecx, ebx
    call upgrade_card_draw
    inc ebx
    cmp ebx, UPGRADE_OFFER_COUNT
    jb upgrade_screen_draw_card

    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rbx
    ret
upgrade_screen_draw ENDP

upgrade_card_draw PROC
    push rbx
    push rsi
    push rdi
    push r12
    push r13
    push r14
    push r15
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 7, FRAME_6_ARGS_ODD_PUSHES_BYTES
    mov ebx, ecx
    assert_below_unsigned ebx, UPGRADE_OFFER_COUNT
    lea rax, upgrade_offer_kinds
    mov esi, dword ptr [rax + rbx * 4]
    assert_below_unsigned esi, UPGRADE_KIND_COUNT
    xor edi, edi
    cmp ebx, upgrade_offer_cursor
    sete dil
    mov eax, match_point_loser_side
    side_color_load r12d, rax

    cmp match_mode, MATCH_MODE_UPGRADE_TAKEN
    jne upgrade_card_draw_position
    test edi, edi
    jz upgrade_card_draw_done

upgrade_card_draw_position:
    mov r13d, UPGRADE_CARD_LEFT_PX
    cmp match_mode, MATCH_MODE_UPGRADE_CHOOSE
    jne upgrade_card_draw_slide_done
    imul eax, ebx, UPGRADE_CARD_SLIDE_STAGGER_TICKS
    mov ecx, UPGRADE_CARD_SLIDE_TICKS
    add eax, ecx
    sub eax, match_mode_ticks
    jle upgrade_card_draw_slide_done
    cmp eax, ecx
    cmovg eax, ecx
    imul eax, eax
    add r13d, eax
upgrade_card_draw_slide_done:
    test edi, edi
    jz upgrade_card_draw_top
    sub r13d, UPGRADE_CARD_SELECTED_SHIFT_PX
upgrade_card_draw_top:
    imul r14d, ebx, UPGRADE_CARD_PITCH_PX
    add r14d, UPGRADE_CARD_TOP_PX

    mov r15d, COLOR_CARD_BORDER_BGRA
    test edi, edi
    jz upgrade_card_draw_border
    cmp match_mode, MATCH_MODE_UPGRADE_TAKEN
    je upgrade_card_draw_border_taken
    mov eax, match_mode_ticks
    and eax, UPGRADE_CARD_PULSE_PERIOD_TICKS - 1
    sub eax, UPGRADE_CARD_PULSE_PERIOD_TICKS / 2
    cdq
    xor eax, edx
    sub eax, edx
    imul edx, eax, UPGRADE_CARD_PULSE_LEVEL_PER_TICK
    add edx, UPGRADE_CARD_PULSE_LEVEL_MIN
    mov ecx, r12d
    call color_scale
    mov r15d, eax
    jmp upgrade_card_draw_border
upgrade_card_draw_border_taken:
    mov r15d, r12d
    test match_mode_ticks, UPGRADE_TAKEN_BLINK_BIT_MASK
    jz upgrade_card_draw_border
    mov r15d, COLOR_WHITE_BGRA

upgrade_card_draw_border:
    mov ecx, r13d
    mov edx, r14d
    mov r8d, UPGRADE_CARD_WIDTH_PX
    mov r9d, UPGRADE_CARD_HEIGHT_PX
    mov dword ptr [rsp + CALL_ARG5], r15d
    call framebuffer_rect_fill

    mov eax, COLOR_CARD_PANEL_BGRA
    test edi, edi
    jz upgrade_card_draw_panel
    mov eax, COLOR_CARD_PANEL_SELECTED_BGRA
upgrade_card_draw_panel:
    mov dword ptr [rsp + CALL_ARG5], eax
    lea ecx, [r13 + UPGRADE_CARD_BORDER_PX]
    lea edx, [r14 + UPGRADE_CARD_BORDER_PX]
    mov r8d, UPGRADE_CARD_WIDTH_PX - 2 * UPGRADE_CARD_BORDER_PX
    mov r9d, UPGRADE_CARD_HEIGHT_PX - 2 * UPGRADE_CARD_BORDER_PX
    call framebuffer_rect_fill

    lea rax, upgrade_name_texts
    mov rcx, qword ptr [rax + rsi * 8]
    lea edx, [r13 + UPGRADE_CARD_TEXT_INSET_PX]
    lea r8d, [r14 + UPGRADE_CARD_NAME_TOP_INSET_PX]
    mov r9d, COLOR_TEXT_DIM_BGRA
    test edi, edi
    jz upgrade_card_draw_name
    mov r9d, COLOR_WHITE_BGRA
upgrade_card_draw_name:
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_LARGE
    call text_draw

    lea rax, upgrade_description_texts
    mov rcx, qword ptr [rax + rsi * 8]
    lea edx, [r13 + UPGRADE_CARD_TEXT_INSET_PX]
    lea r8d, [r14 + UPGRADE_CARD_DESCRIPTION_TOP_INSET_PX]
    mov r9d, COLOR_TEXT_DIM_BGRA
    test edi, edi
    jz upgrade_card_draw_description
    mov r9d, COLOR_TEXT_BRIGHT_BGRA
upgrade_card_draw_description:
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_SMALL
    call text_draw

    mov eax, match_point_loser_side
    player_address_load rax, eax
    mov edi, dword ptr [rax + PLAYER.upgrade_level_by_kind + rsi * 4]
    mov ecx, UPGRADE_CARD_PIPS_MAX
    cmp edi, ecx
    cmova edi, ecx
    xor ebx, ebx
upgrade_card_draw_pip:
    cmp ebx, edi
    jae upgrade_card_draw_done
    lea ecx, [r13 + UPGRADE_CARD_WIDTH_PX - UPGRADE_CARD_PIP_RIGHT_INSET_PX]
    imul eax, ebx, UPGRADE_CARD_PIP_PITCH_PX
    sub ecx, eax
    lea edx, [r14 + UPGRADE_CARD_PIP_TOP_INSET_PX]
    mov r8d, UPGRADE_CARD_PIP_SIZE_PX
    mov r9d, UPGRADE_CARD_PIP_SIZE_PX
    mov dword ptr [rsp + CALL_ARG5], r12d
    call framebuffer_rect_fill
    inc ebx
    jmp upgrade_card_draw_pip

upgrade_card_draw_done:
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop r15
    pop r14
    pop r13
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
upgrade_card_draw ENDP

over_screen_draw PROC
    sub rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 0, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    call framebuffer_darken

    mov eax, match_point_loser_side
    xor eax, SIDE_FLIP
    side_color_load r9d, rax
    mov edx, paddle_right_mode
    imul edx, edx, SIDE_COUNT
    add eax, edx
    lea rcx, over_title_texts
    mov rcx, qword ptr [rcx + rax * 8]
    mov edx, SCREEN_WIDTH_PX / 2
    mov r8d, OVER_TITLE_TOP_PX
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_HUGE
    call text_draw_centered

    lea rcx, text_over_prompt
    mov edx, SCREEN_WIDTH_PX / 2
    mov r8d, OVER_PROMPT_TOP_PX
    mov r9d, COLOR_WHITE_BGRA
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_SMALL
    call text_draw_centered

    add rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    ret
over_screen_draw ENDP

score_draw PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_4_ARGS_ODD_PUSHES_BYTES
    assert_below_unsigned ecx, MATCH_WINNING_SCORE + 1

    mov esi, edx
    mov edi, r8d
    mov eax, ecx
    xor edx, edx
    mov ecx, SCORE_DECIMAL_BASE
    div ecx
    mov ebx, edx
    test eax, eax
    jz score_draw_one_digit
    mov ecx, eax
    lea edx, [rsi - SCORE_TWO_DIGITS_WIDTH_PX / 2]
    mov r8d, edi
    call score_digit_draw
    lea edx, [rsi - SCORE_TWO_DIGITS_WIDTH_PX / 2 + SCORE_DIGIT_ADVANCE_PX]
    jmp score_draw_ones_digit
score_draw_one_digit:
    lea edx, [rsi - SCORE_DIGIT_WIDTH_PX / 2]
score_draw_ones_digit:
    mov ecx, ebx
    mov r8d, edi
    call score_digit_draw

    add rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
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
    frame_alignment_check 7, FRAME_6_ARGS_ODD_PUSHES_BYTES
    assert_below_unsigned ecx, FONT_DIGIT_COUNT

    mov r12d, edx
    mov r13d, r8d
    imul eax, ecx, FONT_DIGIT_ROWS
    lea rbx, font_digit_rows_3x5
    add rbx, rax
    lea r14, [rbx + FONT_DIGIT_ROWS]
    mov edi, SCORE_TOP_PX
score_digit_draw_row:
    movzx esi, byte ptr [rbx]
    mov r15d, r12d
score_digit_draw_cell:
    test esi, FONT_DIGIT_LEFT_COLUMN_BIT
    jz score_digit_draw_cell_next
    mov ecx, r15d
    mov edx, edi
    mov r8d, SCORE_CELL_PX
    mov r9d, SCORE_CELL_PX
    mov dword ptr [rsp + CALL_ARG5], r13d
    call framebuffer_rect_fill
score_digit_draw_cell_next:
    add r15d, SCORE_CELL_PX
    shl esi, 1
    test esi, FONT_DIGIT_ROW_MASK
    jnz score_digit_draw_cell
    add edi, SCORE_CELL_PX
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
    mov eax, dword ptr [rsp + TEXT_DRAW_LOCAL_COLOR]
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

framebuffer_darken PROC
    .ERRNZ SCREEN_PIXEL_COUNT MOD 4
    lea rcx, framebuffer_bgra
    mov edx, SCREEN_PIXEL_COUNT / 4
    movdqa xmm1, xmmword ptr pixel_rgb_quarter_mask_x4
framebuffer_darken_four_pixels:
    movdqa xmm0, xmmword ptr [rcx]
    psrld xmm0, 2
    pand xmm0, xmm1
    movdqa xmmword ptr [rcx], xmm0
    add rcx, 16
    dec edx
    jnz framebuffer_darken_four_pixels
    ret
framebuffer_darken ENDP

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
    assert_not_negative_signed r8d
    assert_not_negative_signed r9d
    mov r10d, dword ptr [rsp + CALLEE_ARG5]
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
