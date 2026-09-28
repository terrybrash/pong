UPGRADE_RARITY_COMMON               equ 0
UPGRADE_RARITY_RARE                 equ 1
UPGRADE_RARITY_EPIC                 equ 2
UPGRADE_RARITY_LEGENDARY            equ 3
UPGRADE_RARITY_COUNT                equ 4
UPGRADE_RARITY_RARE_BELOW_PERCENT   equ 40
UPGRADE_RARITY_EPIC_BELOW_PERCENT   equ 15
UPGRADE_RARITY_LEGENDARY_BELOW_PERCENT equ 4
UPGRADE_RARITY_SEMITONE_STEP        equ 5
UPGRADE_REELS_ALL_STOPPED_MASK      equ (1 SHL UPGRADE_OFFER_COUNT) - 1
UPGRADE_REROLLS_PER_PICK            equ 1
UPGRADE_REELS_START_TICK            equ 26
UPGRADE_REEL_FIRST_STOP_TICKS       equ 30
UPGRADE_REEL_STOP_GAP_TICKS         equ 26
UPGRADE_REEL_STOP_JITTER_TICKS      equ 12
UPGRADE_REEL_SPIN_INTERVAL_MIN_TICKS equ 2
UPGRADE_REEL_SLOWDOWN_TICKS         equ 28
UPGRADE_REEL_SLOWDOWN_DIVISOR       equ 4
UPGRADE_REEL_FLASH_TICKS            equ 12
UPGRADE_REEL_FLASH_LEVEL_PER_TICK   equ 12
UPGRADE_REEL_TICK_SEMITONE          equ 7
UPGRADE_REEL_TICK_SEMITONE_PER_REEL equ 5
UPGRADE_CPU_DECIDE_DELAY_TICKS      equ 40
UPGRADE_CPU_TAKE_DELAY_TICKS        equ 90
UPGRADE_TAKEN_TICKS                 equ 110
UPGRADE_SPIN_BLINK_BIT_MASK         equ 2
UPGRADE_TITLE_TOP_PX                equ 42
UPGRADE_PROMPT_TOP_PX               equ 224
UPGRADE_CARD_LEFT_PX                equ 142
UPGRADE_CARD_WIDTH_PX               equ 168
UPGRADE_CARD_HEIGHT_PX              equ 48
UPGRADE_CARD_TOP_PX                 equ 52
UPGRADE_CARD_PITCH_PX               equ 54
UPGRADE_CARD_CENTER_Y_PX            equ UPGRADE_CARD_TOP_PX + UPGRADE_CARD_HEIGHT_PX / 2
UPGRADE_CARD_BORDER_PX              equ 2
UPGRADE_CARD_GLOW_PX                equ 2
UPGRADE_CARD_GLOW_LEVEL             equ 90
UPGRADE_CARD_DIM_BORDER_LEVEL       equ 150
UPGRADE_CARD_SELECTED_SHIFT_PX      equ 6
UPGRADE_CARD_TEXT_INSET_PX          equ 8
UPGRADE_CARD_NAME_TOP_INSET_PX      equ 6
UPGRADE_CARD_DESCRIPTION_TOP_INSET_PX equ 25
UPGRADE_CARD_RARITY_TOP_INSET_PX    equ 36
UPGRADE_CARD_PIP_SIZE_PX            equ 4
UPGRADE_CARD_PIP_PITCH_PX           equ 6
UPGRADE_CARD_PIP_RIGHT_INSET_PX     equ 11
UPGRADE_CARD_PIP_TOP_INSET_PX       equ 37
UPGRADE_CARD_PIPS_MAX               equ 10
UPGRADE_SCENE_DARKEN_LEVEL          equ 36
UPGRADE_CARD_SLIDE_TICKS            equ 18
UPGRADE_CARD_SLIDE_STAGGER_TICKS    equ 4
.ERRE UPGRADE_CARD_LEFT_PX + UPGRADE_CARD_SLIDE_TICKS * UPGRADE_CARD_SLIDE_TICKS GE SCREEN_WIDTH_PX
UPGRADE_CARD_PULSE_LEVEL_MIN        equ 160
UPGRADE_CARD_PULSE_LEVEL_PER_TICK   equ 6
.ERRE UPGRADE_CARD_PULSE_LEVEL_MIN + UPGRADE_CARD_PULSE_LEVEL_PER_TICK * TRIANGLE_WAVE_PERIOD_TICKS / 2 LE COLOR_LEVEL_FULL
COLOR_CARD_BORDER_BGRA              equ PALETTE_SLATE_BGRA
COLOR_CARD_PANEL_BGRA               equ PALETTE_NIGHT_BGRA
COLOR_CARD_PANEL_SELECTED_BGRA      equ PALETTE_NAVY_BGRA

