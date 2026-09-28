SWING_TICKS                         equ 18
FIGHTER_FLASH_TICKS                 equ 10
GHOST_SPAWN_PERIOD_TICKS            equ 3
GHOST_LIFE_TICKS                    equ 14
GHOST_LEVEL_BASE                    equ 40
GHOST_LEVEL_PER_TICK                equ 12
.ERRE GHOST_LEVEL_BASE + GHOST_LEVEL_PER_TICK * GHOST_LIFE_TICKS LE COLOR_LEVEL_FULL
CPU_REACTION_TICKS                  equ 14
SERVE_WAIT_TICKS                    equ 150
SERVE_BLINK_BIT_MASK                equ 8
SERVE_REEL_START_TICK               equ 2
SERVE_REEL_STOP_TICK                equ 84
SERVE_REEL_INTERVAL_MIN_TICKS       equ 3
SERVE_REEL_SLOWDOWN_TICKS           equ 36
SERVE_REEL_SLOWDOWN_DIVISOR         equ 3
SERVE_REEL_TICK_SEMITONE            equ 12
SERVE_REEL_BOUNCE_TICKS             equ 5
SERVE_REEL_ARPEGGIO_EXTRA_NOTES     equ 2
POINT_SCORED_TICKS                  equ 100
POINT_BIG_MIN                       equ 2
POINT_JACKPOT_MIN                   equ 5
POINT_ARPEGGIO_EXTRA_NOTES          equ 2
COMBO_HITS_PER_MULTIPLIER           equ 4
MULTIPLIER_POP_TICKS                equ 12
MULTIPLIER_UP_ARPEGGIO_NOTES        equ 4
CRIT_CHANCE_PER_POWER_LEVEL_PERCENT equ 5
CRIT_CHANCE_MAX_PERCENT             equ 60
BALL_POP_TICKS                      equ 6
BALL_TRAIL_LENGTH                   equ 16
.ERRNZ BALL_TRAIL_LENGTH AND (BALL_TRAIL_LENGTH - 1)
BALL_TRAIL_LEVEL_PER_STEP           equ 14
BALL_HEAT_COMBO_PER_LEVEL           equ 3
BALL_GOLD_MULTIPLIER_MIN            equ 2
BALL_RAINBOW_MULTIPLIER_MIN         equ 3
BALL_FLAME_MULTIPLIER_MIN           equ 3
BALL_RAINBOW_FLAME_MULTIPLIER_MIN   equ 5
FIGHTER_MOVE_FRAME_BYTES            equ FRAME_7_ARGS_EVEN_PUSHES_BYTES + 16
FIGHTER_MOVE_LOCAL_DIR_X            equ FRAME_7_ARGS_EVEN_PUSHES_BYTES
FIGHTER_MOVE_LOCAL_DIR_Z            equ FRAME_7_ARGS_EVEN_PUSHES_BYTES + 4
BALL_HIT_FRAME_BYTES                equ FRAME_7_ARGS_EVEN_PUSHES_BYTES + 32
BALL_HIT_LOCAL_TARGET_X             equ FRAME_7_ARGS_EVEN_PUSHES_BYTES
BALL_HIT_LOCAL_TARGET_Z             equ FRAME_7_ARGS_EVEN_PUSHES_BYTES + 4
BALL_HIT_LOCAL_AIM_RANGE            equ FRAME_7_ARGS_EVEN_PUSHES_BYTES + 8

.const
gravity_u_per_s2                    REAL4 16.0
ball_radius_u                       REAL4 0.22
ball_pop_extra_radius_u             REAL4 0.08
serve_height_u                      REAL4 3.4
serve_hover_bob_u                   REAL4 0.12
serve_hover_radians_per_tick        REAL4 0.08
serve_flight_s                      REAL4 1.6
serve_target_x_spread_u             REAL4 3.5
serve_target_depth_u                REAL4 5.5
net_clearance_u                     REAL4 0.6
fighter_x_limit_u                   REAL4 8.0
fighter_z_near_net_u                REAL4 0.8
fighter_z_back_u                    REAL4 11.5
fighter_start_z_u                   REAL4 6.0
fighter_hit_height_u                REAL4 1.0
fighter_accel_per_tick              REAL4 0.2
fighter_turn_per_tick               REAL4 0.25
fighter_walk_radians_per_u          REAL4 3.5
fighter_facing_min_length           REAL4 0.01
fighter_direction_epsilon           REAL4 0.0001
fighter_diagonal_factor             REAL4 0.70710678
fighter_dash_dust_speed_u_per_s     REAL4 -2.0
fighter_dash_dust_height_u          REAL4 0.1
fighter_shadow_radius_u             REAL4 0.5
reach_per_big_reach_level_u         REAL4 0.25
reach_per_shrink_level_u            REAL4 0.15
reach_min_u                         REAL4 0.5
reach_max_u                         REAL4 3.8
run_speed_per_quick_level           REAL4 0.12
run_speed_factor_max                REAL4 2.0
dash_cooldown_per_level             REAL4 0.2
dash_cooldown_factor_min            REAL4 0.35
aim_range_per_wide_aim_level_u      REAL4 0.8
aim_depth_min_u                     REAL4 2.2
aim_depth_range_u                   REAL4 6.1
aim_x_limit_u                       REAL4 5.4
aim_random_x_u                      REAL4 0.5
aim_depth_center                    REAL4 0.55
aim_depth_facing_weight             REAL4 0.4
aim_depth_random                    REAL4 0.15
cpu_aim_away_factor                 REAL4 -0.6
cpu_aim_random_factor               REAL4 0.6
cpu_depth_center                    REAL4 0.5
cpu_depth_random                    REAL4 0.45
cpu_error_u                         REAL4 0.55
cpu_home_z_u                        REAL4 5.5
cpu_speed_factor                    REAL4 0.92
cpu_slow_radius_u                   REAL4 0.6
cpu_arrive_radius_u                 REAL4 0.12
cpu_dash_distance_min_u             REAL4 1.6
cpu_dash_time_margin                REAL4 1.1
flight_factor_per_combo             REAL4 0.025
flight_factor_min                   REAL4 0.6
crit_flight_factor                  REAL4 0.6
power_flight_factor_per_level       REAL4 0.07
power_flight_factor_min             REAL4 0.5
ball_spin_radians_per_s             REAL4 9.0
shield_revault_flight_s             REAL4 1.3
shield_revault_x_spread_u           REAL4 4.0
shield_revault_depth_u              REAL4 5.5
particle_hit_speed_factor           REAL4 0.15
ball_shadow_radius_max_u            REAL4 0.38
ball_shadow_shrink_per_u            REAL4 0.03
ball_shadow_radius_min_u            REAL4 0.1
landing_marker_radius_u             REAL4 0.7
landing_marker_pulse_u              REAL4 0.15
landing_marker_pulse_radians_per_tick REAL4 0.3
landing_marker_height_u             REAL4 0.03
ball_flame_back_factor              REAL4 -0.1
ball_heat_color_bgra                DWORD 00F0F0F0h, 00FFE070h, 00FFA040h, 00FF4838h
BALL_HEAT_COLOR_COUNT               equ LENGTHOF ball_heat_color_bgra
serve_reel_weighted_multipliers     DWORD 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 5
SERVE_REEL_WEIGHTED_COUNT           equ LENGTHOF serve_reel_weighted_multipliers
serve_reel_strip_multipliers        DWORD 1, 2, 5, 3, 1, 2, 3, 5, 1, 3, 2, 5, 1, 2, 3, 5
SERVE_REEL_STRIP_COUNT              equ LENGTHOF serve_reel_strip_multipliers
.ERRNZ SERVE_REEL_STRIP_COUNT AND (SERVE_REEL_STRIP_COUNT - 1)

.data?
players                             PLAYER SIDE_COUNT DUP (<>)
match_mode                          DWORD ?
match_mode_ticks                    DWORD ?
match_point_loser_side              DWORD ?
match_best_combo                    DWORD ?
match_crit_count                    DWORD ?
match_jackpot_count                 DWORD ?
rally_combo                         DWORD ?
rally_serve_multiplier_bonus        DWORD ?
multiplier_pop_ticks_left           DWORD ?
serve_reel_result_multiplier        DWORD ?
serve_reel_shown_multiplier         DWORD ?
serve_reel_strip_index              DWORD ?
serve_reel_next_change_tick         DWORD ?
serve_reel_bounce_ticks_left        DWORD ?
ball_pos                            VEC3 <>
ball_vel_u_per_s                    VEC3 <>
ball_target_x_u                     REAL4 ?
ball_target_z_u                     REAL4 ?
ball_flight_ticks_left              DWORD ?
ball_last_hitter_side               DWORD ?
ball_spin_radians                   REAL4 ?
ball_pop_ticks_left                 DWORD ?
ball_trail                          VEC3 BALL_TRAIL_LENGTH DUP (<>)
ball_trail_next_index               DWORD ?
ball_trail_count                    DWORD ?
fighter_pose                        POSE <>
ball_marker_center                  VEC3 <>
ball_marker_half                    VEC3 <>

