ANIM_GROUP_BODY                     equ 0
ANIM_GROUP_HEAD                     equ 1
ANIM_GROUP_LEFT_LEG                 equ 2
ANIM_GROUP_RIGHT_LEG                equ 3
ANIM_GROUP_LEFT_ARM                 equ 4
ANIM_GROUP_RIGHT_ARM                equ 5
ANIM_GROUP_COUNT                    equ 6
CHARACTER_STAT_SPEED                equ 0
CHARACTER_STAT_REACH                equ 1
CHARACTER_STAT_POWER                equ 2
CHARACTER_STAT_DASH                 equ 3
CHARACTER_STAT_AIM                  equ 4
CHARACTER_STAT_COUNT                equ 5
CHARACTER_STAT_BAR_MAX              equ 5
CHARACTER_KNIGHT                    equ 0
CHARACTER_ROGUE                     equ 1
CHARACTER_WIZARD                    equ 2
CHARACTER_ORC                       equ 3
.ERRNZ CHARACTER_COUNT - 4
CHARACTER_DRAW_PUSHED_REGISTER_COUNT equ 7
CHARACTER_DRAW_FRAME_BYTES          equ FRAME_6_ARGS_ODD_PUSHES_BYTES
CHARACTER_ANIM_COMPUTE_FRAME_BYTES  equ 80
CHARACTER_ANIM_LOCAL_T              equ 32
CHARACTER_ANIM_LOCAL_WALK_SIN       equ 36
CHARACTER_ANIM_LOCAL_WALK_COS2      equ 40
CHARACTER_ANIM_LOCAL_WALK_SIN2      equ 44
CHARACTER_ANIM_LOCAL_WAVE           equ 48
CHARACTER_ANIM_LOCAL_JITTER_A       equ 52
CHARACTER_ANIM_LOCAL_JITTER_B       equ 56
CHARACTER_ANIM_LOCAL_ENVELOPE       equ 60
CHARACTER_ANIM_LOCAL_BEAT_SIN       equ 64
CHARACTER_TRANSFORMS_FRAME_BYTES    equ 48
CHARACTER_TRANSFORMS_LOCAL_ANGLE    equ 32
CHARACTER_JITTER_SHIFT              equ 16
POWER_CHARGE_FULL_TICKS             equ 120
POWER_ROAR_BURST_TICKS              equ 8

limb_pitch MACRO group
    EXITM <dword ptr character_limb_pitch_radians[4 * (group)]>
ENDM

limb_roll MACRO group
    EXITM <dword ptr character_limb_roll_radians[4 * (group)]>
ENDM

anim_local MACRO offset
    EXITM <dword ptr [rsp + offset]>
ENDM

anim_store_constant MACRO target, constant
    movss xmm0, constant
    movss target, xmm0
ENDM

anim_store_mirrored MACRO left_target, right_target
    movss right_target, xmm0
    xorps xmm0, xmmword ptr float_sign_mask_x4
    movss left_target, xmm0
ENDM

anim_wave_to_local MACRO local_offset, radians_per_tick
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_T)
    mulss xmm0, radians_per_tick
    call math_sin
    movss anim_local(local_offset), xmm0
ENDM

PART STRUCT
    kind                            DWORD ?
    anim_group                      DWORD ?
    color_bgra                      DWORD ?
    texture_index                   DWORD ?
    center                          VEC3 <>
    half                            VEC3 <>
PART ENDS

CHARACTER STRUCT
    name_text                       QWORD ?
    description_text                QWORD ?
    parts                           QWORD ?
    pivots                          QWORD ?
    part_count                      DWORD ?
    color_bgra                      DWORD ?
    run_speed_u_per_s               REAL4 ?
    dash_speed_u_per_s              REAL4 ?
    dash_ticks                      DWORD ?
    dash_cooldown_ticks             DWORD ?
    reach_u                         REAL4 ?
    flight_time_s                   REAL4 ?
    aim_range_u                     REAL4 ?
    crit_percent                    DWORD ?
    model_scale                     REAL4 ?
    character_padding               DWORD ?
CHARACTER ENDS

GROUP_TRANSFORM STRUCT
    pitch_cos                       REAL4 ?
    pitch_sin                       REAL4 ?
    roll_cos                        REAL4 ?
    roll_sin                        REAL4 ?
    pivot                           VEC3 <>
    group_transform_padding         DWORD ?
GROUP_TRANSFORM ENDS

.const
anim_idle_radians_per_tick          REAL4 0.09
anim_head_wobble_radians_per_tick   REAL4 0.13
anim_head_wobble_radians            REAL4 0.22
anim_move_leg_swing_radians         REAL4 1.05
anim_move_arm_swing_radians         REAL4 1.35
anim_idle_arm_sway_radians          REAL4 0.1
anim_idle_arm_out_radians           REAL4 0.15
anim_move_arm_out_radians           REAL4 0.5
anim_move_bounce_u                  REAL4 0.2
anim_move_lean_radians              REAL4 0.38
anim_move_roll_radians              REAL4 0.22
anim_idle_roll_radians              REAL4 0.05
anim_move_squash                    REAL4 0.16
anim_idle_breath_squash             REAL4 0.035
anim_move_head_nod_radians          REAL4 0.3
anim_swing_arm_radians              REAL4 3.4
anim_swing_arm_back_radians         REAL4 0.7
anim_swing_arm_out_radians          REAL4 0.5
anim_swing_other_arm_out_radians    REAL4 1.5
anim_swing_stretch                  REAL4 0.4
anim_swing_lean_radians             REAL4 0.35
anim_swing_roll_radians             REAL4 -0.4
anim_swing_head_radians             REAL4 -0.5
anim_dash_lean_radians              REAL4 0.8
anim_dash_squash                    REAL4 0.75
anim_dash_lift_u                    REAL4 0.12
anim_dash_leg_split_radians         REAL4 1.15
anim_dash_arm_back_radians          REAL4 -1.7
anim_dash_arm_out_radians           REAL4 0.3
anim_dash_head_radians              REAL4 -0.35
anim_cheer_hop_radians_per_tick     REAL4 0.16
anim_cheer_hop_u                    REAL4 0.9
anim_cheer_squash_radians_per_tick  REAL4 0.32
anim_cheer_squash                   REAL4 0.28
anim_cheer_windmill_radians_per_tick REAL4 0.35
anim_cheer_arm_out_radians          REAL4 0.5
anim_cheer_kick_radians             REAL4 0.7
anim_cheer_spin_radians_per_tick    REAL4 0.09
anim_cheer_head_radians_per_tick    REAL4 0.2
anim_cheer_head_radians             REAL4 0.45
anim_slump_sway_radians_per_tick    REAL4 0.05
anim_slump_lean_radians             REAL4 0.65
anim_slump_lean_sway_radians        REAL4 0.08
anim_slump_squash                   REAL4 0.86
anim_slump_arm_radians_per_tick     REAL4 0.1
anim_slump_arm_swing_radians        REAL4 0.35
anim_slump_head_radians             REAL4 0.75
anim_power_charge_ticks_float       REAL4 120.0
.ERRNZ POWER_CHARGE_FULL_TICKS - 120
anim_power_squash                   REAL4 0.16
anim_power_jitter_squash            REAL4 0.035
anim_power_lift_u                   REAL4 0.35
anim_power_hover_radians_per_tick   REAL4 0.1
anim_power_hover_u                  REAL4 0.06
anim_power_leg_spread_radians       REAL4 0.3
anim_power_arm_pitch_radians        REAL4 0.35
anim_power_arm_flex_radians         REAL4 0.75
anim_power_jitter_arm_radians       REAL4 0.12
anim_power_head_radians             REAL4 -0.35
anim_power_jitter_head_radians      REAL4 0.07
anim_power_jitter_roll_radians      REAL4 0.07
anim_power_lean_radians             REAL4 -0.18
anim_roar_burst_ticks_float         REAL4 8.0
.ERRNZ POWER_ROAR_BURST_TICKS - 8
anim_roar_stretch                   REAL4 0.32
anim_roar_lift_base_u               REAL4 0.35
anim_roar_lift_u                    REAL4 0.25
anim_roar_arm_radians               REAL4 2.55
anim_roar_arm_pitch_radians         REAL4 0.2
anim_roar_leg_spread_radians        REAL4 0.45
anim_roar_head_radians              REAL4 -0.75
anim_roar_lean_radians              REAL4 -0.3
anim_dance_radians_per_tick         REAL4 0.06545
anim_dance_hop_u                    REAL4 0.32
anim_dance_squash                   REAL4 0.16
anim_dance_arm_base_radians         REAL4 1.3
anim_dance_arm_pump_radians         REAL4 1.25
anim_dance_arm_out_radians          REAL4 0.4
anim_dance_roll_radians             REAL4 0.28
anim_dance_leg_radians              REAL4 0.45
anim_dance_head_radians             REAL4 0.35
anim_jitter_unit_scale              REAL4 0.000030517578
body_stretch_base                   REAL4 1.5

