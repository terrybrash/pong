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
CALLEE_ARG7                         equ 56
FRAME_4_ARGS_EVEN_PUSHES_BYTES      equ CALL_SHADOW_BYTES + 8
FRAME_4_ARGS_ODD_PUSHES_BYTES       equ CALL_SHADOW_BYTES
FRAME_6_ARGS_ODD_PUSHES_BYTES       equ CALL_ARG6 + 8
FRAME_7_ARGS_EVEN_PUSHES_BYTES      equ CALL_ARG7 + 8
FRAME_8_ARGS_ODD_PUSHES_BYTES       equ CALL_ARG8 + 8
FRAME_LOCAL_AFTER_ARG5              equ CALL_ARG6

SCREEN_WIDTH_PX                     equ 320
SCREEN_HEIGHT_PX                    equ 240
SCREEN_PIXEL_COUNT                  equ SCREEN_WIDTH_PX * SCREEN_HEIGHT_PX
SCREEN_CENTER_X_PX                  equ SCREEN_WIDTH_PX / 2
SCREEN_CENTER_Y_PX                  equ SCREEN_HEIGHT_PX / 2
SIM_TICKS_PER_SEC                   equ 120
SIM_TICKS_BEHIND_MAX                equ 8
PERCENT_COUNT                       equ 100

COLOR_BLACK_BGRA                    equ 00000000h
COLOR_WHITE_BGRA                    equ 00F0F0F0h
COLOR_GOLD_BGRA                     equ 00FFD040h
COLOR_FLAME_BGRA                    equ 00FF7830h
COLOR_TEXT_BRIGHT_BGRA              equ 00D0D0E0h
COLOR_TEXT_DIM_BGRA                 equ 00808090h
COLOR_COMBO_BGRA                    equ 00FFE070h
COLOR_NONE_BGRA                     equ 00000000h
COLOR_ALPHA_MASK                    equ 0FF000000h
TEXT_COLOR_RAINBOW                  equ 0FF000000h
COLOR_LEVEL_SHIFT                   equ 8
COLOR_LEVEL_FULL                    equ 1 SHL COLOR_LEVEL_SHIFT
LERP_LEVEL_SHIFT                    equ 7
LERP_LEVEL_FULL                     equ 1 SHL LERP_LEVEL_SHIFT
RAINBOW_COLOR_COUNT                 equ 16
RAINBOW_RANDOM_SHIFT                equ 28
TRIANGLE_WAVE_PERIOD_TICKS          equ 32

TEXT_SCALE_SMALL                    equ 1
TEXT_SCALE_LARGE                    equ 2
TEXT_SCALE_HUGE                     equ 3
TEXT_SCALE_GIANT                    equ 4

MATCH_MODE_CHARACTER_SELECT         equ 0
MATCH_MODE_SERVE_WAIT               equ 1
MATCH_MODE_RALLY                    equ 2
MATCH_MODE_POINT_SCORED             equ 3
MATCH_MODE_UPGRADE_CHOOSE           equ 4
MATCH_MODE_UPGRADE_TAKEN            equ 5
MATCH_MODE_OVER                     equ 6
MATCH_MODE_COUNT                    equ 7

SIDE_NEAR                           equ 0
SIDE_FAR                            equ 1
SIDE_COUNT                          equ 2
SIDE_FLIP                           equ SIDE_NEAR XOR SIDE_FAR

MATCH_WINNING_SCORE                 equ 21
SCORE_MAX                           equ 99
RALLY_MULTIPLIER_MAX                equ 9
.ERRE MATCH_WINNING_SCORE - 1 + RALLY_MULTIPLIER_MAX LE SCORE_MAX

UPGRADE_KIND_BIG_REACH              equ 0
UPGRADE_KIND_QUICK_FEET             equ 1
UPGRADE_KIND_POWER_HIT              equ 2
UPGRADE_KIND_WIDE_AIM               equ 3
UPGRADE_KIND_SHIELD                 equ 4
UPGRADE_KIND_SHRINK_FOE             equ 5
UPGRADE_KIND_DASH_MASTER            equ 6
UPGRADE_KIND_COUNT                  equ 7
UPGRADE_OFFER_COUNT                 equ 3
.ERRE UPGRADE_KIND_COUNT GE UPGRADE_OFFER_COUNT

