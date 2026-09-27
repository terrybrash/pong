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
EXTERN waveOutOpen:PROC
EXTERN waveOutPrepareHeader:PROC
EXTERN waveOutWrite:PROC
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
VK_M                                equ 4Dh
VK_R                                equ 52h
VK_S                                equ 53h
VK_W                                equ 57h
VIRTUAL_KEY_COUNT                   equ 256
BI_RGB                              equ 0
DIB_RGB_COLORS                      equ 0
SRCCOPY                             equ 00CC0020h
WAVE_MAPPER                         equ 0FFFFFFFFh
WAVE_FORMAT_PCM                     equ 1
CALLBACK_NULL                       equ 0
MMSYSERR_NOERROR                    equ 0
WHDR_DONE_BIT                       equ 0
WHDR_DONE                           equ 1 SHL WHDR_DONE_BIT
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
FRAME_LOCAL_AFTER_ARG5              equ CALL_ARG6
MAIN_ENTRY_FRAME_BYTES              equ CALL_ARG12 + 16
FRAME_PRESENT_FRAME_BYTES           equ CALL_ARG13 + 8
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
POPUP_SPAWN_PUSHED_REGISTER_COUNT   equ 3
POPUP_SPAWN_ARG5                    equ FRAME_4_ARGS_ODD_PUSHES_BYTES + 8 * POPUP_SPAWN_PUSHED_REGISTER_COUNT + CALLEE_ARG5
POPUP_SPAWN_ARG6                    equ POPUP_SPAWN_ARG5 + 8
PARTICLES_SPAWN_BURST_ARG5          equ 8 + CALLEE_ARG5
SOUND_SYNTHESIZE_PUSHED_REGISTER_COUNT equ 5
SOUND_SYNTHESIZE_ARG5               equ 8 * SOUND_SYNTHESIZE_PUSHED_REGISTER_COUNT + CALLEE_ARG5

SCREEN_WIDTH_PX                     equ 320
SCREEN_HEIGHT_PX                    equ 240
SCREEN_PIXEL_COUNT                  equ SCREEN_WIDTH_PX * SCREEN_HEIGHT_PX
WINDOW_SCALE                        equ 3
WINDOW_CLIENT_WIDTH_PX              equ SCREEN_WIDTH_PX * WINDOW_SCALE
WINDOW_CLIENT_HEIGHT_PX             equ SCREEN_HEIGHT_PX * WINDOW_SCALE
WINDOW_STYLE                        equ WS_CAPTION OR WS_SYSMENU OR WS_MINIMIZEBOX OR WS_VISIBLE

SIM_TICKS_PER_SEC                   equ 120
SIM_TICKS_BEHIND_MAX                equ 8
PERCENT_COUNT                       equ 100

COLOR_BLACK_BGRA                    equ 00000000h
COLOR_CENTER_LINE_BGRA              equ 008080A0h
COLOR_WHITE_BGRA                    equ 00F0F0F0h
COLOR_GOLD_BGRA                     equ 00FFD040h
COLOR_FLAME_BGRA                    equ 00FF7830h
COLOR_STAR_BGRA                     equ 0090A0D0h
COLOR_TEXT_BRIGHT_BGRA              equ 00D0D0E0h
COLOR_TEXT_DIM_BGRA                 equ 00808090h
COLOR_COMBO_BGRA                    equ 00FFE070h
COLOR_CARD_BORDER_BGRA              equ 00383848h
COLOR_CARD_PANEL_BGRA               equ 00101018h
COLOR_CARD_PANEL_SELECTED_BGRA      equ 001A1A2Ah
COLOR_ALPHA_MASK                    equ 0FF000000h
TEXT_COLOR_RAINBOW                  equ 0FF000000h
COLOR_LEVEL_SHIFT                   equ 8
COLOR_LEVEL_FULL                    equ 1 SHL COLOR_LEVEL_SHIFT
LERP_LEVEL_SHIFT                    equ 7
LERP_LEVEL_FULL                     equ 1 SHL LERP_LEVEL_SHIFT
RAINBOW_COLOR_COUNT                 equ 16
RAINBOW_RANDOM_SHIFT                equ 28
TRIANGLE_WAVE_PERIOD_TICKS          equ 32

BACKGROUND_LEVEL_BASE               equ 10
BACKGROUND_LEVEL_PER_MULTIPLIER     equ 5
BACKGROUND_HUE_SHIFT                equ 4
BACKGROUND_FLASH_TICKS              equ 12
BACKGROUND_FLASH_LEVEL_PER_TICK     equ 7
CENTER_LINE_WIDTH_PX                equ 2
CENTER_LINE_DASH_PX                 equ 8
CENTER_LINE_PERIOD_PX               equ 16
CENTER_LINE_LEVEL_BASE              equ 60
CENTER_LINE_LEVEL_PER_TRIANGLE_STEP equ 9
CENTER_LINE_SHIMMER_PHASE_PER_DASH  equ 3
STAR_COUNT                          equ 64
STAR_HASH_MULTIPLIER                equ -1640531535
.ERRNZ (STAR_HASH_MULTIPLIER AND 0FFFFFFFFh) - 9E3779B1h
STAR_SPEED_LAYER_COUNT              equ 4
STAR_LEVEL_BASE                     equ 40
STAR_LEVEL_PER_SPEED_LAYER          equ 40
STAR_IDLE_DRIFT_Q8                  equ 24
STAR_SCROLL_PERIOD_Q8               equ SCREEN_WIDTH_PX * 256 * 12
STAR_STREAK_DIVISOR                 equ 3

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
TEXT_SCALE_SMALL                    equ 1
TEXT_SCALE_LARGE                    equ 2
TEXT_SCALE_HUGE                     equ 3
TEXT_SCALE_GIANT                    equ 4
TEXT_RAINBOW_HUE_PER_CHAR           equ 2
TEXT_WAVE_PHASE_PER_CHAR            equ 5
TEXT_WAVE_DIVISOR                   equ 4
TEXT_SCRATCH_BYTES                  equ 64
TEXT_NUMBER_MAX                     equ 999

SCORE_DECIMAL_BASE                  equ 10
SCORE_CELL_PX                       equ 4
SCORE_POP_CELL_PX                   equ 5
SCORE_TOP_PX                        equ 12
SCORE_CENTER_FROM_SCREEN_CENTER_PX  equ 44
SCORE_MAX                           equ 99
SCORE_ROLL_PERIOD_TICKS             equ 4
.ERRNZ SCORE_ROLL_PERIOD_TICKS AND (SCORE_ROLL_PERIOD_TICKS - 1)
SCORE_POP_TICKS                     equ 6

MATCH_WINNING_SCORE                 equ 21
.ERRE MATCH_WINNING_SCORE - 1 + 9 LE SCORE_MAX
POINT_SCORED_TICKS                  equ 100
POINT_BIG_MIN                       equ 2
POINT_JACKPOT_MIN                   equ 5
POINT_ARPEGGIO_EXTRA_NOTES          equ 2
OVER_FIREWORK_PERIOD_TICKS          equ 16
OVER_COIN_PERIOD_TICKS              equ 2
.ERRNZ OVER_FIREWORK_PERIOD_TICKS AND (OVER_FIREWORK_PERIOD_TICKS - 1)
.ERRNZ OVER_COIN_PERIOD_TICKS AND (OVER_COIN_PERIOD_TICKS - 1)
OVER_TITLE_TOP_PX                   equ 70
OVER_STATS_TOP_PX                   equ 118
OVER_STATS_LINE_PX                  equ 12
OVER_PROMPT_TOP_PX                  equ 170
OVER_PROMPT_BLINK_BIT_MASK          equ 32

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
PADDLE_GLOW_LEVEL                   equ 70

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
SERVE_REEL_BOX_WIDTH_PX             equ 56
SERVE_REEL_BOX_HEIGHT_PX            equ 30
SERVE_REEL_BOX_LEFT_PX              equ (SCREEN_WIDTH_PX - SERVE_REEL_BOX_WIDTH_PX) / 2
SERVE_REEL_BOX_TOP_PX               equ 134
SERVE_REEL_BOX_BORDER_PX            equ 2
SERVE_REEL_SYMBOL_TOP_PX            equ SERVE_REEL_BOX_TOP_PX + (SERVE_REEL_BOX_HEIGHT_PX - FONT_TEXT_ROWS * TEXT_SCALE_HUGE) / 2
SERVE_REEL_LABEL_TOP_PX             equ SERVE_REEL_BOX_TOP_PX + SERVE_REEL_BOX_HEIGHT_PX + 4

RALLY_MULTIPLIER_MAX                equ 9
COMBO_HITS_PER_MULTIPLIER           equ 4
COMBO_POPUP_MIN                     equ 3
MULTIPLIER_POP_TICKS                equ 12
MULTIPLIER_UP_ARPEGGIO_NOTES        equ 4
CRIT_CHANCE_BASE_PERCENT            equ 10
CRIT_CHANCE_PER_POWER_LEVEL_PERCENT equ 5
CRIT_CHANCE_MAX_PERCENT             equ 50
HUD_MULTIPLIER_TOP_PX               equ 38
HUD_COMBO_TOP_PX                    equ 66
BALL_POP_TICKS                      equ 6
BALL_FLAME_MULTIPLIER_MIN           equ 3
BALL_RAINBOW_MULTIPLIER_MIN         equ 3
BALL_GOLD_MULTIPLIER_MIN            equ 2
BALL_RAINBOW_FLAME_MULTIPLIER_MIN   equ 5

UPGRADE_KIND_LONG_PADDLE            equ 0
UPGRADE_KIND_QUICK_PADDLE           equ 1
UPGRADE_KIND_POWER_HIT              equ 2
UPGRADE_KIND_SHARP_ANGLE            equ 3
UPGRADE_KIND_SHIELD                 equ 4
UPGRADE_KIND_SHRINK_FOE             equ 5
UPGRADE_KIND_COUNT                  equ 6
UPGRADE_RARITY_COMMON               equ 0
UPGRADE_RARITY_RARE                 equ 1
UPGRADE_RARITY_EPIC                 equ 2
UPGRADE_RARITY_LEGENDARY            equ 3
UPGRADE_RARITY_COUNT                equ 4
UPGRADE_RARITY_RARE_BELOW_PERCENT   equ 40
UPGRADE_RARITY_EPIC_BELOW_PERCENT   equ 15
UPGRADE_RARITY_LEGENDARY_BELOW_PERCENT equ 4
UPGRADE_RARITY_SEMITONE_STEP        equ 5
UPGRADE_OFFER_COUNT                 equ 3
UPGRADE_REELS_ALL_STOPPED_MASK      equ (1 SHL UPGRADE_OFFER_COUNT) - 1
.ERRE UPGRADE_KIND_COUNT GE UPGRADE_OFFER_COUNT
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
UPGRADE_TAKEN_TICKS                 equ 44
UPGRADE_TAKEN_BLINK_BIT_MASK        equ 4
UPGRADE_SPIN_BLINK_BIT_MASK         equ 2
UPGRADE_TITLE_TOP_PX                equ 42
UPGRADE_PROMPT_TOP_PX               equ 224
UPGRADE_CARD_LEFT_PX                equ 36
UPGRADE_CARD_WIDTH_PX               equ 248
UPGRADE_CARD_HEIGHT_PX              equ 46
UPGRADE_CARD_TOP_PX                 equ 56
UPGRADE_CARD_PITCH_PX               equ 54
UPGRADE_CARD_CENTER_Y_FIELD_PX      equ UPGRADE_CARD_TOP_PX + UPGRADE_CARD_HEIGHT_PX / 2 - SCREEN_HEIGHT_PX / 2
UPGRADE_CARD_BORDER_PX              equ 2
UPGRADE_CARD_GLOW_PX                equ 2
UPGRADE_CARD_GLOW_LEVEL             equ 90
UPGRADE_CARD_DIM_BORDER_LEVEL       equ 150
UPGRADE_CARD_SELECTED_SHIFT_PX      equ 6
UPGRADE_CARD_TEXT_INSET_PX          equ 10
UPGRADE_CARD_NAME_TOP_INSET_PX      equ 9
UPGRADE_CARD_DESCRIPTION_TOP_INSET_PX equ 30
UPGRADE_CARD_RARITY_TOP_INSET_PX    equ 5
UPGRADE_CARD_RARITY_RIGHT_INSET_PX  equ 7
UPGRADE_CARD_PIP_SIZE_PX            equ 4
UPGRADE_CARD_PIP_PITCH_PX           equ 6
UPGRADE_CARD_PIP_RIGHT_INSET_PX     equ 11
UPGRADE_CARD_PIP_TOP_INSET_PX       equ 38
UPGRADE_CARD_PIPS_MAX               equ 12
UPGRADE_CARD_SLIDE_TICKS            equ 18
UPGRADE_CARD_SLIDE_STAGGER_TICKS    equ 4
.ERRE UPGRADE_CARD_LEFT_PX + UPGRADE_CARD_SLIDE_TICKS * UPGRADE_CARD_SLIDE_TICKS GE SCREEN_WIDTH_PX
UPGRADE_CARD_PULSE_LEVEL_MIN        equ 160
UPGRADE_CARD_PULSE_LEVEL_PER_TICK   equ 6
.ERRE UPGRADE_CARD_PULSE_LEVEL_MIN + UPGRADE_CARD_PULSE_LEVEL_PER_TICK * TRIANGLE_WAVE_PERIOD_TICKS / 2 LE COLOR_LEVEL_FULL