.code

match_start PROC
    push rbx
    push rdi
    sub rsp, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 2, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    mov ebx, ecx
    assert_below_unsigned ebx, CHARACTER_COUNT
    lea rdi, players
    mov ecx, SIZEOF players
    xor eax, eax
    rep stosb
    mov ecx, CHARACTER_COUNT - 1
    random_below_to_eax ecx
    cmp eax, ebx
    jb match_start_cpu_character_ready
    inc eax
match_start_cpu_character_ready:
    lea rcx, players[SIZEOF PLAYER * SIDE_FAR]
    mov (PLAYER PTR [rcx]).character_index, eax
    movss xmm0, fighter_start_z_u
    movss (PLAYER PTR [rcx]).pos_z_u, xmm0
    movss xmm0, float_one
    movss (PLAYER PTR [rcx]).side_z_sign, xmm0
    xorps xmm0, xmmword ptr float_sign_mask_x4
    movss (PLAYER PTR [rcx]).facing_z, xmm0
    lea rcx, players[SIZEOF PLAYER * SIDE_NEAR]
    mov (PLAYER PTR [rcx]).character_index, ebx
    movss (PLAYER PTR [rcx]).side_z_sign, xmm0
    movss xmm0, fighter_start_z_u
    xorps xmm0, xmmword ptr float_sign_mask_x4
    movss (PLAYER PTR [rcx]).pos_z_u, xmm0
    movss xmm0, float_one
    movss (PLAYER PTR [rcx]).facing_z, xmm0
    mov match_point_loser_side, SIDE_NEAR
    mov match_best_combo, 0
    mov match_crit_count, 0
    mov match_jackpot_count, 0
    mov rally_combo, 0
    mov rally_serve_multiplier_bonus, 0
    match_mode_set MATCH_MODE_SERVE_WAIT
    call players_stats_update
    screen_punch_call punch_fight
    xorps xmm2, xmm2
    movss xmm3, popup_banner_bottom_y_px
    popup_spawn_call text_popup_fight, POPUP_NO_NUMBER, popup_style_banner
    mov ecx, AUDIO_ARPEGGIO_NOTE_COUNT
    xor edx, edx
    call audio_arpeggio_play
    add rsp, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    pop rdi
    pop rbx
    ret
match_start ENDP

game_tick PROC
    push rbx
    push rdi
    sub rsp, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 2, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    lea rbx, key_was_pressed_by_virtual_key
    cmp byte ptr [rbx + VK_M], 0
    je game_tick_effects
    mov byte ptr [rbx + VK_M], 0
    call music_mute_toggle
game_tick_effects:
    call players_stats_update
    call effects_tick
    call music_state_update
    movss xmm0, camera_ease_per_tick
    call camera_update_tick
    cmp hit_stop_ticks_left, 0
    je game_tick_slow_mo
    dec hit_stop_ticks_left
    jmp game_tick_return
game_tick_slow_mo:
    mov eax, slow_mo_ticks_left
    test eax, eax
    jz game_tick_mode
    dec eax
    mov slow_mo_ticks_left, eax
    xor edx, edx
    mov ecx, SLOW_MO_TICK_DIVISOR
    div ecx
    test edx, edx
    jnz game_tick_return

game_tick_mode:
    inc match_mode_ticks
    mov eax, match_mode
    assert_below_unsigned eax, MATCH_MODE_COUNT
    cmp eax, MATCH_MODE_CHARACTER_SELECT
    je game_tick_character_select
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

game_tick_character_select:
    call character_select_tick
    jmp game_tick_done

game_tick_serve_wait:
    call serve_wait_tick
    jmp game_tick_done

game_tick_rally:
    call player_tick
    call cpu_tick
    call ball_tick
    jmp game_tick_done

game_tick_point_scored:
    call player_tick
    call cpu_tick
    cmp match_mode_ticks, POINT_SCORED_TICKS
    jb game_tick_done
    lea rax, players[SIZEOF PLAYER * SIDE_NEAR]
    mov ecx, (PLAYER PTR [rax]).score
    cmp ecx, (PLAYER PTR [rax]).score_shown
    jne game_tick_done
    lea rax, players[SIZEOF PLAYER * SIDE_FAR]
    mov ecx, (PLAYER PTR [rax]).score
    cmp ecx, (PLAYER PTR [rax]).score_shown
    jne game_tick_done
    mov ecx, match_point_loser_side
    xor ecx, SIDE_FLIP
    player_address_load rax, ecx
    cmp (PLAYER PTR [rax]).score, MATCH_WINNING_SCORE
    jb game_tick_point_scored_offer
    match_mode_set MATCH_MODE_OVER
    jmp game_tick_done
game_tick_point_scored_offer:
    match_mode_set MATCH_MODE_UPGRADE_CHOOSE
    mov upgrade_offer_cursor, 0
    mov upgrade_rerolls_left, UPGRADE_REROLLS_PER_PICK
    mov ecx, UPGRADE_REELS_START_TICK
    call upgrade_offer_roll
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
    call over_tick

game_tick_done:
    lea rdi, key_was_pressed_by_virtual_key
    mov ecx, VIRTUAL_KEY_COUNT
    xor eax, eax
    rep stosb
game_tick_return:
    add rsp, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    pop rdi
    pop rbx
    ret
game_tick ENDP

players_stats_update PROC
    push rbx
    xor r8d, r8d
players_stats_update_side:
    mov r9d, r8d
    xor r9d, SIDE_FLIP
    player_address_load rcx, r8d
    player_address_load rdx, r9d
    mov eax, (PLAYER PTR [rcx]).character_index
    assert_below_unsigned eax, CHARACTER_COUNT
    imul eax, eax, SIZEOF CHARACTER
    lea rbx, characters
    add rbx, rax
    cvtsi2ss xmm0, upgrade_level(rcx, UPGRADE_KIND_BIG_REACH)
    mulss xmm0, reach_per_big_reach_level_u
    addss xmm0, (CHARACTER PTR [rbx]).reach_u
    cvtsi2ss xmm1, upgrade_level(rdx, UPGRADE_KIND_SHRINK_FOE)
    mulss xmm1, reach_per_shrink_level_u
    subss xmm0, xmm1
    float_clamp xmm0, reach_min_u, reach_max_u
    movss (PLAYER PTR [rcx]).reach_u, xmm0
    cvtsi2ss xmm0, upgrade_level(rcx, UPGRADE_KIND_QUICK_FEET)
    mulss xmm0, run_speed_per_quick_level
    addss xmm0, float_one
    minss xmm0, run_speed_factor_max
    mulss xmm0, (CHARACTER PTR [rbx]).run_speed_u_per_s
    movss (PLAYER PTR [rcx]).run_speed_u_per_s, xmm0
    cvtsi2ss xmm0, upgrade_level(rcx, UPGRADE_KIND_DASH_MASTER)
    mulss xmm0, dash_cooldown_per_level
    movss xmm1, float_one
    subss xmm1, xmm0
    maxss xmm1, dash_cooldown_factor_min
    cvtsi2ss xmm0, (CHARACTER PTR [rbx]).dash_cooldown_ticks
    mulss xmm0, xmm1
    cvtss2si eax, xmm0
    mov (PLAYER PTR [rcx]).dash_cooldown_ticks_max, eax
    inc r8d
    cmp r8d, SIDE_COUNT
    jb players_stats_update_side
    pop rbx
    ret
players_stats_update ENDP

fighter_move PROC
    push rbx
    push rsi
    sub rsp, FIGHTER_MOVE_FRAME_BYTES
    frame_alignment_check 2, FIGHTER_MOVE_FRAME_BYTES
    mov rbx, rcx
    movss dword ptr [rsp + FIGHTER_MOVE_LOCAL_DIR_X], xmm1
    movss dword ptr [rsp + FIGHTER_MOVE_LOCAL_DIR_Z], xmm2
    mov esi, r9d
    mov ecx, (PLAYER PTR [rbx]).character_index
    call character_address_load
    xchg rsi, rax
    mov r9d, eax

    movss xmm1, dword ptr [rsp + FIGHTER_MOVE_LOCAL_DIR_X]
    movss xmm2, dword ptr [rsp + FIGHTER_MOVE_LOCAL_DIR_Z]
    movaps xmm3, xmm1
    mulss xmm3, xmm1
    movaps xmm4, xmm2
    mulss xmm4, xmm2
    addss xmm3, xmm4
    comiss xmm3, fighter_direction_epsilon
    jbe fighter_move_dash_check
    sqrtss xmm3, xmm3
    movaps xmm4, xmm1
    divss xmm4, xmm3
    movaps xmm5, xmm2
    divss xmm5, xmm3
    movss xmm0, (PLAYER PTR [rbx]).facing_x
    movaps xmm1, xmm4
    subss xmm1, xmm0
    mulss xmm1, fighter_turn_per_tick
    addss xmm0, xmm1
    movss xmm2, (PLAYER PTR [rbx]).facing_z
    movaps xmm1, xmm5
    subss xmm1, xmm2
    mulss xmm1, fighter_turn_per_tick
    addss xmm2, xmm1
    movaps xmm1, xmm0
    mulss xmm1, xmm0
    movaps xmm3, xmm2
    mulss xmm3, xmm2
    addss xmm1, xmm3
    sqrtss xmm1, xmm1
    comiss xmm1, fighter_facing_min_length
    jae fighter_move_facing_normalize
    movaps xmm0, xmm4
    movaps xmm2, xmm5
    jmp fighter_move_facing_store
