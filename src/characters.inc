ANIM_GROUP_NONE                     equ 0
ANIM_GROUP_BODY                     equ 1
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

COLOR_PART_STEEL_BGRA               equ 00C0D0E0h
COLOR_PART_BLUE_BGRA                equ 004080FFh
COLOR_PART_RED_BGRA                 equ 00FF4040h
COLOR_PART_CYAN_BGRA                equ 0040E0FFh
COLOR_PART_WHITE_BGRA               equ 00F0F0F0h
COLOR_PART_GOLD_BGRA                equ 00FFD040h
COLOR_PART_GREEN_BGRA               equ 0040D060h
COLOR_PART_DARK_GREEN_BGRA          equ 00208848h
COLOR_PART_SKIN_BGRA                equ 00F0C090h
COLOR_PART_PURPLE_BGRA              equ 00B060FFh
COLOR_PART_BROWN_BGRA               equ 00A07040h
COLOR_PART_ORC_SKIN_BGRA            equ 0070C040h
COLOR_PART_GRAY_BGRA                equ 009898A0h

PART STRUCT
    kind                            DWORD ?
    anim_group                      DWORD ?
    color_bgra                      DWORD ?
    part_padding                    DWORD ?
    center                          VEC3 <>
    half                            VEC3 <>
PART ENDS

CHARACTER STRUCT
    name_text                       QWORD ?
    description_text                QWORD ?
    parts                           QWORD ?
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

.const
character_anim_stride_u             REAL4 0.28
character_anim_lift_u               REAL4 0.1
character_anim_arm_swing_u          REAL4 0.22
character_anim_bob_u                REAL4 0.05
character_anim_swing_reach_u        REAL4 0.55
character_anim_swing_lift_u         REAL4 0.25

knight_parts                        PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_LEFT_LEG, COLOR_PART_STEEL_BGRA, 0, <-0.16, 0.38, 0.0>, <0.09, 0.38, 0.11>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_RIGHT_LEG, COLOR_PART_STEEL_BGRA, 0, <0.16, 0.38, 0.0>, <0.09, 0.38, 0.11>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_BODY, COLOR_PART_STEEL_BGRA, 0, <0.0, 1.05, 0.0>, <0.28, 0.32, 0.17>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_BODY, COLOR_PART_BLUE_BGRA, 0, <0.0, 0.8, 0.0>, <0.3, 0.07, 0.19>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_BODY, COLOR_PART_STEEL_BGRA, 0, <0.0, 1.58, 0.0>, <0.16, 0.18, 0.16>>
                                    PART <PRIMITIVE_KIND_PYRAMID, ANIM_GROUP_BODY, COLOR_PART_RED_BGRA, 0, <0.0, 1.88, -0.02>, <0.04, 0.12, 0.16>>
                                    PART <PRIMITIVE_KIND_LINE, ANIM_GROUP_BODY, COLOR_PART_CYAN_BGRA, 0, <0.0, 1.6, 0.17>, <0.12, 0.0, 0.0>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_LEFT_ARM, COLOR_PART_STEEL_BGRA, 0, <-0.4, 1.1, 0.0>, <0.08, 0.28, 0.08>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_RIGHT_ARM, COLOR_PART_STEEL_BGRA, 0, <0.4, 1.1, 0.0>, <0.08, 0.28, 0.08>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_LEFT_ARM, COLOR_PART_BLUE_BGRA, 0, <-0.54, 1.0, 0.12>, <0.03, 0.32, 0.24>>
                                    PART <PRIMITIVE_KIND_LINE, ANIM_GROUP_RIGHT_ARM, COLOR_PART_WHITE_BGRA, 0, <0.42, 0.95, 0.55>, <0.0, 0.05, 0.5>>
                                    PART <PRIMITIVE_KIND_LINE, ANIM_GROUP_RIGHT_ARM, COLOR_PART_GOLD_BGRA, 0, <0.42, 0.9, 0.08>, <0.14, 0.0, 0.0>>
knight_parts_end                    LABEL DWORD
KNIGHT_PART_COUNT                   equ (knight_parts_end - knight_parts) / SIZEOF PART

