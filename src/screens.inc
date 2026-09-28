SELECT_TITLE_TOP_PX                 equ 12
SELECT_NAME_TOP_PX                  equ 150
SELECT_STATS_TOP_PX                 equ 162
SELECT_STATS_ROW_PX                 equ 9
SELECT_STAT_LABEL_LEFT_FROM_CENTER_PX equ 36
SELECT_STAT_BAR_LEFT_FROM_CENTER_PX equ 2
SELECT_STAT_BAR_SIZE_PX             equ 5
SELECT_STAT_BAR_PITCH_PX            equ 6
SELECT_DESCRIPTION_TOP_PX           equ 212
SELECT_PROMPT_TOP_PX                equ 226
SELECT_UNSELECTED_LEVEL             equ 110
SELECT_IDLE_TICKS_OFFSET_PER_CHARACTER equ 37
COLOR_SELECT_BAR_EMPTY_BGRA         equ PALETTE_DUSK_BGRA
COLOR_SELECT_RING_BGRA              equ PALETTE_SLATE_BGRA
HUD_MULTIPLIER_TOP_PX               equ 38
HUD_COMBO_TOP_PX                    equ 66
HUD_LABEL_TOP_PX                    equ 34
HUD_SCORE_CENTER_FROM_SCREEN_CENTER_PX equ 44
HUD_DASH_LEFT_PX                    equ 8
HUD_DASH_LABEL_TOP_PX               equ 221
HUD_DASH_BAR_TOP_PX                 equ 230
HUD_DASH_BAR_WIDTH_PX               equ 48
HUD_DASH_BAR_HEIGHT_PX              equ 4
COLOR_HUD_BAR_EMPTY_BGRA            equ PALETTE_DUSK_BGRA
COMBO_POPUP_MIN                     equ 3
SERVE_REEL_BOX_WIDTH_PX             equ 56
SERVE_REEL_BOX_HEIGHT_PX            equ 30
SERVE_REEL_BOX_LEFT_PX              equ (SCREEN_WIDTH_PX - SERVE_REEL_BOX_WIDTH_PX) / 2
SERVE_REEL_BOX_TOP_PX               equ 40
SERVE_REEL_BOX_BORDER_PX            equ 2
SERVE_REEL_SYMBOL_TOP_PX            equ SERVE_REEL_BOX_TOP_PX + (SERVE_REEL_BOX_HEIGHT_PX - FONT_TEXT_ROWS * TEXT_SCALE_HUGE) / 2
SERVE_REEL_LABEL_TOP_PX             equ SERVE_REEL_BOX_TOP_PX + SERVE_REEL_BOX_HEIGHT_PX + 4
OVER_TITLE_TOP_PX                   equ 70
OVER_STATS_TOP_PX                   equ 118
OVER_STATS_LINE_PX                  equ 12
OVER_PROMPT_TOP_PX                  equ 170
OVER_PROMPT_BLINK_BIT_MASK          equ 32
OVER_FIREWORK_PERIOD_TICKS          equ 16
OVER_COIN_PERIOD_TICKS              equ 2
.ERRNZ OVER_FIREWORK_PERIOD_TICKS AND (OVER_FIREWORK_PERIOD_TICKS - 1)
.ERRNZ OVER_COIN_PERIOD_TICKS AND (OVER_COIN_PERIOD_TICKS - 1)

.const
select_first_x_u                    REAL4 -4.2
select_spacing_u                    REAL4 2.8
select_turn_radians_per_tick        REAL4 0.02
select_turn_offset_per_character    REAL4 1.5
select_ring_radius_u                REAL4 0.9
select_shadow_radius_u              REAL4 0.55
select_particle_y_u                 REAL4 1.0
firework_spread_x_u                 REAL4 6.0
firework_center_y_u                 REAL4 6.0
firework_spread_y_u                 REAL4 1.5
firework_center_z_u                 REAL4 4.0
firework_spread_z_u                 REAL4 4.0
coin_rain_spread_u                  REAL4 8.0
coin_rain_top_u                     REAL4 7.0
text_select_title                   BYTE "CHOOSE YOUR FIGHTER", 0
text_select_prompt                  BYTE "A D: CHOOSE   SPACE: FIGHT!   CLICK: DASH", 0
text_hud_you                        BYTE "YOU", 0
text_hud_cpu                        BYTE "CPU", 0
text_hud_dash                       BYTE "DASH", 0
text_hud_combo_prefix               BYTE "COMBO ", 0
text_serve_reel_label               BYTE "POINT VALUE", 0
text_over_title_you                 BYTE "YOU WIN!", 0
text_over_title_cpu                 BYTE "CPU WINS!", 0
text_over_stat_combo                BYTE "BEST COMBO ", 0
text_over_stat_crits                BYTE "CRITS ", 0
text_over_stat_jackpots             BYTE "JACKPOTS ", 0
text_over_prompt                    BYTE "SPACE OR ENTER: CHOOSE A FIGHTER", 0
ALIGN 8
hud_side_label_texts                QWORD text_hud_you, text_hud_cpu
.ERRNZ LENGTHOF hud_side_label_texts - SIDE_COUNT
over_title_texts                    QWORD text_over_title_you, text_over_title_cpu
.ERRNZ LENGTHOF over_title_texts - SIDE_COUNT