knight_parts                        PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_LEFT_LEG, PALETTE_SILVER_BGRA, TEXTURE_METAL, <-0.16, 0.38, 0.0>, <0.09, 0.38, 0.11>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_RIGHT_LEG, PALETTE_SILVER_BGRA, TEXTURE_METAL, <0.16, 0.38, 0.0>, <0.09, 0.38, 0.11>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_BODY, PALETTE_SILVER_BGRA, TEXTURE_METAL, <0.0, 1.05, 0.0>, <0.28, 0.32, 0.17>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_BODY, PALETTE_BLUE_BGRA, TEXTURE_CLOTH, <0.0, 1.0, 0.175>, <0.17, 0.3, 0.02>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_BODY, PALETTE_YELLOW_BGRA, TEXTURE_LEATHER, <0.0, 0.8, 0.0>, <0.3, 0.06, 0.19>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_HEAD, PALETTE_SILVER_BGRA, TEXTURE_METAL, <0.0, 1.58, 0.0>, <0.16, 0.18, 0.16>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_HEAD, PALETTE_NIGHT_BGRA, TEXTURE_PLAIN, <0.0, 1.6, 0.165>, <0.12, 0.025, 0.01>>
                                    PART <PRIMITIVE_KIND_PYRAMID, ANIM_GROUP_HEAD, PALETTE_RED_BGRA, TEXTURE_CLOTH, <0.0, 1.9, -0.02>, <0.05, 0.14, 0.18>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_LEFT_ARM, PALETTE_SILVER_BGRA, TEXTURE_METAL, <-0.4, 1.1, 0.0>, <0.08, 0.28, 0.08>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_RIGHT_ARM, PALETTE_SILVER_BGRA, TEXTURE_METAL, <0.4, 1.1, 0.0>, <0.08, 0.28, 0.08>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_LEFT_ARM, PALETTE_BLUE_BGRA, TEXTURE_METAL, <-0.54, 1.0, 0.12>, <0.03, 0.32, 0.24>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_LEFT_ARM, PALETTE_YELLOW_BGRA, TEXTURE_GEM, <-0.575, 1.02, 0.12>, <0.01, 0.12, 0.09>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_RIGHT_ARM, PALETTE_WHITE_BGRA, TEXTURE_METAL, <0.42, 0.88, 0.62>, <0.025, 0.06, 0.52>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_RIGHT_ARM, PALETTE_YELLOW_BGRA, TEXTURE_METAL, <0.42, 0.88, 0.1>, <0.15, 0.035, 0.035>>
knight_parts_end                    LABEL DWORD
KNIGHT_PART_COUNT                   equ (knight_parts_end - knight_parts) / SIZEOF PART
knight_pivots                       VEC3 <0.0, 0.0, 0.0>, <0.0, 1.4, 0.0>, <-0.16, 0.76, 0.0>, <0.16, 0.76, 0.0>, <-0.4, 1.36, 0.0>, <0.4, 1.36, 0.0>
.ERRNZ LENGTHOF knight_pivots - ANIM_GROUP_COUNT

rogue_parts                         PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_LEFT_LEG, PALETTE_DUSK_BGRA, TEXTURE_LEATHER, <-0.12, 0.4, 0.0>, <0.07, 0.4, 0.08>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_RIGHT_LEG, PALETTE_DUSK_BGRA, TEXTURE_LEATHER, <0.12, 0.4, 0.0>, <0.07, 0.4, 0.08>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_BODY, PALETTE_GREEN_BGRA, TEXTURE_CLOTH, <0.0, 1.05, 0.0>, <0.2, 0.3, 0.13>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_BODY, PALETTE_RED_BGRA, TEXTURE_LEATHER, <0.0, 0.82, 0.0>, <0.21, 0.045, 0.14>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_BODY, PALETTE_TEAL_BGRA, TEXTURE_CLOTH, <0.0, 0.95, -0.2>, <0.24, 0.45, 0.02>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_HEAD, PALETTE_YELLOW_BGRA, TEXTURE_SKIN, <0.0, 1.52, 0.0>, <0.12, 0.14, 0.12>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_HEAD, PALETTE_RED_BGRA, TEXTURE_CLOTH, <0.0, 1.47, 0.125>, <0.125, 0.04, 0.01>>
                                    PART <PRIMITIVE_KIND_PYRAMID, ANIM_GROUP_HEAD, PALETTE_TEAL_BGRA, TEXTURE_CLOTH, <0.0, 1.68, -0.03>, <0.18, 0.28, 0.18>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_LEFT_ARM, PALETTE_GREEN_BGRA, TEXTURE_CLOTH, <-0.3, 1.08, 0.0>, <0.06, 0.26, 0.06>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_RIGHT_ARM, PALETTE_GREEN_BGRA, TEXTURE_CLOTH, <0.3, 1.08, 0.0>, <0.06, 0.26, 0.06>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_LEFT_ARM, PALETTE_WHITE_BGRA, TEXTURE_METAL, <-0.32, 0.84, 0.28>, <0.02, 0.035, 0.24>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_RIGHT_ARM, PALETTE_WHITE_BGRA, TEXTURE_METAL, <0.32, 0.84, 0.28>, <0.02, 0.035, 0.24>>