UPGRADE_REEL STRUCT
    kind                            DWORD ?
    rarity                          DWORD ?
    stop_tick                       DWORD ?
    shown_kind                      DWORD ?
    next_change_tick                DWORD ?
    flash_ticks_left                DWORD ?
UPGRADE_REEL ENDS

.const
popup_card_rarity_x_px              REAL4 66.0
popup_card_gain_x_px                REAL4 66.0
card_center_x_px_float              REAL4 226.0
upgrade_rarity_level_gain           DWORD 1, 2, 3, 5
upgrade_rarity_color_bgra           DWORD PALETTE_SILVER_BGRA, PALETTE_SKY_BGRA, PALETTE_RED_BGRA, PALETTE_YELLOW_BGRA
text_upgrade_big_reach_name         BYTE "BIG REACH", 0
text_upgrade_big_reach_description  BYTE "HIT FROM FARTHER", 0
text_upgrade_quick_feet_name        BYTE "QUICK FEET", 0
text_upgrade_quick_feet_description BYTE "RUN FASTER", 0
text_upgrade_power_hit_name         BYTE "POWER HIT", 0
text_upgrade_power_hit_description  BYTE "FAST SHOTS, MORE CRITS", 0
text_upgrade_wide_aim_name          BYTE "WIDE AIM", 0
text_upgrade_wide_aim_description   BYTE "AIM WIDER SHOTS", 0
text_upgrade_shield_name            BYTE "SHIELD", 0
text_upgrade_shield_description     BYTE "SAVES ONE POINT", 0
text_upgrade_shrink_foe_name        BYTE "SHRINK FOE", 0
text_upgrade_shrink_foe_description BYTE "FOE REACH SHRINKS", 0
text_upgrade_dash_master_name       BYTE "DASH MASTER", 0
text_upgrade_dash_master_description BYTE "DASH RECHARGES FASTER", 0
text_upgrade_rarity_common          BYTE "COMMON +1", 0
text_upgrade_rarity_rare            BYTE "RARE +2", 0
text_upgrade_rarity_epic            BYTE "EPIC +3", 0
text_upgrade_rarity_legendary       BYTE "LEGENDARY +5", 0
text_upgrade_title_you              BYTE "YOU LOST THE POINT. SPIN FOR AN UPGRADE!", 0
text_upgrade_title_cpu              BYTE "CPU LOST THE POINT. IT SPINS!", 0
text_upgrade_prompt                 BYTE "W S: MOVE   SPACE: TAKE", 0
text_upgrade_prompt_reroll          BYTE "   R: REROLL", 0
text_popup_common                   BYTE "COMMON", 0
text_popup_rare                     BYTE "RARE!", 0
text_popup_epic                     BYTE "EPIC!!", 0
text_popup_legendary                BYTE "LEGENDARY!!!", 0