.data?
character_select_index              DWORD ?
select_pose                         POSE <>
select_ring_center                  VEC3 <>
select_ring_half                    VEC3 <>

.code

select_character_x_load PROC
    cvtsi2ss xmm0, ecx
    mulss xmm0, select_spacing_u
    addss xmm0, select_first_x_u
    ret
select_character_x_load ENDP

character_select_tick PROC
    push rbx
    sub rsp, FRAME_8_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 1, FRAME_8_ARGS_ODD_PUSHES_BYTES
    lea rbx, key_was_pressed_by_virtual_key
    movzx ecx, byte ptr [rbx + VK_A]
    or cl, byte ptr [rbx + VK_LEFT]
    movzx edx, byte ptr [rbx + VK_D]
    or dl, byte ptr [rbx + VK_RIGHT]
    mov eax, character_select_index
    sub eax, ecx
    add eax, edx
    jns character_select_tick_not_negative
    add eax, CHARACTER_COUNT
character_select_tick_not_negative:
    cmp eax, CHARACTER_COUNT
    jb character_select_tick_wrapped
    sub eax, CHARACTER_COUNT
character_select_tick_wrapped:
    cmp eax, character_select_index
    je character_select_tick_confirm
    mov character_select_index, eax
    audio_play_call sound_blip, 0, VOLUME_NORMAL, 0
    screen_punch_call punch_select
    mov ecx, character_select_index
    call select_character_x_load
    movss xmm1, select_particle_y_u
    xorps xmm2, xmm2
    particles_spawn_call particles_select, COLOR_WHITE_BGRA
character_select_tick_confirm:
    movzx eax, byte ptr [rbx + VK_SPACE]
    or al, byte ptr [rbx + VK_RETURN]
    jz character_select_tick_done
    mov ecx, character_select_index
    call match_start
character_select_tick_done:
    add rsp, FRAME_8_ARGS_ODD_PUSHES_BYTES
    pop rbx
    ret
character_select_tick ENDP

select_screen_draw PROC
    push rbx
    push rsi
    push rdi
    push r12
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES + 16
    frame_alignment_check 4, FRAME_4_ARGS_EVEN_PUSHES_BYTES + 16
    xor ebx, ebx
select_screen_draw_character:
    mov ecx, ebx
    call select_character_x_load
    movss select_pose.pos.x, xmm0
    movss select_ring_center.x, xmm0
    xorps xmm1, xmm1
    movss select_pose.pos.z, xmm1
    movss select_ring_center.z, xmm1
    movss select_ring_center.y, xmm1
    movss select_ring_half.y, xmm1
    movss xmm1, select_ring_radius_u
    movss select_ring_half.x, xmm1
    movss select_ring_half.z, xmm1
    movss xmm0, select_pose.pos.x
    movss xmm1, select_pose.pos.z
    movss xmm2, select_shadow_radius_u
    call ground_shadow_draw

    mov r9d, COLOR_SELECT_RING_BGRA
    cmp ebx, character_select_index
    jne select_screen_draw_ring
    mov eax, effects_ticks
    rainbow_color_from_eax r9d
