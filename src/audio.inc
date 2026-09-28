EXTERN waveOutOpen:PROC
EXTERN waveOutPrepareHeader:PROC
EXTERN waveOutWrite:PROC

WAVE_MAPPER                         equ 0FFFFFFFFh
WAVE_FORMAT_PCM                     equ 1
CALLBACK_NULL                       equ 0
MMSYSERR_NOERROR                    equ 0
WHDR_DONE_BIT                       equ 0
WHDR_DONE                           equ 1 SHL WHDR_DONE_BIT

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
AUDIO_SEMITONE_STEP_COUNT           equ AUDIO_SEMITONE_MAX - AUDIO_SEMITONE_MIN + 1
AUDIO_POSITION_FRACTION_BITS        equ 16
AUDIO_SAMPLE_COUNT_MAX              equ 1 SHL AUDIO_POSITION_FRACTION_BITS
AUDIO_PITCH_JITTER_MASK             equ 2047
AUDIO_PITCH_JITTER_CENTER           equ 1024
AUDIO_PITCH_JITTER_SHIFT            equ 15
AUDIO_ARPEGGIO_NOTE_DELAY_SAMPLES   equ AUDIO_SAMPLE_RATE_HZ * 55 / 1000

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
SOUND_SYNTHESIZE_PUSHED_REGISTER_COUNT equ 5
SOUND_SYNTHESIZE_ARG5               equ 8 * SOUND_SYNTHESIZE_PUSHED_REGISTER_COUNT + CALLEE_ARG5

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
MUSIC_LEAD_MULTIPLIER_MIN           equ 2
MUSIC_BUSY_MULTIPLIER_MIN           equ 5
MUSIC_ARP_TONES_PER_BAR             equ 4

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

music_note_call MACRO channel, instrument, semitone, delay_reg32
    mov r8d, semitone
    mov r9d, delay_reg32
    mov ecx, channel
    mov edx, instrument
    call music_note_play
ENDM

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

.data?
sound_define sound_hit, SOUND_WAVEFORM_SQUARE_SWEEP, 60, 440, 660
sound_define sound_blip, SOUND_WAVEFORM_SQUARE_SWEEP, 35, 880, 880
sound_define sound_tick, SOUND_WAVEFORM_TRIANGLE_SWEEP, 22, 1300, 1000
sound_define sound_clack, SOUND_WAVEFORM_NOISE, 45, 0, 0
sound_define sound_boom, SOUND_WAVEFORM_NOISE, 380, 0, 0
sound_define sound_zap, SOUND_WAVEFORM_SQUARE_SWEEP, 240, 1500, 180
sound_define sound_point, SOUND_WAVEFORM_SQUARE_SWEEP, 520, 900, 110
sound_define sound_coin, SOUND_WAVEFORM_SQUARE_TWO_TONE, 120, 988, 1319
sound_define sound_rise, SOUND_WAVEFORM_SQUARE_SWEEP, 400, 220, 1320
sound_define sound_shield, SOUND_WAVEFORM_TRIANGLE_SWEEP, 220, 150, 900
sound_define sound_dash, SOUND_WAVEFORM_SQUARE_SWEEP, 140, 260, 1000
sound_define music_kick, SOUND_WAVEFORM_TRIANGLE_SWEEP, 170, 170, 40
sound_define music_snare, SOUND_WAVEFORM_NOISE, 140, 0, 0
sound_define music_hat, SOUND_WAVEFORM_NOISE, 28, 0, 0
sound_define music_open_hat, SOUND_WAVEFORM_NOISE, 110, 0, 0
sound_define music_bass, SOUND_WAVEFORM_SQUARE_SWEEP, 170, 110, 110
sound_define music_arp, SOUND_WAVEFORM_SQUARE_SWEEP, 70, 220, 220
sound_define music_lead, SOUND_WAVEFORM_SQUARE_SWEEP, 190, 440, 440

ALIGN 16
audio_mix_accumulator               DWORD AUDIO_BUFFER_SAMPLES DUP (?)
audio_buffers                       WORD AUDIO_BUFFER_SAMPLES * AUDIO_BUFFER_COUNT DUP (?)
audio_headers                       WAVEHDR AUDIO_BUFFER_COUNT DUP (<>)
audio_voices                        VOICE AUDIO_VOICE_COUNT DUP (<>)
audio_device                        QWORD ?
audio_sfx_voice_next                DWORD ?
music_step                          DWORD ?
music_samples_until_step            DWORD ?
music_intensity                     DWORD ?
music_tempo_bonus                   DWORD ?
music_muted                         DWORD ?

.data
audio_format                        WAVEFORMATEX <WAVE_FORMAT_PCM, 1, AUDIO_SAMPLE_RATE_HZ, AUDIO_SAMPLE_RATE_HZ * AUDIO_BYTES_PER_SAMPLE, AUDIO_BYTES_PER_SAMPLE, AUDIO_BITS_PER_SAMPLE, 0>

.const
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

.code

audio_sounds_synthesize PROC
    sub rsp, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 0, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    sound_synthesize_call sound_hit
    sound_synthesize_call sound_blip
    sound_synthesize_call sound_tick
    sound_synthesize_call sound_clack
    sound_synthesize_call sound_boom
    sound_synthesize_call sound_zap
    sound_synthesize_call sound_point
    sound_synthesize_call sound_coin
    sound_synthesize_call sound_rise
    sound_synthesize_call sound_shield
    sound_synthesize_call sound_dash
    sound_synthesize_call music_kick
    sound_synthesize_call music_snare
    sound_synthesize_call music_hat
    sound_synthesize_call music_open_hat
    sound_synthesize_call music_bass
    sound_synthesize_call music_arp
    sound_synthesize_call music_lead
    add rsp, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    ret
audio_sounds_synthesize ENDP

audio_init PROC
    push rbx
    push rsi
    sub rsp, FRAME_7_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 2, FRAME_7_ARGS_EVEN_PUSHES_BYTES
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
    add rsp, FRAME_7_ARGS_EVEN_PUSHES_BYTES
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

music_state_update PROC
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 0, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    mov eax, match_mode
    cmp eax, MATCH_MODE_RALLY
    je music_state_update_rally
    mov ecx, MUSIC_INTENSITY_DRUMS_AND_BASS
    cmp eax, MATCH_MODE_SERVE_WAIT
    je music_state_update_calm
    mov ecx, MUSIC_INTENSITY_ARP
    cmp eax, MATCH_MODE_CHARACTER_SELECT
    je music_state_update_calm
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
music_state_update_calm:
    mov music_tempo_bonus, 0
    jmp music_state_update_set
music_state_update_rally:
    call rally_multiplier_get
    mov edx, eax
    dec eax
    mov music_tempo_bonus, eax
    mov ecx, MUSIC_INTENSITY_ARP
    cmp edx, MUSIC_LEAD_MULTIPLIER_MIN
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