fighter_move_facing_normalize:
    divss xmm0, xmm1
    divss xmm2, xmm1
fighter_move_facing_store:
    movss (PLAYER PTR [rbx]).facing_x, xmm0
    movss (PLAYER PTR [rbx]).facing_z, xmm2

fighter_move_dash_check:
    test r9d, r9d
    jz fighter_move_velocity
    cmp (PLAYER PTR [rbx]).dash_ticks_left, 0
    jne fighter_move_velocity
    cmp (PLAYER PTR [rbx]).dash_cooldown_ticks_left, 0
    jne fighter_move_velocity
    mov eax, (CHARACTER PTR [rsi]).dash_ticks
    mov (PLAYER PTR [rbx]).dash_ticks_left, eax
    mov eax, (PLAYER PTR [rbx]).dash_cooldown_ticks_max
    mov (PLAYER PTR [rbx]).dash_cooldown_ticks_left, eax
    audio_play_call sound_dash, 0, VOLUME_NORMAL, 0
    screen_punch_call punch_dash
    movss xmm4, (PLAYER PTR [rbx]).facing_x
    mulss xmm4, fighter_dash_dust_speed_u_per_s
    movss xmm5, (PLAYER PTR [rbx]).facing_z
    mulss xmm5, fighter_dash_dust_speed_u_per_s
    movss xmm0, (PLAYER PTR [rbx]).pos_x_u
    movss xmm1, fighter_dash_dust_height_u
    movss xmm2, (PLAYER PTR [rbx]).pos_z_u
    particles_spawn_call particles_dash, COLOR_WHITE_BGRA, xmm4, xmm5

fighter_move_velocity:
    cmp (PLAYER PTR [rbx]).dash_ticks_left, 0
    je fighter_move_run
    dec (PLAYER PTR [rbx]).dash_ticks_left
    movss xmm0, (PLAYER PTR [rbx]).facing_x
    mulss xmm0, (CHARACTER PTR [rsi]).dash_speed_u_per_s
    movss (PLAYER PTR [rbx]).vel_x_u_per_s, xmm0
    movss xmm0, (PLAYER PTR [rbx]).facing_z
    mulss xmm0, (CHARACTER PTR [rsi]).dash_speed_u_per_s
    movss (PLAYER PTR [rbx]).vel_z_u_per_s, xmm0
    mov eax, (PLAYER PTR [rbx]).dash_ticks_left
    xor edx, edx
    mov ecx, GHOST_SPAWN_PERIOD_TICKS
    div ecx
    test edx, edx
    jnz fighter_move_integrate
    mov eax, (PLAYER PTR [rbx]).ghost_next_index
    assert_below_unsigned eax, GHOST_COUNT
    movss xmm0, (PLAYER PTR [rbx]).pos_x_u
    movss dword ptr [rbx + PLAYER.ghost_x_u + rax * 4], xmm0
    movss xmm0, (PLAYER PTR [rbx]).pos_z_u
    movss dword ptr [rbx + PLAYER.ghost_z_u + rax * 4], xmm0
    mov dword ptr [rbx + PLAYER.ghost_ticks_left + rax * 4], GHOST_LIFE_TICKS
    inc eax
    xor edx, edx
    mov ecx, GHOST_COUNT
    div ecx
    mov (PLAYER PTR [rbx]).ghost_next_index, edx
    jmp fighter_move_integrate
fighter_move_run:
    movss xmm0, dword ptr [rsp + FIGHTER_MOVE_LOCAL_DIR_X]
    mulss xmm0, (PLAYER PTR [rbx]).run_speed_u_per_s
    subss xmm0, (PLAYER PTR [rbx]).vel_x_u_per_s
    mulss xmm0, fighter_accel_per_tick
    addss xmm0, (PLAYER PTR [rbx]).vel_x_u_per_s
    movss (PLAYER PTR [rbx]).vel_x_u_per_s, xmm0
    movss xmm0, dword ptr [rsp + FIGHTER_MOVE_LOCAL_DIR_Z]
    mulss xmm0, (PLAYER PTR [rbx]).run_speed_u_per_s
    subss xmm0, (PLAYER PTR [rbx]).vel_z_u_per_s
    mulss xmm0, fighter_accel_per_tick
    addss xmm0, (PLAYER PTR [rbx]).vel_z_u_per_s
    movss (PLAYER PTR [rbx]).vel_z_u_per_s, xmm0

fighter_move_integrate:
    movss xmm0, (PLAYER PTR [rbx]).vel_x_u_per_s
    mulss xmm0, tick_seconds
    addss xmm0, (PLAYER PTR [rbx]).pos_x_u
    float_clamp_symmetric xmm0, xmm3, fighter_x_limit_u
    movss (PLAYER PTR [rbx]).pos_x_u, xmm0
    movss xmm0, (PLAYER PTR [rbx]).vel_z_u_per_s
    mulss xmm0, tick_seconds
    addss xmm0, (PLAYER PTR [rbx]).pos_z_u
    mulss xmm0, (PLAYER PTR [rbx]).side_z_sign
    float_clamp xmm0, fighter_z_near_net_u, fighter_z_back_u
    mulss xmm0, (PLAYER PTR [rbx]).side_z_sign
    movss (PLAYER PTR [rbx]).pos_z_u, xmm0

    movss xmm0, (PLAYER PTR [rbx]).vel_x_u_per_s
    mulss xmm0, xmm0
    movss xmm1, (PLAYER PTR [rbx]).vel_z_u_per_s
    mulss xmm1, xmm1
    addss xmm0, xmm1
    sqrtss xmm0, xmm0
    movaps xmm1, xmm0
    divss xmm1, (CHARACTER PTR [rsi]).run_speed_u_per_s
    minss xmm1, float_one
    movss (PLAYER PTR [rbx]).walk_amount, xmm1
    mulss xmm0, tick_seconds
    mulss xmm0, fighter_walk_radians_per_u
    addss xmm0, (PLAYER PTR [rbx]).walk_phase_radians
    comiss xmm0, float_two_pi
    jb fighter_move_phase_ready
    subss xmm0, float_two_pi
fighter_move_phase_ready:
    movss (PLAYER PTR [rbx]).walk_phase_radians, xmm0
    counter_down_to_zero <(PLAYER PTR [rbx]).dash_cooldown_ticks_left>
    counter_down_to_zero <(PLAYER PTR [rbx]).swing_ticks_left>
    add rsp, FIGHTER_MOVE_FRAME_BYTES
    pop rsi
    pop rbx
    ret
fighter_move ENDP

player_tick PROC
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 0, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    lea rax, key_is_down_by_virtual_key
    movzx ecx, byte ptr [rax + VK_D]
    or cl, byte ptr [rax + VK_RIGHT]
    movzx edx, byte ptr [rax + VK_A]
    or dl, byte ptr [rax + VK_LEFT]
    sub ecx, edx
    movzx r8d, byte ptr [rax + VK_W]
    or r8b, byte ptr [rax + VK_UP]
    movzx edx, byte ptr [rax + VK_S]
    or dl, byte ptr [rax + VK_DOWN]
    sub r8d, edx
    cvtsi2ss xmm1, ecx
    cvtsi2ss xmm2, r8d
    test ecx, ecx
    jz player_tick_direction_ready
    test r8d, r8d
    jz player_tick_direction_ready
    mulss xmm1, fighter_diagonal_factor
    mulss xmm2, fighter_diagonal_factor
player_tick_direction_ready:
    lea rax, key_was_pressed_by_virtual_key
    movzx r9d, byte ptr [rax + VK_LBUTTON]
    lea rcx, players[SIZEOF PLAYER * SIDE_NEAR]
    call fighter_move
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    ret
player_tick ENDP