rogue_parts_end                     LABEL DWORD
ROGUE_PART_COUNT                    equ (rogue_parts_end - rogue_parts) / SIZEOF PART
rogue_pivots                        VEC3 <0.0, 0.0, 0.0>, <0.0, 1.38, 0.0>, <-0.12, 0.8, 0.0>, <0.12, 0.8, 0.0>, <-0.3, 1.32, 0.0>, <0.3, 1.32, 0.0>
.ERRNZ LENGTHOF rogue_pivots - ANIM_GROUP_COUNT

wizard_parts                        PART <PRIMITIVE_KIND_PYRAMID, ANIM_GROUP_BODY, PALETTE_BLUE_BGRA, TEXTURE_ROBE, <0.0, 0.62, 0.0>, <0.36, 0.62, 0.36>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_BODY, PALETTE_BLUE_BGRA, TEXTURE_ROBE, <0.0, 1.12, 0.0>, <0.2, 0.2, 0.14>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_HEAD, PALETTE_YELLOW_BGRA, TEXTURE_SKIN, <0.0, 1.48, 0.0>, <0.12, 0.13, 0.12>>
                                    PART <PRIMITIVE_KIND_PYRAMID_DOWN, ANIM_GROUP_HEAD, PALETTE_WHITE_BGRA, TEXTURE_CLOTH, <0.0, 1.27, 0.13>, <0.11, 0.16, 0.04>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_HEAD, PALETTE_PLUM_BGRA, TEXTURE_ROBE, <0.0, 1.63, 0.0>, <0.3, 0.025, 0.3>>
                                    PART <PRIMITIVE_KIND_PYRAMID, ANIM_GROUP_HEAD, PALETTE_PLUM_BGRA, TEXTURE_ROBE, <0.0, 2.0, -0.04>, <0.17, 0.37, 0.17>>
                                    PART <PRIMITIVE_KIND_DIAMOND, ANIM_GROUP_HEAD, PALETTE_YELLOW_BGRA, TEXTURE_GEM, <0.0, 1.86, 0.16>, <0.05, 0.05, 0.025>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_LEFT_ARM, PALETTE_BLUE_BGRA, TEXTURE_ROBE, <-0.3, 1.12, 0.0>, <0.07, 0.22, 0.07>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_RIGHT_ARM, PALETTE_BLUE_BGRA, TEXTURE_ROBE, <0.3, 1.12, 0.0>, <0.07, 0.22, 0.07>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_RIGHT_ARM, PALETTE_ORANGE_BGRA, TEXTURE_WOOD, <0.42, 1.0, 0.15>, <0.035, 1.0, 0.035>>
                                    PART <PRIMITIVE_KIND_DIAMOND, ANIM_GROUP_RIGHT_ARM, PALETTE_CYAN_BGRA, TEXTURE_GEM, <0.42, 2.12, 0.15>, <0.13, 0.15, 0.13>>
wizard_parts_end                    LABEL DWORD
WIZARD_PART_COUNT                   equ (wizard_parts_end - wizard_parts) / SIZEOF PART
wizard_pivots                       VEC3 <0.0, 0.0, 0.0>, <0.0, 1.35, 0.0>, <-0.1, 0.6, 0.0>, <0.1, 0.6, 0.0>, <-0.3, 1.32, 0.0>, <0.3, 1.32, 0.0>
.ERRNZ LENGTHOF wizard_pivots - ANIM_GROUP_COUNT

orc_parts                           PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_LEFT_LEG, PALETTE_DUSK_BGRA, TEXTURE_LEATHER, <-0.2, 0.34, 0.0>, <0.13, 0.34, 0.14>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_RIGHT_LEG, PALETTE_DUSK_BGRA, TEXTURE_LEATHER, <0.2, 0.34, 0.0>, <0.13, 0.34, 0.14>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_BODY, PALETTE_GREEN_BGRA, TEXTURE_SKIN, <0.0, 1.0, 0.0>, <0.38, 0.34, 0.24>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_BODY, PALETTE_RED_BGRA, TEXTURE_LEATHER, <0.0, 0.7, 0.0>, <0.4, 0.07, 0.26>>
                                    PART <PRIMITIVE_KIND_PYRAMID, ANIM_GROUP_BODY, PALETTE_SILVER_BGRA, TEXTURE_METAL, <-0.42, 1.42, 0.0>, <0.09, 0.16, 0.09>>
                                    PART <PRIMITIVE_KIND_PYRAMID, ANIM_GROUP_BODY, PALETTE_SILVER_BGRA, TEXTURE_METAL, <0.42, 1.42, 0.0>, <0.09, 0.16, 0.09>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_HEAD, PALETTE_GREEN_BGRA, TEXTURE_SKIN, <0.0, 1.42, 0.08>, <0.15, 0.13, 0.15>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_HEAD, PALETTE_RED_BGRA, TEXTURE_PLAIN, <0.0, 1.46, 0.235>, <0.1, 0.02, 0.01>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_HEAD, PALETTE_WHITE_BGRA, TEXTURE_PLAIN, <-0.08, 1.33, 0.24>, <0.025, 0.05, 0.02>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_HEAD, PALETTE_WHITE_BGRA, TEXTURE_PLAIN, <0.08, 1.33, 0.24>, <0.025, 0.05, 0.02>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_LEFT_ARM, PALETTE_GREEN_BGRA, TEXTURE_SKIN, <-0.52, 1.02, 0.0>, <0.11, 0.3, 0.11>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_RIGHT_ARM, PALETTE_GREEN_BGRA, TEXTURE_SKIN, <0.52, 1.02, 0.0>, <0.11, 0.3, 0.11>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_RIGHT_ARM, PALETTE_ORANGE_BGRA, TEXTURE_WOOD, <0.56, 0.95, 0.45>, <0.045, 0.05, 0.45>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_RIGHT_ARM, PALETTE_SLATE_BGRA, TEXTURE_METAL, <0.56, 1.0, 0.95>, <0.15, 0.15, 0.15>>