ALIGN 8
upgrade_name_texts                  QWORD text_upgrade_big_reach_name, text_upgrade_quick_feet_name, text_upgrade_power_hit_name, text_upgrade_wide_aim_name, text_upgrade_shield_name, text_upgrade_shrink_foe_name, text_upgrade_dash_master_name
.ERRNZ LENGTHOF upgrade_name_texts - UPGRADE_KIND_COUNT
upgrade_description_texts           QWORD text_upgrade_big_reach_description, text_upgrade_quick_feet_description, text_upgrade_power_hit_description, text_upgrade_wide_aim_description, text_upgrade_shield_description, text_upgrade_shrink_foe_description, text_upgrade_dash_master_description
.ERRNZ LENGTHOF upgrade_description_texts - UPGRADE_KIND_COUNT
upgrade_rarity_texts                QWORD text_upgrade_rarity_common, text_upgrade_rarity_rare, text_upgrade_rarity_epic, text_upgrade_rarity_legendary
.ERRNZ LENGTHOF upgrade_rarity_texts - UPGRADE_RARITY_COUNT
upgrade_rarity_popup_texts          QWORD text_popup_common, text_popup_rare, text_popup_epic, text_popup_legendary
.ERRNZ LENGTHOF upgrade_rarity_popup_texts - UPGRADE_RARITY_COUNT
upgrade_rarity_particle_styles      QWORD particles_reel_common, particles_reel_rare, particles_reel_epic, particles_reel_legendary
.ERRNZ LENGTHOF upgrade_rarity_particle_styles - UPGRADE_RARITY_COUNT
upgrade_rarity_punches              QWORD punch_reel_stop, punch_reel_stop, punch_reel_epic, punch_jackpot
.ERRNZ LENGTHOF upgrade_rarity_punches - UPGRADE_RARITY_COUNT
upgrade_title_texts                 QWORD text_upgrade_title_you, text_upgrade_title_cpu
.ERRNZ LENGTHOF upgrade_title_texts - SIDE_COUNT

.data?
upgrade_reels                       UPGRADE_REEL UPGRADE_OFFER_COUNT DUP (<>)
upgrade_reels_stopped_mask          DWORD ?
upgrade_reels_all_stopped_tick      DWORD ?
upgrade_offer_cursor                DWORD ?
upgrade_rerolls_left                DWORD ?

.code

upgrade_offer_roll PROC
    push rbx
    push rsi
    push rdi
    .ERRNZ UPGRADE_OFFER_COUNT - 3
    mov edi, ecx
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
    lea rsi, upgrade_reels
    mov (UPGRADE_REEL PTR [rsi]).kind, r8d
    mov (UPGRADE_REEL PTR [rsi + SIZEOF UPGRADE_REEL]).kind, r9d
    mov (UPGRADE_REEL PTR [rsi + 2 * SIZEOF UPGRADE_REEL]).kind, eax
    xor ebx, ebx
upgrade_offer_roll_reel:
    mov ecx, PERCENT_COUNT
    random_below_to_eax ecx
    mov edx, UPGRADE_RARITY_COMMON
    mov ecx, UPGRADE_RARITY_RARE
    cmp eax, UPGRADE_RARITY_RARE_BELOW_PERCENT
    cmovb edx, ecx
    mov ecx, UPGRADE_RARITY_EPIC
    cmp eax, UPGRADE_RARITY_EPIC_BELOW_PERCENT
    cmovb edx, ecx
    mov ecx, UPGRADE_RARITY_LEGENDARY
    cmp eax, UPGRADE_RARITY_LEGENDARY_BELOW_PERCENT
    cmovb edx, ecx
    mov (UPGRADE_REEL PTR [rsi]).rarity, edx
    mov ecx, UPGRADE_REEL_STOP_JITTER_TICKS
    random_below_to_eax ecx
    imul ecx, ebx, UPGRADE_REEL_STOP_GAP_TICKS
    add eax, ecx
    add eax, edi
    add eax, UPGRADE_REEL_FIRST_STOP_TICKS
    mov (UPGRADE_REEL PTR [rsi]).stop_tick, eax
    mov ecx, UPGRADE_KIND_COUNT
    random_below_to_eax ecx
    mov (UPGRADE_REEL PTR [rsi]).shown_kind, eax
    mov (UPGRADE_REEL PTR [rsi]).next_change_tick, edi
    mov (UPGRADE_REEL PTR [rsi]).flash_ticks_left, 0
    add rsi, SIZEOF UPGRADE_REEL
    inc ebx
    cmp ebx, UPGRADE_OFFER_COUNT
    jb upgrade_offer_roll_reel
    mov upgrade_reels_stopped_mask, 0
    pop rdi
    pop rsi
    pop rbx
    ret
upgrade_offer_roll ENDP

upgrade_choose_tick PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_6_ARGS_ODD_PUSHES_BYTES
    xor ebx, ebx
    lea rsi, upgrade_reels
