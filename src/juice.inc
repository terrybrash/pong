PARTICLE_COUNT_MAX                  equ 512
.ERRNZ PARTICLE_COUNT_MAX AND (PARTICLE_COUNT_MAX - 1)
PARTICLE_LEVEL_PER_LIFE_TICK        equ 6
PARTICLE_COLOR_MODE_ARGUMENT        equ 0
PARTICLE_COLOR_MODE_RANDOM_HUE      equ 1
PARTICLE_SIZE_NEAR_PX               equ 2
PARTICLE_SIZE_FAR_PX                equ 1
PARTICLES_SPAWN_BURST_PUSHED_REGISTER_COUNT equ 1
PARTICLES_SPAWN_BURST_ARG5          equ 8 * PARTICLES_SPAWN_BURST_PUSHED_REGISTER_COUNT + CALLEE_ARG5
PARTICLES_SPAWN_BURST_ARG6          equ 8 * PARTICLES_SPAWN_BURST_PUSHED_REGISTER_COUNT + CALLEE_ARG6
PARTICLES_SPAWN_BURST_ARG7          equ 8 * PARTICLES_SPAWN_BURST_PUSHED_REGISTER_COUNT + CALLEE_ARG7
POPUP_COUNT                         equ 16
.ERRNZ POPUP_COUNT AND (POPUP_COUNT - 1)
POPUP_TEXT_BYTES                    equ 32
POPUP_POP_BIG_TICKS                 equ 4
POPUP_POP_TICKS                     equ 9
POPUP_BLINK_TICKS                   equ 16
POPUP_BLINK_BIT_MASK                equ 4
POPUP_SPAWN_PUSHED_REGISTER_COUNT   equ 3
POPUP_SPAWN_ARG5                    equ FRAME_4_ARGS_ODD_PUSHES_BYTES + 8 * POPUP_SPAWN_PUSHED_REGISTER_COUNT + CALLEE_ARG5
POPUP_SPAWN_ARG6                    equ POPUP_SPAWN_ARG5 + 8
SCORE_ROLL_PERIOD_TICKS             equ 4
.ERRNZ SCORE_ROLL_PERIOD_TICKS AND (SCORE_ROLL_PERIOD_TICKS - 1)
SCORE_POP_TICKS                     equ 6
BACKGROUND_FLASH_TICKS              equ 12
BACKGROUND_FLASH_LEVEL_PER_TICK     equ 7
SLOW_MO_TICK_DIVISOR                equ 3

PARTICLE STRUCT
    pos                             VEC3 <>
    vel_u_per_s                     VEC3 <>
    gravity_u_per_s2                REAL4 ?
    life_ticks_left                 DWORD ?
    color_bgra                      DWORD ?
    particle_padding                DWORD ?
PARTICLE ENDS

PARTICLE_STYLE STRUCT
    burst_count                     DWORD ?
    spread_u_per_s                  REAL4 ?
    base_vel_y_u_per_s              REAL4 ?
    gravity_u_per_s2                REAL4 ?
    life_min_ticks                  DWORD ?
    life_random_ticks               DWORD ?
    color_mode                      DWORD ?
PARTICLE_STYLE ENDS

POPUP_STYLE STRUCT
    scale_base                      DWORD ?
    color_bgra                      DWORD ?
    life_ticks                      DWORD ?
    vel_y_px_per_tick               REAL4 ?
POPUP_STYLE ENDS

POPUP STRUCT
    pos_x_px                        REAL4 ?
    pos_y_px                        REAL4 ?
    vel_y_px_per_tick               REAL4 ?
    life_ticks_left                 DWORD ?
    life_ticks_total                DWORD ?
    scale_base                      DWORD ?
    color_bgra                      DWORD ?
    text_bytes                      BYTE POPUP_TEXT_BYTES DUP (?)
POPUP ENDS