orc_parts_end                       LABEL DWORD
ORC_PART_COUNT                      equ (orc_parts_end - orc_parts) / SIZEOF PART
orc_pivots                          VEC3 <0.0, 0.0, 0.0>, <0.0, 1.29, 0.08>, <-0.2, 0.68, 0.0>, <0.2, 0.68, 0.0>, <-0.52, 1.3, 0.0>, <0.52, 1.3, 0.0>
.ERRNZ LENGTHOF orc_pivots - ANIM_GROUP_COUNT

text_character_knight_name          BYTE "KNIGHT", 0
text_character_knight_description   BYTE "BALANCED. BIG SWORD, STURDY SHOTS.", 0
text_character_rogue_name           BYTE "ROGUE", 0
text_character_rogue_description    BYTE "VERY FAST, LONG DASH, MANY CRITS.", 0
text_character_wizard_name          BYTE "WIZARD", 0
text_character_wizard_description   BYTE "HUGE REACH, BLINK DASH, FLOATY SHOTS.", 0
text_character_orc_name             BYTE "ORC", 0
text_character_orc_description      BYTE "SLOW, BUT SMASHES THE BALL HARD.", 0
text_character_stat_speed           BYTE "SPEED", 0
text_character_stat_reach           BYTE "REACH", 0
text_character_stat_power           BYTE "POWER", 0
text_character_stat_dash            BYTE "DASH", 0
text_character_stat_aim             BYTE "AIM", 0

ALIGN 8
characters                          CHARACTER <text_character_knight_name, text_character_knight_description, knight_parts, knight_pivots, KNIGHT_PART_COUNT, PALETTE_SKY_BGRA, 9.0, 21.0, 14, 120, 1.4, 1.6, 6.0, 10, 1.0, 0>
                                    CHARACTER <text_character_rogue_name, text_character_rogue_description, rogue_parts, rogue_pivots, ROGUE_PART_COUNT, PALETTE_LIME_BGRA, 13.0, 33.0, 12, 60, 1.0, 1.75, 8.0, 30, 0.92, 0>
                                    CHARACTER <text_character_wizard_name, text_character_wizard_description, wizard_parts, wizard_pivots, WIZARD_PART_COUNT, PALETTE_CYAN_BGRA, 8.0, 50.0, 10, 180, 2.2, 2.1, 11.0, 15, 1.0, 0>
                                    CHARACTER <text_character_orc_name, text_character_orc_description, orc_parts, orc_pivots, ORC_PART_COUNT, PALETTE_ORANGE_BGRA, 7.5, 25.0, 16, 150, 1.7, 1.15, 4.4, 5, 1.22, 0>
characters_end                      LABEL QWORD
.ERRNZ (characters_end - characters) - CHARACTER_COUNT * SIZEOF CHARACTER
character_stat_bars                 BYTE 3, 3, 3, 2, 3
                                    BYTE 5, 1, 2, 5, 4
                                    BYTE 2, 5, 1, 3, 5
                                    BYTE 1, 4, 5, 2, 1
character_stat_bars_end             LABEL BYTE
.ERRNZ (character_stat_bars_end - character_stat_bars) - CHARACTER_COUNT * CHARACTER_STAT_COUNT
character_stat_texts                QWORD text_character_stat_speed, text_character_stat_reach, text_character_stat_power, text_character_stat_dash, text_character_stat_aim
.ERRNZ LENGTHOF character_stat_texts - CHARACTER_STAT_COUNT

.data?
character_limb_pitch_radians        REAL4 ANIM_GROUP_COUNT DUP (?)
character_limb_roll_radians         REAL4 ANIM_GROUP_COUNT DUP (?)
character_body_lean_radians         REAL4 ?
character_body_roll_radians         REAL4 ?
character_body_spin_radians         REAL4 ?
character_body_lift_u               REAL4 ?
character_anim_outputs_end          LABEL DWORD
character_body_squash               REAL4 ?
character_body_stretch              REAL4 ?
character_body_lean_cos             REAL4 ?
character_body_lean_sin             REAL4 ?
character_body_roll_cos             REAL4 ?
character_body_roll_sin             REAL4 ?
character_facing_x                  REAL4 ?
character_facing_z                  REAL4 ?
character_group_transforms          GROUP_TRANSFORM ANIM_GROUP_COUNT DUP (<>)

.code

character_address_load PROC
    assert_below_unsigned ecx, CHARACTER_COUNT
    imul eax, ecx, SIZEOF CHARACTER
    lea rcx, characters
    add rax, rcx
    ret
character_address_load ENDP

character_anim_compute PROC
    push rbx
    sub rsp, CHARACTER_ANIM_COMPUTE_FRAME_BYTES
    frame_alignment_check 1, CHARACTER_ANIM_COMPUTE_FRAME_BYTES
    mov rbx, rcx
    lea rax, character_limb_pitch_radians
    xorps xmm0, xmm0
    mov ecx, (character_anim_outputs_end - character_limb_pitch_radians) / 4