select_screen_draw_ring:
    mov ecx, PRIMITIVE_KIND_RING
    lea rdx, select_ring_center
    lea r8, select_ring_half
    call primitive_draw

    xorps xmm0, xmm0
    movss select_pose.pos.y, xmm0
    movss select_pose.walk_amount, xmm0
    movss select_pose.walk_phase_radians, xmm0
    movss select_pose.swing_fraction, xmm0
    movss select_pose.spin_radians, xmm0
    mov select_pose.color_override_bgra, COLOR_NONE_BGRA
    mov select_pose.render_mode, POSE_RENDER_SOLID
    mov select_pose.action, POSE_ACTION_MOVE
    imul eax, ebx, SELECT_IDLE_TICKS_OFFSET_PER_CHARACTER
    add eax, effects_ticks
    mov select_pose.action_ticks, eax
    cmp ebx, character_select_index
    jne select_screen_draw_turn
    mov select_pose.action, POSE_ACTION_DANCE
    mov eax, effects_ticks
    mov select_pose.action_ticks, eax
select_screen_draw_turn:
    cvtsi2ss xmm0, effects_ticks
    mulss xmm0, select_turn_radians_per_tick
    cvtsi2ss xmm1, ebx
    mulss xmm1, select_turn_offset_per_character
    addss xmm0, xmm1
    movss dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5], xmm0
    call math_sin
    movss select_pose.facing_x, xmm0
    movss xmm0, dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5]
    call math_cos
    xorps xmm0, xmmword ptr float_sign_mask_x4
    movss select_pose.facing_z, xmm0
    mov select_pose.character_index, ebx
    lea rcx, select_pose
    call character_draw
    inc ebx
    cmp ebx, CHARACTER_COUNT
    jb select_screen_draw_character

    lea rcx, text_select_title
    mov edx, SCREEN_CENTER_X_PX
    mov r8d, SELECT_TITLE_TOP_PX
    mov r9d, TEXT_COLOR_RAINBOW
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_LARGE
    call text_draw_centered

    xor ebx, ebx
select_screen_draw_column:
    mov ecx, ebx
    call select_character_x_load
    xorps xmm1, xmm1
    xorps xmm2, xmm2
    call screen_position_from_world
    cvtss2si esi, xmm0
    add esi, SCREEN_CENTER_X_PX
    mov ecx, ebx
    call character_address_load
    mov r12, rax
    mov edi, (CHARACTER PTR [r12]).color_bgra
    mov r9d, edi
    cmp ebx, character_select_index
    jne select_screen_draw_name
    mov r9d, TEXT_COLOR_RAINBOW
select_screen_draw_name:
    mov rcx, (CHARACTER PTR [r12]).name_text
    mov edx, esi
    mov r8d, SELECT_NAME_TOP_PX
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_SMALL
    call text_draw_centered
    xor r12d, r12d
select_screen_draw_stat:
    lea rax, character_stat_texts
    mov rcx, qword ptr [rax + r12 * 8]
    lea edx, [rsi - SELECT_STAT_LABEL_LEFT_FROM_CENTER_PX]
    imul r8d, r12d, SELECT_STATS_ROW_PX
    add r8d, SELECT_STATS_TOP_PX
    mov r9d, COLOR_TEXT_DIM_BGRA
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_SMALL
    call text_draw
    imul eax, ebx, CHARACTER_STAT_COUNT
    add eax, r12d
    lea rcx, character_stat_bars
    movzx eax, byte ptr [rcx + rax]
    mov dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5], eax
    xor ecx, ecx
    mov dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5 + 4], ecx
select_screen_draw_bar:
    mov ecx, dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5 + 4]
    cmp ecx, CHARACTER_STAT_BAR_MAX
    jae select_screen_draw_stat_next
    mov eax, COLOR_SELECT_BAR_EMPTY_BGRA
    cmp ecx, dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5]
    jae select_screen_draw_bar_color_ready
    mov eax, edi
select_screen_draw_bar_color_ready:
    mov dword ptr [rsp + CALL_ARG5], eax
    imul ecx, ecx, SELECT_STAT_BAR_PITCH_PX
    lea ecx, [rcx + rsi + SELECT_STAT_BAR_LEFT_FROM_CENTER_PX]
    imul edx, r12d, SELECT_STATS_ROW_PX
    add edx, SELECT_STATS_TOP_PX + 1
    mov r8d, SELECT_STAT_BAR_SIZE_PX
    mov r9d, SELECT_STAT_BAR_SIZE_PX
    call framebuffer_rect_fill
    inc dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5 + 4]
    jmp select_screen_draw_bar