upgrade_choose_tick_reel:
    bt upgrade_reels_stopped_mask, ebx
    jc upgrade_choose_tick_reel_next
    mov edi, match_mode_ticks
    cmp edi, (UPGRADE_REEL PTR [rsi]).stop_tick
    jae upgrade_choose_tick_reel_stop
    cmp edi, (UPGRADE_REEL PTR [rsi]).next_change_tick
    jb upgrade_choose_tick_reel_next
    mov ecx, UPGRADE_KIND_COUNT - 1
    random_below_to_eax ecx
    inc eax
    add eax, (UPGRADE_REEL PTR [rsi]).shown_kind
    xor edx, edx
    mov ecx, UPGRADE_KIND_COUNT
    div ecx
    mov (UPGRADE_REEL PTR [rsi]).shown_kind, edx
    mov eax, (UPGRADE_REEL PTR [rsi]).stop_tick
    sub eax, edi
    mov ecx, UPGRADE_REEL_SLOWDOWN_TICKS
    sub ecx, eax
    xor edx, edx
    test ecx, ecx
    cmovs ecx, edx
    mov eax, ecx
    xor edx, edx
    mov ecx, UPGRADE_REEL_SLOWDOWN_DIVISOR
    div ecx
    lea ecx, [rax + rdi + UPGRADE_REEL_SPIN_INTERVAL_MIN_TICKS]
    mov (UPGRADE_REEL PTR [rsi]).next_change_tick, ecx
    imul ecx, ebx, UPGRADE_REEL_TICK_SEMITONE_PER_REEL
    add ecx, UPGRADE_REEL_TICK_SEMITONE
    audio_play_call sound_tick, ecx, VOLUME_QUIET, 0
    jmp upgrade_choose_tick_reel_next
upgrade_choose_tick_reel_stop:
    mov ecx, ebx
    call upgrade_reel_stop
upgrade_choose_tick_reel_next:
    add rsi, SIZEOF UPGRADE_REEL
    inc ebx
    cmp ebx, UPGRADE_OFFER_COUNT
    jb upgrade_choose_tick_reel

    cmp upgrade_reels_stopped_mask, UPGRADE_REELS_ALL_STOPPED_MASK
    jne upgrade_choose_tick_done
    mov eax, match_point_loser_side
    assert_below_unsigned eax, SIDE_COUNT
    cmp eax, SIDE_FAR
    je upgrade_choose_tick_cpu

    lea rbx, key_was_pressed_by_virtual_key
    movzx ecx, byte ptr [rbx + VK_W]
    or cl, byte ptr [rbx + VK_UP]
    movzx edx, byte ptr [rbx + VK_S]
    or dl, byte ptr [rbx + VK_DOWN]
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
    je upgrade_choose_tick_reroll_check
    mov upgrade_offer_cursor, eax
    audio_play_call sound_blip, 0, VOLUME_NORMAL, 0
upgrade_choose_tick_reroll_check:
    cmp byte ptr [rbx + VK_R], 0
    je upgrade_choose_tick_take_check
    cmp upgrade_rerolls_left, 0
    je upgrade_choose_tick_take_check
    call upgrade_reroll
    jmp upgrade_choose_tick_done
upgrade_choose_tick_take_check:
    movzx eax, byte ptr [rbx + VK_SPACE]
    or al, byte ptr [rbx + VK_RETURN]
    jz upgrade_choose_tick_done
    call upgrade_take
    jmp upgrade_choose_tick_done

upgrade_choose_tick_cpu:
    mov eax, match_mode_ticks
    sub eax, upgrade_reels_all_stopped_tick
    cmp eax, UPGRADE_CPU_DECIDE_DELAY_TICKS
    jne upgrade_choose_tick_cpu_take_check
    call upgrade_cpu_decide
    jmp upgrade_choose_tick_done
upgrade_choose_tick_cpu_take_check:
    cmp eax, UPGRADE_CPU_TAKE_DELAY_TICKS
    jb upgrade_choose_tick_done
    call upgrade_take

upgrade_choose_tick_done:
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
upgrade_choose_tick ENDP