cpu_tick PROC
    push rbx
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 1, FRAME_6_ARGS_ODD_PUSHES_BYTES
    lea rbx, players[SIZEOF PLAYER * SIDE_FAR]
    xor r9d, r9d
    movss xmm0, (PLAYER PTR [rbx]).pos_x_u
    movss xmm1, (PLAYER PTR [rbx]).pos_z_u
    cmp match_mode, MATCH_MODE_RALLY
    jne cpu_tick_home
    cmp ball_last_hitter_side, SIDE_NEAR
    jne cpu_tick_home
    cmp (PLAYER PTR [rbx]).cpu_reaction_ticks_left, 0
    je cpu_tick_chase
    dec (PLAYER PTR [rbx]).cpu_reaction_ticks_left
    jmp cpu_tick_target_ready
cpu_tick_chase:
    movss xmm0, (PLAYER PTR [rbx]).cpu_target_x_u
    movss xmm1, (PLAYER PTR [rbx]).cpu_target_z_u
    mov r9d, 1
    jmp cpu_tick_target_ready
cpu_tick_home:
    xorps xmm0, xmm0
    movss xmm1, cpu_home_z_u
cpu_tick_target_ready:
    subss xmm0, (PLAYER PTR [rbx]).pos_x_u
    subss xmm1, (PLAYER PTR [rbx]).pos_z_u
    movaps xmm2, xmm0
    mulss xmm2, xmm0
    movaps xmm3, xmm1
    mulss xmm3, xmm1
    addss xmm2, xmm3
    sqrtss xmm2, xmm2
    comiss xmm2, cpu_arrive_radius_u
    jae cpu_tick_move
    xorps xmm1, xmm1
    xorps xmm2, xmm2
    xor r9d, r9d
    jmp cpu_tick_apply
cpu_tick_move:
    divss xmm0, xmm2
    divss xmm1, xmm2
    test r9d, r9d
    jz cpu_tick_no_dash
    xor r9d, r9d
    cmp (PLAYER PTR [rbx]).dash_cooldown_ticks_left, 0
    jne cpu_tick_no_dash
    comiss xmm2, cpu_dash_distance_min_u
    jb cpu_tick_no_dash
    cvtsi2ss xmm3, ball_flight_ticks_left
    mulss xmm3, tick_seconds
    mulss xmm3, (PLAYER PTR [rbx]).run_speed_u_per_s
    movaps xmm4, xmm2
    mulss xmm4, cpu_dash_time_margin
    comiss xmm3, xmm4
    jae cpu_tick_no_dash
    movss (PLAYER PTR [rbx]).facing_x, xmm0
    movss (PLAYER PTR [rbx]).facing_z, xmm1
    mov r9d, 1
cpu_tick_no_dash:
    movaps xmm3, xmm2
    divss xmm3, cpu_slow_radius_u
    minss xmm3, float_one
    mulss xmm3, cpu_speed_factor
    movaps xmm2, xmm1
    mulss xmm2, xmm3
    movaps xmm1, xmm0
    mulss xmm1, xmm3
    jmp cpu_tick_call
cpu_tick_apply:
cpu_tick_call:
    mov rcx, rbx
    call fighter_move
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rbx
    ret
cpu_tick ENDP

cpu_receive_plan PROC
    lea rcx, players[SIZEOF PLAYER * SIDE_FAR]
    mov (PLAYER PTR [rcx]).cpu_reaction_ticks_left, CPU_REACTION_TICKS
    random_signed_unit_float_to xmm0
    mulss xmm0, cpu_error_u
    addss xmm0, ball_target_x_u
    movss (PLAYER PTR [rcx]).cpu_target_x_u, xmm0
    random_signed_unit_float_to xmm0
    mulss xmm0, cpu_error_u
    addss xmm0, ball_target_z_u
    movss (PLAYER PTR [rcx]).cpu_target_z_u, xmm0
    ret
cpu_receive_plan ENDP

serve_wait_tick PROC
    push rbx
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 1, FRAME_6_ARGS_ODD_PUSHES_BYTES
    call player_tick
    call cpu_tick
    cvtsi2ss xmm0, match_mode_ticks
    mulss xmm0, serve_hover_radians_per_tick
    call math_sin
    mulss xmm0, serve_hover_bob_u
    addss xmm0, serve_height_u
    movss ball_pos.y, xmm0
    xorps xmm0, xmm0
    movss ball_pos.x, xmm0
    movss ball_pos.z, xmm0

    mov ebx, match_mode_ticks
    cmp ebx, 1
    jne serve_wait_tick_reel
    mov rally_combo, 0
    mov rally_serve_multiplier_bonus, 0
    mov ball_trail_count, 0
    mov ecx, SERVE_REEL_WEIGHTED_COUNT
    random_below_to_eax ecx
    lea rcx, serve_reel_weighted_multipliers
    mov eax, dword ptr [rcx + rax * 4]
    mov serve_reel_result_multiplier, eax
    mov serve_reel_shown_multiplier, 1
    mov serve_reel_next_change_tick, SERVE_REEL_START_TICK
    lea rax, players[SIZEOF PLAYER * SIDE_NEAR]
    cmp (PLAYER PTR [rax]).score, MATCH_WINNING_SCORE - 1
    jae serve_wait_tick_match_point
    lea rax, players[SIZEOF PLAYER * SIDE_FAR]
    cmp (PLAYER PTR [rax]).score, MATCH_WINNING_SCORE - 1
    jb serve_wait_tick_reel
serve_wait_tick_match_point:
    xorps xmm2, xmm2
    movss xmm3, popup_banner_bottom_y_px
    popup_spawn_call text_popup_match_point, POPUP_NO_NUMBER, popup_style_banner
    audio_play_call sound_rise, 0, VOLUME_NORMAL, 0

serve_wait_tick_reel:
    cmp ebx, SERVE_REEL_STOP_TICK
    je serve_wait_tick_land
    ja serve_wait_tick_after_land
    cmp ebx, serve_reel_next_change_tick
    jb serve_wait_tick_done
    mov eax, serve_reel_strip_index
    inc eax
    and eax, SERVE_REEL_STRIP_COUNT - 1
    mov serve_reel_strip_index, eax
    lea rcx, serve_reel_strip_multipliers
    mov eax, dword ptr [rcx + rax * 4]
    mov serve_reel_shown_multiplier, eax
    mov serve_reel_bounce_ticks_left, SERVE_REEL_BOUNCE_TICKS
    mov eax, SERVE_REEL_STOP_TICK
    sub eax, ebx
    mov ecx, SERVE_REEL_SLOWDOWN_TICKS
    sub ecx, eax
    xor edx, edx
    test ecx, ecx
    cmovs ecx, edx
    mov eax, ecx
    xor edx, edx
    mov ecx, SERVE_REEL_SLOWDOWN_DIVISOR
    div ecx
    lea ecx, [rax + rbx + SERVE_REEL_INTERVAL_MIN_TICKS]
    mov serve_reel_next_change_tick, ecx
    mov ecx, SERVE_REEL_TICK_SEMITONE
    sub ecx, eax
    audio_play_call sound_tick, ecx, VOLUME_QUIET, 0
    jmp serve_wait_tick_done

serve_wait_tick_land:
    mov eax, serve_reel_result_multiplier
    mov serve_reel_shown_multiplier, eax
    dec eax
    mov rally_serve_multiplier_bonus, eax
    mov serve_reel_bounce_ticks_left, SERVE_REEL_BOUNCE_TICKS
    audio_play_call sound_clack, 0, VOLUME_LOUD, 0
    cmp serve_reel_result_multiplier, BALL_GOLD_MULTIPLIER_MIN
    jb serve_wait_tick_done
    xorps xmm2, xmm2
    movss xmm3, popup_banner_middle_y_px
    popup_spawn_call text_popup_times, serve_reel_result_multiplier, popup_style_banner, text_popup_point_suffix
    screen_punch_call punch_serve_multiplier
    mov ecx, serve_reel_result_multiplier
    add ecx, SERVE_REEL_ARPEGGIO_EXTRA_NOTES
    xor edx, edx
    call audio_arpeggio_play
    jmp serve_wait_tick_done

serve_wait_tick_after_land:
    cmp ebx, SERVE_WAIT_TICKS
    jb serve_wait_tick_done
    call ball_serve

serve_wait_tick_done:
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rbx
    ret
serve_wait_tick ENDP

ball_serve PROC
    push rbx
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 1, FRAME_6_ARGS_ODD_PUSHES_BYTES
    mov ebx, match_point_loser_side
    assert_below_unsigned ebx, SIDE_COUNT
    xorps xmm0, xmm0
    movss ball_pos.x, xmm0
    movss ball_pos.z, xmm0
    movss xmm0, serve_height_u
    movss ball_pos.y, xmm0
    player_address_load rax, ebx
    movss xmm1, serve_target_depth_u
    mulss xmm1, (PLAYER PTR [rax]).side_z_sign
    random_signed_unit_float_to xmm0
    mulss xmm0, serve_target_x_spread_u
    movss xmm2, serve_flight_s
    call ball_vault
    mov eax, ebx
    xor eax, SIDE_FLIP
    mov ball_last_hitter_side, eax
    cmp ebx, SIDE_FAR
    jne ball_serve_plan_ready
    call cpu_receive_plan