PUNCH STRUCT
    shake_px                        REAL4 ?
    shake_ticks                     DWORD ?
    flash_color_bgra                DWORD ?
    flash_ticks                     DWORD ?
    chroma_ticks                    DWORD ?
    zoom_ticks                      DWORD ?
    hit_stop_ticks                  DWORD ?
    slow_mo_ticks                   DWORD ?
PUNCH ENDS

.const
particle_drag_per_tick              REAL4 0.985
particle_near_depth_u               REAL4 9.0
popup_banner_top_y_px               REAL4 -56.0
popup_banner_middle_y_px            REAL4 -26.0
popup_banner_low_y_px               REAL4 24.0
popup_banner_rally_y_px             REAL4 -24.0
popup_banner_bottom_y_px            REAL4 64.0
popup_rise_above_px                 REAL4 -14.0
popup_combo_below_px                REAL4 10.0

particles_hit                       PARTICLE_STYLE <16, 2.4, 1.5, 7.0, 14, 18, PARTICLE_COLOR_MODE_ARGUMENT>
particles_crit                      PARTICLE_STYLE <50, 5.0, 2.5, 6.0, 20, 30, PARTICLE_COLOR_MODE_RANDOM_HUE>
particles_dash                      PARTICLE_STYLE <14, 1.4, 1.0, 4.0, 12, 14, PARTICLE_COLOR_MODE_ARGUMENT>
particles_land                      PARTICLE_STYLE <60, 4.2, 4.0, 10.0, 24, 30, PARTICLE_COLOR_MODE_ARGUMENT>
particles_coins                     PARTICLE_STYLE <24, 2.6, 6.5, 13.0, 50, 40, PARTICLE_COLOR_MODE_ARGUMENT>
particles_flame                     PARTICLE_STYLE <1, 0.6, 0.9, -1.5, 8, 10, PARTICLE_COLOR_MODE_ARGUMENT>
particles_flame_rainbow             PARTICLE_STYLE <2, 0.9, 0.9, -1.5, 10, 12, PARTICLE_COLOR_MODE_RANDOM_HUE>
particles_shield                    PARTICLE_STYLE <36, 3.2, 3.5, 5.0, 20, 26, PARTICLE_COLOR_MODE_ARGUMENT>
particles_firework                  PARTICLE_STYLE <60, 5.0, 0.5, 3.5, 30, 40, PARTICLE_COLOR_MODE_RANDOM_HUE>
particles_coin_rain                 PARTICLE_STYLE <1, 0.4, -1.5, 6.0, 90, 30, PARTICLE_COLOR_MODE_ARGUMENT>
particles_select                    PARTICLE_STYLE <30, 2.2, 3.0, 7.0, 16, 20, PARTICLE_COLOR_MODE_RANDOM_HUE>
particles_reel_common               PARTICLE_STYLE <10, 3.0, 0.5, 0.0, 12, 16, PARTICLE_COLOR_MODE_ARGUMENT>
particles_reel_rare                 PARTICLE_STYLE <24, 4.0, 0.5, 0.0, 16, 20, PARTICLE_COLOR_MODE_ARGUMENT>
particles_reel_epic                 PARTICLE_STYLE <44, 5.0, 0.5, 0.0, 18, 26, PARTICLE_COLOR_MODE_ARGUMENT>
particles_reel_legendary            PARTICLE_STYLE <90, 6.0, 1.0, 4.0, 30, 40, PARTICLE_COLOR_MODE_RANDOM_HUE>
particles_upgrade_take              PARTICLE_STYLE <50, 5.0, 0.5, 0.0, 20, 30, PARTICLE_COLOR_MODE_ARGUMENT>
particles_ui_coins                  PARTICLE_STYLE <24, 4.0, 4.0, 10.0, 40, 40, PARTICLE_COLOR_MODE_ARGUMENT>