upgrade_card_particles_spawn PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_8_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_8_ARGS_ODD_PUSHES_BYTES
    mov ebx, ecx
    mov rsi, rdx
    mov edi, r8d
    imul eax, ebx, UPGRADE_CARD_PITCH_PX
    add eax, UPGRADE_CARD_CENTER_Y_PX
    cvtsi2ss xmm1, eax
    movss xmm0, card_center_x_px_float
    call world_point_from_screen
    mov dword ptr [rsp + CALL_ARG5], edi
    mov dword ptr [rsp + CALL_ARG6], 0
    mov dword ptr [rsp + CALL_ARG7], 0
    mov r9, rsi
    call particles_spawn_burst
    add rsp, FRAME_8_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
upgrade_card_particles_spawn ENDP

upgrade_reel_stop PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_8_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_8_ARGS_ODD_PUSHES_BYTES
    mov ebx, ecx
    assert_below_unsigned ebx, UPGRADE_OFFER_COUNT
    imul eax, ebx, SIZEOF UPGRADE_REEL
    lea rsi, upgrade_reels
    add rsi, rax
    mov eax, (UPGRADE_REEL PTR [rsi]).kind
    mov (UPGRADE_REEL PTR [rsi]).shown_kind, eax
    mov (UPGRADE_REEL PTR [rsi]).flash_ticks_left, UPGRADE_REEL_FLASH_TICKS
    bts upgrade_reels_stopped_mask, ebx
    cmp upgrade_reels_stopped_mask, UPGRADE_REELS_ALL_STOPPED_MASK
    jne upgrade_reel_stop_effects
    mov eax, match_mode_ticks
    mov upgrade_reels_all_stopped_tick, eax

upgrade_reel_stop_effects:
    mov edi, (UPGRADE_REEL PTR [rsi]).rarity
    assert_below_unsigned edi, UPGRADE_RARITY_COUNT
    audio_play_call sound_clack, 0, VOLUME_LOUD, 0
    imul eax, edi, UPGRADE_RARITY_SEMITONE_STEP
    audio_play_call sound_blip, eax, VOLUME_NORMAL, 0
    lea rax, upgrade_rarity_particle_styles
    mov rdx, qword ptr [rax + rdi * 8]
    lea rax, upgrade_rarity_color_bgra
    mov r8d, dword ptr [rax + rdi * 4]
    mov ecx, ebx
    call upgrade_card_particles_spawn
    lea rax, upgrade_rarity_punches
    mov rcx, qword ptr [rax + rdi * 8]
    call screen_punch

    cmp edi, UPGRADE_RARITY_RARE
    jb upgrade_reel_stop_done
    movss xmm2, popup_card_rarity_x_px
    imul eax, ebx, UPGRADE_CARD_PITCH_PX
    add eax, UPGRADE_CARD_CENTER_Y_PX - SCREEN_CENTER_Y_PX
    cvtsi2ss xmm3, eax
    lea rax, upgrade_rarity_popup_texts
    mov rcx, qword ptr [rax + rdi * 8]
    mov edx, POPUP_NO_NUMBER
    lea rax, popup_style_rarity
    mov qword ptr [rsp + CALL_ARG5], rax
    mov qword ptr [rsp + CALL_ARG6], 0
    call popup_spawn

    cmp edi, UPGRADE_RARITY_EPIC
    jne upgrade_reel_stop_legendary_check
    audio_play_call sound_rise, 0, VOLUME_NORMAL, 0
upgrade_reel_stop_legendary_check:
    cmp edi, UPGRADE_RARITY_LEGENDARY
    jne upgrade_reel_stop_done
    inc match_jackpot_count
    xorps xmm2, xmm2
    movss xmm3, popup_banner_top_y_px
    popup_spawn_call text_popup_jackpot, POPUP_NO_NUMBER, popup_style_jackpot
    mov ecx, AUDIO_ARPEGGIO_NOTE_COUNT
    xor edx, edx
    call audio_arpeggio_play
    audio_play_call sound_boom, 0, VOLUME_LOUD, 0
    mov ecx, ebx
    lea rdx, particles_ui_coins
    mov r8d, COLOR_GOLD_BGRA
    call upgrade_card_particles_spawn
    mov ecx, ebx
    lea rdx, particles_ui_coins
    mov r8d, COLOR_GOLD_BGRA
    call upgrade_card_particles_spawn