ball_serve_plan_ready:
    mov ball_trail_count, 0
    match_mode_set MATCH_MODE_RALLY
    audio_play_call sound_rise, AUDIO_SEMITONE_MIN, VOLUME_QUIET, 0
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rbx
    ret
ball_serve ENDP

ball_vault PROC
    movss ball_target_x_u, xmm0
    movss ball_target_z_u, xmm1
    movss xmm3, ball_pos.z
    movaps xmm4, xmm3
    mulss xmm4, xmm1
    comiss xmm4, float_zero
    jae ball_vault_velocity
    movaps xmm4, xmm3
    subss xmm4, xmm1
    movaps xmm5, xmm3
    divss xmm5, xmm4
    movss xmm4, float_one
    subss xmm4, xmm5
    movss xmm3, ball_pos.y
    subss xmm3, ball_radius_u
    mulss xmm3, xmm4
    movss xmm1, net_top_u
    addss xmm1, net_clearance_u
    subss xmm1, xmm3
    comiss xmm1, float_zero
    jbe ball_vault_velocity_restore
    addss xmm1, xmm1
    mulss xmm4, xmm5
    mulss xmm4, gravity_u_per_s2
    divss xmm1, xmm4
    sqrtss xmm1, xmm1
    maxss xmm2, xmm1
ball_vault_velocity_restore:
    movss xmm1, ball_target_z_u
ball_vault_velocity:
    subss xmm0, ball_pos.x
    divss xmm0, xmm2
    movss ball_vel_u_per_s.x, xmm0
    subss xmm1, ball_pos.z
    divss xmm1, xmm2
    movss ball_vel_u_per_s.z, xmm1
    movaps xmm3, xmm2
    mulss xmm3, xmm2
    mulss xmm3, gravity_u_per_s2
    mulss xmm3, float_half
    movss xmm4, ball_pos.y
    subss xmm4, ball_radius_u
    subss xmm3, xmm4
    divss xmm3, xmm2
    movss ball_vel_u_per_s.y, xmm3
    mulss xmm2, float_ticks_per_second
    cvtss2si eax, xmm2
    mov ball_flight_ticks_left, eax
    ret
ball_vault ENDP

ball_tick PROC
    push rbx
    push rsi
    sub rsp, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 2, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    movss xmm0, gravity_u_per_s2
    mulss xmm0, tick_seconds
    movss xmm1, ball_vel_u_per_s.y
    subss xmm1, xmm0
    movss ball_vel_u_per_s.y, xmm1
    movss xmm0, ball_vel_u_per_s.x
    mulss xmm0, tick_seconds
    addss xmm0, ball_pos.x
    movss ball_pos.x, xmm0
    mulss xmm1, tick_seconds
    addss xmm1, ball_pos.y
    movss ball_pos.y, xmm1
    movss xmm0, ball_vel_u_per_s.z
    mulss xmm0, tick_seconds
    addss xmm0, ball_pos.z
    movss ball_pos.z, xmm0
    movss xmm0, ball_spin_radians_per_s
    mulss xmm0, tick_seconds
    addss xmm0, ball_spin_radians
    comiss xmm0, float_two_pi
    jb ball_tick_spin_ready
    subss xmm0, float_two_pi
ball_tick_spin_ready:
    movss ball_spin_radians, xmm0
    counter_down_to_zero ball_flight_ticks_left

    mov eax, ball_trail_next_index
    imul ecx, eax, SIZEOF VEC3
    lea rdx, ball_trail
    add rdx, rcx
    movss xmm0, ball_pos.x
    movss (VEC3 PTR [rdx]).x, xmm0
    movss xmm0, ball_pos.y
    movss (VEC3 PTR [rdx]).y, xmm0
    movss xmm0, ball_pos.z
    movss (VEC3 PTR [rdx]).z, xmm0
    inc eax
    and eax, BALL_TRAIL_LENGTH - 1
    mov ball_trail_next_index, eax
    cmp ball_trail_count, BALL_TRAIL_LENGTH
    jae ball_tick_flame
    inc ball_trail_count

ball_tick_flame:
    call rally_multiplier_get
    mov ebx, eax
    call ball_heat_index_get
    cmp eax, BALL_HEAT_COLOR_COUNT - 1
    jae ball_tick_flame_spawn
    cmp ebx, BALL_FLAME_MULTIPLIER_MIN
    jb ball_tick_hit_check
ball_tick_flame_spawn:
    movss xmm4, ball_vel_u_per_s.x
    mulss xmm4, ball_flame_back_factor
    movss xmm5, ball_vel_u_per_s.z
    mulss xmm5, ball_flame_back_factor
    movss xmm0, ball_pos.x
    movss xmm1, ball_pos.y
    movss xmm2, ball_pos.z
    cmp ebx, BALL_RAINBOW_FLAME_MULTIPLIER_MIN
    jae ball_tick_flame_rainbow
    particles_spawn_call particles_flame, COLOR_FLAME_BGRA, xmm4, xmm5
    jmp ball_tick_hit_check
ball_tick_flame_rainbow:
    particles_spawn_call particles_flame_rainbow, COLOR_BLACK_BGRA, xmm4, xmm5

ball_tick_hit_check:
    mov ebx, SIDE_NEAR
    xorps xmm0, xmm0
    comiss xmm0, ball_pos.z
    ja ball_tick_receiver_known
    mov ebx, SIDE_FAR
ball_tick_receiver_known:
    cmp ebx, ball_last_hitter_side
    je ball_tick_ground
    player_address_load rsi, ebx
    movss xmm0, ball_pos.x
    subss xmm0, (PLAYER PTR [rsi]).pos_x_u
    mulss xmm0, xmm0
    movss xmm1, ball_pos.y
    subss xmm1, fighter_hit_height_u
    mulss xmm1, xmm1
    addss xmm0, xmm1
    movss xmm1, ball_pos.z
    subss xmm1, (PLAYER PTR [rsi]).pos_z_u
    mulss xmm1, xmm1
    addss xmm0, xmm1
    movss xmm1, (PLAYER PTR [rsi]).reach_u
    mulss xmm1, xmm1
    comiss xmm0, xmm1
    ja ball_tick_ground
    mov ecx, ebx
    call ball_hit
    jmp ball_tick_done

ball_tick_ground:
    movss xmm0, ball_pos.y
    comiss xmm0, ball_radius_u
    ja ball_tick_done
    movss xmm0, ball_radius_u
    movss ball_pos.y, xmm0
    mov ecx, ebx
    call ball_land

ball_tick_done:
    add rsp, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    pop rsi
    pop rbx
    ret
ball_tick ENDP

ball_hit PROC
    push rbx
    push rsi
    push rdi
    push r12
    sub rsp, BALL_HIT_FRAME_BYTES
    frame_alignment_check 4, BALL_HIT_FRAME_BYTES
    mov ebx, ecx
    assert_below_unsigned ebx, SIDE_COUNT
    player_address_load rsi, ebx
    mov ecx, (PLAYER PTR [rsi]).character_index
    call character_address_load
    mov rdi, rax

    inc rally_combo
    mov eax, rally_combo
    counter_raise_to match_best_combo, eax
    mov ecx, upgrade_level(rsi, UPGRADE_KIND_POWER_HIT)
    imul ecx, ecx, CRIT_CHANCE_PER_POWER_LEVEL_PERCENT
    add ecx, (CHARACTER PTR [rdi]).crit_percent
    mov eax, CRIT_CHANCE_MAX_PERCENT
    cmp ecx, eax
    cmova ecx, eax
    mov r8d, ecx
    mov ecx, PERCENT_COUNT
    random_below_to_eax ecx
    xor r12d, r12d
    cmp eax, r8d
    setb r12b

    cvtsi2ss xmm0, upgrade_level(rsi, UPGRADE_KIND_WIDE_AIM)
    mulss xmm0, aim_range_per_wide_aim_level_u
    addss xmm0, (CHARACTER PTR [rdi]).aim_range_u
    movss dword ptr [rsp + BALL_HIT_LOCAL_AIM_RANGE], xmm0
    cmp ebx, SIDE_NEAR
    jne ball_hit_cpu_aim
    movss xmm0, (PLAYER PTR [rsi]).facing_x
    mulss xmm0, dword ptr [rsp + BALL_HIT_LOCAL_AIM_RANGE]
    addss xmm0, ball_pos.x
    random_signed_unit_float_to xmm1
    mulss xmm1, aim_random_x_u
    addss xmm0, xmm1
    movss dword ptr [rsp + BALL_HIT_LOCAL_TARGET_X], xmm0
    movss xmm0, (PLAYER PTR [rsi]).facing_z
    mulss xmm0, (PLAYER PTR [rsi]).side_z_sign
    xorps xmm0, xmmword ptr float_sign_mask_x4
    mulss xmm0, aim_depth_facing_weight
    addss xmm0, aim_depth_center
    random_signed_unit_float_to xmm1
    mulss xmm1, aim_depth_random
    addss xmm0, xmm1
    jmp ball_hit_aim_ready