rogue_parts                         PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_LEFT_LEG, COLOR_PART_DARK_GREEN_BGRA, 0, <-0.12, 0.4, 0.0>, <0.07, 0.4, 0.08>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_RIGHT_LEG, COLOR_PART_DARK_GREEN_BGRA, 0, <0.12, 0.4, 0.0>, <0.07, 0.4, 0.08>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_BODY, COLOR_PART_GREEN_BGRA, 0, <0.0, 1.05, 0.0>, <0.2, 0.3, 0.13>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_BODY, COLOR_PART_SKIN_BGRA, 0, <0.0, 1.52, 0.0>, <0.12, 0.14, 0.12>>
                                    PART <PRIMITIVE_KIND_PYRAMID, ANIM_GROUP_BODY, COLOR_PART_DARK_GREEN_BGRA, 0, <0.0, 1.66, -0.03>, <0.17, 0.26, 0.17>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_BODY, COLOR_PART_DARK_GREEN_BGRA, 0, <0.0, 0.95, -0.2>, <0.24, 0.45, 0.02>>
                                    PART <PRIMITIVE_KIND_LINE, ANIM_GROUP_BODY, COLOR_PART_RED_BGRA, 0, <0.0, 1.52, 0.13>, <0.08, 0.0, 0.0>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_LEFT_ARM, COLOR_PART_GREEN_BGRA, 0, <-0.3, 1.08, 0.0>, <0.06, 0.26, 0.06>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_RIGHT_ARM, COLOR_PART_GREEN_BGRA, 0, <0.3, 1.08, 0.0>, <0.06, 0.26, 0.06>>
                                    PART <PRIMITIVE_KIND_LINE, ANIM_GROUP_LEFT_ARM, COLOR_PART_WHITE_BGRA, 0, <-0.32, 0.84, 0.26>, <0.0, 0.02, 0.22>>
                                    PART <PRIMITIVE_KIND_LINE, ANIM_GROUP_RIGHT_ARM, COLOR_PART_WHITE_BGRA, 0, <0.32, 0.84, 0.26>, <0.0, 0.02, 0.22>>
rogue_parts_end                     LABEL DWORD
ROGUE_PART_COUNT                    equ (rogue_parts_end - rogue_parts) / SIZEOF PART

wizard_parts                        PART <PRIMITIVE_KIND_PYRAMID, ANIM_GROUP_BODY, COLOR_PART_PURPLE_BGRA, 0, <0.0, 0.62, 0.0>, <0.36, 0.62, 0.36>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_BODY, COLOR_PART_PURPLE_BGRA, 0, <0.0, 1.12, 0.0>, <0.2, 0.2, 0.14>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_BODY, COLOR_PART_SKIN_BGRA, 0, <0.0, 1.48, 0.0>, <0.12, 0.13, 0.12>>
                                    PART <PRIMITIVE_KIND_PYRAMID_DOWN, ANIM_GROUP_BODY, COLOR_PART_WHITE_BGRA, 0, <0.0, 1.28, 0.13>, <0.1, 0.14, 0.03>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_BODY, COLOR_PART_PURPLE_BGRA, 0, <0.0, 1.63, 0.0>, <0.3, 0.02, 0.3>>
                                    PART <PRIMITIVE_KIND_PYRAMID, ANIM_GROUP_BODY, COLOR_PART_PURPLE_BGRA, 0, <0.0, 1.99, -0.04>, <0.17, 0.36, 0.17>>
                                    PART <PRIMITIVE_KIND_DIAMOND, ANIM_GROUP_BODY, COLOR_PART_GOLD_BGRA, 0, <0.0, 1.86, 0.15>, <0.05, 0.05, 0.02>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_LEFT_ARM, COLOR_PART_PURPLE_BGRA, 0, <-0.3, 1.12, 0.0>, <0.07, 0.22, 0.07>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_RIGHT_ARM, COLOR_PART_PURPLE_BGRA, 0, <0.3, 1.12, 0.0>, <0.07, 0.22, 0.07>>
                                    PART <PRIMITIVE_KIND_LINE, ANIM_GROUP_RIGHT_ARM, COLOR_PART_BROWN_BGRA, 0, <0.42, 1.0, 0.15>, <0.0, 1.0, 0.0>>
                                    PART <PRIMITIVE_KIND_DIAMOND, ANIM_GROUP_RIGHT_ARM, COLOR_PART_CYAN_BGRA, 0, <0.42, 2.12, 0.15>, <0.12, 0.14, 0.12>>
wizard_parts_end                    LABEL DWORD
WIZARD_PART_COUNT                   equ (wizard_parts_end - wizard_parts) / SIZEOF PART