character_anim_compute_clear:
    movss dword ptr [rax + rcx * 4 - 4], xmm0
    dec ecx
    jnz character_anim_compute_clear
    anim_store_constant character_body_squash, float_one

    cvtsi2ss xmm0, (POSE PTR [rbx]).action_ticks
    movss anim_local(CHARACTER_ANIM_LOCAL_T), xmm0
    mov eax, (POSE PTR [rbx]).action_ticks
    imul eax, eax, HASH_MULTIPLIER
    mov ecx, eax
    sar eax, CHARACTER_JITTER_SHIFT
    cvtsi2ss xmm0, eax
    mulss xmm0, anim_jitter_unit_scale
    movss anim_local(CHARACTER_ANIM_LOCAL_JITTER_A), xmm0
    imul ecx, ecx, HASH_MULTIPLIER
    sar ecx, CHARACTER_JITTER_SHIFT
    cvtsi2ss xmm0, ecx
    mulss xmm0, anim_jitter_unit_scale
    movss anim_local(CHARACTER_ANIM_LOCAL_JITTER_B), xmm0

    mov eax, (POSE PTR [rbx]).action
    assert_below_unsigned eax, POSE_ACTION_COUNT
    cmp eax, POSE_ACTION_DASH
    je character_anim_compute_dash
    cmp eax, POSE_ACTION_CHEER
    je character_anim_compute_cheer
    cmp eax, POSE_ACTION_SLUMP
    je character_anim_compute_slump
    cmp eax, POSE_ACTION_POWER_CHARGE
    je character_anim_compute_power_charge
    cmp eax, POSE_ACTION_POWER_ROAR
    je character_anim_compute_power_roar
    cmp eax, POSE_ACTION_DANCE
    je character_anim_compute_dance

    movss xmm0, (POSE PTR [rbx]).walk_phase_radians
    call math_sin
    movss anim_local(CHARACTER_ANIM_LOCAL_WALK_SIN), xmm0
    movss xmm0, (POSE PTR [rbx]).walk_phase_radians
    addss xmm0, xmm0
    call math_sin
    movss anim_local(CHARACTER_ANIM_LOCAL_WALK_SIN2), xmm0
    movss xmm0, (POSE PTR [rbx]).walk_phase_radians
    addss xmm0, xmm0
    call math_cos
    movss anim_local(CHARACTER_ANIM_LOCAL_WALK_COS2), xmm0
    anim_wave_to_local CHARACTER_ANIM_LOCAL_WAVE, anim_idle_radians_per_tick
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_T)
    mulss xmm0, anim_head_wobble_radians_per_tick
    call math_sin
    mulss xmm0, anim_head_wobble_radians
    movss limb_roll(ANIM_GROUP_HEAD), xmm0

    movss xmm5, (POSE PTR [rbx]).walk_amount
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_WALK_SIN)
    mulss xmm0, anim_move_leg_swing_radians
    mulss xmm0, xmm5
    movss limb_pitch(ANIM_GROUP_LEFT_LEG), xmm0
    xorps xmm0, xmmword ptr float_sign_mask_x4
    movss limb_pitch(ANIM_GROUP_RIGHT_LEG), xmm0
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_WALK_SIN)
    mulss xmm0, anim_move_arm_swing_radians
    mulss xmm0, xmm5
    anim_store_mirrored limb_pitch(ANIM_GROUP_LEFT_ARM), limb_pitch(ANIM_GROUP_RIGHT_ARM)
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_WAVE)
    mulss xmm0, anim_idle_arm_sway_radians
    addss xmm0, anim_idle_arm_out_radians
    movaps xmm1, xmm5
    mulss xmm1, anim_move_arm_out_radians
    addss xmm0, xmm1
    anim_store_mirrored limb_roll(ANIM_GROUP_LEFT_ARM), limb_roll(ANIM_GROUP_RIGHT_ARM)
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_WALK_SIN)
    andps xmm0, xmmword ptr float_abs_mask_x4
    mulss xmm0, anim_move_bounce_u
    mulss xmm0, xmm5
    movss character_body_lift_u, xmm0
    movaps xmm0, xmm5
    mulss xmm0, anim_move_lean_radians
    movss character_body_lean_radians, xmm0
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_WALK_SIN)
    mulss xmm0, anim_move_roll_radians
    mulss xmm0, xmm5
    movss xmm1, anim_local(CHARACTER_ANIM_LOCAL_WAVE)
    mulss xmm1, anim_idle_roll_radians
    addss xmm0, xmm1
    movss character_body_roll_radians, xmm0
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_WALK_COS2)
    mulss xmm0, anim_move_squash
    mulss xmm0, xmm5
    movss xmm1, float_one
    subss xmm1, xmm0
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_WAVE)
    mulss xmm0, anim_idle_breath_squash
    addss xmm1, xmm0
    movss character_body_squash, xmm1
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_WALK_SIN2)
    mulss xmm0, anim_move_head_nod_radians
    mulss xmm0, xmm5
    movss limb_pitch(ANIM_GROUP_HEAD), xmm0

    movss xmm4, (POSE PTR [rbx]).swing_fraction
    comiss xmm4, float_zero
    jbe character_anim_compute_done
    movaps xmm0, xmm4
    mulss xmm0, anim_swing_arm_radians
    subss xmm0, anim_swing_arm_back_radians
    movss limb_pitch(ANIM_GROUP_RIGHT_ARM), xmm0
    movaps xmm0, xmm4
    mulss xmm0, anim_swing_arm_out_radians
    movss limb_roll(ANIM_GROUP_RIGHT_ARM), xmm0
    movaps xmm0, xmm4
    mulss xmm0, anim_swing_other_arm_out_radians
    xorps xmm0, xmmword ptr float_sign_mask_x4
    movss limb_roll(ANIM_GROUP_LEFT_ARM), xmm0
    movaps xmm0, xmm4
    mulss xmm0, anim_swing_stretch
    addss xmm0, character_body_squash
    movss character_body_squash, xmm0
    movaps xmm0, xmm4
    mulss xmm0, anim_swing_lean_radians
    addss xmm0, character_body_lean_radians
    movss character_body_lean_radians, xmm0
    movaps xmm0, xmm4
    mulss xmm0, anim_swing_roll_radians
    addss xmm0, character_body_roll_radians
    movss character_body_roll_radians, xmm0
    movaps xmm0, xmm4
    mulss xmm0, anim_swing_head_radians
    movss limb_pitch(ANIM_GROUP_HEAD), xmm0
    jmp character_anim_compute_done

character_anim_compute_dash:
    anim_store_constant character_body_lean_radians, anim_dash_lean_radians
    anim_store_constant character_body_squash, anim_dash_squash
    anim_store_constant character_body_lift_u, anim_dash_lift_u
    movss xmm0, anim_dash_leg_split_radians
    anim_store_mirrored limb_pitch(ANIM_GROUP_RIGHT_LEG), limb_pitch(ANIM_GROUP_LEFT_LEG)
    anim_store_constant limb_pitch(ANIM_GROUP_LEFT_ARM), anim_dash_arm_back_radians
    anim_store_constant limb_pitch(ANIM_GROUP_RIGHT_ARM), anim_dash_arm_back_radians
    movss xmm0, anim_dash_arm_out_radians
    anim_store_mirrored limb_roll(ANIM_GROUP_LEFT_ARM), limb_roll(ANIM_GROUP_RIGHT_ARM)
    anim_store_constant limb_pitch(ANIM_GROUP_HEAD), anim_dash_head_radians
    jmp character_anim_compute_done

character_anim_compute_cheer:
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_T)
    mulss xmm0, anim_cheer_hop_radians_per_tick
    call math_sin
    andps xmm0, xmmword ptr float_abs_mask_x4
    mulss xmm0, anim_cheer_hop_u
    movss character_body_lift_u, xmm0
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_T)
    mulss xmm0, anim_cheer_squash_radians_per_tick
    call math_cos
    mulss xmm0, anim_cheer_squash
    addss xmm0, float_one
    movss character_body_squash, xmm0
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_T)
    mulss xmm0, anim_cheer_windmill_radians_per_tick
    movss limb_pitch(ANIM_GROUP_LEFT_ARM), xmm0
    addss xmm0, float_pi
    movss limb_pitch(ANIM_GROUP_RIGHT_ARM), xmm0
    movss xmm0, anim_cheer_arm_out_radians
    anim_store_mirrored limb_roll(ANIM_GROUP_LEFT_ARM), limb_roll(ANIM_GROUP_RIGHT_ARM)
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_T)
    mulss xmm0, anim_cheer_squash_radians_per_tick
    call math_sin
    mulss xmm0, anim_cheer_kick_radians
    anim_store_mirrored limb_pitch(ANIM_GROUP_RIGHT_LEG), limb_pitch(ANIM_GROUP_LEFT_LEG)
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_T)
    mulss xmm0, anim_cheer_spin_radians_per_tick
    movss character_body_spin_radians, xmm0
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_T)
    mulss xmm0, anim_cheer_head_radians_per_tick
    call math_sin
    mulss xmm0, anim_cheer_head_radians
    movss limb_roll(ANIM_GROUP_HEAD), xmm0
    jmp character_anim_compute_done