ball_hit_cpu_aim:
    lea rax, players[SIZEOF PLAYER * SIDE_NEAR]
    movss xmm0, (PLAYER PTR [rax]).pos_x_u
    mulss xmm0, cpu_aim_away_factor
    random_signed_unit_float_to xmm1
    mulss xmm1, dword ptr [rsp + BALL_HIT_LOCAL_AIM_RANGE]
    mulss xmm1, cpu_aim_random_factor
    addss xmm0, xmm1
    movss dword ptr [rsp + BALL_HIT_LOCAL_TARGET_X], xmm0
    random_signed_unit_float_to xmm0
    mulss xmm0, cpu_depth_random
    addss xmm0, cpu_depth_center
ball_hit_aim_ready:
    float_clamp xmm0, float_zero, float_one
    mulss xmm0, aim_depth_range_u
    addss xmm0, aim_depth_min_u
    mulss xmm0, (PLAYER PTR [rsi]).side_z_sign
    xorps xmm0, xmmword ptr float_sign_mask_x4
    movss dword ptr [rsp + BALL_HIT_LOCAL_TARGET_Z], xmm0
    movss xmm0, dword ptr [rsp + BALL_HIT_LOCAL_TARGET_X]
    float_clamp_symmetric xmm0, xmm1, aim_x_limit_u
    movss dword ptr [rsp + BALL_HIT_LOCAL_TARGET_X], xmm0

    cvtsi2ss xmm2, upgrade_level(rsi, UPGRADE_KIND_POWER_HIT)
    mulss xmm2, power_flight_factor_per_level
    movss xmm3, float_one
    subss xmm3, xmm2
    maxss xmm3, power_flight_factor_min
    cvtsi2ss xmm2, rally_combo
    mulss xmm2, flight_factor_per_combo
    movss xmm4, float_one
    subss xmm4, xmm2
    maxss xmm4, flight_factor_min
    mulss xmm3, xmm4
    mulss xmm3, (CHARACTER PTR [rdi]).flight_time_s
    test r12d, r12d
    jz ball_hit_flight_ready
    mulss xmm3, crit_flight_factor
ball_hit_flight_ready:
    movaps xmm2, xmm3
    movss xmm0, dword ptr [rsp + BALL_HIT_LOCAL_TARGET_X]
    movss xmm1, dword ptr [rsp + BALL_HIT_LOCAL_TARGET_Z]
    call ball_vault
    mov ball_last_hitter_side, ebx
    cmp ebx, SIDE_NEAR
    jne ball_hit_effects
    call cpu_receive_plan

ball_hit_effects:
    mov (PLAYER PTR [rsi]).swing_ticks_left, SWING_TICKS
    mov (PLAYER PTR [rsi]).flash_ticks_left, FIGHTER_FLASH_TICKS
    mov ball_pop_ticks_left, BALL_POP_TICKS
    lea rcx, punch_player_hit
    cmp ebx, SIDE_NEAR
    je ball_hit_punch_crit_check
    lea rcx, punch_cpu_hit
ball_hit_punch_crit_check:
    test r12d, r12d
    jz ball_hit_punch
    lea rcx, punch_player_crit
    cmp ebx, SIDE_NEAR
    je ball_hit_punch
    lea rcx, punch_cpu_crit
ball_hit_punch:
    call screen_punch

    movss xmm4, ball_vel_u_per_s.x
    mulss xmm4, particle_hit_speed_factor
    movss xmm5, ball_vel_u_per_s.z
    mulss xmm5, particle_hit_speed_factor
    movss xmm0, ball_pos.x
    movss xmm1, ball_pos.y
    movss xmm2, ball_pos.z
    test r12d, r12d
    jnz ball_hit_crit_effects
    side_color_load eax, rbx
    particles_spawn_call particles_hit, eax, xmm4, xmm5
    jmp ball_hit_sound
ball_hit_crit_effects:
    particles_spawn_call particles_crit, COLOR_BLACK_BGRA, xmm4, xmm5
    inc match_crit_count
    movss xmm0, ball_pos.x
    movss xmm1, ball_pos.y
    movss xmm2, ball_pos.z
    call screen_position_from_world
    movaps xmm2, xmm0
    movaps xmm3, xmm1
    addss xmm3, popup_rise_above_px
    popup_spawn_call text_popup_crit, POPUP_NO_NUMBER, popup_style_crit
    audio_play_call sound_zap, 0, VOLUME_LOUD, 0
    audio_play_call sound_boom, 0, VOLUME_NORMAL, 0

ball_hit_sound:
    mov eax, rally_combo
    mov ecx, AUDIO_SEMITONE_MAX
    cmp eax, ecx
    cmova eax, ecx
    audio_play_call sound_hit, eax, VOLUME_NORMAL, 0
    cmp rally_combo, COMBO_POPUP_MIN
    jb ball_hit_multiplier_check
    movss xmm0, ball_pos.x
    movss xmm1, ball_pos.y
    movss xmm2, ball_pos.z
    call screen_position_from_world
    movaps xmm2, xmm0
    movaps xmm3, xmm1
    addss xmm3, popup_combo_below_px
    popup_spawn_call text_empty, rally_combo, popup_style_combo, text_popup_hits_suffix

ball_hit_multiplier_check:
    mov eax, rally_combo
    xor edx, edx
    mov ecx, COMBO_HITS_PER_MULTIPLIER
    div ecx
    test edx, edx
    jnz ball_hit_done
    add eax, rally_serve_multiplier_bonus
    inc eax
    cmp eax, RALLY_MULTIPLIER_MAX
    ja ball_hit_done
    mov ebx, eax
    mov multiplier_pop_ticks_left, MULTIPLIER_POP_TICKS
    xorps xmm2, xmm2
    movss xmm3, popup_banner_rally_y_px
    popup_spawn_call text_popup_multiplier_prefix, ebx, popup_style_banner, text_popup_exclamation
    screen_punch_call punch_multiplier_up
    mov ecx, MULTIPLIER_UP_ARPEGGIO_NOTES
    mov edx, ebx
    call audio_arpeggio_play

ball_hit_done:
    add rsp, BALL_HIT_FRAME_BYTES
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
ball_hit ENDP

ball_land PROC
    push rbx
    push rsi
    sub rsp, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 2, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    mov ebx, ecx
    assert_below_unsigned ebx, SIDE_COUNT
    player_address_load rsi, ebx
    cmp upgrade_level(rsi, UPGRADE_KIND_SHIELD), 0
    je ball_land_point
    dec upgrade_level(rsi, UPGRADE_KIND_SHIELD)
    movss xmm1, shield_revault_depth_u
    mulss xmm1, (PLAYER PTR [rsi]).side_z_sign
    xorps xmm1, xmmword ptr float_sign_mask_x4
    random_signed_unit_float_to xmm0
    mulss xmm0, shield_revault_x_spread_u
    movss xmm2, shield_revault_flight_s
    call ball_vault
    mov ball_last_hitter_side, ebx
    cmp ebx, SIDE_NEAR
    jne ball_land_shield_effects
    call cpu_receive_plan
ball_land_shield_effects:
    screen_punch_call punch_shield
    side_color_load eax, rbx
    movss xmm0, ball_pos.x
    movss xmm1, ball_pos.y
    movss xmm2, ball_pos.z
    particles_spawn_call particles_shield, eax
    movss xmm0, ball_pos.x
    movss xmm1, ball_pos.y
    movss xmm2, ball_pos.z
    call screen_position_from_world
    movaps xmm2, xmm0
    movaps xmm3, xmm1
    addss xmm3, popup_rise_above_px
    popup_spawn_call text_popup_saved, POPUP_NO_NUMBER, popup_style_info
    audio_play_call sound_shield, 0, VOLUME_LOUD, 0
    jmp ball_land_done
ball_land_point:
    mov ecx, ebx
    call point_score
ball_land_done:
    add rsp, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    pop rsi
    pop rbx
    ret
ball_land ENDP