CHARACTER_COUNT                     equ 4
GHOST_COUNT                         equ 4

VIRTUAL_KEY_COUNT                   equ 256
VK_LBUTTON                          equ 01h
VK_TAB                              equ 09h
VK_RETURN                           equ 0Dh
VK_ESCAPE                           equ 1Bh
VK_SPACE                            equ 20h
VK_LEFT                             equ 25h
VK_UP                               equ 26h
VK_RIGHT                            equ 27h
VK_DOWN                             equ 28h
VK_A                                equ 41h
VK_D                                equ 44h
VK_M                                equ 4Dh
VK_R                                equ 52h
VK_S                                equ 53h
VK_W                                equ 57h

AUDIO_SAMPLE_RATE_HZ                equ 22050
AUDIO_SEMITONE_MIN                  equ -12
AUDIO_SEMITONE_MAX                  equ 24
VOLUME_QUIET                        equ 45
VOLUME_NORMAL                       equ 90
VOLUME_LOUD                         equ 130

POPUP_NO_NUMBER                     equ -1

RANDOM_LCG_MULTIPLIER               equ 1664525
RANDOM_LCG_INCREMENT                equ 1013904223
RANDOM_UNIT_FLOAT_DROPPED_BITS      equ 8
HASH_MULTIPLIER                     equ -1640531535
.ERRNZ (HASH_MULTIPLIER AND 0FFFFFFFFh) - 9E3779B1h

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

assert_bits_clear MACRO value, bits
    LOCAL assert_bits_clear_ok
    test value, bits
    jz assert_bits_clear_ok
    ud2
assert_bits_clear_ok:
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

counter_raise_to MACRO counter, value_reg32
    LOCAL counter_raise_to_done
    cmp counter, value_reg32
    jae counter_raise_to_done
    mov counter, value_reg32
counter_raise_to_done:
ENDM

triangle_wave_from_eax MACRO
    and eax, TRIANGLE_WAVE_PERIOD_TICKS - 1
    sub eax, TRIANGLE_WAVE_PERIOD_TICKS / 2
    cdq
    xor eax, edx
    sub eax, edx
ENDM

float_clamp_symmetric MACRO xmm_reg, xmm_temp, limit
    movss xmm_temp, limit
    minss xmm_reg, xmm_temp
    xorps xmm_temp, xmmword ptr float_sign_mask_x4
    maxss xmm_reg, xmm_temp
ENDM

float_clamp MACRO xmm_reg, low_limit, high_limit
    maxss xmm_reg, low_limit
    minss xmm_reg, high_limit
ENDM

rainbow_color_from_eax MACRO color_reg32
    and eax, RAINBOW_COLOR_COUNT - 1
    lea r11, rainbow_color_bgra
    mov color_reg32, dword ptr [r11 + rax * 4]
ENDM

side_color_load MACRO color_reg32, side_reg64
    lea r11, side_color_bgra
    mov color_reg32, dword ptr [r11 + side_reg64 * 4]
ENDM

player_address_load MACRO player_reg64, side_reg32
    imul r11d, side_reg32, SIZEOF PLAYER
    lea player_reg64, players
    add player_reg64, r11
ENDM

upgrade_level MACRO player_reg64, kind
    EXITM <dword ptr [player_reg64 + PLAYER.upgrade_level_by_kind + 4 * (kind)]>
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

audio_play_call MACRO sound_name, semitone, volume, delay_ms
    mov r8d, semitone
    lea rcx, sound_name
    mov edx, sound_name&_SAMPLE_COUNT
    mov r9d, volume
    mov dword ptr [rsp + CALL_ARG5], (delay_ms) * AUDIO_SAMPLE_RATE_HZ / 1000
    call audio_play
ENDM

particles_spawn_call MACRO style, color, base_vel_x, base_vel_z
    mov dword ptr [rsp + CALL_ARG5], color
    IFB <base_vel_x>
        mov dword ptr [rsp + CALL_ARG6], 0
        mov dword ptr [rsp + CALL_ARG7], 0
    ELSE
        movss dword ptr [rsp + CALL_ARG6], base_vel_x
        movss dword ptr [rsp + CALL_ARG7], base_vel_z
    ENDIF
    lea r9, style
    call particles_spawn_burst