orc_parts                           PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_LEFT_LEG, COLOR_PART_BROWN_BGRA, 0, <-0.2, 0.34, 0.0>, <0.13, 0.34, 0.14>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_RIGHT_LEG, COLOR_PART_BROWN_BGRA, 0, <0.2, 0.34, 0.0>, <0.13, 0.34, 0.14>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_BODY, COLOR_PART_ORC_SKIN_BGRA, 0, <0.0, 1.0, 0.0>, <0.38, 0.34, 0.24>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_BODY, COLOR_PART_BROWN_BGRA, 0, <0.0, 0.7, 0.0>, <0.4, 0.07, 0.26>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_BODY, COLOR_PART_ORC_SKIN_BGRA, 0, <0.0, 1.42, 0.08>, <0.15, 0.13, 0.15>>
                                    PART <PRIMITIVE_KIND_LINE, ANIM_GROUP_BODY, COLOR_PART_WHITE_BGRA, 0, <-0.08, 1.33, 0.24>, <0.0, 0.06, 0.0>>
                                    PART <PRIMITIVE_KIND_LINE, ANIM_GROUP_BODY, COLOR_PART_WHITE_BGRA, 0, <0.08, 1.33, 0.24>, <0.0, 0.06, 0.0>>
                                    PART <PRIMITIVE_KIND_PYRAMID, ANIM_GROUP_BODY, COLOR_PART_GRAY_BGRA, 0, <-0.42, 1.4, 0.0>, <0.08, 0.14, 0.08>>
                                    PART <PRIMITIVE_KIND_PYRAMID, ANIM_GROUP_BODY, COLOR_PART_GRAY_BGRA, 0, <0.42, 1.4, 0.0>, <0.08, 0.14, 0.08>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_LEFT_ARM, COLOR_PART_ORC_SKIN_BGRA, 0, <-0.52, 1.02, 0.0>, <0.11, 0.3, 0.11>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_RIGHT_ARM, COLOR_PART_ORC_SKIN_BGRA, 0, <0.52, 1.02, 0.0>, <0.11, 0.3, 0.11>>
                                    PART <PRIMITIVE_KIND_LINE, ANIM_GROUP_RIGHT_ARM, COLOR_PART_BROWN_BGRA, 0, <0.56, 0.95, 0.45>, <0.0, 0.05, 0.45>>
                                    PART <PRIMITIVE_KIND_BOX, ANIM_GROUP_RIGHT_ARM, COLOR_PART_GRAY_BGRA, 0, <0.56, 1.0, 0.95>, <0.13, 0.13, 0.13>>
orc_parts_end                       LABEL DWORD
ORC_PART_COUNT                      equ (orc_parts_end - orc_parts) / SIZEOF PART

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
characters                          CHARACTER <text_character_knight_name, text_character_knight_description, knight_parts, KNIGHT_PART_COUNT, 004080FFh, 5.5, 13.0, 14, 120, 1.35, 1.25, 3.0, 10, 1.0, 0>
                                    CHARACTER <text_character_rogue_name, text_character_rogue_description, rogue_parts, ROGUE_PART_COUNT, 0040D060h, 8.5, 22.0, 12, 60, 0.95, 1.45, 4.0, 30, 0.92, 0>
                                    CHARACTER <text_character_wizard_name, text_character_wizard_description, wizard_parts, WIZARD_PART_COUNT, 00B060FFh, 5.0, 34.0, 10, 180, 2.1, 1.75, 5.5, 15, 1.0, 0>
                                    CHARACTER <text_character_orc_name, text_character_orc_description, orc_parts, ORC_PART_COUNT, 00FF6030h, 4.2, 16.0, 16, 150, 1.6, 0.85, 1.8, 5, 1.22, 0>
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
character_group_offsets             VEC3 ANIM_GROUP_COUNT DUP (<>)
character_walk_sin                  REAL4 ?
character_walk_cos                  REAL4 ?

.code

character_address_load PROC
    assert_below_unsigned ecx, CHARACTER_COUNT
    imul eax, ecx, SIZEOF CHARACTER
    lea rcx, characters
    add rax, rcx
    ret
character_address_load ENDP

character_draw PROC
    push rbx
    push rsi
    push rdi
    push r12
    push r13
    push r14
    push r15
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 7, FRAME_6_ARGS_ODD_PUSHES_BYTES
    mov rbx, rcx
    mov ecx, (POSE PTR [rbx]).character_index
    call character_address_load
    mov r12, rax

    movss xmm0, (POSE PTR [rbx]).walk_phase_radians
    call math_sin
    movss character_walk_sin, xmm0
    movss xmm0, (POSE PTR [rbx]).walk_phase_radians
    call math_cos
    movss character_walk_cos, xmm0

    lea rdi, character_group_offsets
    xorps xmm0, xmm0
    mov ecx, ANIM_GROUP_COUNT * 3