popup_style_combo                   POPUP_STYLE <TEXT_SCALE_SMALL, COLOR_COMBO_BGRA, 40, -0.6>
popup_style_crit                    POPUP_STYLE <TEXT_SCALE_HUGE, TEXT_COLOR_RAINBOW, 60, -0.35>
popup_style_banner                  POPUP_STYLE <TEXT_SCALE_LARGE, TEXT_COLOR_RAINBOW, 90, 0.0>
popup_style_jackpot                 POPUP_STYLE <TEXT_SCALE_HUGE, TEXT_COLOR_RAINBOW, 110, -0.15>
popup_style_points                  POPUP_STYLE <TEXT_SCALE_HUGE, COLOR_GOLD_BGRA, 70, -0.5>
popup_style_info                    POPUP_STYLE <TEXT_SCALE_LARGE, COLOR_WHITE_BGRA, 60, -0.3>
popup_style_rarity                  POPUP_STYLE <TEXT_SCALE_SMALL, TEXT_COLOR_RAINBOW, 50, -0.4>

punch_player_hit                    PUNCH <1.6, 10, 0, 0, 0, 5, 7, 0>
punch_player_crit                   PUNCH <4.5, 26, COLOR_WHITE_BGRA, 8, 14, 14, 12, 30>
punch_cpu_hit                       PUNCH <0.8, 8, 0, 0, 0, 2, 3, 0>
punch_cpu_crit                      PUNCH <3.5, 22, COLOR_WHITE_BGRA, 6, 12, 10, 8, 24>
punch_dash                          PUNCH <0.8, 6, 0, 0, 0, 3, 0, 0>
punch_multiplier_up                 PUNCH <2.0, 16, COLOR_GOLD_BGRA, 6, 6, 10, 0, 0>
punch_serve_multiplier              PUNCH <2.0, 14, COLOR_GOLD_BGRA, 6, 8, 10, 0, 0>
punch_shield                        PUNCH <3.0, 24, COLOR_WHITE_BGRA, 5, 6, 8, 8, 0>
punch_point                         PUNCH <4.5, 36, COLOR_WHITE_BGRA, 6, 10, 12, 14, 0>
punch_point_big                     PUNCH <6.0, 50, COLOR_GOLD_BGRA, 12, 18, 16, 16, 0>
punch_jackpot                       PUNCH <7.0, 60, COLOR_GOLD_BGRA, 16, 24, 18, 18, 0>
punch_match_won                     PUNCH <6.0, 60, COLOR_WHITE_BGRA, 20, 20, 18, 0, 90>
punch_reel_stop                     PUNCH <1.0, 6, 0, 0, 0, 4, 0, 0>
punch_reel_epic                     PUNCH <2.5, 16, 00B048FFh, 6, 8, 8, 0, 0>
punch_reroll                        PUNCH <1.5, 10, COLOR_WHITE_BGRA, 4, 4, 6, 0, 0>
punch_upgrade_take                  PUNCH <2.0, 14, COLOR_WHITE_BGRA, 6, 6, 10, 0, 0>
punch_select                        PUNCH <1.0, 6, 0, 0, 0, 4, 0, 0>
punch_fight                         PUNCH <3.0, 20, COLOR_WHITE_BGRA, 10, 10, 14, 0, 0>

text_empty                          BYTE 0
text_popup_crit                     BYTE "CRIT!", 0
text_popup_hits_suffix              BYTE " HITS!", 0
text_popup_multiplier_prefix        BYTE "MULTIPLIER *", 0
text_popup_exclamation              BYTE "!", 0
text_popup_plus                     BYTE "+", 0
text_popup_times                    BYTE "*", 0
text_popup_point_suffix             BYTE " POINT!", 0
text_popup_points_suffix            BYTE " POINTS!", 0
text_popup_jackpot                  BYTE "JACKPOT!!!", 0
text_popup_saved                    BYTE "SAVED!", 0
text_popup_match_point              BYTE "MATCH POINT!", 0
text_popup_reroll                   BYTE "REROLL!", 0
text_popup_fight                    BYTE "FIGHT!", 0