character_anim_compute_slump:
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_T)
    mulss xmm0, anim_slump_sway_radians_per_tick
    call math_sin
    mulss xmm0, anim_slump_lean_sway_radians
    addss xmm0, anim_slump_lean_radians
    movss character_body_lean_radians, xmm0
    anim_store_constant character_body_squash, anim_slump_squash
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_T)
    mulss xmm0, anim_slump_arm_radians_per_tick
    call math_sin
    mulss xmm0, anim_slump_arm_swing_radians
    anim_store_mirrored limb_pitch(ANIM_GROUP_LEFT_ARM), limb_pitch(ANIM_GROUP_RIGHT_ARM)
    anim_store_constant limb_pitch(ANIM_GROUP_HEAD), anim_slump_head_radians
    jmp character_anim_compute_done

character_anim_compute_power_charge:
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_T)
    divss xmm0, anim_power_charge_ticks_float
    minss xmm0, float_one
    movss anim_local(CHARACTER_ANIM_LOCAL_ENVELOPE), xmm0
    movss xmm5, xmm0
    mulss xmm0, anim_power_squash
    movss xmm1, float_one
    subss xmm1, xmm0
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_JITTER_A)
    mulss xmm0, anim_power_jitter_squash
    addss xmm1, xmm0
    movss character_body_squash, xmm1
    movaps xmm0, xmm5
    mulss xmm0, anim_power_leg_spread_radians
    anim_store_mirrored limb_roll(ANIM_GROUP_LEFT_LEG), limb_roll(ANIM_GROUP_RIGHT_LEG)
    anim_store_constant limb_pitch(ANIM_GROUP_LEFT_ARM), anim_power_arm_pitch_radians
    anim_store_constant limb_pitch(ANIM_GROUP_RIGHT_ARM), anim_power_arm_pitch_radians
    movss xmm1, anim_local(CHARACTER_ANIM_LOCAL_JITTER_A)
    mulss xmm1, anim_power_jitter_arm_radians
    movaps xmm0, xmm5
    mulss xmm0, anim_power_arm_flex_radians
    addss xmm0, xmm1
    movss limb_roll(ANIM_GROUP_RIGHT_ARM), xmm0
    movss xmm1, anim_local(CHARACTER_ANIM_LOCAL_JITTER_B)
    mulss xmm1, anim_power_jitter_arm_radians
    movaps xmm0, xmm5
    mulss xmm0, anim_power_arm_flex_radians
    addss xmm0, xmm1
    xorps xmm0, xmmword ptr float_sign_mask_x4
    movss limb_roll(ANIM_GROUP_LEFT_ARM), xmm0
    movss xmm1, anim_local(CHARACTER_ANIM_LOCAL_JITTER_B)
    mulss xmm1, anim_power_jitter_head_radians
    movaps xmm0, xmm5
    mulss xmm0, anim_power_head_radians
    addss xmm0, xmm1
    movss limb_pitch(ANIM_GROUP_HEAD), xmm0
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_JITTER_A)
    mulss xmm0, anim_power_jitter_roll_radians
    mulss xmm0, xmm5
    movss character_body_roll_radians, xmm0
    movaps xmm0, xmm5
    mulss xmm0, anim_power_lean_radians
    movss character_body_lean_radians, xmm0
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_T)
    mulss xmm0, anim_power_hover_radians_per_tick
    call math_sin
    mulss xmm0, anim_power_hover_u
    movss xmm1, anim_local(CHARACTER_ANIM_LOCAL_ENVELOPE)
    mulss xmm1, anim_power_lift_u
    addss xmm0, xmm1
    movss character_body_lift_u, xmm0
    jmp character_anim_compute_done

character_anim_compute_power_roar:
    movss xmm5, anim_local(CHARACTER_ANIM_LOCAL_T)
    divss xmm5, anim_roar_burst_ticks_float
    minss xmm5, float_one
    movaps xmm0, xmm5
    mulss xmm0, anim_roar_stretch
    addss xmm0, float_one
    movss character_body_squash, xmm0
    movaps xmm0, xmm5
    mulss xmm0, anim_roar_lift_u
    addss xmm0, anim_roar_lift_base_u
    movss character_body_lift_u, xmm0
    movaps xmm0, xmm5
    mulss xmm0, anim_roar_arm_radians
    anim_store_mirrored limb_roll(ANIM_GROUP_LEFT_ARM), limb_roll(ANIM_GROUP_RIGHT_ARM)
    anim_store_constant limb_pitch(ANIM_GROUP_LEFT_ARM), anim_roar_arm_pitch_radians
    anim_store_constant limb_pitch(ANIM_GROUP_RIGHT_ARM), anim_roar_arm_pitch_radians
    movaps xmm0, xmm5
    mulss xmm0, anim_roar_leg_spread_radians
    anim_store_mirrored limb_roll(ANIM_GROUP_LEFT_LEG), limb_roll(ANIM_GROUP_RIGHT_LEG)
    movaps xmm0, xmm5
    mulss xmm0, anim_roar_head_radians
    movss limb_pitch(ANIM_GROUP_HEAD), xmm0
    movaps xmm0, xmm5
    mulss xmm0, anim_roar_lean_radians
    movss character_body_lean_radians, xmm0
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_JITTER_A)
    mulss xmm0, anim_power_jitter_roll_radians
    movss character_body_roll_radians, xmm0
    jmp character_anim_compute_done