HIT_STOP_SHIELD_TICKS               equ 8
SLOW_MO_TICK_DIVISOR                equ 3
SCREEN_FLASH_LEVEL_MAX              equ 100
.ERRE SCREEN_FLASH_LEVEL_MAX LE LERP_LEVEL_FULL
SCREEN_DARKEN_LEVEL                 equ 96
CHROMA_OFFSET_MAX_PX                equ 4
CHROMA_TICKS_PER_PX                 equ 3
CHROMA_ROW_PADDING_PX               equ 8
.ERRE CHROMA_ROW_PADDING_PX GE CHROMA_OFFSET_MAX_PX
ZOOM_MAX_PX                         equ 16

PARTICLE_COUNT_MAX                  equ 512
.ERRNZ PARTICLE_COUNT_MAX AND (PARTICLE_COUNT_MAX - 1)
PARTICLE_LEVEL_PER_LIFE_TICK        equ 6
PARTICLE_COLOR_MODE_ARGUMENT        equ 0
PARTICLE_COLOR_MODE_RANDOM_HUE      equ 1
POPUP_COUNT                         equ 16
.ERRNZ POPUP_COUNT AND (POPUP_COUNT - 1)
POPUP_TEXT_BYTES                    equ 32
POPUP_NO_NUMBER                     equ -1
POPUP_POP_BIG_TICKS                 equ 4
POPUP_POP_TICKS                     equ 9
POPUP_BLINK_TICKS                   equ 16
POPUP_BLINK_BIT_MASK                equ 4

BALL_TRAIL_LENGTH                   equ 16
.ERRNZ BALL_TRAIL_LENGTH AND (BALL_TRAIL_LENGTH - 1)
BALL_TRAIL_LEVEL_PER_STEP           equ 10

AUDIO_SAMPLE_RATE_HZ                equ 22050
AUDIO_BYTES_PER_SAMPLE              equ 2
AUDIO_BITS_PER_SAMPLE               equ 16
AUDIO_BUFFER_SAMPLES                equ 256
.ERRNZ AUDIO_BUFFER_SAMPLES MOD 8
AUDIO_BUFFER_COUNT                  equ 5
AUDIO_VOICE_COUNT                   equ 24
MUSIC_CHANNEL_COUNT                 equ 8
AUDIO_SFX_VOICE_FIRST               equ MUSIC_CHANNEL_COUNT
AUDIO_SFX_VOICE_COUNT               equ AUDIO_VOICE_COUNT - MUSIC_CHANNEL_COUNT
.ERRNZ AUDIO_SFX_VOICE_COUNT AND (AUDIO_SFX_VOICE_COUNT - 1)
AUDIO_SEMITONE_MIN                  equ -12
AUDIO_SEMITONE_MAX                  equ 24
AUDIO_SEMITONE_STEP_COUNT           equ AUDIO_SEMITONE_MAX - AUDIO_SEMITONE_MIN + 1
AUDIO_POSITION_FRACTION_BITS        equ 16
AUDIO_SAMPLE_COUNT_MAX              equ 1 SHL AUDIO_POSITION_FRACTION_BITS
AUDIO_PITCH_JITTER_MASK             equ 2047
AUDIO_PITCH_JITTER_CENTER           equ 1024
AUDIO_PITCH_JITTER_SHIFT            equ 15
AUDIO_ARPEGGIO_NOTE_DELAY_SAMPLES   equ AUDIO_SAMPLE_RATE_HZ * 55 / 1000
VOLUME_QUIET                        equ 45
VOLUME_NORMAL                       equ 90
VOLUME_LOUD                         equ 130

SOUND_WAVEFORM_SQUARE_SWEEP         equ 0
SOUND_WAVEFORM_TRIANGLE_SWEEP       equ 1
SOUND_WAVEFORM_NOISE                equ 2
SOUND_WAVEFORM_SQUARE_TWO_TONE      equ 3
SOUND_WAVEFORM_COUNT                equ 4
SOUND_AMPLITUDE                     equ 100
SOUND_PHASE_STEP_PER_HZ             equ 194783
.ERRE SOUND_PHASE_STEP_PER_HZ * AUDIO_SAMPLE_RATE_HZ LE 0FFFFFFFFh
.ERRE (SOUND_PHASE_STEP_PER_HZ + 1) * AUDIO_SAMPLE_RATE_HZ GT 0FFFFFFFFh
SOUND_TRIANGLE_HALF_PERIOD          equ 128
SOUND_SAMPLE_PEAK                   equ 127

MUSIC_STEPS_PER_BAR_SHIFT           equ 4
MUSIC_STEPS_PER_BAR                 equ 1 SHL MUSIC_STEPS_PER_BAR_SHIFT
MUSIC_BAR_COUNT                     equ 8
MUSIC_SONG_STEP_COUNT               equ MUSIC_STEPS_PER_BAR * MUSIC_BAR_COUNT
.ERRNZ MUSIC_SONG_STEP_COUNT AND (MUSIC_SONG_STEP_COUNT - 1)
MUSIC_BEATS_PER_MINUTE_BASE         equ 150
MUSIC_STEP_SAMPLES_BASE             equ AUDIO_SAMPLE_RATE_HZ * 60 / MUSIC_BEATS_PER_MINUTE_BASE / 4
MUSIC_STEP_SAMPLES_PER_TEMPO_BONUS  equ 45
MUSIC_TEMPO_BONUS_MAX               equ RALLY_MULTIPLIER_MAX - 1
.ERRE MUSIC_STEP_SAMPLES_BASE - MUSIC_STEP_SAMPLES_PER_TEMPO_BONUS * MUSIC_TEMPO_BONUS_MAX GT AUDIO_BUFFER_SAMPLES
MUSIC_REST                          equ 127
MUSIC_DRUM_KICK                     equ 1
MUSIC_DRUM_SNARE                    equ 2
MUSIC_DRUM_HAT                      equ 4
MUSIC_DRUM_OPEN_HAT                 equ 8
MUSIC_CHANNEL_KICK                  equ 0
MUSIC_CHANNEL_SNARE                 equ 1
MUSIC_CHANNEL_HAT                   equ 2
MUSIC_CHANNEL_BASS                  equ 3
MUSIC_CHANNEL_ARP                   equ 4
MUSIC_CHANNEL_LEAD                  equ 5
MUSIC_INSTRUMENT_KICK               equ 0
MUSIC_INSTRUMENT_SNARE              equ 1
MUSIC_INSTRUMENT_HAT                equ 2
MUSIC_INSTRUMENT_OPEN_HAT           equ 3
MUSIC_INSTRUMENT_BASS               equ 4
MUSIC_INSTRUMENT_ARP                equ 5
MUSIC_INSTRUMENT_LEAD               equ 6
MUSIC_INSTRUMENT_COUNT              equ 7
MUSIC_INTENSITY_DRUMS_AND_BASS      equ 0
MUSIC_INTENSITY_ARP                 equ 1
MUSIC_INTENSITY_LEAD                equ 2
MUSIC_INTENSITY_BUSY                equ 3
MUSIC_LEAD_COMBO_MIN                equ 4
MUSIC_BUSY_MULTIPLIER_MIN           equ 5
MUSIC_ARP_TONES_PER_BAR             equ 4

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

rainbow_color_from_eax MACRO color_reg32
    and eax, RAINBOW_COLOR_COUNT - 1
    lea r11, rainbow_color_bgra
    mov color_reg32, dword ptr [r11 + rax * 4]
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

float_clamp_symmetric MACRO xmm_reg, xmm_temp, limit
    movss xmm_temp, limit
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

sound_define MACRO sound_name, waveform, duration_ms, start_hz, end_hz
    sound_name&_WAVEFORM equ waveform
    sound_name&_SAMPLE_COUNT equ AUDIO_SAMPLE_RATE_HZ * duration_ms / 1000
    sound_name&_START_HZ equ start_hz
    sound_name&_END_HZ equ end_hz
    .ERRE sound_name&_SAMPLE_COUNT LT AUDIO_SAMPLE_COUNT_MAX
    sound_name SBYTE sound_name&_SAMPLE_COUNT DUP (?)
ENDM

sound_synthesize_call MACRO sound_name
    lea rcx, sound_name
    mov edx, sound_name&_SAMPLE_COUNT
    mov r8d, sound_name&_START_HZ
    mov r9d, sound_name&_END_HZ
    mov dword ptr [rsp + CALL_ARG5], sound_name&_WAVEFORM
    call sound_synthesize
ENDM

audio_play_call MACRO sound_name, semitone, volume, delay_ms
    mov r8d, semitone
    lea rcx, sound_name
    mov edx, sound_name&_SAMPLE_COUNT
    mov r9d, volume
    mov dword ptr [rsp + CALL_ARG5], (delay_ms) * AUDIO_SAMPLE_RATE_HZ / 1000
    call audio_play
ENDM

music_note_call MACRO channel, instrument, semitone, delay_reg32
    mov r8d, semitone
    mov r9d, delay_reg32
    mov ecx, channel
    mov edx, instrument
    call music_note_play
ENDM

particles_spawn_call MACRO style, color
    mov dword ptr [rsp + CALL_ARG5], color
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

WAVEFORMATEX STRUCT
    wFormatTag                      WORD ?
    nChannels                       WORD ?
    nSamplesPerSec                  DWORD ?
    nAvgBytesPerSec                 DWORD ?
    nBlockAlign                     WORD ?
    wBitsPerSample                  WORD ?
    cbSize                          WORD ?
WAVEFORMATEX ENDS
.ERRNZ SIZEOF WAVEFORMATEX - 18

WAVEHDR STRUCT
    lpData                          QWORD ?
    dwBufferLength                  DWORD ?
    dwBytesRecorded                 DWORD ?
    dwUser                          QWORD ?
    dwFlags                         DWORD ?
    dwLoops                         DWORD ?
    lpNext                          QWORD ?
    reserved                        QWORD ?
WAVEHDR ENDS
.ERRNZ SIZEOF WAVEHDR - 48

VOICE STRUCT
    sample_pointer                  QWORD ?
    sample_count                    DWORD ?
    position_q16                    DWORD ?
    step_q16                        DWORD ?
    volume                          DWORD ?
    delay_samples                   DWORD ?
    voice_padding                   DWORD ?
VOICE ENDS
.ERRNZ SIZEOF VOICE - 32

MUSIC_INSTRUMENT STRUCT
    sample_pointer                  QWORD ?
    sample_count                    DWORD ?
    volume                          DWORD ?
MUSIC_INSTRUMENT ENDS

PLAYER STRUCT
    paddle_center_y_px              REAL4 ?
    paddle_half_height_px           REAL4 ?
    paddle_half_height_shown_px     REAL4 ?
    paddle_speed_px_per_tick        REAL4 ?
    paddle_recoil_px                REAL4 ?
    paddle_flash_ticks_left         DWORD ?
    score                           DWORD ?
    score_shown                     DWORD ?
    score_pop_ticks_left            DWORD ?
    upgrade_level_by_kind           DWORD UPGRADE_KIND_COUNT DUP (?)
PLAYER ENDS

PARTICLE STRUCT
    pos_x_px                        REAL4 ?
    pos_y_px                        REAL4 ?
    vel_x_px_per_tick               REAL4 ?
    vel_y_px_per_tick               REAL4 ?
    gravity_px_per_tick2            REAL4 ?
    life_ticks_left                 DWORD ?
    color_bgra                      DWORD ?
    particle_padding                DWORD ?
PARTICLE ENDS

PARTICLE_STYLE STRUCT
    burst_count                     DWORD ?
    spread_px_per_tick              REAL4 ?
    base_vel_y_px_per_tick          REAL4 ?
    gravity_px_per_tick2            REAL4 ?
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

UPGRADE_REEL STRUCT
    kind                            DWORD ?
    rarity                          DWORD ?
    stop_tick                       DWORD ?
    shown_kind                      DWORD ?
    next_change_tick                DWORD ?
    flash_ticks_left                DWORD ?
UPGRADE_REEL ENDS

.data?
sound_define sound_hit, SOUND_WAVEFORM_SQUARE_SWEEP, 60, 440, 660
sound_define sound_wall, SOUND_WAVEFORM_TRIANGLE_SWEEP, 60, 330, 250
sound_define sound_blip, SOUND_WAVEFORM_SQUARE_SWEEP, 35, 880, 880
sound_define sound_tick, SOUND_WAVEFORM_TRIANGLE_SWEEP, 22, 1300, 1000
sound_define sound_clack, SOUND_WAVEFORM_NOISE, 45, 0, 0
sound_define sound_boom, SOUND_WAVEFORM_NOISE, 380, 0, 0
sound_define sound_zap, SOUND_WAVEFORM_SQUARE_SWEEP, 240, 1500, 180
sound_define sound_point, SOUND_WAVEFORM_SQUARE_SWEEP, 520, 900, 110
sound_define sound_coin, SOUND_WAVEFORM_SQUARE_TWO_TONE, 120, 988, 1319
sound_define sound_rise, SOUND_WAVEFORM_SQUARE_SWEEP, 400, 220, 1320
sound_define sound_shield, SOUND_WAVEFORM_TRIANGLE_SWEEP, 220, 150, 900
sound_define music_kick, SOUND_WAVEFORM_TRIANGLE_SWEEP, 170, 170, 40
sound_define music_snare, SOUND_WAVEFORM_NOISE, 140, 0, 0
sound_define music_hat, SOUND_WAVEFORM_NOISE, 28, 0, 0
sound_define music_open_hat, SOUND_WAVEFORM_NOISE, 110, 0, 0
sound_define music_bass, SOUND_WAVEFORM_SQUARE_SWEEP, 170, 110, 110
sound_define music_arp, SOUND_WAVEFORM_SQUARE_SWEEP, 70, 220, 220
sound_define music_lead, SOUND_WAVEFORM_SQUARE_SWEEP, 190, 440, 440