ENDM

popup_spawn_call MACRO prefix_text, number, style, suffix_text
    mov edx, number
    lea rcx, prefix_text
    lea rax, style
    mov qword ptr [rsp + CALL_ARG5], rax
    IFB <suffix_text>
        mov qword ptr [rsp + CALL_ARG6], 0
    ELSE
        lea rax, suffix_text
        mov qword ptr [rsp + CALL_ARG6], rax
    ENDIF
    call popup_spawn
ENDM

screen_punch_call MACRO punch
    lea rcx, punch
    call screen_punch
ENDM

VEC3 STRUCT
    x                               REAL4 ?
    y                               REAL4 ?
    z                               REAL4 ?
VEC3 ENDS

PLAYER STRUCT
    pos_x_u                         REAL4 ?
    pos_z_u                         REAL4 ?
    vel_x_u_per_s                   REAL4 ?
    vel_z_u_per_s                   REAL4 ?
    facing_x                        REAL4 ?
    facing_z                        REAL4 ?
    side_z_sign                     REAL4 ?
    walk_phase_radians              REAL4 ?
    walk_amount                     REAL4 ?
    reach_u                         REAL4 ?
    run_speed_u_per_s               REAL4 ?
    dash_cooldown_ticks_max         DWORD ?
    dash_ticks_left                 DWORD ?
    dash_cooldown_ticks_left        DWORD ?
    swing_ticks_left                DWORD ?
    flash_ticks_left                DWORD ?
    character_index                 DWORD ?
    cpu_reaction_ticks_left         DWORD ?
    cpu_target_x_u                  REAL4 ?
    cpu_target_z_u                  REAL4 ?
    ghost_x_u                       REAL4 GHOST_COUNT DUP (?)
    ghost_z_u                       REAL4 GHOST_COUNT DUP (?)
    ghost_ticks_left                DWORD GHOST_COUNT DUP (?)
    ghost_next_index                DWORD ?
    score                           DWORD ?
    score_shown                     DWORD ?
    score_pop_ticks_left            DWORD ?
    upgrade_level_by_kind           DWORD UPGRADE_KIND_COUNT DUP (?)
PLAYER ENDS

POSE STRUCT
    pos                             VEC3 <>
    facing_x                        REAL4 ?
    facing_z                        REAL4 ?
    walk_phase_radians              REAL4 ?
    walk_amount                     REAL4 ?
    swing_fraction                  REAL4 ?
    character_index                 DWORD ?
    color_override_bgra             DWORD ?
POSE ENDS

.const
ALIGN 16
float_sign_mask_x4                  DWORD 4 DUP (80000000h)
float_abs_mask_x4                   DWORD 4 DUP (7FFFFFFFh)
float_zero                          REAL4 0.0
float_one                           REAL4 1.0
float_half                          REAL4 0.5
float_two                           REAL4 2.0
float_pi                            REAL4 3.14159265
float_two_pi                        REAL4 6.28318531
float_half_pi                       REAL4 1.57079633
float_inverse_two_pi                REAL4 0.15915494
float_ticks_per_second              REAL4 120.0
tick_seconds                        REAL4 0.0083333333
random_unit_float_scale             REAL4 5.9604645e-8
rainbow_color_bgra                  DWORD 00FF0000h, 00FF5F00h, 00FFBF00h, 00DFFF00h, 007FFF00h, 001FFF00h, 0000FF3Fh, 0000FF9Fh
                                    DWORD 0000FFFFh, 00009FFFh, 00003FFFh, 001F00FFh, 007F00FFh, 00DF00FFh, 00FF00BFh, 00FF005Fh
rainbow_color_bgra_end              LABEL DWORD
.ERRNZ (rainbow_color_bgra_end - rainbow_color_bgra) - 4 * RAINBOW_COLOR_COUNT
side_color_bgra                     DWORD 0040C8FFh, 00FF7040h
.ERRNZ LENGTHOF side_color_bgra - SIDE_COUNT

.data?
random_state                        DWORD ?