upgrade_reel_stop_done:
    add rsp, FRAME_8_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
upgrade_reel_stop ENDP

upgrade_cpu_decide PROC
    sub rsp, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 0, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    lea rcx, upgrade_reels
    xor eax, eax
    mov edx, (UPGRADE_REEL PTR [rcx]).rarity
    mov r8d, 1
upgrade_cpu_decide_scan:
    add rcx, SIZEOF UPGRADE_REEL
    mov r9d, (UPGRADE_REEL PTR [rcx]).rarity
    cmp r9d, edx
    jbe upgrade_cpu_decide_scan_next
    mov edx, r9d
    mov eax, r8d
upgrade_cpu_decide_scan_next:
    inc r8d
    cmp r8d, UPGRADE_OFFER_COUNT
    jb upgrade_cpu_decide_scan
    cmp edx, UPGRADE_RARITY_COMMON
    jne upgrade_cpu_decide_choose
    cmp upgrade_rerolls_left, 0
    je upgrade_cpu_decide_choose
    call upgrade_reroll
    jmp upgrade_cpu_decide_done
upgrade_cpu_decide_choose:
    mov upgrade_offer_cursor, eax
    audio_play_call sound_blip, 0, VOLUME_NORMAL, 0
upgrade_cpu_decide_done:
    add rsp, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    ret
upgrade_cpu_decide ENDP

upgrade_reroll PROC
    sub rsp, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 0, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    assert_above_zero_signed upgrade_rerolls_left
    dec upgrade_rerolls_left
    mov ecx, match_mode_ticks
    call upgrade_offer_roll
    xorps xmm2, xmm2
    movss xmm3, popup_banner_top_y_px
    popup_spawn_call text_popup_reroll, POPUP_NO_NUMBER, popup_style_banner
    audio_play_call sound_rise, 0, VOLUME_NORMAL, 0
    screen_punch_call punch_reroll
    add rsp, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    ret
upgrade_reroll ENDP

upgrade_take PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_8_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_8_ARGS_ODD_PUSHES_BYTES
    mov ebx, upgrade_offer_cursor
    assert_below_unsigned ebx, UPGRADE_OFFER_COUNT
    imul eax, ebx, SIZEOF UPGRADE_REEL
    lea rsi, upgrade_reels
    add rsi, rax
    mov eax, (UPGRADE_REEL PTR [rsi]).kind
    assert_below_unsigned eax, UPGRADE_KIND_COUNT
    mov ecx, (UPGRADE_REEL PTR [rsi]).rarity
    assert_below_unsigned ecx, UPGRADE_RARITY_COUNT
    lea rdx, upgrade_rarity_level_gain
    mov edi, dword ptr [rdx + rcx * 4]
    mov edx, match_point_loser_side
    player_address_load r8, edx
    add dword ptr [r8 + PLAYER.upgrade_level_by_kind + rax * 4], edi
    match_mode_set MATCH_MODE_UPGRADE_TAKEN
    audio_play_call sound_rise, 0, VOLUME_NORMAL, 0
    audio_play_call sound_coin, 0, VOLUME_NORMAL, 0
    screen_punch_call punch_upgrade_take
    mov ecx, (UPGRADE_REEL PTR [rsi]).rarity
    lea rax, upgrade_rarity_color_bgra
    mov r8d, dword ptr [rax + rcx * 4]
    mov ecx, ebx
    lea rdx, particles_upgrade_take
    call upgrade_card_particles_spawn
    movss xmm2, popup_card_gain_x_px
    imul ecx, ebx, UPGRADE_CARD_PITCH_PX
    add ecx, UPGRADE_CARD_CENTER_Y_PX - SCREEN_CENTER_Y_PX
    cvtsi2ss xmm3, ecx
    popup_spawn_call text_popup_plus, edi, popup_style_points
    add rsp, FRAME_8_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
upgrade_take ENDP