.const
ALIGN 16
float_sign_mask_x4                  DWORD 4 DUP (80000000h)
float_abs_mask_x4                   DWORD 4 DUP (7FFFFFFFh)
pixel_red_mask_x4                   DWORD 4 DUP (00FF0000h)
pixel_green_mask_x4                 DWORD 4 DUP (0000FF00h)
pixel_blue_mask_x4                  DWORD 4 DUP (000000FFh)
float_one                           REAL4 1.0
random_unit_float_scale             REAL4 5.9604645e-8
field_half_width_px                 REAL4 160.0
field_half_height_px                REAL4 120.0
paddle_right_center_x_px            REAL4 142.0
paddle_half_width_px                REAL4 2.0
paddle_flash_half_width_extra_px    REAL4 1.0
paddle_glow_extra_px                REAL4 3.0
paddle_recoil_hit_px                REAL4 4.0
paddle_recoil_decay_per_tick        REAL4 0.75
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
ball_pop_extra_half_size_px         REAL4 1.0
ball_serve_speed_px_per_tick        REAL4 1.6
ball_speed_gain_per_paddle_hit      REAL4 1.06
ball_speed_add_per_power_level_px_per_tick REAL4 0.3
ball_speed_cap_base_px_per_tick     REAL4 3.5
ball_speed_cap_per_power_level_px_per_tick REAL4 0.5
ball_speed_cap_max_px_per_tick      REAL4 6.0
ball_crit_speed_factor              REAL4 1.3
ball_speed_absolute_max_px_per_tick REAL4 7.0
ball_bounce_slope_per_sharp_level   REAL4 0.4
ball_bounce_slope_max               REAL4 2.2
ball_serve_slopes                   REAL4 -0.6, -0.3, 0.3, 0.6
BALL_SERVE_SLOPE_COUNT              equ LENGTHOF ball_serve_slopes
ball_heat_levels_per_px_per_tick    REAL4 2.1
ball_trail_half_size_per_step_px    REAL4 0.125
ball_flame_back_speed_factor        REAL4 -0.3
shield_line_center_x_px             REAL4 157.0
shield_line_half_width_px           REAL4 1.0
particle_drag_per_tick              REAL4 0.94
particle_half_size_px               REAL4 1.0
particle_paddle_hit_speed_px_per_tick REAL4 1.3
particle_shield_speed_px_per_tick   REAL4 1.6
particle_point_speed_px_per_tick    REAL4 2.2
particle_coin_speed_px_per_tick     REAL4 1.2
confetti_spread_x_px                REAL4 130.0
confetti_spread_y_px                REAL4 70.0
firework_center_y_px                REAL4 -20.0
coin_rain_spread_x_px               REAL4 155.0
coin_rain_top_y_px                  REAL4 -125.0
star_scroll_q8_per_px_per_tick      REAL4 -80.0
popup_banner_top_y_px               REAL4 -56.0
popup_banner_middle_y_px            REAL4 -26.0
popup_banner_low_y_px               REAL4 24.0
popup_banner_rally_y_px             REAL4 -24.0
popup_banner_bottom_y_px            REAL4 64.0
popup_crit_rise_px                  REAL4 12.0
popup_combo_offset_y_px             REAL4 10.0
popup_goal_x_max_px                 REAL4 135.0
popup_goal_y_max_px                 REAL4 90.0
popup_card_rarity_x_px              REAL4 96.0
popup_card_gain_x_px                REAL4 -104.0
side_color_bgra                     DWORD 0040C8FFh, 00FF7040h
.ERRNZ LENGTHOF side_color_bgra - SIDE_COUNT
ball_heat_color_bgra                DWORD 00F0F0F0h, 00FFE070h, 00FFA040h, 00FF4838h
BALL_HEAT_COLOR_COUNT               equ LENGTHOF ball_heat_color_bgra
rainbow_color_bgra                  DWORD 00FF0000h, 00FF5F00h, 00FFBF00h, 00DFFF00h, 007FFF00h, 001FFF00h, 0000FF3Fh, 0000FF9Fh
                                    DWORD 0000FFFFh, 00009FFFh, 00003FFFh, 001F00FFh, 007F00FFh, 00DF00FFh, 00FF00BFh, 00FF005Fh
rainbow_color_bgra_end              LABEL DWORD
.ERRNZ (rainbow_color_bgra_end - rainbow_color_bgra) - 4 * RAINBOW_COLOR_COUNT
serve_reel_weighted_multipliers     DWORD 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 5
SERVE_REEL_WEIGHTED_COUNT           equ LENGTHOF serve_reel_weighted_multipliers
serve_reel_strip_multipliers        DWORD 1, 2, 5, 3, 1, 2, 3, 5, 1, 3, 2, 5, 1, 2, 3, 5
SERVE_REEL_STRIP_COUNT              equ LENGTHOF serve_reel_strip_multipliers
.ERRNZ SERVE_REEL_STRIP_COUNT AND (SERVE_REEL_STRIP_COUNT - 1)
upgrade_rarity_level_gain           DWORD 1, 2, 3, 5
upgrade_rarity_color_bgra           DWORD 00C8C8D0h, 003C8CFFh, 00B048FFh, 00FFC830h
audio_semitone_steps_q16            DWORD 32768, 34717, 36781, 38968, 41285, 43740, 46341, 49097, 52016, 55109, 58386, 61858
                                    DWORD 65536, 69433, 73562, 77936, 82570, 87480, 92682, 98193, 104032, 110218, 116772, 123715
                                    DWORD 131072, 138866, 147124, 155872, 165140, 174960, 185364, 196386, 208064, 220436, 233544, 247430
                                    DWORD 262144
audio_semitone_steps_q16_end        LABEL DWORD
.ERRNZ (audio_semitone_steps_q16_end - audio_semitone_steps_q16) - 4 * AUDIO_SEMITONE_STEP_COUNT
audio_arpeggio_semitones            DWORD 0, 4, 7, 12, 16, 19, 24
AUDIO_ARPEGGIO_NOTE_COUNT           equ LENGTHOF audio_arpeggio_semitones

music_drum_patterns                 BYTE 5, 0, 4, 1, 6, 0, 4, 0, 4, 1, 5, 0, 6, 0, 8, 2
                                    BYTE 5, 0, 4, 1, 6, 0, 5, 0, 2, 0, 2, 2, 6, 2, 2, 2
music_bar_drum_patterns             BYTE 0, 0, 0, 1, 0, 0, 0, 1
.ERRNZ LENGTHOF music_bar_drum_patterns - MUSIC_BAR_COUNT
music_bass_rhythm                   SBYTE 0, 127, 0, 12, 127, 0, 127, 12, 0, 127, 7, 127, 0, 12, 10, 7
.ERRNZ LENGTHOF music_bass_rhythm - MUSIC_STEPS_PER_BAR
music_bar_chord_roots               SBYTE 0, 0, -4, -2, 0, 0, -4, -5
.ERRNZ LENGTHOF music_bar_chord_roots - MUSIC_BAR_COUNT
music_bar_arp_tones                 SBYTE 0, 3, 7, 12, 0, 3, 7, 12, -4, 0, 3, 8, -2, 2, 5, 10
                                    SBYTE 0, 3, 7, 12, 0, 3, 7, 12, -4, 0, 3, 8, -5, -1, 2, 7
music_bar_arp_tones_end             LABEL BYTE
.ERRNZ (music_bar_arp_tones_end - music_bar_arp_tones) - MUSIC_BAR_COUNT * MUSIC_ARP_TONES_PER_BAR
music_lead_notes                    SBYTE 12, 127, 127, 10, 127, 127, 7, 127, 10, 127, 12, 127, 15, 127, 12, 127
                                    SBYTE 12, 127, 127, 10, 127, 127, 7, 127, 5, 127, 7, 127, 3, 127, 0, 127
                                    SBYTE 8, 127, 127, 7, 127, 127, 5, 127, 7, 127, 8, 127, 12, 127, 8, 127
                                    SBYTE 10, 127, 127, 7, 127, 127, 10, 127, 14, 127, 12, 127, 10, 127, 7, 127
                                    SBYTE 12, 127, 127, 10, 127, 127, 7, 127, 10, 127, 12, 127, 15, 127, 12, 127
                                    SBYTE 12, 127, 15, 127, 17, 127, 15, 127, 12, 127, 10, 127, 12, 127, 127, 127
                                    SBYTE 8, 127, 12, 127, 15, 127, 12, 127, 20, 127, 19, 127, 17, 127, 15, 127
                                    SBYTE 7, 127, 11, 127, 14, 127, 11, 127, 19, 127, 16, 127, 14, 127, 11, 127
music_lead_notes_end                LABEL BYTE
.ERRNZ (music_lead_notes_end - music_lead_notes) - MUSIC_SONG_STEP_COUNT

ALIGN 8
music_instruments                   MUSIC_INSTRUMENT <music_kick, music_kick_SAMPLE_COUNT, 150>
                                    MUSIC_INSTRUMENT <music_snare, music_snare_SAMPLE_COUNT, 100>
                                    MUSIC_INSTRUMENT <music_hat, music_hat_SAMPLE_COUNT, 38>
                                    MUSIC_INSTRUMENT <music_open_hat, music_open_hat_SAMPLE_COUNT, 42>
                                    MUSIC_INSTRUMENT <music_bass, music_bass_SAMPLE_COUNT, 85>
                                    MUSIC_INSTRUMENT <music_arp, music_arp_SAMPLE_COUNT, 34>
                                    MUSIC_INSTRUMENT <music_lead, music_lead_SAMPLE_COUNT, 58>
music_instruments_end               LABEL QWORD
.ERRNZ (music_instruments_end - music_instruments) - MUSIC_INSTRUMENT_COUNT * SIZEOF MUSIC_INSTRUMENT

particles_paddle_hit                PARTICLE_STYLE <14, 1.1, 0.0, 0.0, 14, 24, PARTICLE_COLOR_MODE_ARGUMENT>
particles_crit                      PARTICLE_STYLE <48, 2.6, 0.0, 0.0, 20, 34, PARTICLE_COLOR_MODE_RANDOM_HUE>
particles_wall_hit                  PARTICLE_STYLE <8, 0.9, 0.0, 0.0, 10, 16, PARTICLE_COLOR_MODE_ARGUMENT>
particles_shield                    PARTICLE_STYLE <30, 1.6, 0.0, 0.0, 18, 26, PARTICLE_COLOR_MODE_ARGUMENT>
particles_point                     PARTICLE_STYLE <60, 2.6, 0.0, 0.0, 20, 36, PARTICLE_COLOR_MODE_ARGUMENT>
particles_coin_burst                PARTICLE_STYLE <24, 1.8, -1.8, 0.06, 40, 40, PARTICLE_COLOR_MODE_ARGUMENT>
particles_flame                     PARTICLE_STYLE <1, 0.35, -0.15, -0.01, 8, 10, PARTICLE_COLOR_MODE_ARGUMENT>
particles_flame_rainbow             PARTICLE_STYLE <2, 0.45, -0.15, -0.01, 10, 12, PARTICLE_COLOR_MODE_RANDOM_HUE>
particles_firework                  PARTICLE_STYLE <60, 2.2, 0.0, 0.035, 30, 40, PARTICLE_COLOR_MODE_RANDOM_HUE>
particles_coin_rain                 PARTICLE_STYLE <1, 0.3, 1.0, 0.04, 90, 30, PARTICLE_COLOR_MODE_ARGUMENT>
particles_reel_common               PARTICLE_STYLE <10, 1.4, 0.0, 0.0, 12, 16, PARTICLE_COLOR_MODE_ARGUMENT>
particles_reel_rare                 PARTICLE_STYLE <24, 1.8, 0.0, 0.0, 16, 20, PARTICLE_COLOR_MODE_ARGUMENT>
particles_reel_epic                 PARTICLE_STYLE <44, 2.3, 0.0, 0.0, 18, 26, PARTICLE_COLOR_MODE_ARGUMENT>
particles_reel_legendary            PARTICLE_STYLE <90, 3.0, 0.0, 0.02, 30, 40, PARTICLE_COLOR_MODE_RANDOM_HUE>
particles_upgrade_take              PARTICLE_STYLE <50, 2.4, 0.0, 0.0, 20, 30, PARTICLE_COLOR_MODE_ARGUMENT>

popup_style_combo                   POPUP_STYLE <TEXT_SCALE_SMALL, COLOR_COMBO_BGRA, 40, -0.6>
popup_style_crit                    POPUP_STYLE <TEXT_SCALE_HUGE, TEXT_COLOR_RAINBOW, 60, -0.35>
popup_style_banner                  POPUP_STYLE <TEXT_SCALE_LARGE, TEXT_COLOR_RAINBOW, 90, 0.0>
popup_style_jackpot                 POPUP_STYLE <TEXT_SCALE_HUGE, TEXT_COLOR_RAINBOW, 110, -0.15>
popup_style_points                  POPUP_STYLE <TEXT_SCALE_HUGE, COLOR_GOLD_BGRA, 70, -0.5>
popup_style_info                    POPUP_STYLE <TEXT_SCALE_LARGE, COLOR_WHITE_BGRA, 60, -0.3>
popup_style_rarity                  POPUP_STYLE <TEXT_SCALE_SMALL, TEXT_COLOR_RAINBOW, 50, -0.4>