character_draw_offsets_clear:
    movss dword ptr [rdi + rcx * 4 - 4], xmm0
    dec ecx
    jnz character_draw_offsets_clear

    movss xmm1, character_walk_sin
    andps xmm1, xmmword ptr float_abs_mask_x4
    mulss xmm1, character_anim_bob_u
    mulss xmm1, (POSE PTR [rbx]).walk_amount
    movss dword ptr [rdi + ANIM_GROUP_BODY * SIZEOF VEC3 + VEC3.y], xmm1
    movss dword ptr [rdi + ANIM_GROUP_LEFT_ARM * SIZEOF VEC3 + VEC3.y], xmm1

    movss xmm2, character_walk_cos
    maxss xmm2, float_zero
    mulss xmm2, character_anim_lift_u
    mulss xmm2, (POSE PTR [rbx]).walk_amount
    movss dword ptr [rdi + ANIM_GROUP_LEFT_LEG * SIZEOF VEC3 + VEC3.y], xmm2
    movss xmm3, character_walk_sin
    mulss xmm3, character_anim_stride_u
    mulss xmm3, (POSE PTR [rbx]).walk_amount
    movss dword ptr [rdi + ANIM_GROUP_LEFT_LEG * SIZEOF VEC3 + VEC3.z], xmm3
    movss xmm2, character_walk_cos
    xorps xmm2, xmmword ptr float_sign_mask_x4
    maxss xmm2, float_zero
    mulss xmm2, character_anim_lift_u
    mulss xmm2, (POSE PTR [rbx]).walk_amount
    movss dword ptr [rdi + ANIM_GROUP_RIGHT_LEG * SIZEOF VEC3 + VEC3.y], xmm2
    xorps xmm3, xmmword ptr float_sign_mask_x4
    movss dword ptr [rdi + ANIM_GROUP_RIGHT_LEG * SIZEOF VEC3 + VEC3.z], xmm3

    movss xmm3, character_walk_sin
    mulss xmm3, character_anim_arm_swing_u
    mulss xmm3, (POSE PTR [rbx]).walk_amount
    movaps xmm4, xmm3
    xorps xmm4, xmmword ptr float_sign_mask_x4
    movss dword ptr [rdi + ANIM_GROUP_LEFT_ARM * SIZEOF VEC3 + VEC3.z], xmm4
    movss xmm4, (POSE PTR [rbx]).swing_fraction
    mulss xmm4, character_anim_swing_reach_u
    addss xmm3, xmm4
    movss dword ptr [rdi + ANIM_GROUP_RIGHT_ARM * SIZEOF VEC3 + VEC3.z], xmm3
    movss xmm4, (POSE PTR [rbx]).swing_fraction
    mulss xmm4, character_anim_swing_lift_u
    addss xmm4, xmm1
    movss dword ptr [rdi + ANIM_GROUP_RIGHT_ARM * SIZEOF VEC3 + VEC3.y], xmm4

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
    imul eax, eax, SIZEOF VEC3
    lea r15, character_group_offsets
    add r15, rax
    mov rdi, (PRIMITIVE PTR [r14]).unit_vertices
    mov ecx, (PRIMITIVE PTR [r14]).vertex_count
    lea rdx, mesh_scratch_vertices
character_draw_vertex:
    movss xmm0, (VEC3 PTR [rdi]).x
    mulss xmm0, (PART PTR [rsi]).half.x
    addss xmm0, (PART PTR [rsi]).center.x
    addss xmm0, (VEC3 PTR [r15]).x
    mulss xmm0, (CHARACTER PTR [r12]).model_scale
    movss xmm1, (VEC3 PTR [rdi]).y
    mulss xmm1, (PART PTR [rsi]).half.y
    addss xmm1, (PART PTR [rsi]).center.y
    addss xmm1, (VEC3 PTR [r15]).y
    mulss xmm1, (CHARACTER PTR [r12]).model_scale
    movss xmm2, (VEC3 PTR [rdi]).z
    mulss xmm2, (PART PTR [rsi]).half.z
    addss xmm2, (PART PTR [rsi]).center.z
    addss xmm2, (VEC3 PTR [r15]).z
    mulss xmm2, (CHARACTER PTR [r12]).model_scale
    movaps xmm3, xmm0
    mulss xmm3, (POSE PTR [rbx]).facing_z
    movaps xmm4, xmm2
    mulss xmm4, (POSE PTR [rbx]).facing_x
    addss xmm3, xmm4
    addss xmm3, (POSE PTR [rbx]).pos.x
    movss (VEC3 PTR [rdx]).x, xmm3
    addss xmm1, (POSE PTR [rbx]).pos.y
    movss (VEC3 PTR [rdx]).y, xmm1
    mulss xmm2, (POSE PTR [rbx]).facing_z
    mulss xmm0, (POSE PTR [rbx]).facing_x
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
    mov dword ptr [rsp + CALL_ARG5], eax
    lea rcx, mesh_scratch_vertices
    mov edx, (PRIMITIVE PTR [r14]).vertex_count
    mov r8, (PRIMITIVE PTR [r14]).edges
    mov r9d, (PRIMITIVE PTR [r14]).edge_count
    call mesh_draw
    add rsi, SIZEOF PART
    dec r13d
    jnz character_draw_part

    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop r15
    pop r14
    pop r13
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
character_draw ENDP