select_screen_draw_stat_next:
    inc r12d
    cmp r12d, CHARACTER_STAT_COUNT
    jb select_screen_draw_stat
    inc ebx
    cmp ebx, CHARACTER_COUNT
    jb select_screen_draw_column

    mov ecx, character_select_index
    call character_address_load
    mov rcx, (CHARACTER PTR [rax]).description_text
    mov edx, SCREEN_CENTER_X_PX
    mov r8d, SELECT_DESCRIPTION_TOP_PX
    mov r9d, COLOR_WHITE_BGRA
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_SMALL
    call text_draw_centered
    lea rcx, text_select_prompt
    mov edx, SCREEN_CENTER_X_PX
    mov r8d, SELECT_PROMPT_TOP_PX
    mov r9d, COLOR_TEXT_BRIGHT_BGRA
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_SMALL
    call text_draw_centered
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES + 16
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
select_screen_draw ENDP

hud_draw PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_6_ARGS_ODD_PUSHES_BYTES
    xor ebx, ebx
hud_draw_side:
    player_address_load rsi, ebx
    side_color_load edi, rbx
    mov r8d, COLOR_WHITE_BGRA
    mov r9d, SCORE_CELL_PX
    cmp (PLAYER PTR [rsi]).score_pop_ticks_left, 0
    je hud_draw_side_score
    mov r8d, edi
    mov r9d, SCORE_POP_CELL_PX
hud_draw_side_score:
    mov ecx, (PLAYER PTR [rsi]).score_shown
    mov edx, SCREEN_CENTER_X_PX - HUD_SCORE_CENTER_FROM_SCREEN_CENTER_PX
    cmp ebx, SIDE_FAR
    jne hud_draw_side_score_x
    mov edx, SCREEN_CENTER_X_PX + HUD_SCORE_CENTER_FROM_SCREEN_CENTER_PX
hud_draw_side_score_x:
    mov dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5], edx
    call score_draw
    lea rax, hud_side_label_texts
    mov rcx, qword ptr [rax + rbx * 8]
    mov edx, dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5]
    mov r8d, HUD_LABEL_TOP_PX
    mov r9d, edi
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_SMALL
    call text_draw_centered
    inc ebx
    cmp ebx, SIDE_COUNT
    jb hud_draw_side

    cmp match_mode, MATCH_MODE_SERVE_WAIT
    jne hud_draw_rally
    call serve_reel_draw
    jmp hud_draw_dash
hud_draw_rally:
    cmp match_mode, MATCH_MODE_RALLY
    jne hud_draw_dash
    call rally_multiplier_get
    mov ebx, eax
    cmp ebx, 2
    jb hud_draw_combo
    lea rcx, text_scratch
    lea rdx, text_popup_times
    call text_append_string
    mov rcx, rax
    mov edx, ebx
    call text_append_number
    mov eax, TEXT_SCALE_HUGE
    cmp multiplier_pop_ticks_left, 0
    je hud_draw_multiplier_scale_ready
    mov eax, TEXT_SCALE_GIANT
hud_draw_multiplier_scale_ready:
    mov dword ptr [rsp + CALL_ARG5], eax
    lea rcx, text_scratch
    mov edx, SCREEN_CENTER_X_PX
    mov r8d, HUD_MULTIPLIER_TOP_PX
    mov r9d, TEXT_COLOR_RAINBOW
    call text_draw_centered
hud_draw_combo:
    mov eax, rally_combo
    cmp eax, COMBO_POPUP_MIN - 1
    jb hud_draw_dash
    lea rcx, text_scratch
    lea rdx, text_hud_combo_prefix
    call text_append_string
    mov rcx, rax
    mov edx, rally_combo
    call text_append_number
    mov r9d, COLOR_COMBO_BGRA
    cmp ebx, 3
    jb hud_draw_combo_color_ready
    mov r9d, TEXT_COLOR_RAINBOW
hud_draw_combo_color_ready:
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_SMALL
    lea rcx, text_scratch
    mov edx, SCREEN_CENTER_X_PX
    mov r8d, HUD_COMBO_TOP_PX
    call text_draw_centered