upgrade_screen_draw PROC
    push rbx
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 1, FRAME_6_ARGS_ODD_PUSHES_BYTES
    mov ecx, COLOR_BLACK_BGRA
    mov edx, UPGRADE_SCENE_DARKEN_LEVEL
    call framebuffer_lerp_toward

    mov eax, match_point_loser_side
    assert_below_unsigned eax, SIDE_COUNT
    lea rcx, upgrade_title_texts
    mov rcx, qword ptr [rcx + rax * 8]
    mov edx, SCREEN_CENTER_X_PX
    mov r8d, UPGRADE_TITLE_TOP_PX
    mov r9d, TEXT_COLOR_RAINBOW
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_SMALL
    call text_draw_centered

    cmp match_mode, MATCH_MODE_UPGRADE_CHOOSE
    jne upgrade_screen_draw_cards
    cmp upgrade_reels_stopped_mask, UPGRADE_REELS_ALL_STOPPED_MASK
    jne upgrade_screen_draw_cards
    cmp match_point_loser_side, SIDE_FAR
    je upgrade_screen_draw_cards
    lea rcx, text_scratch
    lea rdx, text_upgrade_prompt
    call text_append_string
    cmp upgrade_rerolls_left, 0
    je upgrade_screen_draw_prompt_ready
    mov rcx, rax
    lea rdx, text_upgrade_prompt_reroll
    call text_append_string
upgrade_screen_draw_prompt_ready:
    lea rcx, text_scratch
    mov edx, SCREEN_CENTER_X_PX
    mov r8d, UPGRADE_PROMPT_TOP_PX
    mov r9d, COLOR_TEXT_BRIGHT_BGRA
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
    imul eax, ebx, SIZEOF UPGRADE_REEL
    lea rsi, upgrade_reels
    add rsi, rax
    xor edi, edi
    cmp ebx, upgrade_offer_cursor
    sete dil
    xor eax, eax
    bt upgrade_reels_stopped_mask, ebx
    setc al
    mov dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5], eax

    mov eax, (UPGRADE_REEL PTR [rsi]).rarity
    assert_below_unsigned eax, UPGRADE_RARITY_COUNT
    lea rcx, upgrade_rarity_color_bgra
    mov r12d, dword ptr [rcx + rax * 4]
    cmp eax, UPGRADE_RARITY_LEGENDARY
    jne upgrade_card_draw_position
    mov eax, effects_ticks
    shr eax, 1
    rainbow_color_from_eax r12d

upgrade_card_draw_position:
    mov r13d, UPGRADE_CARD_LEFT_PX
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
    cmp dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5], 0
    je upgrade_card_draw_top
    sub r13d, UPGRADE_CARD_SELECTED_SHIFT_PX
upgrade_card_draw_top:
    imul r14d, ebx, UPGRADE_CARD_PITCH_PX
    add r14d, UPGRADE_CARD_TOP_PX

    cmp dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5], 0
    jne upgrade_card_draw_border_stopped
    mov r15d, COLOR_CARD_BORDER_BGRA
    test match_mode_ticks, UPGRADE_SPIN_BLINK_BIT_MASK
    jz upgrade_card_draw_border
    mov r15d, COLOR_WHITE_BGRA
    jmp upgrade_card_draw_border
upgrade_card_draw_border_stopped:
    test edi, edi
    jnz upgrade_card_draw_border_selected
    mov ecx, r12d
    mov edx, UPGRADE_CARD_DIM_BORDER_LEVEL
    call color_scale
    mov r15d, eax
    jmp upgrade_card_draw_border
upgrade_card_draw_border_selected:
    mov ecx, r12d
    mov edx, UPGRADE_CARD_GLOW_LEVEL
    call color_scale
    mov dword ptr [rsp + CALL_ARG5], eax
    lea ecx, [r13 - UPGRADE_CARD_GLOW_PX]
    lea edx, [r14 - UPGRADE_CARD_GLOW_PX]
    mov r8d, UPGRADE_CARD_WIDTH_PX + 2 * UPGRADE_CARD_GLOW_PX
    mov r9d, UPGRADE_CARD_HEIGHT_PX + 2 * UPGRADE_CARD_GLOW_PX
    call framebuffer_rect_fill
    mov eax, match_mode_ticks
    triangle_wave_from_eax
    imul edx, eax, UPGRADE_CARD_PULSE_LEVEL_PER_TICK
    add edx, UPGRADE_CARD_PULSE_LEVEL_MIN
    mov ecx, r12d
    call color_scale
    mov r15d, eax
    jmp upgrade_card_draw_border