punch_wall_hit                      PUNCH <0.7, 5, 0, 0, 0, 0, 0, 0>
punch_paddle_hit                    PUNCH <1.3, 10, 0, 0, 0, 3, 3, 0>
punch_crit                          PUNCH <4.0, 24, COLOR_WHITE_BGRA, 8, 14, 14, 9, 30>
punch_multiplier_up                 PUNCH <2.0, 16, COLOR_GOLD_BGRA, 6, 6, 10, 0, 0>
punch_serve_multiplier              PUNCH <2.0, 14, COLOR_GOLD_BGRA, 6, 8, 10, 0, 0>
punch_shield                        PUNCH <3.0, 24, COLOR_WHITE_BGRA, 5, 6, 8, HIT_STOP_SHIELD_TICKS, 0>
punch_point                         PUNCH <4.5, 36, COLOR_WHITE_BGRA, 6, 10, 12, 0, 0>
punch_point_big                     PUNCH <6.0, 50, COLOR_GOLD_BGRA, 12, 18, 16, 0, 0>
punch_jackpot                       PUNCH <7.0, 60, COLOR_GOLD_BGRA, 16, 24, 18, 0, 0>
punch_match_won                     PUNCH <6.0, 60, COLOR_WHITE_BGRA, 20, 20, 18, 0, 90>
punch_reel_stop                     PUNCH <1.0, 6, 0, 0, 0, 4, 0, 0>
punch_reel_epic                     PUNCH <2.5, 16, 00B048FFh, 6, 8, 8, 0, 0>
punch_reroll                        PUNCH <1.5, 10, COLOR_WHITE_BGRA, 4, 4, 6, 0, 0>
punch_upgrade_take                  PUNCH <2.0, 14, COLOR_WHITE_BGRA, 6, 6, 10, 0, 0>

ALIGN 8
upgrade_rarity_particle_styles      QWORD particles_reel_common, particles_reel_rare, particles_reel_epic, particles_reel_legendary
.ERRNZ LENGTHOF upgrade_rarity_particle_styles - UPGRADE_RARITY_COUNT
upgrade_rarity_punches              QWORD punch_reel_stop, punch_reel_stop, punch_reel_epic, punch_jackpot
.ERRNZ LENGTHOF upgrade_rarity_punches - UPGRADE_RARITY_COUNT

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

text_empty                          BYTE 0
text_upgrade_long_paddle_name       BYTE "LONG PADDLE", 0
text_upgrade_long_paddle_description BYTE "YOUR PADDLE GETS LONGER", 0
text_upgrade_quick_paddle_name      BYTE "QUICK PADDLE", 0
text_upgrade_quick_paddle_description BYTE "YOUR PADDLE MOVES FASTER", 0
text_upgrade_power_hit_name         BYTE "POWER HIT", 0
text_upgrade_power_hit_description  BYTE "FASTER BALL, MORE CRITS", 0
text_upgrade_sharp_angle_name       BYTE "SHARP ANGLE", 0
text_upgrade_sharp_angle_description BYTE "YOUR HITS GO AT STEEPER ANGLES", 0
text_upgrade_shield_name            BYTE "SHIELD", 0
text_upgrade_shield_description     BYTE "A WALL BEHIND YOU STOPS A GOAL", 0
text_upgrade_shrink_foe_name        BYTE "SHRINK FOE", 0
text_upgrade_shrink_foe_description BYTE "THE OTHER PADDLE GETS SHORTER", 0
text_upgrade_rarity_common          BYTE "COMMON +1", 0
text_upgrade_rarity_rare            BYTE "RARE +2", 0
text_upgrade_rarity_epic            BYTE "EPIC +3", 0
text_upgrade_rarity_legendary       BYTE "LEGENDARY +5", 0
text_upgrade_title_you              BYTE "YOU LOST THE POINT. SPIN FOR AN UPGRADE!", 0
text_upgrade_title_cpu              BYTE "CPU LOST THE POINT. IT SPINS!", 0
text_upgrade_title_left             BYTE "LEFT LOST THE POINT. SPIN FOR AN UPGRADE!", 0
text_upgrade_title_right            BYTE "RIGHT LOST THE POINT. SPIN FOR AN UPGRADE!", 0
text_upgrade_prompt                 BYTE "YOUR KEYS: MOVE   SPACE: TAKE", 0
text_upgrade_prompt_reroll          BYTE "   R: REROLL", 0
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
text_popup_common                   BYTE "COMMON", 0
text_popup_rare                     BYTE "RARE!", 0
text_popup_epic                     BYTE "EPIC!!", 0
text_popup_legendary                BYTE "LEGENDARY!!!", 0
text_hud_combo_prefix               BYTE "COMBO ", 0
text_serve_reel_label               BYTE "POINT VALUE", 0
text_over_title_you                 BYTE "YOU WIN!", 0
text_over_title_cpu                 BYTE "CPU WINS!", 0
text_over_title_left                BYTE "LEFT WINS!", 0
text_over_title_right               BYTE "RIGHT WINS!", 0
text_over_stat_combo                BYTE "BEST COMBO ", 0
text_over_stat_crits                BYTE "CRITS ", 0
text_over_stat_jackpots             BYTE "JACKPOTS ", 0
text_over_prompt                    BYTE "SPACE OR ENTER: NEW MATCH", 0

ALIGN 8
upgrade_name_texts                  QWORD text_upgrade_long_paddle_name, text_upgrade_quick_paddle_name, text_upgrade_power_hit_name, text_upgrade_sharp_angle_name, text_upgrade_shield_name, text_upgrade_shrink_foe_name
.ERRNZ LENGTHOF upgrade_name_texts - UPGRADE_KIND_COUNT
upgrade_description_texts           QWORD text_upgrade_long_paddle_description, text_upgrade_quick_paddle_description, text_upgrade_power_hit_description, text_upgrade_sharp_angle_description, text_upgrade_shield_description, text_upgrade_shrink_foe_description
.ERRNZ LENGTHOF upgrade_description_texts - UPGRADE_KIND_COUNT
upgrade_rarity_texts                QWORD text_upgrade_rarity_common, text_upgrade_rarity_rare, text_upgrade_rarity_epic, text_upgrade_rarity_legendary
.ERRNZ LENGTHOF upgrade_rarity_texts - UPGRADE_RARITY_COUNT
upgrade_rarity_popup_texts          QWORD text_popup_common, text_popup_rare, text_popup_epic, text_popup_legendary
.ERRNZ LENGTHOF upgrade_rarity_popup_texts - UPGRADE_RARITY_COUNT
upgrade_title_texts                 QWORD text_upgrade_title_you, text_upgrade_title_cpu, text_upgrade_title_left, text_upgrade_title_right
.ERRNZ LENGTHOF upgrade_title_texts - PADDLE_RIGHT_MODE_COUNT * SIDE_COUNT
over_title_texts                    QWORD text_over_title_you, text_over_title_cpu, text_over_title_left, text_over_title_right
.ERRNZ LENGTHOF over_title_texts - PADDLE_RIGHT_MODE_COUNT * SIDE_COUNT

.data
window_class_name                   BYTE "pong", 0
window_title                        BYTE "Pong    W S or Up Down: move    Tab: 2 players    M: music    Esc: quit", 0
window_class                        WNDCLASSEXA <SIZEOF WNDCLASSEXA, CS_OWNDC>
window_outer_rect                   RECT <0, 0, WINDOW_CLIENT_WIDTH_PX, WINDOW_CLIENT_HEIGHT_PX>
framebuffer_bitmap_info             BITMAPINFOHEADER <SIZEOF BITMAPINFOHEADER, SCREEN_WIDTH_PX, -SCREEN_HEIGHT_PX, 1, 32, BI_RGB>
window_message                      MSG <>
audio_format                        WAVEFORMATEX <WAVE_FORMAT_PCM, 1, AUDIO_SAMPLE_RATE_HZ, AUDIO_SAMPLE_RATE_HZ * AUDIO_BYTES_PER_SAMPLE, AUDIO_BYTES_PER_SAMPLE, AUDIO_BITS_PER_SAMPLE, 0>

.data?
ALIGN 16
framebuffer_bgra                    DWORD SCREEN_PIXEL_COUNT DUP (?)
chroma_row_bgra                     DWORD SCREEN_WIDTH_PX + 2 * CHROMA_ROW_PADDING_PX DUP (?)
audio_mix_accumulator               DWORD AUDIO_BUFFER_SAMPLES DUP (?)
audio_buffers                       WORD AUDIO_BUFFER_SAMPLES * AUDIO_BUFFER_COUNT DUP (?)
audio_headers                       WAVEHDR AUDIO_BUFFER_COUNT DUP (<>)
audio_voices                        VOICE AUDIO_VOICE_COUNT DUP (<>)
audio_device                        QWORD ?
window_dc                           QWORD ?
qpc_counts_per_sec                  QWORD ?
qpc_counts_per_tick                 QWORD ?
qpc_frame_last                      QWORD ?
qpc_frame_now                       QWORD ?
qpc_sim_behind_counts               QWORD ?
players                             PLAYER SIDE_COUNT DUP (<>)
particles                           PARTICLE PARTICLE_COUNT_MAX DUP (<>)
popups                              POPUP POPUP_COUNT DUP (<>)
upgrade_reels                       UPGRADE_REEL UPGRADE_OFFER_COUNT DUP (<>)
text_scratch                        BYTE TEXT_SCRATCH_BYTES DUP (?)
match_mode                          DWORD ?
match_mode_ticks                    DWORD ?
match_point_loser_side              DWORD ?
match_best_combo                    DWORD ?
match_crit_count                    DWORD ?
match_jackpot_count                 DWORD ?
paddle_right_mode                   DWORD ?
paddle_cpu_aim_offset_fraction      REAL4 ?
ball_center_x_px                    REAL4 ?
ball_center_y_px                    REAL4 ?
ball_vel_x_px_per_tick              REAL4 ?
ball_vel_y_px_per_tick              REAL4 ?
ball_speed_px_per_tick              REAL4 ?
ball_pop_ticks_left                 DWORD ?
ball_trail_x_px                     REAL4 BALL_TRAIL_LENGTH DUP (?)
ball_trail_y_px                     REAL4 BALL_TRAIL_LENGTH DUP (?)
ball_trail_next_index               DWORD ?
ball_trail_count                    DWORD ?
rally_combo                         DWORD ?
rally_serve_multiplier_bonus        DWORD ?
multiplier_pop_ticks_left           DWORD ?
serve_reel_result_multiplier        DWORD ?
serve_reel_shown_multiplier         DWORD ?
serve_reel_strip_index              DWORD ?
serve_reel_next_change_tick         DWORD ?
serve_reel_bounce_ticks_left        DWORD ?
upgrade_reels_stopped_mask          DWORD ?
upgrade_reels_all_stopped_tick      DWORD ?
upgrade_offer_cursor                DWORD ?
upgrade_rerolls_left                DWORD ?
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
starfield_scroll_q8                 DWORD ?
effects_ticks                       DWORD ?
particle_next_index                 DWORD ?
popup_next_index                    DWORD ?
audio_sfx_voice_next                DWORD ?
music_step                          DWORD ?
music_samples_until_step            DWORD ?
music_intensity                     DWORD ?
music_tempo_bonus                   DWORD ?
music_muted                         DWORD ?
random_state                        DWORD ?
key_is_down_by_virtual_key          BYTE VIRTUAL_KEY_COUNT DUP (?)
key_was_pressed_by_virtual_key      BYTE VIRTUAL_KEY_COUNT DUP (?)

.code

main_entry PROC
    sub rsp, MAIN_ENTRY_FRAME_BYTES
    frame_alignment_check 0, MAIN_ENTRY_FRAME_BYTES

    rdtsc
    mov random_state, eax
    sound_synthesize_call sound_hit
    sound_synthesize_call sound_wall
    sound_synthesize_call sound_blip
    sound_synthesize_call sound_tick
    sound_synthesize_call sound_clack
    sound_synthesize_call sound_boom
    sound_synthesize_call sound_zap
    sound_synthesize_call sound_point
    sound_synthesize_call sound_coin
    sound_synthesize_call sound_rise
    sound_synthesize_call sound_shield
    sound_synthesize_call music_kick
    sound_synthesize_call music_snare
    sound_synthesize_call music_hat
    sound_synthesize_call music_open_hat
    sound_synthesize_call music_bass
    sound_synthesize_call music_arp
    sound_synthesize_call music_lead
    call audio_init

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
    call audio_pump
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
    sub rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 2, FRAME_6_ARGS_EVEN_PUSHES_BYTES

    lea rbx, key_was_pressed_by_virtual_key
    cmp byte ptr [rbx + VK_TAB], 0
    je game_tick_music_key
    mov byte ptr [rbx + VK_TAB], 0
    assert_below_unsigned paddle_right_mode, PADDLE_RIGHT_MODE_COUNT
    xor paddle_right_mode, PADDLE_RIGHT_MODE_CPU XOR PADDLE_RIGHT_MODE_KEYBOARD
game_tick_music_key:
    cmp byte ptr [rbx + VK_M], 0
    je game_tick_effects
    mov byte ptr [rbx + VK_M], 0
    call music_mute_toggle

game_tick_effects:
    call players_stats_update
    call effects_tick
    call music_state_update
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
    call serve_wait_tick
    jmp game_tick_done

game_tick_rally:
    call paddles_tick
    call ball_tick
    jmp game_tick_done

game_tick_point_scored:
    call paddles_tick
    cmp match_mode_ticks, POINT_SCORED_TICKS
    jb game_tick_done
    lea rax, players[SIZEOF PLAYER * SIDE_LEFT]
    mov ecx, (PLAYER PTR [rax]).score
    cmp ecx, (PLAYER PTR [rax]).score_shown
    jne game_tick_done
    lea rax, players[SIZEOF PLAYER * SIDE_RIGHT]
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
    call paddles_tick
    call over_tick

game_tick_done:
    lea rdi, key_was_pressed_by_virtual_key
    mov ecx, VIRTUAL_KEY_COUNT
    xor eax, eax
    rep stosb
game_tick_return:
    add rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
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
    push rbx
    push rsi
    sub rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 2, FRAME_6_ARGS_EVEN_PUSHES_BYTES
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
    addss xmm0, (PARTICLE PTR [rcx]).gravity_px_per_tick2
    mulss xmm0, xmm2
    movss (PARTICLE PTR [rcx]).vel_y_px_per_tick, xmm0
    addss xmm0, (PARTICLE PTR [rcx]).pos_y_px
    movss (PARTICLE PTR [rcx]).pos_y_px, xmm0
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

    mov eax, STAR_IDLE_DRIFT_Q8
    cmp match_mode, MATCH_MODE_RALLY
    jne effects_tick_star_scroll
    movss xmm0, ball_vel_x_px_per_tick
    mulss xmm0, star_scroll_q8_per_px_per_tick
    cvtss2si ecx, xmm0
    add eax, ecx