hud_draw_dash:
    lea rsi, players[SIZEOF PLAYER * SIDE_NEAR]
    lea rcx, text_hud_dash
    mov edx, HUD_DASH_LEFT_PX
    mov r8d, HUD_DASH_LABEL_TOP_PX
    mov r9d, COLOR_TEXT_DIM_BGRA
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_SMALL
    call text_draw
    mov dword ptr [rsp + CALL_ARG5], COLOR_HUD_BAR_EMPTY_BGRA
    mov ecx, HUD_DASH_LEFT_PX
    mov edx, HUD_DASH_BAR_TOP_PX
    mov r8d, HUD_DASH_BAR_WIDTH_PX
    mov r9d, HUD_DASH_BAR_HEIGHT_PX
    call framebuffer_rect_fill
    mov ecx, (PLAYER PTR [rsi]).dash_cooldown_ticks_max
    test ecx, ecx
    jz hud_draw_done
    mov eax, ecx
    sub eax, (PLAYER PTR [rsi]).dash_cooldown_ticks_left
    imul eax, eax, HUD_DASH_BAR_WIDTH_PX
    xor edx, edx
    div ecx
    mov ebx, eax
    mov eax, SIDE_NEAR
    side_color_load edi, rax
    cmp (PLAYER PTR [rsi]).dash_cooldown_ticks_left, 0
    jne hud_draw_dash_fill
    mov eax, effects_ticks
    triangle_wave_from_eax
    imul edx, eax, UPGRADE_CARD_PULSE_LEVEL_PER_TICK
    add edx, UPGRADE_CARD_PULSE_LEVEL_MIN
    mov ecx, COLOR_WHITE_BGRA
    call color_scale
    mov edi, eax
hud_draw_dash_fill:
    mov dword ptr [rsp + CALL_ARG5], edi
    mov ecx, HUD_DASH_LEFT_PX
    mov edx, HUD_DASH_BAR_TOP_PX
    mov r8d, ebx
    mov r9d, HUD_DASH_BAR_HEIGHT_PX
    call framebuffer_rect_fill
hud_draw_done:
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
hud_draw ENDP

serve_reel_draw PROC
    push rbx
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 1, FRAME_6_ARGS_ODD_PUSHES_BYTES
    mov ebx, match_mode_ticks
    cmp ebx, SERVE_REEL_STOP_TICK
    jae serve_reel_draw_landed
    mov eax, COLOR_WHITE_BGRA
    test ebx, UPGRADE_SPIN_BLINK_BIT_MASK
    jz serve_reel_draw_border
    mov eax, COLOR_GOLD_BGRA
    jmp serve_reel_draw_border
serve_reel_draw_landed:
    mov eax, COLOR_CARD_BORDER_BGRA
    cmp serve_reel_result_multiplier, 2
    jb serve_reel_draw_border
    mov eax, effects_ticks
    rainbow_color_from_eax eax
serve_reel_draw_border:
    mov dword ptr [rsp + CALL_ARG5], eax
    mov ecx, SERVE_REEL_BOX_LEFT_PX
    mov edx, SERVE_REEL_BOX_TOP_PX
    mov r8d, SERVE_REEL_BOX_WIDTH_PX
    mov r9d, SERVE_REEL_BOX_HEIGHT_PX
    call framebuffer_rect_fill
    mov dword ptr [rsp + CALL_ARG5], COLOR_CARD_PANEL_SELECTED_BGRA
    mov ecx, SERVE_REEL_BOX_LEFT_PX + SERVE_REEL_BOX_BORDER_PX
    mov edx, SERVE_REEL_BOX_TOP_PX + SERVE_REEL_BOX_BORDER_PX
    mov r8d, SERVE_REEL_BOX_WIDTH_PX - 2 * SERVE_REEL_BOX_BORDER_PX
    mov r9d, SERVE_REEL_BOX_HEIGHT_PX - 2 * SERVE_REEL_BOX_BORDER_PX
    call framebuffer_rect_fill
    lea rcx, text_scratch
    lea rdx, text_popup_times
    call text_append_string
    mov rcx, rax
    mov edx, serve_reel_shown_multiplier
    call text_append_number
    mov r9d, COLOR_WHITE_BGRA
    cmp ebx, SERVE_REEL_STOP_TICK
    jb serve_reel_draw_symbol
    cmp serve_reel_result_multiplier, 2
    jb serve_reel_draw_symbol
    mov r9d, TEXT_COLOR_RAINBOW