character_anim_compute_dance:
    anim_wave_to_local CHARACTER_ANIM_LOCAL_BEAT_SIN, anim_dance_radians_per_tick
    andps xmm0, xmmword ptr float_abs_mask_x4
    mulss xmm0, anim_dance_hop_u
    movss character_body_lift_u, xmm0
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_T)
    mulss xmm0, anim_dance_radians_per_tick
    addss xmm0, xmm0
    call math_cos
    mulss xmm0, anim_dance_squash
    movss xmm1, float_one
    subss xmm1, xmm0
    movss character_body_squash, xmm1
    movss xmm1, anim_local(CHARACTER_ANIM_LOCAL_BEAT_SIN)
    mulss xmm1, anim_dance_arm_pump_radians
    movss xmm0, anim_dance_arm_base_radians
    addss xmm0, xmm1
    movss limb_pitch(ANIM_GROUP_LEFT_ARM), xmm0
    movss xmm0, anim_dance_arm_base_radians
    subss xmm0, xmm1
    movss limb_pitch(ANIM_GROUP_RIGHT_ARM), xmm0
    movss xmm0, anim_dance_arm_out_radians
    anim_store_mirrored limb_roll(ANIM_GROUP_LEFT_ARM), limb_roll(ANIM_GROUP_RIGHT_ARM)
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_BEAT_SIN)
    mulss xmm0, anim_dance_roll_radians
    movss character_body_roll_radians, xmm0
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_BEAT_SIN)
    mulss xmm0, anim_dance_leg_radians
    anim_store_mirrored limb_pitch(ANIM_GROUP_RIGHT_LEG), limb_pitch(ANIM_GROUP_LEFT_LEG)
    movss xmm0, anim_local(CHARACTER_ANIM_LOCAL_T)
    mulss xmm0, anim_dance_radians_per_tick
    mulss xmm0, float_half
    call math_sin
    mulss xmm0, anim_dance_head_radians
    movss limb_roll(ANIM_GROUP_HEAD), xmm0

character_anim_compute_done:
    add rsp, CHARACTER_ANIM_COMPUTE_FRAME_BYTES
    pop rbx
    ret
character_anim_compute ENDP

character_transforms_compute PROC
    push rbx
    push rsi
    push rdi
    sub rsp, CHARACTER_TRANSFORMS_FRAME_BYTES
    frame_alignment_check 3, CHARACTER_TRANSFORMS_FRAME_BYTES
    mov rbx, rcx
    mov rdi, (CHARACTER PTR [rdx]).pivots
    xor esi, esi
character_transforms_compute_group:
    lea rax, character_limb_pitch_radians
    movss xmm0, dword ptr [rax + rsi * 4]
    movss dword ptr [rsp + CHARACTER_TRANSFORMS_LOCAL_ANGLE], xmm0
    call math_cos
    imul eax, esi, SIZEOF GROUP_TRANSFORM
    lea rcx, character_group_transforms
    movss (GROUP_TRANSFORM PTR [rcx + rax]).pitch_cos, xmm0
    movss xmm0, dword ptr [rsp + CHARACTER_TRANSFORMS_LOCAL_ANGLE]
    call math_sin
    imul eax, esi, SIZEOF GROUP_TRANSFORM
    lea rcx, character_group_transforms
    movss (GROUP_TRANSFORM PTR [rcx + rax]).pitch_sin, xmm0
    lea rax, character_limb_roll_radians
    movss xmm0, dword ptr [rax + rsi * 4]
    movss dword ptr [rsp + CHARACTER_TRANSFORMS_LOCAL_ANGLE], xmm0
    call math_cos
    imul eax, esi, SIZEOF GROUP_TRANSFORM
    lea rcx, character_group_transforms
    movss (GROUP_TRANSFORM PTR [rcx + rax]).roll_cos, xmm0
    movss xmm0, dword ptr [rsp + CHARACTER_TRANSFORMS_LOCAL_ANGLE]
    call math_sin
    imul eax, esi, SIZEOF GROUP_TRANSFORM
    lea rcx, character_group_transforms
    add rcx, rax
    movss (GROUP_TRANSFORM PTR [rcx]).roll_sin, xmm0
    movss xmm0, (VEC3 PTR [rdi]).x
    movss (GROUP_TRANSFORM PTR [rcx]).pivot.x, xmm0
    movss xmm0, (VEC3 PTR [rdi]).y
    movss (GROUP_TRANSFORM PTR [rcx]).pivot.y, xmm0
    movss xmm0, (VEC3 PTR [rdi]).z
    movss (GROUP_TRANSFORM PTR [rcx]).pivot.z, xmm0
    add rdi, SIZEOF VEC3
    inc esi
    cmp esi, ANIM_GROUP_COUNT
    jb character_transforms_compute_group

    movss xmm0, body_stretch_base
    movss xmm1, character_body_squash
    mulss xmm1, float_half
    subss xmm0, xmm1
    movss character_body_stretch, xmm0
    movss xmm0, character_body_lean_radians
    call math_cos
    movss character_body_lean_cos, xmm0
    movss xmm0, character_body_lean_radians
    call math_sin
    movss character_body_lean_sin, xmm0
    movss xmm0, character_body_roll_radians
    call math_cos
    movss character_body_roll_cos, xmm0
    movss xmm0, character_body_roll_radians
    call math_sin
    movss character_body_roll_sin, xmm0
    movss xmm0, (POSE PTR [rbx]).spin_radians
    addss xmm0, character_body_spin_radians
    movss dword ptr [rsp + CHARACTER_TRANSFORMS_LOCAL_ANGLE], xmm0
    call math_cos
    movss dword ptr [rsp + CHARACTER_TRANSFORMS_LOCAL_ANGLE + 4], xmm0
    movss xmm0, dword ptr [rsp + CHARACTER_TRANSFORMS_LOCAL_ANGLE]
    call math_sin
    movss xmm1, dword ptr [rsp + CHARACTER_TRANSFORMS_LOCAL_ANGLE + 4]
    movss xmm2, (POSE PTR [rbx]).facing_x
    movss xmm3, (POSE PTR [rbx]).facing_z
    movaps xmm4, xmm2
    mulss xmm4, xmm1
    movaps xmm5, xmm3
    mulss xmm5, xmm0
    subss xmm4, xmm5
    movss character_facing_x, xmm4
    mulss xmm2, xmm0
    mulss xmm3, xmm1
    addss xmm2, xmm3
    movss character_facing_z, xmm2
    add rsp, CHARACTER_TRANSFORMS_FRAME_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
character_transforms_compute ENDP

character_draw PROC
    push rbx
    push rsi
    push rdi
    push r12
    push r13
    push r14
    push r15
    sub rsp, CHARACTER_DRAW_FRAME_BYTES
    frame_alignment_check CHARACTER_DRAW_PUSHED_REGISTER_COUNT, CHARACTER_DRAW_FRAME_BYTES
    mov rbx, rcx
    assert_below_unsigned (POSE PTR [rbx]).render_mode, POSE_RENDER_COUNT
    mov ecx, (POSE PTR [rbx]).character_index
    call character_address_load
    mov r12, rax
    mov rcx, rbx
    call character_anim_compute
    mov rcx, rbx
    mov rdx, r12
    call character_transforms_compute

    mov rsi, (CHARACTER PTR [r12]).parts
    mov r13d, (CHARACTER PTR [r12]).part_count
