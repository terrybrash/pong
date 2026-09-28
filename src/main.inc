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
EXTERN QueryPerformanceFrequency:PROC
EXTERN QueryPerformanceCounter:PROC
EXTERN DwmFlush:PROC
EXTERN Sleep:PROC
EXTERN ExitProcess:PROC

CS_OWNDC                            equ 00000020h
IDC_ARROW                           equ 32512
WS_CAPTION                          equ 00C00000h
WS_SYSMENU                          equ 00080000h
WS_MINIMIZEBOX                      equ 00020000h
WS_VISIBLE                          equ 10000000h
WINDOW_STYLE                        equ WS_CAPTION OR WS_SYSMENU OR WS_MINIMIZEBOX OR WS_VISIBLE
CW_USEDEFAULT                       equ 80000000h
PM_REMOVE                           equ 1
WM_DESTROY                          equ 0002h
WM_KILLFOCUS                        equ 0008h
WM_QUIT                             equ 0012h
WM_KEYDOWN                          equ 0100h
WM_KEYUP                            equ 0101h
WM_LBUTTONDOWN                      equ 0201h
WM_LBUTTONUP                        equ 0202h
KEYDOWN_LPARAM_WAS_DOWN_BIT         equ 30
DWM_FLUSH_FAILED_SLEEP_MS           equ 1
MAIN_ENTRY_FRAME_BYTES              equ CALL_ARG12 + 16

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

.data
window_class_name                   BYTE "pong", 0
window_title                        BYTE "Pong 3D    WASD: move    Click: dash    M: music    Esc: quit", 0
window_class                        WNDCLASSEXA <SIZEOF WNDCLASSEXA, CS_OWNDC>
window_outer_rect                   RECT <0, 0, WINDOW_CLIENT_WIDTH_PX, WINDOW_CLIENT_HEIGHT_PX>
window_message                      MSG <>

.data?
qpc_counts_per_sec                  QWORD ?
qpc_counts_per_tick                 QWORD ?
qpc_frame_last                      QWORD ?
qpc_frame_now                       QWORD ?
qpc_sim_behind_counts               QWORD ?
key_is_down_by_virtual_key          BYTE VIRTUAL_KEY_COUNT DUP (?)
key_was_pressed_by_virtual_key      BYTE VIRTUAL_KEY_COUNT DUP (?)

.code

main_entry PROC
    sub rsp, MAIN_ENTRY_FRAME_BYTES
    frame_alignment_check 0, MAIN_ENTRY_FRAME_BYTES

    rdtsc
    mov random_state, eax
    call audio_sounds_synthesize
    call audio_init
    movss xmm0, float_one
    call camera_update_tick

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
    cmp edx, WM_LBUTTONDOWN
    je window_proc_button_down
    cmp edx, WM_LBUTTONUP
    je window_proc_button_up
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

window_proc_button_down:
    lea rax, key_is_down_by_virtual_key
    mov byte ptr [rax + VK_LBUTTON], 1
    lea rax, key_was_pressed_by_virtual_key
    mov byte ptr [rax + VK_LBUTTON], 1
    jmp window_proc_handled

window_proc_button_up:
    lea rax, key_is_down_by_virtual_key
    mov byte ptr [rax + VK_LBUTTON], 0
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