.data?
particles                           PARTICLE PARTICLE_COUNT_MAX DUP (<>)
popups                              POPUP POPUP_COUNT DUP (<>)
particle_next_index                 DWORD ?
popup_next_index                    DWORD ?
effects_ticks                       DWORD ?
hit_stop_ticks_left                 DWORD ?
slow_mo_ticks_left                  DWORD ?
screen_shake_strength_px            REAL4 ?
screen_shake_ticks_left             DWORD ?
screen_shake_duration_ticks         DWORD ?
screen_shake_offset_x_px            DWORD ?
screen_shake_offset_y_px            DWORD ?
screen_flash_ticks_left             DWORD ?
screen_flash_duration_ticks         DWORD ?
screen_flash_color_bgra             DWORD ?
screen_chroma_ticks_left            DWORD ?
screen_zoom_ticks_left              DWORD ?
screen_zoom_duration_ticks          DWORD ?
background_flash_ticks_left         DWORD ?

.code

effects_tick PROC
    push rbx
    push rsi
    sub rsp, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 2, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    inc effects_ticks

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
    movss xmm3, particle_drag_per_tick
    movss xmm4, tick_seconds
effects_tick_particle:
    cmp (PARTICLE PTR [rcx]).life_ticks_left, 0
    je effects_tick_particle_next
    dec (PARTICLE PTR [rcx]).life_ticks_left
    movss xmm0, (PARTICLE PTR [rcx]).gravity_u_per_s2
    mulss xmm0, xmm4
    movss xmm1, (PARTICLE PTR [rcx]).vel_u_per_s.y
    subss xmm1, xmm0
    mulss xmm1, xmm3
    movss (PARTICLE PTR [rcx]).vel_u_per_s.y, xmm1
    mulss xmm1, xmm4
    addss xmm1, (PARTICLE PTR [rcx]).pos.y
    movss (PARTICLE PTR [rcx]).pos.y, xmm1
    movss xmm1, (PARTICLE PTR [rcx]).vel_u_per_s.x
    mulss xmm1, xmm3
    movss (PARTICLE PTR [rcx]).vel_u_per_s.x, xmm1
    mulss xmm1, xmm4
    addss xmm1, (PARTICLE PTR [rcx]).pos.x
    movss (PARTICLE PTR [rcx]).pos.x, xmm1
    movss xmm1, (PARTICLE PTR [rcx]).vel_u_per_s.z
    mulss xmm1, xmm3
    movss (PARTICLE PTR [rcx]).vel_u_per_s.z, xmm1
    mulss xmm1, xmm4
    addss xmm1, (PARTICLE PTR [rcx]).pos.z
    movss (PARTICLE PTR [rcx]).pos.z, xmm1
effects_tick_particle_next:
    add rcx, SIZEOF PARTICLE
    dec edx
    jnz effects_tick_particle

    lea rcx, popups
    mov edx, POPUP_COUNT
effects_tick_popup:
    cmp (POPUP PTR [rcx]).life_ticks_left, 0
    je effects_tick_popup_next
    dec (POPUP PTR [rcx]).life_ticks_left
    movss xmm0, (POPUP PTR [rcx]).pos_y_px
    addss xmm0, (POPUP PTR [rcx]).vel_y_px_per_tick
    movss (POPUP PTR [rcx]).pos_y_px, xmm0
effects_tick_popup_next:
    add rcx, SIZEOF POPUP
    dec edx
    jnz effects_tick_popup

    lea rcx, upgrade_reels
    mov edx, UPGRADE_OFFER_COUNT
effects_tick_reel:
    counter_down_to_zero <(UPGRADE_REEL PTR [rcx]).flash_ticks_left>
    add rcx, SIZEOF UPGRADE_REEL
    dec edx
    jnz effects_tick_reel

    counter_down_to_zero background_flash_ticks_left
    counter_down_to_zero screen_flash_ticks_left
    counter_down_to_zero screen_chroma_ticks_left
    counter_down_to_zero screen_zoom_ticks_left
    counter_down_to_zero ball_pop_ticks_left
    counter_down_to_zero multiplier_pop_ticks_left
    counter_down_to_zero serve_reel_bounce_ticks_left

    lea rbx, players
    xor esi, esi