upgrade_card_draw_border:
    mov dword ptr [rsp + CALL_ARG5], r15d
    mov ecx, r13d
    mov edx, r14d
    mov r8d, UPGRADE_CARD_WIDTH_PX
    mov r9d, UPGRADE_CARD_HEIGHT_PX
    call framebuffer_rect_fill

    mov eax, COLOR_CARD_PANEL_BGRA
    test edi, edi
    jz upgrade_card_draw_panel_flash
    mov eax, COLOR_CARD_PANEL_SELECTED_BGRA
upgrade_card_draw_panel_flash:
    mov edx, (UPGRADE_REEL PTR [rsi]).flash_ticks_left
    test edx, edx
    jz upgrade_card_draw_panel
    imul edx, edx, UPGRADE_REEL_FLASH_LEVEL_PER_TICK
    mov ecx, r12d
    call color_scale
upgrade_card_draw_panel:
    mov dword ptr [rsp + CALL_ARG5], eax
    lea ecx, [r13 + UPGRADE_CARD_BORDER_PX]
    lea edx, [r14 + UPGRADE_CARD_BORDER_PX]
    mov r8d, UPGRADE_CARD_WIDTH_PX - 2 * UPGRADE_CARD_BORDER_PX
    mov r9d, UPGRADE_CARD_HEIGHT_PX - 2 * UPGRADE_CARD_BORDER_PX
    call framebuffer_rect_fill

    mov eax, (UPGRADE_REEL PTR [rsi]).shown_kind
    assert_below_unsigned eax, UPGRADE_KIND_COUNT
    lea rcx, upgrade_name_texts
    mov rcx, qword ptr [rcx + rax * 8]
    lea edx, [r13 + UPGRADE_CARD_TEXT_INSET_PX]
    lea r8d, [r14 + UPGRADE_CARD_NAME_TOP_INSET_PX]
    mov r9d, COLOR_TEXT_DIM_BGRA
    cmp dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5], 0
    jne upgrade_card_draw_name_stopped
    mov eax, match_mode_ticks
    and eax, 1
    lea r8d, [r8 + rax * 2 - 1]
    jmp upgrade_card_draw_name
upgrade_card_draw_name_stopped:
    test edi, edi
    jz upgrade_card_draw_name
    mov r9d, COLOR_WHITE_BGRA
upgrade_card_draw_name:
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_LARGE
    call text_draw

    cmp dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5], 0
    je upgrade_card_draw_done
    mov eax, (UPGRADE_REEL PTR [rsi]).kind
    lea rcx, upgrade_description_texts
    mov rcx, qword ptr [rcx + rax * 8]
    lea edx, [r13 + UPGRADE_CARD_TEXT_INSET_PX]
    lea r8d, [r14 + UPGRADE_CARD_DESCRIPTION_TOP_INSET_PX]
    mov r9d, COLOR_TEXT_DIM_BGRA
    test edi, edi
    jz upgrade_card_draw_description
    mov r9d, COLOR_TEXT_BRIGHT_BGRA
upgrade_card_draw_description:
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_SMALL
    call text_draw

    lea edx, [r13 + UPGRADE_CARD_TEXT_INSET_PX]
    mov eax, (UPGRADE_REEL PTR [rsi]).rarity
    lea rcx, upgrade_rarity_texts
    mov rcx, qword ptr [rcx + rax * 8]
    lea r8d, [r14 + UPGRADE_CARD_RARITY_TOP_INSET_PX]
    mov r9d, r12d
    cmp eax, UPGRADE_RARITY_LEGENDARY
    jne upgrade_card_draw_rarity
    mov r9d, TEXT_COLOR_RAINBOW
upgrade_card_draw_rarity:
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_SMALL
    call text_draw

    mov eax, match_point_loser_side
    player_address_load rax, eax
    mov ecx, (UPGRADE_REEL PTR [rsi]).kind
    mov edi, dword ptr [rax + PLAYER.upgrade_level_by_kind + rcx * 4]
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