point_score PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_8_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_8_ARGS_ODD_PUSHES_BYTES
    mov ebx, ecx
    assert_below_unsigned ebx, SIDE_COUNT
    mov match_point_loser_side, ebx
    call rally_multiplier_get
    mov edi, eax
    mov ecx, ebx
    xor ecx, SIDE_FLIP
    player_address_load rsi, ecx
    mov eax, (PLAYER PTR [rsi]).score
    add eax, edi
    mov ecx, SCORE_MAX
    cmp eax, ecx
    cmova eax, ecx
    mov (PLAYER PTR [rsi]).score, eax
    mov background_flash_ticks_left, BACKGROUND_FLASH_TICKS
    match_mode_set MATCH_MODE_POINT_SCORED

    lea rcx, punch_point
    cmp edi, POINT_BIG_MIN
    jb point_score_punch
    lea rcx, punch_point_big
    cmp edi, POINT_JACKPOT_MIN
    jb point_score_punch
    lea rcx, punch_jackpot
point_score_punch:
    call screen_punch
    cmp (PLAYER PTR [rsi]).score, MATCH_WINNING_SCORE
    jb point_score_burst
    screen_punch_call punch_match_won

point_score_burst:
    mov eax, ebx
    xor eax, SIDE_FLIP
    side_color_load eax, rax
    movss xmm0, ball_pos.x
    movss xmm1, ball_pos.y
    movss xmm2, ball_pos.z
    particles_spawn_call particles_land, eax
    movss xmm0, ball_pos.x
    movss xmm1, ball_pos.y
    movss xmm2, ball_pos.z
    call screen_position_from_world
    movaps xmm2, xmm0
    movaps xmm3, xmm1
    addss xmm3, popup_rise_above_px
    popup_spawn_call text_popup_plus, edi, popup_style_points
    audio_play_call sound_point, 0, VOLUME_NORMAL, 0
    audio_play_call sound_boom, 0, VOLUME_LOUD, 0

    cmp edi, POINT_BIG_MIN
    jb point_score_done
    mov ebx, edi
point_score_coins:
    movss xmm0, ball_pos.x
    movss xmm1, ball_pos.y
    movss xmm2, ball_pos.z
    particles_spawn_call particles_coins, COLOR_GOLD_BGRA
    dec ebx
    jnz point_score_coins
    xorps xmm2, xmm2
    movss xmm3, popup_banner_middle_y_px
    popup_spawn_call text_popup_times, edi, popup_style_banner, text_popup_points_suffix
    lea ecx, [rdi + POINT_ARPEGGIO_EXTRA_NOTES]
    mov eax, AUDIO_ARPEGGIO_NOTE_COUNT
    cmp ecx, eax
    cmova ecx, eax
    xor edx, edx
    call audio_arpeggio_play
    cmp edi, POINT_JACKPOT_MIN
    jb point_score_done
    inc match_jackpot_count
    xorps xmm2, xmm2
    movss xmm3, popup_banner_low_y_px
    popup_spawn_call text_popup_jackpot, POPUP_NO_NUMBER, popup_style_jackpot

point_score_done:
    add rsp, FRAME_8_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
point_score ENDP

rally_multiplier_get PROC
    mov eax, rally_combo
    xor edx, edx
    mov ecx, COMBO_HITS_PER_MULTIPLIER
    div ecx
    add eax, rally_serve_multiplier_bonus
    inc eax
    mov ecx, RALLY_MULTIPLIER_MAX
    cmp eax, ecx
    cmova eax, ecx
    ret
rally_multiplier_get ENDP

ball_heat_index_get PROC
    mov eax, rally_combo
    xor edx, edx
    mov ecx, BALL_HEAT_COMBO_PER_LEVEL
    div ecx
    mov ecx, BALL_HEAT_COLOR_COUNT - 1
    cmp eax, ecx
    cmova eax, ecx
    ret
ball_heat_index_get ENDP

frame_render PROC
    push rbx
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 1, FRAME_6_ARGS_ODD_PUSHES_BYTES
    call camera_basis_compute
    call arena_draw
    cmp match_mode, MATCH_MODE_CHARACTER_SELECT
    jne frame_render_match
    call select_screen_draw
    jmp frame_render_effects

frame_render_match:
    call shadows_draw
    mov ecx, SIDE_FAR
    call fighter_draw
    movss xmm0, ball_pos.z
    comiss xmm0, float_zero
    jbe frame_render_net_first
    call ball_draw
    call net_draw
    jmp frame_render_near
frame_render_net_first:
    call net_draw
    call ball_draw
frame_render_near:
    mov ecx, SIDE_NEAR
    call fighter_draw
    call hud_draw
    mov eax, match_mode
    cmp eax, MATCH_MODE_UPGRADE_CHOOSE
    je frame_render_upgrade_screen
    cmp eax, MATCH_MODE_UPGRADE_TAKEN
    je frame_render_upgrade_screen
    cmp eax, MATCH_MODE_OVER
    jne frame_render_effects
    call over_screen_draw
    jmp frame_render_effects
frame_render_upgrade_screen:
    call upgrade_screen_draw
frame_render_effects:
    call particles_draw
    call popups_draw
    call frame_post_effects
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rbx
    ret
frame_render ENDP

ball_visible_check PROC
    xor eax, eax
    mov ecx, match_mode
    cmp ecx, MATCH_MODE_RALLY
    je ball_visible_check_yes
    cmp ecx, MATCH_MODE_POINT_SCORED
    je ball_visible_check_yes
    cmp ecx, MATCH_MODE_SERVE_WAIT
    jne ball_visible_check_done
    test match_mode_ticks, SERVE_BLINK_BIT_MASK
    jnz ball_visible_check_done
ball_visible_check_yes:
    mov eax, 1
ball_visible_check_done:
    ret
ball_visible_check ENDP

shadows_draw PROC
    push rbx
    push rsi
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 2, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    xor ebx, ebx
shadows_draw_fighter:
    player_address_load rsi, ebx
    mov ecx, (PLAYER PTR [rsi]).character_index
    call character_address_load
    movss xmm2, fighter_shadow_radius_u
    mulss xmm2, (CHARACTER PTR [rax]).model_scale
    movss xmm0, (PLAYER PTR [rsi]).pos_x_u
    movss xmm1, (PLAYER PTR [rsi]).pos_z_u
    call ground_shadow_draw
    inc ebx
    cmp ebx, SIDE_COUNT
    jb shadows_draw_fighter
    call ball_visible_check
    test eax, eax
    jz shadows_draw_done
    movss xmm2, ball_pos.y
    mulss xmm2, ball_shadow_shrink_per_u
    movss xmm0, ball_shadow_radius_max_u
    subss xmm0, xmm2
    maxss xmm0, ball_shadow_radius_min_u
    movaps xmm2, xmm0
    movss xmm0, ball_pos.x
    movss xmm1, ball_pos.z
    call ground_shadow_draw
shadows_draw_done:
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    pop rsi
    pop rbx
    ret
shadows_draw ENDP

fighter_draw PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_4_ARGS_ODD_PUSHES_BYTES
    mov ebx, ecx
    assert_below_unsigned ebx, SIDE_COUNT
    player_address_load rsi, ebx
    mov eax, (PLAYER PTR [rsi]).character_index
    mov fighter_pose.character_index, eax
    movss xmm0, (PLAYER PTR [rsi]).facing_x
    movss fighter_pose.facing_x, xmm0
    movss xmm0, (PLAYER PTR [rsi]).facing_z
    movss fighter_pose.facing_z, xmm0
    movss xmm0, (PLAYER PTR [rsi]).walk_phase_radians
    movss fighter_pose.walk_phase_radians, xmm0
    xorps xmm0, xmm0
    movss fighter_pose.pos.y, xmm0
    movss fighter_pose.walk_amount, xmm0
    movss fighter_pose.swing_fraction, xmm0
    xor edi, edi
fighter_draw_ghost:
    mov eax, dword ptr [rsi + PLAYER.ghost_ticks_left + rdi * 4]
    test eax, eax
    jz fighter_draw_ghost_next
    imul edx, eax, GHOST_LEVEL_PER_TICK
    add edx, GHOST_LEVEL_BASE
    side_color_load ecx, rbx
    call color_scale
    mov fighter_pose.color_override_bgra, eax
    movss xmm0, dword ptr [rsi + PLAYER.ghost_x_u + rdi * 4]
    movss fighter_pose.pos.x, xmm0
    movss xmm0, dword ptr [rsi + PLAYER.ghost_z_u + rdi * 4]
    movss fighter_pose.pos.z, xmm0
    lea rcx, fighter_pose
    call character_draw