effects_tick_star_scroll:
    add eax, starfield_scroll_q8
    jns effects_tick_star_scroll_not_negative
    add eax, STAR_SCROLL_PERIOD_Q8
effects_tick_star_scroll_not_negative:
    cmp eax, STAR_SCROLL_PERIOD_Q8
    jb effects_tick_star_scroll_wrapped
    sub eax, STAR_SCROLL_PERIOD_Q8
effects_tick_star_scroll_wrapped:
    mov starfield_scroll_q8, eax

    lea rbx, players
    xor esi, esi
effects_tick_player:
    counter_down_to_zero <(PLAYER PTR [rbx]).paddle_flash_ticks_left>
    counter_down_to_zero <(PLAYER PTR [rbx]).score_pop_ticks_left>
    movss xmm0, (PLAYER PTR [rbx]).paddle_recoil_px
    mulss xmm0, paddle_recoil_decay_per_tick
    movss (PLAYER PTR [rbx]).paddle_recoil_px, xmm0
    movss xmm0, (PLAYER PTR [rbx]).paddle_half_height_px
    movss xmm1, (PLAYER PTR [rbx]).paddle_half_height_shown_px
    subss xmm0, xmm1
    mulss xmm0, paddle_half_height_shown_ease_per_tick
    addss xmm0, xmm1
    movss (PLAYER PTR [rbx]).paddle_half_height_shown_px, xmm0
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

    add rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    pop rsi
    pop rbx
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

serve_wait_tick PROC
    push rbx
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 1, FRAME_6_ARGS_ODD_PUSHES_BYTES
    call paddles_tick
    xorps xmm0, xmm0
    movss ball_center_x_px, xmm0
    movss ball_center_y_px, xmm0
    movss xmm0, ball_serve_speed_px_per_tick
    movss ball_speed_px_per_tick, xmm0

    mov ebx, match_mode_ticks
    cmp ebx, 1
    jne serve_wait_tick_reel
    mov rally_combo, 0
    mov rally_serve_multiplier_bonus, 0
    mov ecx, SERVE_REEL_WEIGHTED_COUNT
    random_below_to_eax ecx
    lea rcx, serve_reel_weighted_multipliers
    mov eax, dword ptr [rcx + rax * 4]
    mov serve_reel_result_multiplier, eax
    mov serve_reel_shown_multiplier, 1
    mov serve_reel_next_change_tick, SERVE_REEL_START_TICK
    lea rax, players[SIZEOF PLAYER * SIDE_LEFT]
    cmp (PLAYER PTR [rax]).score, MATCH_WINNING_SCORE - 1
    jae serve_wait_tick_match_point
    lea rax, players[SIZEOF PLAYER * SIDE_RIGHT]
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
    sub rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 0, FRAME_6_ARGS_EVEN_PUSHES_BYTES
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
    audio_play_call sound_rise, AUDIO_SEMITONE_MIN, VOLUME_QUIET, 0
    add rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
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
    jae ball_tick_flame
    inc ball_trail_count

ball_tick_flame:
    call rally_multiplier_get
    mov ebx, eax
    call ball_heat_index_get
    cmp eax, BALL_HEAT_COLOR_COUNT - 1
    jae ball_tick_flame_spawn
    cmp ebx, BALL_FLAME_MULTIPLIER_MIN
    jb ball_tick_walls
ball_tick_flame_spawn:
    movss xmm0, ball_center_x_px
    movss xmm1, ball_center_y_px
    movss xmm2, ball_vel_x_px_per_tick
    mulss xmm2, ball_flame_back_speed_factor
    cmp ebx, BALL_RAINBOW_FLAME_MULTIPLIER_MIN
    jae ball_tick_flame_rainbow
    particles_spawn_call particles_flame, COLOR_FLAME_BGRA
    jmp ball_tick_walls
ball_tick_flame_rainbow:
    particles_spawn_call particles_flame_rainbow, COLOR_BLACK_BGRA

ball_tick_walls:
    movss xmm1, ball_center_y_px
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
    movss xmm0, ball_center_x_px
    movss xmm1, ball_center_y_px
    xorps xmm2, xmm2
    particles_spawn_call particles_wall_hit, COLOR_WHITE_BGRA
    screen_punch_call punch_wall_hit
    audio_play_call sound_wall, 0, VOLUME_NORMAL, 0

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
    screen_punch_call punch_shield
    side_color_load eax, rbx
    movss xmm2, particle_shield_speed_px_per_tick
    movss xmm0, ball_vel_x_px_per_tick
    andps xmm0, xmmword ptr float_sign_mask_x4
    orps xmm2, xmm0
    movss xmm0, ball_center_x_px
    movss xmm1, ball_center_y_px
    particles_spawn_call particles_shield, eax
    movss xmm2, ball_center_x_px
    movss xmm3, ball_center_y_px
    popup_spawn_call text_popup_saved, POPUP_NO_NUMBER, popup_style_info
    audio_play_call sound_shield, 0, VOLUME_LOUD, 0
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
    push rdi
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_6_ARGS_ODD_PUSHES_BYTES
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

    inc rally_combo
    mov eax, rally_combo
    counter_raise_to match_best_combo, eax
    mov ecx, upgrade_level(rsi, UPGRADE_KIND_POWER_HIT)
    imul ecx, ecx, CRIT_CHANCE_PER_POWER_LEVEL_PERCENT
    add ecx, CRIT_CHANCE_BASE_PERCENT
    mov eax, CRIT_CHANCE_MAX_PERCENT
    cmp ecx, eax
    cmova ecx, eax
    mov r8d, ecx
    mov ecx, PERCENT_COUNT
    random_below_to_eax ecx
    xor edi, edi
    cmp eax, r8d
    setb dil
    test edi, edi
    jz ball_paddle_bounce_speed_set
    mulss xmm3, ball_crit_speed_factor
    minss xmm3, ball_speed_absolute_max_px_per_tick
ball_paddle_bounce_speed_set:
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
    movss xmm0, paddle_recoil_hit_px
    movss (PLAYER PTR [rsi]).paddle_recoil_px, xmm0
    mov ball_pop_ticks_left, BALL_POP_TICKS

    movss xmm2, particle_paddle_hit_speed_px_per_tick
    movss xmm0, ball_vel_x_px_per_tick
    andps xmm0, xmmword ptr float_sign_mask_x4
    orps xmm2, xmm0
    movss xmm0, ball_center_x_px
    movss xmm1, ball_center_y_px
    test edi, edi
    jnz ball_paddle_bounce_crit
    side_color_load eax, rbx
    particles_spawn_call particles_paddle_hit, eax
    screen_punch_call punch_paddle_hit
    jmp ball_paddle_bounce_sound
ball_paddle_bounce_crit:
    particles_spawn_call particles_crit, COLOR_BLACK_BGRA
    screen_punch_call punch_crit
    inc match_crit_count
    movss xmm2, ball_center_x_px
    movss xmm3, ball_center_y_px
    subss xmm3, popup_crit_rise_px
    popup_spawn_call text_popup_crit, POPUP_NO_NUMBER, popup_style_crit
    audio_play_call sound_zap, 0, VOLUME_LOUD, 0
    audio_play_call sound_boom, 0, VOLUME_NORMAL, 0

ball_paddle_bounce_sound:
    mov eax, rally_combo
    mov ecx, AUDIO_SEMITONE_MAX
    cmp eax, ecx
    cmova eax, ecx
    audio_play_call sound_hit, eax, VOLUME_NORMAL, 0

    cmp rally_combo, COMBO_POPUP_MIN
    jb ball_paddle_bounce_multiplier_check
    movss xmm2, ball_center_x_px
    movss xmm3, ball_center_y_px
    addss xmm3, popup_combo_offset_y_px
    popup_spawn_call text_empty, rally_combo, popup_style_combo, text_popup_hits_suffix

ball_paddle_bounce_multiplier_check:
    mov eax, rally_combo
    xor edx, edx
    mov ecx, COMBO_HITS_PER_MULTIPLIER
    div ecx
    test edx, edx
    jnz ball_paddle_bounce_done
    add eax, rally_serve_multiplier_bonus
    inc eax
    cmp eax, RALLY_MULTIPLIER_MAX
    ja ball_paddle_bounce_done
    mov ebx, eax
    mov multiplier_pop_ticks_left, MULTIPLIER_POP_TICKS
    xorps xmm2, xmm2
    movss xmm3, popup_banner_rally_y_px
    popup_spawn_call text_popup_multiplier_prefix, ebx, popup_style_banner, text_popup_exclamation
    screen_punch_call punch_multiplier_up
    mov ecx, MULTIPLIER_UP_ARPEGGIO_NOTES
    mov edx, ebx
    call audio_arpeggio_play

ball_paddle_bounce_done:
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
ball_paddle_bounce ENDP

point_score PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_6_ARGS_ODD_PUSHES_BYTES
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
    mov ball_trail_count, 0
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
    movss xmm2, particle_point_speed_px_per_tick
    movss xmm0, ball_center_x_px
    andps xmm0, xmmword ptr float_sign_mask_x4
    xorps xmm0, xmmword ptr float_sign_mask_x4
    orps xmm2, xmm0
    movss xmm0, ball_center_x_px
    movss xmm1, ball_center_y_px
    particles_spawn_call particles_point, eax

    movss xmm2, ball_center_x_px
    float_clamp_symmetric xmm2, xmm4, popup_goal_x_max_px
    movss xmm3, ball_center_y_px
    float_clamp_symmetric xmm3, xmm4, popup_goal_y_max_px
    popup_spawn_call text_popup_plus, edi, popup_style_points
    audio_play_call sound_point, 0, VOLUME_NORMAL, 0
    audio_play_call sound_boom, 0, VOLUME_LOUD, 0

    cmp edi, POINT_BIG_MIN
    jb point_score_done
    mov ebx, edi
point_score_coins:
    movss xmm0, ball_center_x_px
    float_clamp_symmetric xmm0, xmm4, popup_goal_x_max_px
    movss xmm1, ball_center_y_px
    movss xmm2, particle_coin_speed_px_per_tick
    movss xmm4, ball_center_x_px
    andps xmm4, xmmword ptr float_sign_mask_x4
    xorps xmm4, xmmword ptr float_sign_mask_x4
    orps xmm2, xmm4
    particles_spawn_call particles_coin_burst, COLOR_GOLD_BGRA
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
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
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
    ret
ball_heat_index_get ENDP

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

upgrade_reel_stop PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_6_ARGS_ODD_PUSHES_BYTES
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

    xorps xmm0, xmm0
    imul eax, ebx, UPGRADE_CARD_PITCH_PX
    add eax, UPGRADE_CARD_CENTER_Y_FIELD_PX
    cvtsi2ss xmm1, eax
    xorps xmm2, xmm2
    lea rax, upgrade_rarity_color_bgra
    mov eax, dword ptr [rax + rdi * 4]
    mov dword ptr [rsp + CALL_ARG5], eax
    lea rax, upgrade_rarity_particle_styles
    mov r9, qword ptr [rax + rdi * 8]
    call particles_spawn_burst
    lea rax, upgrade_rarity_punches
    mov rcx, qword ptr [rax + rdi * 8]
    call screen_punch

    cmp edi, UPGRADE_RARITY_RARE
    jb upgrade_reel_stop_done
    movss xmm2, popup_card_rarity_x_px
    imul eax, ebx, UPGRADE_CARD_PITCH_PX
    add eax, UPGRADE_CARD_CENTER_Y_FIELD_PX
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
    xorps xmm0, xmm0
    imul eax, ebx, UPGRADE_CARD_PITCH_PX
    add eax, UPGRADE_CARD_CENTER_Y_FIELD_PX
    cvtsi2ss xmm1, eax
    xorps xmm2, xmm2
    particles_spawn_call particles_coin_burst, COLOR_GOLD_BGRA
    xorps xmm0, xmm0
    imul eax, ebx, UPGRADE_CARD_PITCH_PX
    add eax, UPGRADE_CARD_CENTER_Y_FIELD_PX
    cvtsi2ss xmm1, eax
    xorps xmm2, xmm2
    particles_spawn_call particles_coin_burst, COLOR_GOLD_BGRA

upgrade_reel_stop_done:
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
upgrade_reel_stop ENDP

upgrade_cpu_decide PROC
    sub rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 0, FRAME_6_ARGS_EVEN_PUSHES_BYTES
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
    add rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    ret
upgrade_cpu_decide ENDP

upgrade_reroll PROC
    sub rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 0, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    assert_above_zero_signed upgrade_rerolls_left
    dec upgrade_rerolls_left
    mov ecx, match_mode_ticks
    call upgrade_offer_roll
    xorps xmm2, xmm2
    movss xmm3, popup_banner_top_y_px
    popup_spawn_call text_popup_reroll, POPUP_NO_NUMBER, popup_style_banner
    audio_play_call sound_rise, 0, VOLUME_NORMAL, 0
    screen_punch_call punch_reroll
    add rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    ret
upgrade_reroll ENDP

upgrade_take PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_6_ARGS_ODD_PUSHES_BYTES
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
    mov eax, dword ptr [rax + rcx * 4]
    xorps xmm0, xmm0
    imul ecx, ebx, UPGRADE_CARD_PITCH_PX
    add ecx, UPGRADE_CARD_CENTER_Y_FIELD_PX
    cvtsi2ss xmm1, ecx
    xorps xmm2, xmm2
    particles_spawn_call particles_upgrade_take, eax
    movss xmm2, popup_card_gain_x_px
    imul ecx, ebx, UPGRADE_CARD_PITCH_PX
    add ecx, UPGRADE_CARD_CENTER_Y_FIELD_PX
    cvtsi2ss xmm3, ecx
    popup_spawn_call text_popup_plus, edi, popup_style_points
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
upgrade_take ENDP