character_draw_part:
    mov eax, (PART PTR [rsi]).kind
    assert_below_unsigned eax, PRIMITIVE_KIND_COUNT
    imul eax, eax, SIZEOF PRIMITIVE
    lea r14, primitives
    add r14, rax
    mov eax, (PART PTR [rsi]).anim_group
    assert_below_unsigned eax, ANIM_GROUP_COUNT
    imul eax, eax, SIZEOF GROUP_TRANSFORM
    lea r15, character_group_transforms
    add r15, rax
    mov rdi, (PRIMITIVE PTR [r14]).unit_vertices
    mov ecx, (PRIMITIVE PTR [r14]).vertex_count
    lea rdx, mesh_scratch_vertices
character_draw_vertex:
    movss xmm0, (VEC3 PTR [rdi]).x
    mulss xmm0, (PART PTR [rsi]).half.x
    addss xmm0, (PART PTR [rsi]).center.x
    subss xmm0, (GROUP_TRANSFORM PTR [r15]).pivot.x
    movss xmm1, (VEC3 PTR [rdi]).y
    mulss xmm1, (PART PTR [rsi]).half.y
    addss xmm1, (PART PTR [rsi]).center.y
    subss xmm1, (GROUP_TRANSFORM PTR [r15]).pivot.y
    movss xmm2, (VEC3 PTR [rdi]).z
    mulss xmm2, (PART PTR [rsi]).half.z
    addss xmm2, (PART PTR [rsi]).center.z
    subss xmm2, (GROUP_TRANSFORM PTR [r15]).pivot.z
    movaps xmm3, xmm2
    mulss xmm3, (GROUP_TRANSFORM PTR [r15]).pitch_cos
    movaps xmm4, xmm1
    mulss xmm4, (GROUP_TRANSFORM PTR [r15]).pitch_sin
    subss xmm3, xmm4
    mulss xmm1, (GROUP_TRANSFORM PTR [r15]).pitch_cos
    mulss xmm2, (GROUP_TRANSFORM PTR [r15]).pitch_sin
    addss xmm1, xmm2
    movaps xmm2, xmm3
    movaps xmm3, xmm0
    mulss xmm3, (GROUP_TRANSFORM PTR [r15]).roll_cos
    movaps xmm4, xmm1
    mulss xmm4, (GROUP_TRANSFORM PTR [r15]).roll_sin
    subss xmm3, xmm4
    mulss xmm0, (GROUP_TRANSFORM PTR [r15]).roll_sin
    mulss xmm1, (GROUP_TRANSFORM PTR [r15]).roll_cos
    addss xmm1, xmm0
    movaps xmm0, xmm3
    addss xmm0, (GROUP_TRANSFORM PTR [r15]).pivot.x
    addss xmm1, (GROUP_TRANSFORM PTR [r15]).pivot.y
    addss xmm2, (GROUP_TRANSFORM PTR [r15]).pivot.z
    mulss xmm0, character_body_stretch
    mulss xmm1, character_body_squash
    mulss xmm2, character_body_stretch
    movaps xmm3, xmm2
    mulss xmm3, character_body_lean_cos
    movaps xmm4, xmm1
    mulss xmm4, character_body_lean_sin
    addss xmm3, xmm4
    mulss xmm1, character_body_lean_cos
    mulss xmm2, character_body_lean_sin
    subss xmm1, xmm2
    movaps xmm2, xmm3
    movaps xmm3, xmm0
    mulss xmm3, character_body_roll_cos
    movaps xmm4, xmm1
    mulss xmm4, character_body_roll_sin
    subss xmm3, xmm4
    mulss xmm1, character_body_roll_cos
    mulss xmm0, character_body_roll_sin
    addss xmm1, xmm0
    movaps xmm0, xmm3
    movss xmm5, (CHARACTER PTR [r12]).model_scale
    mulss xmm0, xmm5
    mulss xmm1, xmm5
    mulss xmm2, xmm5
    movaps xmm3, xmm0
    mulss xmm3, character_facing_z
    movaps xmm4, xmm2
    mulss xmm4, character_facing_x
    addss xmm3, xmm4
    addss xmm3, (POSE PTR [rbx]).pos.x
    movss (VEC3 PTR [rdx]).x, xmm3
    addss xmm1, character_body_lift_u
    addss xmm1, (POSE PTR [rbx]).pos.y
    movss (VEC3 PTR [rdx]).y, xmm1
    mulss xmm2, character_facing_z
    mulss xmm0, character_facing_x
    subss xmm2, xmm0
    addss xmm2, (POSE PTR [rbx]).pos.z
    movss (VEC3 PTR [rdx]).z, xmm2
    add rdi, SIZEOF VEC3
    add rdx, SIZEOF VEC3
    dec ecx
    jnz character_draw_vertex

    mov eax, (POSE PTR [rbx]).color_override_bgra
    cmp eax, COLOR_NONE_BGRA
    jne character_draw_part_color_ready
    mov eax, (PART PTR [rsi]).color_bgra
character_draw_part_color_ready:
    cmp (POSE PTR [rbx]).render_mode, POSE_RENDER_WIREFRAME
    je character_draw_part_wireframe
    mov edi, eax
    lea rcx, mesh_scratch_vertices
    mov edx, (PRIMITIVE PTR [r14]).vertex_count
    call mesh_project
    assert_above_zero_signed (PRIMITIVE PTR [r14]).face_count
    mov eax, (PART PTR [rsi]).texture_index
    assert_below_unsigned eax, TEXTURE_COUNT
    imul eax, eax, TEXTURE_TEXEL_COUNT
    lea rcx, textures
    add rax, rcx
    mov qword ptr [rsp + CALL_ARG5], rax
    mov dword ptr [rsp + CALL_ARG6], DEPTH_MODE_TEST_AND_WRITE
    lea rcx, mesh_scratch_vertices
    mov rdx, (PRIMITIVE PTR [r14]).faces
    mov r8d, (PRIMITIVE PTR [r14]).face_count
    mov r9d, edi
    call mesh_faces_draw
    mov ecx, edi
    mov edx, MESH_OUTLINE_LEVEL
    call color_scale
    mov r8d, eax
    mov rcx, (PRIMITIVE PTR [r14]).edges
    mov edx, (PRIMITIVE PTR [r14]).edge_count
    call mesh_edges_depth_draw
    jmp character_draw_part_next
character_draw_part_wireframe:
    mov dword ptr [rsp + CALL_ARG5], eax
    lea rcx, mesh_scratch_vertices
    mov edx, (PRIMITIVE PTR [r14]).vertex_count
    mov r8, (PRIMITIVE PTR [r14]).edges
    mov r9d, (PRIMITIVE PTR [r14]).edge_count
    call mesh_draw
character_draw_part_next:
    add rsi, SIZEOF PART
    dec r13d
    jnz character_draw_part

    add rsp, CHARACTER_DRAW_FRAME_BYTES
    pop r15
    pop r14
    pop r13
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
character_draw ENDP