serve_reel_draw_symbol:
    mov r8d, SERVE_REEL_SYMBOL_TOP_PX
    sub r8d, serve_reel_bounce_ticks_left
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_HUGE
    lea rcx, text_scratch
    mov edx, SCREEN_CENTER_X_PX
    call text_draw_centered
    lea rcx, text_serve_reel_label
    mov edx, SCREEN_CENTER_X_PX
    mov r8d, SERVE_REEL_LABEL_TOP_PX
    mov r9d, COLOR_TEXT_DIM_BGRA
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_SMALL
    call text_draw_centered
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rbx
    ret
serve_reel_draw ENDP

over_tick PROC
    sub rsp, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 0, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    lea rax, key_was_pressed_by_virtual_key
    movzx ecx, byte ptr [rax + VK_SPACE]
    or cl, byte ptr [rax + VK_RETURN]
    jnz over_tick_select
    test match_mode_ticks, OVER_FIREWORK_PERIOD_TICKS - 1
    jnz over_tick_coins
    random_signed_unit_float_to xmm0
    mulss xmm0, firework_spread_x_u
    random_signed_unit_float_to xmm1
    mulss xmm1, firework_spread_y_u
    addss xmm1, firework_center_y_u
    random_signed_unit_float_to xmm2
    mulss xmm2, firework_spread_z_u
    addss xmm2, firework_center_z_u
    particles_spawn_call particles_firework, COLOR_BLACK_BGRA
    mov ecx, 8
    random_below_to_eax ecx
    sub eax, 8
    audio_play_call sound_boom, eax, VOLUME_QUIET, 0
over_tick_coins:
    test match_mode_ticks, OVER_COIN_PERIOD_TICKS - 1
    jnz over_tick_done
    random_signed_unit_float_to xmm0
    mulss xmm0, coin_rain_spread_u
    random_signed_unit_float_to xmm2
    mulss xmm2, coin_rain_spread_u
    movss xmm1, coin_rain_top_u
    particles_spawn_call particles_coin_rain, COLOR_GOLD_BGRA
    jmp over_tick_done
over_tick_select:
    match_mode_set MATCH_MODE_CHARACTER_SELECT
over_tick_done:
    add rsp, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    ret
over_tick ENDP

over_screen_draw PROC
    push rbx
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 1, FRAME_6_ARGS_ODD_PUSHES_BYTES
    mov ecx, COLOR_BLACK_BGRA
    mov edx, SCREEN_DARKEN_LEVEL
    call framebuffer_lerp_toward
    mov eax, match_point_loser_side
    xor eax, SIDE_FLIP
    lea rcx, over_title_texts
    mov rcx, qword ptr [rcx + rax * 8]
    mov edx, SCREEN_CENTER_X_PX
    mov r8d, OVER_TITLE_TOP_PX
    mov r9d, TEXT_COLOR_RAINBOW
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_GIANT
    call text_draw_centered

    mov ebx, OVER_STATS_TOP_PX
    lea rcx, text_scratch
    lea rdx, text_over_stat_combo
    call text_append_string
    mov rcx, rax
    mov edx, match_best_combo
    call text_append_number
    mov ecx, ebx
    call over_screen_stat_line_draw
    add ebx, OVER_STATS_LINE_PX
    lea rcx, text_scratch
    lea rdx, text_over_stat_crits
    call text_append_string
    mov rcx, rax
    mov edx, match_crit_count
    call text_append_number
    mov ecx, ebx
    call over_screen_stat_line_draw
    add ebx, OVER_STATS_LINE_PX
    lea rcx, text_scratch
    lea rdx, text_over_stat_jackpots
    call text_append_string
    mov rcx, rax
    mov edx, match_jackpot_count
    call text_append_number
    mov ecx, ebx
    call over_screen_stat_line_draw

    test match_mode_ticks, OVER_PROMPT_BLINK_BIT_MASK
    jnz over_screen_draw_done
    lea rcx, text_over_prompt
    mov edx, SCREEN_CENTER_X_PX
    mov r8d, OVER_PROMPT_TOP_PX
    mov r9d, COLOR_WHITE_BGRA
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_SMALL
    call text_draw_centered
over_screen_draw_done:
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rbx
    ret
over_screen_draw ENDP

over_screen_stat_line_draw PROC
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 0, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    mov r8d, ecx
    lea rcx, text_scratch
    mov edx, SCREEN_CENTER_X_PX
    mov r9d, COLOR_GOLD_BGRA
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_SMALL
    call text_draw_centered
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    ret
over_screen_stat_line_draw ENDP