effects_tick_player:
    counter_down_to_zero <(PLAYER PTR [rbx]).flash_ticks_left>
    counter_down_to_zero <(PLAYER PTR [rbx]).score_pop_ticks_left>
    xor ecx, ecx
effects_tick_player_ghost:
    counter_down_to_zero <dword ptr [rbx + PLAYER.ghost_ticks_left + rcx * 4]>
    inc ecx
    cmp ecx, GHOST_COUNT
    jb effects_tick_player_ghost
    mov eax, (PLAYER PTR [rbx]).score_shown
    cmp eax, (PLAYER PTR [rbx]).score
    jae effects_tick_player_next
    test effects_ticks, SCORE_ROLL_PERIOD_TICKS - 1
    jnz effects_tick_player_next
    inc eax
    mov (PLAYER PTR [rbx]).score_shown, eax
    mov (PLAYER PTR [rbx]).score_pop_ticks_left, SCORE_POP_TICKS
    mov ecx, AUDIO_SEMITONE_MAX
    cmp eax, ecx
    cmova eax, ecx
    audio_play_call sound_blip, eax, VOLUME_NORMAL, 0
effects_tick_player_next:
    add rbx, SIZEOF PLAYER
    inc esi
    cmp esi, SIDE_COUNT
    jb effects_tick_player

    add rsp, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    pop rsi
    pop rbx
    ret
effects_tick ENDP

particles_spawn_burst PROC
    push rbx
    mov r10d, dword ptr [rsp + PARTICLES_SPAWN_BURST_ARG5]
    mov r8d, (PARTICLE_STYLE PTR [r9]).burst_count
    assert_above_zero_signed r8d
particles_spawn_burst_one:
    mov ecx, particle_next_index
    lea edx, [rcx + 1]
    and edx, PARTICLE_COUNT_MAX - 1
    mov particle_next_index, edx
    imul ecx, ecx, SIZEOF PARTICLE
    lea rbx, particles
    add rbx, rcx
    movss (PARTICLE PTR [rbx]).pos.x, xmm0
    movss (PARTICLE PTR [rbx]).pos.y, xmm1
    movss (PARTICLE PTR [rbx]).pos.z, xmm2
    random_signed_unit_float_to xmm4
    mulss xmm4, (PARTICLE_STYLE PTR [r9]).spread_u_per_s
    addss xmm4, dword ptr [rsp + PARTICLES_SPAWN_BURST_ARG6]
    movss (PARTICLE PTR [rbx]).vel_u_per_s.x, xmm4
    random_signed_unit_float_to xmm4
    mulss xmm4, (PARTICLE_STYLE PTR [r9]).spread_u_per_s
    addss xmm4, (PARTICLE_STYLE PTR [r9]).base_vel_y_u_per_s
    movss (PARTICLE PTR [rbx]).vel_u_per_s.y, xmm4
    random_signed_unit_float_to xmm4
    mulss xmm4, (PARTICLE_STYLE PTR [r9]).spread_u_per_s
    addss xmm4, dword ptr [rsp + PARTICLES_SPAWN_BURST_ARG7]
    movss (PARTICLE PTR [rbx]).vel_u_per_s.z, xmm4
    movss xmm4, (PARTICLE_STYLE PTR [r9]).gravity_u_per_s2
    movss (PARTICLE PTR [rbx]).gravity_u_per_s2, xmm4
    mov ecx, (PARTICLE_STYLE PTR [r9]).life_random_ticks
    random_below_to_eax ecx
    add eax, (PARTICLE_STYLE PTR [r9]).life_min_ticks
    mov (PARTICLE PTR [rbx]).life_ticks_left, eax
    mov eax, r10d
    cmp (PARTICLE_STYLE PTR [r9]).color_mode, PARTICLE_COLOR_MODE_RANDOM_HUE
    jne particles_spawn_burst_color_ready
    random_next_to_eax
    shr eax, RAINBOW_RANDOM_SHIFT
    rainbow_color_from_eax eax