over_tick PROC
    sub rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 0, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    lea rax, key_was_pressed_by_virtual_key
    movzx ecx, byte ptr [rax + VK_SPACE]
    or cl, byte ptr [rax + VK_RETURN]
    jnz over_tick_new_match
    test match_mode_ticks, OVER_FIREWORK_PERIOD_TICKS - 1
    jnz over_tick_coins
    random_signed_unit_float_to xmm0
    mulss xmm0, confetti_spread_x_px
    random_signed_unit_float_to xmm1
    mulss xmm1, confetti_spread_y_px
    addss xmm1, firework_center_y_px
    xorps xmm2, xmm2
    particles_spawn_call particles_firework, COLOR_BLACK_BGRA
    mov ecx, STAR_SPEED_LAYER_COUNT * 2
    random_below_to_eax ecx
    sub eax, STAR_SPEED_LAYER_COUNT * 2
    audio_play_call sound_boom, eax, VOLUME_QUIET, 0
over_tick_coins:
    test match_mode_ticks, OVER_COIN_PERIOD_TICKS - 1
    jnz over_tick_done
    random_signed_unit_float_to xmm0
    mulss xmm0, coin_rain_spread_x_px
    movss xmm1, coin_rain_top_y_px
    xorps xmm2, xmm2
    particles_spawn_call particles_coin_rain, COLOR_GOLD_BGRA
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
    mov match_best_combo, 0
    mov match_crit_count, 0
    mov match_jackpot_count, 0
    mov rally_combo, 0
    mov rally_serve_multiplier_bonus, 0
    match_mode_set MATCH_MODE_SERVE_WAIT
    ret
match_new ENDP

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
    movss (PARTICLE PTR [rbx]).pos_x_px, xmm0
    movss (PARTICLE PTR [rbx]).pos_y_px, xmm1
    random_signed_unit_float_to xmm4
    mulss xmm4, (PARTICLE_STYLE PTR [r9]).spread_px_per_tick
    addss xmm4, xmm2
    movss (PARTICLE PTR [rbx]).vel_x_px_per_tick, xmm4
    random_signed_unit_float_to xmm4
    mulss xmm4, (PARTICLE_STYLE PTR [r9]).spread_px_per_tick
    addss xmm4, (PARTICLE_STYLE PTR [r9]).base_vel_y_px_per_tick
    movss (PARTICLE PTR [rbx]).vel_y_px_per_tick, xmm4
    movss xmm4, (PARTICLE_STYLE PTR [r9]).gravity_px_per_tick2
    movss (PARTICLE PTR [rbx]).gravity_px_per_tick2, xmm4
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

music_state_update PROC
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 0, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    mov eax, match_mode
    cmp eax, MATCH_MODE_RALLY
    je music_state_update_rally
    mov ecx, MUSIC_INTENSITY_DRUMS_AND_BASS
    cmp eax, MATCH_MODE_SERVE_WAIT
    je music_state_update_serve
    mov ecx, MUSIC_INTENSITY_ARP
    cmp eax, MATCH_MODE_UPGRADE_CHOOSE
    je music_state_update_set
    cmp eax, MATCH_MODE_UPGRADE_TAKEN
    je music_state_update_set
    mov ecx, MUSIC_INTENSITY_LEAD
    cmp eax, MATCH_MODE_POINT_SCORED
    je music_state_update_set
    mov ecx, MUSIC_INTENSITY_BUSY
    mov music_tempo_bonus, MUSIC_TEMPO_BONUS_MAX
    jmp music_state_update_set
music_state_update_serve:
    mov music_tempo_bonus, 0
    jmp music_state_update_set
music_state_update_rally:
    call rally_multiplier_get
    mov edx, eax
    dec eax
    mov music_tempo_bonus, eax
    mov ecx, MUSIC_INTENSITY_ARP
    cmp edx, BALL_GOLD_MULTIPLIER_MIN
    jae music_state_update_lead
    cmp rally_combo, MUSIC_LEAD_COMBO_MIN
    jb music_state_update_set
music_state_update_lead:
    mov ecx, MUSIC_INTENSITY_LEAD
    cmp edx, MUSIC_BUSY_MULTIPLIER_MIN
    jb music_state_update_set
    mov ecx, MUSIC_INTENSITY_BUSY
music_state_update_set:
    mov music_intensity, ecx
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    ret
music_state_update ENDP

music_mute_toggle PROC
    xor music_muted, 1
    lea rcx, audio_voices
    mov edx, MUSIC_CHANNEL_COUNT
music_mute_toggle_voice:
    mov (VOICE PTR [rcx]).sample_count, 0
    add rcx, SIZEOF VOICE
    dec edx
    jnz music_mute_toggle_voice
    ret
music_mute_toggle ENDP

audio_init PROC
    push rbx
    push rsi
    sub rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 2, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    lea rcx, audio_device
    mov edx, WAVE_MAPPER
    lea r8, audio_format
    xor r9d, r9d
    mov qword ptr [rsp + CALL_ARG5], 0
    mov dword ptr [rsp + CALL_ARG6], CALLBACK_NULL
    call waveOutOpen
    cmp eax, MMSYSERR_NOERROR
    je audio_init_buffers
    mov audio_device, 0
    jmp audio_init_done
audio_init_buffers:
    xor ebx, ebx
    lea rsi, audio_headers
audio_init_buffer:
    imul eax, ebx, AUDIO_BUFFER_SAMPLES * AUDIO_BYTES_PER_SAMPLE
    lea rdx, audio_buffers
    add rdx, rax
    mov (WAVEHDR PTR [rsi]).lpData, rdx
    mov (WAVEHDR PTR [rsi]).dwBufferLength, AUDIO_BUFFER_SAMPLES * AUDIO_BYTES_PER_SAMPLE
    mov rcx, audio_device
    mov rdx, rsi
    mov r8d, SIZEOF WAVEHDR
    call waveOutPrepareHeader
    mov rcx, rsi
    call audio_header_submit
    add rsi, SIZEOF WAVEHDR
    inc ebx
    cmp ebx, AUDIO_BUFFER_COUNT
    jb audio_init_buffer
audio_init_done:
    add rsp, FRAME_6_ARGS_EVEN_PUSHES_BYTES
    pop rsi
    pop rbx
    ret
audio_init ENDP

audio_pump PROC
    push rbx
    push rsi
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 2, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    cmp audio_device, 0
    je audio_pump_done
    lea rsi, audio_headers
    mov ebx, AUDIO_BUFFER_COUNT
audio_pump_header:
    test (WAVEHDR PTR [rsi]).dwFlags, WHDR_DONE
    jz audio_pump_header_next
    mov rcx, rsi
    call audio_header_submit
audio_pump_header_next:
    add rsi, SIZEOF WAVEHDR
    dec ebx
    jnz audio_pump_header
audio_pump_done:
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    pop rsi
    pop rbx
    ret
audio_pump ENDP

audio_header_submit PROC
    push rbx
    sub rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 1, FRAME_4_ARGS_ODD_PUSHES_BYTES
    mov rbx, rcx
    mov rcx, (WAVEHDR PTR [rbx]).lpData
    call audio_buffer_mix
    btr (WAVEHDR PTR [rbx]).dwFlags, WHDR_DONE_BIT
    mov rcx, audio_device
    mov rdx, rbx
    mov r8d, SIZEOF WAVEHDR
    call waveOutWrite
    add rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    pop rbx
    ret
audio_header_submit ENDP

audio_buffer_mix PROC
    push rbx
    push rsi
    push rdi
    push r12
    push r13
    push r14
    push r15
    sub rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 7, FRAME_4_ARGS_ODD_PUSHES_BYTES
    mov r15, rcx
    lea rdi, audio_mix_accumulator
    mov ecx, AUDIO_BUFFER_SAMPLES
    xor eax, eax
    rep stosd
    call music_sequencer_advance

    lea rbx, audio_voices
    mov r14d, AUDIO_VOICE_COUNT
    lea r12, audio_mix_accumulator
audio_buffer_mix_voice:
    mov r8d, (VOICE PTR [rbx]).sample_count
    test r8d, r8d
    jz audio_buffer_mix_voice_next
    mov eax, (VOICE PTR [rbx]).delay_samples
    cmp eax, AUDIO_BUFFER_SAMPLES
    jb audio_buffer_mix_voice_start
    sub eax, AUDIO_BUFFER_SAMPLES
    mov (VOICE PTR [rbx]).delay_samples, eax
    jmp audio_buffer_mix_voice_next
audio_buffer_mix_voice_start:
    mov (VOICE PTR [rbx]).delay_samples, 0
    mov ecx, eax
    mov rsi, (VOICE PTR [rbx]).sample_pointer
    mov r9d, (VOICE PTR [rbx]).position_q16
    mov r10d, (VOICE PTR [rbx]).step_q16
    mov r11d, (VOICE PTR [rbx]).volume
audio_buffer_mix_sample:
    cmp ecx, AUDIO_BUFFER_SAMPLES
    jae audio_buffer_mix_voice_store
    mov edx, r9d
    shr edx, AUDIO_POSITION_FRACTION_BITS
    cmp edx, r8d
    jae audio_buffer_mix_voice_finished
    movsx eax, byte ptr [rsi + rdx]
    imul eax, r11d
    add dword ptr [r12 + rcx * 4], eax
    add r9d, r10d
    inc ecx
    jmp audio_buffer_mix_sample
audio_buffer_mix_voice_finished:
    mov (VOICE PTR [rbx]).sample_count, 0
    jmp audio_buffer_mix_voice_next
audio_buffer_mix_voice_store:
    mov (VOICE PTR [rbx]).position_q16, r9d
audio_buffer_mix_voice_next:
    add rbx, SIZEOF VOICE
    dec r14d
    jnz audio_buffer_mix_voice

    mov rsi, r12
    mov ecx, AUDIO_BUFFER_SAMPLES / 8
audio_buffer_mix_convert:
    movdqa xmm0, xmmword ptr [rsi]
    movdqa xmm1, xmmword ptr [rsi + 16]
    packssdw xmm0, xmm1
    movdqu xmmword ptr [r15], xmm0
    add rsi, 32
    add r15, 16
    dec ecx
    jnz audio_buffer_mix_convert

    add rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    pop r15
    pop r14
    pop r13
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
audio_buffer_mix ENDP

audio_play PROC
    assert_above_zero_signed edx
    assert_below_unsigned edx, AUDIO_SAMPLE_COUNT_MAX
    mov r10d, dword ptr [rsp + CALLEE_ARG5]
    lea eax, [r8 - AUDIO_SEMITONE_MIN]
    assert_below_unsigned eax, AUDIO_SEMITONE_STEP_COUNT
    lea r11, audio_semitone_steps_q16
    mov r8d, dword ptr [r11 + rax * 4]
    random_next_to_eax
    and eax, AUDIO_PITCH_JITTER_MASK
    sub eax, AUDIO_PITCH_JITTER_CENTER
    imul eax, r8d
    sar eax, AUDIO_PITCH_JITTER_SHIFT
    add r8d, eax
    mov eax, audio_sfx_voice_next
    lea r11d, [rax + 1]
    and r11d, AUDIO_SFX_VOICE_COUNT - 1
    mov audio_sfx_voice_next, r11d
    add eax, AUDIO_SFX_VOICE_FIRST
    imul eax, eax, SIZEOF VOICE
    lea r11, audio_voices
    add r11, rax
    mov (VOICE PTR [r11]).sample_pointer, rcx
    mov (VOICE PTR [r11]).position_q16, 0
    mov (VOICE PTR [r11]).step_q16, r8d
    mov (VOICE PTR [r11]).volume, r9d
    mov (VOICE PTR [r11]).delay_samples, r10d
    mov (VOICE PTR [r11]).sample_count, edx
    ret
audio_play ENDP

audio_arpeggio_play PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_6_ARGS_ODD_PUSHES_BYTES
    assert_below_unsigned ecx, AUDIO_ARPEGGIO_NOTE_COUNT + 1
    mov ebx, ecx
    mov esi, edx
    xor edi, edi
audio_arpeggio_play_note:
    cmp edi, ebx
    jae audio_arpeggio_play_done
    lea rax, audio_arpeggio_semitones
    mov r8d, dword ptr [rax + rdi * 4]
    add r8d, esi
    mov eax, AUDIO_SEMITONE_MAX
    cmp r8d, eax
    cmovg r8d, eax
    lea rcx, sound_coin
    mov edx, sound_coin_SAMPLE_COUNT
    mov r9d, VOLUME_NORMAL
    imul eax, edi, AUDIO_ARPEGGIO_NOTE_DELAY_SAMPLES
    mov dword ptr [rsp + CALL_ARG5], eax
    call audio_play
    inc edi
    jmp audio_arpeggio_play_note
audio_arpeggio_play_done:
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
audio_arpeggio_play ENDP

music_sequencer_advance PROC
    push rbx
    sub rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 1, FRAME_4_ARGS_ODD_PUSHES_BYTES
    assert_below_unsigned music_tempo_bonus, MUSIC_TEMPO_BONUS_MAX + 1
    mov ebx, music_samples_until_step
music_sequencer_advance_step:
    cmp ebx, AUDIO_BUFFER_SAMPLES
    jge music_sequencer_advance_done
    mov ecx, ebx
    call music_step_trigger
    mov eax, music_step
    inc eax
    and eax, MUSIC_SONG_STEP_COUNT - 1
    mov music_step, eax
    imul eax, music_tempo_bonus, MUSIC_STEP_SAMPLES_PER_TEMPO_BONUS
    neg eax
    add eax, MUSIC_STEP_SAMPLES_BASE
    add ebx, eax
    jmp music_sequencer_advance_step