fighter_draw_ghost_next:
    inc edi
    cmp edi, GHOST_COUNT
    jb fighter_draw_ghost

    movss xmm0, (PLAYER PTR [rsi]).pos_x_u
    movss fighter_pose.pos.x, xmm0
    movss xmm0, (PLAYER PTR [rsi]).pos_z_u
    movss fighter_pose.pos.z, xmm0
    movss xmm0, (PLAYER PTR [rsi]).walk_amount
    movss fighter_pose.walk_amount, xmm0
    cvtsi2ss xmm0, (PLAYER PTR [rsi]).swing_ticks_left
    mov eax, SWING_TICKS
    cvtsi2ss xmm1, eax
    divss xmm0, xmm1
    movss fighter_pose.swing_fraction, xmm0
    mov fighter_pose.color_override_bgra, COLOR_NONE_BGRA
    cmp (PLAYER PTR [rsi]).flash_ticks_left, 0
    je fighter_draw_body
    mov fighter_pose.color_override_bgra, COLOR_WHITE_BGRA
fighter_draw_body:
    lea rcx, fighter_pose
    call character_draw
    add rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
fighter_draw ENDP

ball_color_get PROC
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 0, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    call rally_multiplier_get
    cmp eax, BALL_RAINBOW_MULTIPLIER_MIN
    jb ball_color_get_gold_check
    mov eax, effects_ticks
    shr eax, 1
    rainbow_color_from_eax eax
    jmp ball_color_get_done
ball_color_get_gold_check:
    cmp eax, BALL_GOLD_MULTIPLIER_MIN
    jb ball_color_get_heat
    mov eax, COLOR_GOLD_BGRA
    jmp ball_color_get_done
ball_color_get_heat:
    call ball_heat_index_get
    lea rcx, ball_heat_color_bgra
    mov eax, dword ptr [rcx + rax * 4]
ball_color_get_done:
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    ret
ball_color_get ENDP

ball_draw PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_6_ARGS_ODD_PUSHES_BYTES
    call ball_visible_check
    test eax, eax
    jz ball_draw_done
    call ball_color_get
    mov edi, eax

    cmp match_mode, MATCH_MODE_RALLY
    jne ball_draw_trail
    cmp ball_flight_ticks_left, 0
    je ball_draw_trail
    movss xmm0, ball_target_x_u
    movss ball_marker_center.x, xmm0
    movss xmm0, landing_marker_height_u
    movss ball_marker_center.y, xmm0
    movss xmm0, ball_target_z_u
    movss ball_marker_center.z, xmm0
    cvtsi2ss xmm0, effects_ticks
    mulss xmm0, landing_marker_pulse_radians_per_tick
    call math_sin
    mulss xmm0, landing_marker_pulse_u
    addss xmm0, landing_marker_radius_u
    movss ball_marker_half.x, xmm0
    movss ball_marker_half.z, xmm0
    xorps xmm0, xmm0
    movss ball_marker_half.y, xmm0
    mov eax, SIDE_NEAR
    xorps xmm0, xmm0
    comiss xmm0, ball_target_z_u
    ja ball_draw_marker_side_ready
    mov eax, SIDE_FAR
ball_draw_marker_side_ready:
    side_color_load r9d, rax
    mov ecx, PRIMITIVE_KIND_RING
    lea rdx, ball_marker_center
    lea r8, ball_marker_half
    call primitive_draw

ball_draw_trail:
    cmp match_mode, MATCH_MODE_RALLY
    jne ball_draw_body
    call rally_multiplier_get
    mov ebx, eax
    mov esi, 1
ball_draw_trail_segment:
    cmp esi, ball_trail_count
    jae ball_draw_body
    mov eax, ball_trail_next_index
    sub eax, esi
    and eax, BALL_TRAIL_LENGTH - 1
    imul eax, eax, SIZEOF VEC3
    lea rcx, ball_trail
    lea rdx, world_line_points
    movss xmm0, (VEC3 PTR [rcx + rax]).x
    movss (VEC3 PTR [rdx]).x, xmm0
    movss xmm0, (VEC3 PTR [rcx + rax]).y
    movss (VEC3 PTR [rdx]).y, xmm0
    movss xmm0, (VEC3 PTR [rcx + rax]).z
    movss (VEC3 PTR [rdx]).z, xmm0
    mov eax, ball_trail_next_index
    sub eax, esi
    dec eax
    and eax, BALL_TRAIL_LENGTH - 1
    imul eax, eax, SIZEOF VEC3
    movss xmm0, (VEC3 PTR [rcx + rax]).x
    movss (VEC3 PTR [rdx + SIZEOF VEC3]).x, xmm0
    movss xmm0, (VEC3 PTR [rcx + rax]).y
    movss (VEC3 PTR [rdx + SIZEOF VEC3]).y, xmm0
    movss xmm0, (VEC3 PTR [rcx + rax]).z
    movss (VEC3 PTR [rdx + SIZEOF VEC3]).z, xmm0
    mov ecx, edi
    cmp ebx, BALL_RAINBOW_MULTIPLIER_MIN
    jb ball_draw_trail_color_ready
    lea eax, [rsi * 2]
    add eax, effects_ticks
    rainbow_color_from_eax ecx
ball_draw_trail_color_ready:
    mov edx, BALL_TRAIL_LENGTH
    sub edx, esi
    imul edx, edx, BALL_TRAIL_LEVEL_PER_STEP
    call color_scale
    mov edx, eax
    lea rcx, world_line_points
    call world_line_draw
    inc esi
    jmp ball_draw_trail_segment

ball_draw_body:
    movss xmm0, ball_spin_radians
    call math_cos
    movss dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5], xmm0
    movss xmm0, ball_spin_radians
    call math_sin
    movss dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5 + 4], xmm0
    movss xmm5, ball_radius_u
    cmp ball_pop_ticks_left, 0
    je ball_draw_radius_ready
    addss xmm5, ball_pop_extra_radius_u
ball_draw_radius_ready:
    movss xmm3, dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5]
    mulss xmm3, xmm5
    movss xmm4, dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5 + 4]
    mulss xmm4, xmm5
    lea rcx, mesh_scratch_vertices
    movss xmm0, ball_pos.x
    addss xmm0, xmm3
    movss (VEC3 PTR [rcx]).x, xmm0
    movss xmm0, ball_pos.y
    movss (VEC3 PTR [rcx]).y, xmm0
    movss xmm0, ball_pos.z
    addss xmm0, xmm4
    movss (VEC3 PTR [rcx]).z, xmm0
    movss xmm0, ball_pos.x
    subss xmm0, xmm3
    movss (VEC3 PTR [rcx + SIZEOF VEC3]).x, xmm0
    movss xmm0, ball_pos.y
    movss (VEC3 PTR [rcx + SIZEOF VEC3]).y, xmm0
    movss xmm0, ball_pos.z
    subss xmm0, xmm4
    movss (VEC3 PTR [rcx + SIZEOF VEC3]).z, xmm0
    movss xmm0, ball_pos.x
    movss (VEC3 PTR [rcx + 2 * SIZEOF VEC3]).x, xmm0
    movss (VEC3 PTR [rcx + 3 * SIZEOF VEC3]).x, xmm0
    movss xmm0, ball_pos.y
    addss xmm0, xmm5
    movss (VEC3 PTR [rcx + 2 * SIZEOF VEC3]).y, xmm0
    movss xmm0, ball_pos.y
    subss xmm0, xmm5
    movss (VEC3 PTR [rcx + 3 * SIZEOF VEC3]).y, xmm0
    movss xmm0, ball_pos.z
    movss (VEC3 PTR [rcx + 2 * SIZEOF VEC3]).z, xmm0
    movss (VEC3 PTR [rcx + 3 * SIZEOF VEC3]).z, xmm0
    movss xmm0, ball_pos.x
    subss xmm0, xmm4
    movss (VEC3 PTR [rcx + 4 * SIZEOF VEC3]).x, xmm0
    movss xmm0, ball_pos.y
    movss (VEC3 PTR [rcx + 4 * SIZEOF VEC3]).y, xmm0
    movss xmm0, ball_pos.z
    addss xmm0, xmm3
    movss (VEC3 PTR [rcx + 4 * SIZEOF VEC3]).z, xmm0
    movss xmm0, ball_pos.x
    addss xmm0, xmm4
    movss (VEC3 PTR [rcx + 5 * SIZEOF VEC3]).x, xmm0
    movss xmm0, ball_pos.y
    movss (VEC3 PTR [rcx + 5 * SIZEOF VEC3]).y, xmm0
    movss xmm0, ball_pos.z
    subss xmm0, xmm3
    movss (VEC3 PTR [rcx + 5 * SIZEOF VEC3]).z, xmm0
    mov dword ptr [rsp + CALL_ARG5], edi
    lea rax, primitives[PRIMITIVE_KIND_DIAMOND * SIZEOF PRIMITIVE]
    lea rcx, mesh_scratch_vertices
    mov edx, (PRIMITIVE PTR [rax]).vertex_count
    mov r8, (PRIMITIVE PTR [rax]).edges
    mov r9d, (PRIMITIVE PTR [rax]).edge_count
    call mesh_draw
ball_draw_done:
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
ball_draw ENDP