particles_spawn_burst_color_ready:
    mov (PARTICLE PTR [rbx]).color_bgra, eax
    dec r8d
    jnz particles_spawn_burst_one
    pop rbx
    ret
particles_spawn_burst ENDP

particles_draw PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_6_ARGS_ODD_PUSHES_BYTES
    lea rbx, particles
    mov esi, PARTICLE_COUNT_MAX
particles_draw_one:
    mov edx, (PARTICLE PTR [rbx]).life_ticks_left
    test edx, edx
    jz particles_draw_next
    movss xmm0, (PARTICLE PTR [rbx]).pos.x
    movss xmm1, (PARTICLE PTR [rbx]).pos.y
    movss xmm2, (PARTICLE PTR [rbx]).pos.z
    call world_to_view
    comiss xmm2, camera_near_u
    jb particles_draw_next
    mov edi, PARTICLE_SIZE_NEAR_PX
    comiss xmm2, particle_near_depth_u
    jb particles_draw_size_ready
    mov edi, PARTICLE_SIZE_FAR_PX
particles_draw_size_ready:
    call view_project
    float_clamp_symmetric xmm0, xmm3, line_coordinate_limit_px
    float_clamp_symmetric xmm1, xmm3, line_coordinate_limit_px
    cvtss2si eax, xmm0
    mov dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5], eax
    cvtss2si eax, xmm1
    mov dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5 + 4], eax
    mov edx, (PARTICLE PTR [rbx]).life_ticks_left
    imul edx, edx, PARTICLE_LEVEL_PER_LIFE_TICK
    mov eax, COLOR_LEVEL_FULL
    cmp edx, eax
    cmova edx, eax
    mov ecx, (PARTICLE PTR [rbx]).color_bgra
    call color_scale
    mov dword ptr [rsp + CALL_ARG5], eax
    mov ecx, dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5]
    mov edx, dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5 + 4]
    mov r8d, edi
    mov r9d, edi
    call framebuffer_rect_fill
particles_draw_next:
    add rbx, SIZEOF PARTICLE
    dec esi
    jnz particles_draw_one
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
particles_draw ENDP

popup_spawn PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check POPUP_SPAWN_PUSHED_REGISTER_COUNT, FRAME_4_ARGS_ODD_PUSHES_BYTES
    mov esi, edx
    mov rdi, rcx
    mov eax, popup_next_index
    lea r8d, [rax + 1]
    and r8d, POPUP_COUNT - 1
    mov popup_next_index, r8d
    imul eax, eax, SIZEOF POPUP
    lea rbx, popups
    add rbx, rax
    movss (POPUP PTR [rbx]).pos_x_px, xmm2
    movss (POPUP PTR [rbx]).pos_y_px, xmm3
    mov rax, qword ptr [rsp + POPUP_SPAWN_ARG5]
    mov ecx, (POPUP_STYLE PTR [rax]).scale_base
    mov (POPUP PTR [rbx]).scale_base, ecx
    mov ecx, (POPUP_STYLE PTR [rax]).color_bgra
    mov (POPUP PTR [rbx]).color_bgra, ecx
    movss xmm0, (POPUP_STYLE PTR [rax]).vel_y_px_per_tick
    movss (POPUP PTR [rbx]).vel_y_px_per_tick, xmm0
    mov ecx, (POPUP_STYLE PTR [rax]).life_ticks
    assert_above_zero_signed ecx
    mov (POPUP PTR [rbx]).life_ticks_total, ecx
    mov (POPUP PTR [rbx]).life_ticks_left, ecx
    lea rcx, [rbx + POPUP.text_bytes]
    mov rdx, rdi
    call text_append_string
    test esi, esi
    js popup_spawn_suffix
    mov rcx, rax
    mov edx, esi
    call text_append_number