music_sequencer_advance_done:
    sub ebx, AUDIO_BUFFER_SAMPLES
    mov music_samples_until_step, ebx
    add rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    pop rbx
    ret
music_sequencer_advance ENDP

music_step_trigger PROC
    push rbx
    push rsi
    push rdi
    push r12
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 4, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    cmp music_muted, 0
    jne music_step_trigger_done
    mov r12d, ecx
    mov eax, music_step
    mov ebx, eax
    shr ebx, MUSIC_STEPS_PER_BAR_SHIFT
    and eax, MUSIC_STEPS_PER_BAR - 1
    mov esi, eax
    lea rax, music_bar_drum_patterns
    movzx eax, byte ptr [rax + rbx]
    shl eax, MUSIC_STEPS_PER_BAR_SHIFT
    add eax, esi
    lea rcx, music_drum_patterns
    movzx edi, byte ptr [rcx + rax]
    cmp music_intensity, MUSIC_INTENSITY_BUSY
    jb music_step_trigger_kick
    test esi, 1
    jz music_step_trigger_kick
    or edi, MUSIC_DRUM_HAT

music_step_trigger_kick:
    test edi, MUSIC_DRUM_KICK
    jz music_step_trigger_snare
    music_note_call MUSIC_CHANNEL_KICK, MUSIC_INSTRUMENT_KICK, 0, r12d
music_step_trigger_snare:
    test edi, MUSIC_DRUM_SNARE
    jz music_step_trigger_hat
    music_note_call MUSIC_CHANNEL_SNARE, MUSIC_INSTRUMENT_SNARE, 0, r12d
music_step_trigger_hat:
    test edi, MUSIC_DRUM_HAT
    jz music_step_trigger_open_hat
    music_note_call MUSIC_CHANNEL_HAT, MUSIC_INSTRUMENT_HAT, 0, r12d
music_step_trigger_open_hat:
    test edi, MUSIC_DRUM_OPEN_HAT
    jz music_step_trigger_bass
    music_note_call MUSIC_CHANNEL_HAT, MUSIC_INSTRUMENT_OPEN_HAT, 0, r12d

music_step_trigger_bass:
    lea rax, music_bass_rhythm
    movsx eax, byte ptr [rax + rsi]
    cmp eax, MUSIC_REST
    je music_step_trigger_arp
    lea rcx, music_bar_chord_roots
    movsx ecx, byte ptr [rcx + rbx]
    add eax, ecx
    music_note_call MUSIC_CHANNEL_BASS, MUSIC_INSTRUMENT_BASS, eax, r12d

music_step_trigger_arp:
    cmp music_intensity, MUSIC_INTENSITY_ARP
    jb music_step_trigger_done
    mov eax, esi
    and eax, MUSIC_ARP_TONES_PER_BAR - 1
    lea eax, [rax + rbx * MUSIC_ARP_TONES_PER_BAR]
    lea rcx, music_bar_arp_tones
    movsx eax, byte ptr [rcx + rax]
    music_note_call MUSIC_CHANNEL_ARP, MUSIC_INSTRUMENT_ARP, eax, r12d

    cmp music_intensity, MUSIC_INTENSITY_LEAD
    jb music_step_trigger_done
    mov eax, ebx
    shl eax, MUSIC_STEPS_PER_BAR_SHIFT
    add eax, esi
    lea rcx, music_lead_notes
    movsx eax, byte ptr [rcx + rax]
    cmp eax, MUSIC_REST
    je music_step_trigger_done
    music_note_call MUSIC_CHANNEL_LEAD, MUSIC_INSTRUMENT_LEAD, eax, r12d

music_step_trigger_done:
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
music_step_trigger ENDP

music_note_play PROC
    assert_below_unsigned ecx, MUSIC_CHANNEL_COUNT
    assert_below_unsigned edx, MUSIC_INSTRUMENT_COUNT
    lea eax, [r8 - AUDIO_SEMITONE_MIN]
    assert_below_unsigned eax, AUDIO_SEMITONE_STEP_COUNT
    lea r10, audio_semitone_steps_q16
    mov r8d, dword ptr [r10 + rax * 4]
    imul eax, edx, SIZEOF MUSIC_INSTRUMENT
    lea r10, music_instruments
    add r10, rax
    imul eax, ecx, SIZEOF VOICE
    lea r11, audio_voices
    add r11, rax
    mov rax, (MUSIC_INSTRUMENT PTR [r10]).sample_pointer
    mov (VOICE PTR [r11]).sample_pointer, rax
    mov (VOICE PTR [r11]).position_q16, 0
    mov (VOICE PTR [r11]).step_q16, r8d
    mov eax, (MUSIC_INSTRUMENT PTR [r10]).volume
    mov (VOICE PTR [r11]).volume, eax
    mov (VOICE PTR [r11]).delay_samples, r9d
    mov eax, (MUSIC_INSTRUMENT PTR [r10]).sample_count
    mov (VOICE PTR [r11]).sample_count, eax
    ret
music_note_play ENDP

sound_synthesize PROC
    push rbx
    push rsi
    push rdi
    push r12
    push r13
    mov r12d, dword ptr [rsp + SOUND_SYNTHESIZE_ARG5]
    assert_below_unsigned r12d, SOUND_WAVEFORM_COUNT
    assert_above_zero_signed edx
    assert_below_unsigned edx, AUDIO_SAMPLE_COUNT_MAX
    mov rdi, rcx
    mov esi, edx
    xor ebx, ebx
    xor r10d, r10d
    mov r13d, r9d
    sub r13d, r8d
sound_synthesize_sample:
    cmp r12d, SOUND_WAVEFORM_SQUARE_TWO_TONE
    jne sound_synthesize_sweep
    mov eax, r8d
    mov ecx, esi
    shr ecx, 1
    cmp ebx, ecx
    jb sound_synthesize_frequency_ready
    mov eax, r9d
    jmp sound_synthesize_frequency_ready
sound_synthesize_sweep:
    mov eax, r13d
    imul eax, ebx
    cdq
    idiv esi
    add eax, r8d
sound_synthesize_frequency_ready:
    imul eax, eax, SOUND_PHASE_STEP_PER_HZ
    add r10d, eax
    mov eax, esi
    sub eax, ebx
    imul eax, eax, SOUND_AMPLITUDE
    xor edx, edx
    div esi
    mov r11d, eax
    cmp r12d, SOUND_WAVEFORM_NOISE
    je sound_synthesize_noise
    cmp r12d, SOUND_WAVEFORM_TRIANGLE_SWEEP
    je sound_synthesize_triangle
    mov eax, r11d
    test r10d, r10d
    jns sound_synthesize_store
    neg eax
    jmp sound_synthesize_store
sound_synthesize_triangle:
    mov eax, r10d
    shr eax, 24
    cmp eax, SOUND_TRIANGLE_HALF_PERIOD
    jb sound_synthesize_triangle_rising
    mov ecx, 2 * SOUND_TRIANGLE_HALF_PERIOD - 1
    sub ecx, eax
    mov eax, ecx
sound_synthesize_triangle_rising:
    lea eax, [rax + rax - SOUND_SAMPLE_PEAK]
    imul eax, r11d
    sar eax, 7
    jmp sound_synthesize_store
sound_synthesize_noise:
    random_next_to_eax
    sar eax, 24
    imul eax, r11d
    sar eax, 7
sound_synthesize_store:
    mov byte ptr [rdi + rbx], al
    inc ebx
    cmp ebx, esi
    jb sound_synthesize_sample
    pop r13
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
sound_synthesize ENDP

frame_render PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_6_ARGS_ODD_PUSHES_BYTES

    mov ebx, 1
    cmp match_mode, MATCH_MODE_RALLY
    jne frame_render_background
    call rally_multiplier_get
    mov ebx, eax
frame_render_background:
    lea edx, [rbx - 1]
    imul edx, edx, BACKGROUND_LEVEL_PER_MULTIPLIER
    add edx, BACKGROUND_LEVEL_BASE
    mov eax, effects_ticks
    shr eax, BACKGROUND_HUE_SHIFT
    rainbow_color_from_eax ecx
    call color_scale
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

    call starfield_draw
    call center_line_draw

    xor ebx, ebx
frame_render_side:
    player_address_load rsi, ebx
    cmp upgrade_level(rsi, UPGRADE_KIND_SHIELD), 0
    je frame_render_side_score
    mov eax, effects_ticks
    triangle_wave_from_eax
    imul edx, eax, UPGRADE_CARD_PULSE_LEVEL_PER_TICK
    add edx, UPGRADE_CARD_PULSE_LEVEL_MIN
    side_color_load ecx, rbx
    call color_scale
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
    mov r9d, SCORE_CELL_PX
    cmp (PLAYER PTR [rsi]).score_pop_ticks_left, 0
    je frame_render_side_score_draw
    side_color_load edi, rbx
    mov r9d, SCORE_POP_CELL_PX
frame_render_side_score_draw:
    mov ecx, (PLAYER PTR [rsi]).score_shown
    mov edx, SCREEN_WIDTH_PX / 2 + SCORE_CENTER_FROM_SCREEN_CENTER_PX
    cmp ebx, SIDE_RIGHT
    je frame_render_side_score_x
    mov edx, SCREEN_WIDTH_PX / 2 - SCORE_CENTER_FROM_SCREEN_CENTER_PX
frame_render_side_score_x:
    mov r8d, edi
    call score_draw

    paddle_center_x_load xmm0, ebx
    movss xmm4, (PLAYER PTR [rsi]).paddle_recoil_px
    movaps xmm5, xmm0
    andps xmm5, xmmword ptr float_sign_mask_x4
    orps xmm4, xmm5
    addss xmm0, xmm4
    movss dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5], xmm0
    side_color_load ecx, rbx
    mov edx, PADDLE_GLOW_LEVEL
    call color_scale
    mov dword ptr [rsp + CALL_ARG5], eax
    movss xmm0, dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5]
    movss xmm1, (PLAYER PTR [rsi]).paddle_center_y_px
    movss xmm2, paddle_half_width_px
    addss xmm2, paddle_glow_extra_px
    movss xmm3, (PLAYER PTR [rsi]).paddle_half_height_shown_px
    addss xmm3, paddle_glow_extra_px
    call framebuffer_rect_fill_field

    side_color_load edi, rbx
    movss xmm0, dword ptr [rsp + FRAME_LOCAL_AFTER_ARG5]
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
    jne frame_render_hud
    test match_mode_ticks, SERVE_BLINK_BIT_MASK
    jnz frame_render_hud
frame_render_ball:
    call ball_draw

frame_render_hud:
    mov eax, match_mode
    cmp eax, MATCH_MODE_RALLY
    je frame_render_hud_draw
    cmp eax, MATCH_MODE_SERVE_WAIT
    jne frame_render_overlay
    call serve_reel_draw
frame_render_hud_draw:
    call hud_draw

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
    call popups_draw
    call frame_post_effects

    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
frame_render ENDP

starfield_draw PROC
    push rbx
    push rsi
    push rdi
    push r12
    push r13
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 5, FRAME_6_ARGS_ODD_PUSHES_BYTES
    mov r12d, 1
    cmp match_mode, MATCH_MODE_RALLY
    jne starfield_draw_stars
    call rally_multiplier_get
    mov r12d, eax
starfield_draw_stars:
    xor ebx, ebx
starfield_draw_star:
    lea esi, [rbx + 1]
    imul esi, esi, STAR_HASH_MULTIPLIER
    mov edi, esi
    shr edi, 5
    and edi, STAR_SPEED_LAYER_COUNT - 1
    inc edi
    mov eax, starfield_scroll_q8
    imul eax, edi
    shr eax, 8
    movzx ecx, si
    imul ecx, ecx, SCREEN_WIDTH_PX
    shr ecx, 16
    add eax, ecx
    xor edx, edx
    mov ecx, SCREEN_WIDTH_PX
    div ecx
    mov r13d, edx
    imul edx, edi, STAR_LEVEL_PER_SPEED_LAYER
    add edx, STAR_LEVEL_BASE
    mov ecx, COLOR_STAR_BGRA
    call color_scale
    mov dword ptr [rsp + CALL_ARG5], eax
    mov eax, edi
    imul eax, r12d
    xor edx, edx
    mov ecx, STAR_STREAK_DIVISOR
    div ecx
    lea r8d, [rax + 1]
    mov edx, esi
    shr edx, 16
    imul edx, edx, SCREEN_HEIGHT_PX
    shr edx, 16
    mov ecx, r13d
    mov r9d, 1
    call framebuffer_rect_fill
    inc ebx
    cmp ebx, STAR_COUNT
    jb starfield_draw_star
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop r13
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
starfield_draw ENDP

center_line_draw PROC
    push rbx
    push rsi
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 2, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    mov ebx, (CENTER_LINE_PERIOD_PX - CENTER_LINE_DASH_PX) / 2
    xor esi, esi
center_line_draw_dash:
    imul eax, esi, CENTER_LINE_SHIMMER_PHASE_PER_DASH
    add eax, effects_ticks
    triangle_wave_from_eax
    imul edx, eax, CENTER_LINE_LEVEL_PER_TRIANGLE_STEP
    add edx, CENTER_LINE_LEVEL_BASE
    mov ecx, COLOR_CENTER_LINE_BGRA
    call color_scale
    mov dword ptr [rsp + CALL_ARG5], eax
    mov ecx, (SCREEN_WIDTH_PX - CENTER_LINE_WIDTH_PX) / 2
    mov edx, ebx
    mov r8d, CENTER_LINE_WIDTH_PX
    mov r9d, CENTER_LINE_DASH_PX
    call framebuffer_rect_fill
    add ebx, CENTER_LINE_PERIOD_PX
    inc esi
    cmp ebx, SCREEN_HEIGHT_PX
    jb center_line_draw_dash
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    pop rsi
    pop rbx
    ret
center_line_draw ENDP

ball_draw PROC
    push rbx
    push rsi
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 2, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    call rally_multiplier_get
    mov esi, eax
    cmp esi, BALL_RAINBOW_MULTIPLIER_MIN
    jb ball_draw_gold_check
    mov eax, effects_ticks
    shr eax, 1
    rainbow_color_from_eax ebx
    jmp ball_draw_color_ready
ball_draw_gold_check:
    mov ebx, COLOR_GOLD_BGRA
    cmp esi, BALL_GOLD_MULTIPLIER_MIN
    jae ball_draw_color_ready
    call ball_heat_index_get
    lea rcx, ball_heat_color_bgra
    mov ebx, dword ptr [rcx + rax * 4]
ball_draw_color_ready:
    mov ecx, ebx
    xor edx, edx
    cmp esi, BALL_RAINBOW_MULTIPLIER_MIN
    setae dl
    call ball_trail_draw
    mov dword ptr [rsp + CALL_ARG5], ebx
    movss xmm0, ball_center_x_px
    movss xmm1, ball_center_y_px
    movss xmm2, ball_half_size_px
    cmp ball_pop_ticks_left, 0
    je ball_draw_size_ready
    addss xmm2, ball_pop_extra_half_size_px
ball_draw_size_ready:
    movaps xmm3, xmm2
    call framebuffer_rect_fill_field
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    pop rsi
    pop rbx
    ret
ball_draw ENDP

ball_trail_draw PROC
    push rbx
    push rsi
    push rdi
    push r12
    push r13
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 5, FRAME_6_ARGS_ODD_PUSHES_BYTES
    mov r12d, ecx
    mov r13d, edx
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
    mov ecx, r12d
    test r13d, r13d
    jz ball_trail_draw_color_ready
    lea eax, [rbx * 2]
    add eax, effects_ticks
    rainbow_color_from_eax ecx
ball_trail_draw_color_ready:
    mov edx, BALL_TRAIL_LENGTH
    sub edx, ebx
    imul edx, edx, BALL_TRAIL_LEVEL_PER_STEP
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
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop r13
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
ball_trail_draw ENDP

hud_draw PROC
    push rbx
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 1, FRAME_6_ARGS_ODD_PUSHES_BYTES
    call rally_multiplier_get
    mov ebx, eax
    cmp ebx, BALL_GOLD_MULTIPLIER_MIN
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
    mov edx, SCREEN_WIDTH_PX / 2
    mov r8d, HUD_MULTIPLIER_TOP_PX
    mov r9d, TEXT_COLOR_RAINBOW
    call text_draw_centered

hud_draw_combo:
    cmp match_mode, MATCH_MODE_RALLY
    jne hud_draw_done
    mov eax, rally_combo
    cmp eax, COMBO_POPUP_MIN - 1
    jb hud_draw_done
    lea rcx, text_scratch
    lea rdx, text_hud_combo_prefix
    call text_append_string
    mov rcx, rax
    mov edx, rally_combo
    call text_append_number
    mov r9d, COLOR_COMBO_BGRA
    cmp ebx, BALL_RAINBOW_MULTIPLIER_MIN
    jb hud_draw_combo_color_ready
    mov r9d, TEXT_COLOR_RAINBOW
hud_draw_combo_color_ready:
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_SMALL
    lea rcx, text_scratch
    mov edx, SCREEN_WIDTH_PX / 2
    mov r8d, HUD_COMBO_TOP_PX
    call text_draw_centered
hud_draw_done:
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
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
    cmp serve_reel_result_multiplier, BALL_GOLD_MULTIPLIER_MIN
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
    cmp serve_reel_result_multiplier, BALL_GOLD_MULTIPLIER_MIN
    jb serve_reel_draw_symbol
    mov r9d, TEXT_COLOR_RAINBOW
serve_reel_draw_symbol:
    mov r8d, SERVE_REEL_SYMBOL_TOP_PX
    sub r8d, serve_reel_bounce_ticks_left
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_HUGE
    lea rcx, text_scratch
    mov edx, SCREEN_WIDTH_PX / 2
    call text_draw_centered
    lea rcx, text_serve_reel_label
    mov edx, SCREEN_WIDTH_PX / 2
    mov r8d, SERVE_REEL_LABEL_TOP_PX
    mov r9d, COLOR_TEXT_DIM_BGRA
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_SMALL
    call text_draw_centered
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rbx
    ret
serve_reel_draw ENDP

particles_draw PROC
    push rbx
    push rsi
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 2, FRAME_4_ARGS_EVEN_PUSHES_BYTES
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
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    pop rsi
    pop rbx
    ret
particles_draw ENDP

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
    add edx, SCREEN_WIDTH_PX / 2
    cvtss2si r8d, (POPUP PTR [rbx]).pos_y_px
    add r8d, SCREEN_HEIGHT_PX / 2
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

frame_post_effects PROC
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 0, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    mov eax, screen_flash_ticks_left
    test eax, eax
    jz frame_post_effects_chroma
    imul eax, eax, SCREEN_FLASH_LEVEL_MAX
    xor edx, edx
    div screen_flash_duration_ticks
    mov edx, eax
    mov ecx, screen_flash_color_bgra
    call framebuffer_lerp_toward
frame_post_effects_chroma:
    mov eax, screen_chroma_ticks_left
    test eax, eax
    jz frame_post_effects_done
    add eax, CHROMA_TICKS_PER_PX - 1
    xor edx, edx
    mov ecx, CHROMA_TICKS_PER_PX
    div ecx
    mov ecx, CHROMA_OFFSET_MAX_PX
    cmp eax, ecx
    cmova eax, ecx
    mov ecx, eax
    call framebuffer_chromatic_split
frame_post_effects_done:
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    ret
frame_post_effects ENDP

upgrade_screen_draw PROC
    push rbx
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 1, FRAME_6_ARGS_ODD_PUSHES_BYTES
    mov ecx, COLOR_BLACK_BGRA
    mov edx, SCREEN_DARKEN_LEVEL
    call framebuffer_lerp_toward

    mov eax, paddle_right_mode
    imul eax, eax, SIDE_COUNT
    add eax, match_point_loser_side
    lea rcx, upgrade_title_texts
    mov rcx, qword ptr [rcx + rax * 8]
    mov edx, SCREEN_WIDTH_PX / 2
    mov r8d, UPGRADE_TITLE_TOP_PX
    mov r9d, TEXT_COLOR_RAINBOW
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_SMALL
    call text_draw_centered

    cmp match_mode, MATCH_MODE_UPGRADE_CHOOSE
    jne upgrade_screen_draw_cards
    cmp upgrade_reels_stopped_mask, UPGRADE_REELS_ALL_STOPPED_MASK
    jne upgrade_screen_draw_cards
    cmp match_point_loser_side, SIDE_RIGHT
    jne upgrade_screen_draw_prompt
    cmp paddle_right_mode, PADDLE_RIGHT_MODE_CPU
    je upgrade_screen_draw_cards
upgrade_screen_draw_prompt:
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
    mov edx, SCREEN_WIDTH_PX / 2
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
    jne upgrade_card_draw_taken_check
    mov eax, effects_ticks
    shr eax, 1
    rainbow_color_from_eax r12d

upgrade_card_draw_taken_check:
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
    cmp match_mode, MATCH_MODE_UPGRADE_TAKEN
    je upgrade_card_draw_border_taken
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
upgrade_card_draw_border_taken:
    mov r15d, r12d
    test match_mode_ticks, UPGRADE_TAKEN_BLINK_BIT_MASK
    jz upgrade_card_draw_border
    mov r15d, COLOR_WHITE_BGRA

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

    mov eax, (UPGRADE_REEL PTR [rsi]).rarity
    lea rcx, upgrade_rarity_texts
    mov rcx, qword ptr [rcx + rax * 8]
    mov edx, TEXT_SCALE_SMALL
    call text_width_px
    lea edx, [r13 + UPGRADE_CARD_WIDTH_PX - UPGRADE_CARD_RARITY_RIGHT_INSET_PX]
    sub edx, eax
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

over_screen_draw PROC
    push rbx
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 1, FRAME_6_ARGS_ODD_PUSHES_BYTES
    mov ecx, COLOR_BLACK_BGRA
    mov edx, SCREEN_DARKEN_LEVEL
    call framebuffer_lerp_toward

    mov eax, match_point_loser_side
    xor eax, SIDE_FLIP
    mov edx, paddle_right_mode
    imul edx, edx, SIDE_COUNT
    add eax, edx
    lea rcx, over_title_texts
    mov rcx, qword ptr [rcx + rax * 8]
    mov edx, SCREEN_WIDTH_PX / 2
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
    mov edx, SCREEN_WIDTH_PX / 2
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
    mov edx, SCREEN_WIDTH_PX / 2
    mov r9d, COLOR_GOLD_BGRA
    mov dword ptr [rsp + CALL_ARG5], TEXT_SCALE_SMALL
    call text_draw_centered
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    ret
over_screen_stat_line_draw ENDP

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

framebuffer_lerp_toward PROC
    assert_below_unsigned edx, LERP_LEVEL_FULL + 1
    pxor xmm3, xmm3
    movd xmm5, ecx
    punpcklbw xmm5, xmm3
    punpcklqdq xmm5, xmm5
    movd xmm4, edx
    pshuflw xmm4, xmm4, 0
    punpcklqdq xmm4, xmm4
    lea rcx, framebuffer_bgra
    mov edx, SCREEN_PIXEL_COUNT / 4
framebuffer_lerp_toward_four_pixels:
    movdqa xmm0, xmmword ptr [rcx]
    movdqa xmm1, xmm0
    pxor xmm3, xmm3
    punpcklbw xmm0, xmm3
    punpckhbw xmm1, xmm3
    movdqa xmm2, xmm5
    psubw xmm2, xmm0
    pmullw xmm2, xmm4
    psraw xmm2, LERP_LEVEL_SHIFT
    paddw xmm0, xmm2
    movdqa xmm2, xmm5
    psubw xmm2, xmm1
    pmullw xmm2, xmm4
    psraw xmm2, LERP_LEVEL_SHIFT
    paddw xmm1, xmm2
    packuswb xmm0, xmm1
    movdqa xmmword ptr [rcx], xmm0
    add rcx, 16
    dec edx
    jnz framebuffer_lerp_toward_four_pixels
    ret
framebuffer_lerp_toward ENDP

framebuffer_chromatic_split PROC
    push rsi
    push rdi
    assert_above_zero_signed ecx
    assert_below_unsigned ecx, CHROMA_OFFSET_MAX_PX + 1
    movdqa xmm3, xmmword ptr pixel_red_mask_x4
    movdqa xmm4, xmmword ptr pixel_green_mask_x4
    movdqa xmm5, xmmword ptr pixel_blue_mask_x4
    shl ecx, 2
    lea r8, framebuffer_bgra
    mov r9d, SCREEN_HEIGHT_PX
framebuffer_chromatic_split_row:
    mov rsi, r8
    lea rdi, chroma_row_bgra
    add rdi, CHROMA_ROW_PADDING_PX * 4
    mov edx, SCREEN_WIDTH_PX / 4
framebuffer_chromatic_split_copy:
    movdqa xmm0, xmmword ptr [rsi]
    movdqu xmmword ptr [rdi], xmm0
    add rsi, 16
    add rdi, 16
    dec edx
    jnz framebuffer_chromatic_split_copy
    lea rsi, chroma_row_bgra
    add rsi, CHROMA_ROW_PADDING_PX * 4
    mov rdi, r8
    mov edx, SCREEN_WIDTH_PX / 4
framebuffer_chromatic_split_combine:
    movdqu xmm0, xmmword ptr [rsi + rcx]
    pand xmm0, xmm3
    movdqu xmm1, xmmword ptr [rsi]
    pand xmm1, xmm4
    por xmm0, xmm1
    mov rax, rsi
    sub rax, rcx
    movdqu xmm1, xmmword ptr [rax]
    pand xmm1, xmm5
    por xmm0, xmm1
    movdqa xmmword ptr [rdi], xmm0
    add rsi, 16
    add rdi, 16
    dec edx
    jnz framebuffer_chromatic_split_combine
    add r8, SCREEN_WIDTH_PX * 4
    dec r9d
    jnz framebuffer_chromatic_split_row
    pop rdi
    pop rsi
    ret
framebuffer_chromatic_split ENDP

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
    assert_bits_clear r10d, COLOR_ALPHA_MASK
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
    xor eax, eax
    mov ecx, screen_zoom_ticks_left
    test ecx, ecx
    jz frame_present_zoom_ready
    imul eax, ecx, ZOOM_MAX_PX
    xor edx, edx
    div screen_zoom_duration_ticks
frame_present_zoom_ready:
    mov dword ptr [rsp + CALL_ARG6], eax
    mov ecx, SCREEN_WIDTH_PX
    sub ecx, eax
    sub ecx, eax
    mov dword ptr [rsp + CALL_ARG8], ecx
    imul eax, eax, 3
    shr eax, 2
    mov dword ptr [rsp + CALL_ARG7], eax
    mov ecx, SCREEN_HEIGHT_PX
    sub ecx, eax
    sub ecx, eax
    mov dword ptr [rsp + CALL_ARG9], ecx
    mov rcx, window_dc
    xor edx, edx
    xor r8d, r8d
    mov r9d, WINDOW_CLIENT_WIDTH_PX
    mov dword ptr [rsp + CALL_ARG5], WINDOW_CLIENT_HEIGHT_PX
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