popup_spawn_suffix:
    mov rdx, qword ptr [rsp + POPUP_SPAWN_ARG6]
    test rdx, rdx
    jz popup_spawn_text_done
    mov rcx, rax
    call text_append_string
popup_spawn_text_done:
    lea rcx, [rbx + POPUP.text_bytes]
    sub rax, rcx
    assert_below_unsigned rax, POPUP_TEXT_BYTES
    add rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
popup_spawn ENDP

popups_draw PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_6_ARGS_ODD_PUSHES_BYTES
    lea rbx, popups
    mov esi, POPUP_COUNT
popups_draw_one:
    mov eax, (POPUP PTR [rbx]).life_ticks_left
    test eax, eax
    jz popups_draw_next
    cmp eax, POPUP_BLINK_TICKS
    jae popups_draw_visible
    test eax, POPUP_BLINK_BIT_MASK
    jnz popups_draw_next
popups_draw_visible:
    mov edi, (POPUP PTR [rbx]).scale_base
    mov ecx, (POPUP PTR [rbx]).life_ticks_total
    sub ecx, eax
    cmp ecx, POPUP_POP_BIG_TICKS
    jae popups_draw_pop_small
    add edi, 2
    jmp popups_draw_scaled
popups_draw_pop_small:
    cmp ecx, POPUP_POP_TICKS
    jae popups_draw_scaled
    inc edi
popups_draw_scaled:
    cvtss2si edx, (POPUP PTR [rbx]).pos_x_px
    add edx, SCREEN_CENTER_X_PX
    cvtss2si r8d, (POPUP PTR [rbx]).pos_y_px
    add r8d, SCREEN_CENTER_Y_PX
    imul eax, edi, FONT_TEXT_ROWS
    sar eax, 1
    sub r8d, eax
    mov r9d, (POPUP PTR [rbx]).color_bgra
    mov dword ptr [rsp + CALL_ARG5], edi
    lea rcx, [rbx + POPUP.text_bytes]
    call text_draw_centered
popups_draw_next:
    add rbx, SIZEOF POPUP
    dec esi
    jnz popups_draw_one
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
popups_draw ENDP

screen_punch PROC
    push rbx
    sub rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 1, FRAME_4_ARGS_ODD_PUSHES_BYTES
    mov rbx, rcx
    mov ecx, (PUNCH PTR [rbx]).shake_ticks
    test ecx, ecx
    jz screen_punch_flash
    movss xmm0, (PUNCH PTR [rbx]).shake_px
    call screen_shake_start
screen_punch_flash:
    mov eax, (PUNCH PTR [rbx]).flash_ticks
    cmp eax, screen_flash_ticks_left
    jbe screen_punch_chroma
    mov screen_flash_ticks_left, eax
    mov screen_flash_duration_ticks, eax
    mov eax, (PUNCH PTR [rbx]).flash_color_bgra
    mov screen_flash_color_bgra, eax
screen_punch_chroma:
    mov eax, (PUNCH PTR [rbx]).chroma_ticks
    counter_raise_to screen_chroma_ticks_left, eax
    mov eax, (PUNCH PTR [rbx]).zoom_ticks
    cmp eax, screen_zoom_ticks_left
    jbe screen_punch_hit_stop
    mov screen_zoom_ticks_left, eax
    mov screen_zoom_duration_ticks, eax
screen_punch_hit_stop:
    mov eax, (PUNCH PTR [rbx]).hit_stop_ticks
    counter_raise_to hit_stop_ticks_left, eax
    mov eax, (PUNCH PTR [rbx]).slow_mo_ticks
    counter_raise_to slow_mo_ticks_left, eax
    add rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    pop rbx
    ret
screen_punch ENDP

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
