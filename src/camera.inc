MESH_VERTEX_MAX                     equ 16
PRIMITIVE_KIND_BOX                  equ 0
PRIMITIVE_KIND_PYRAMID              equ 1
PRIMITIVE_KIND_PYRAMID_DOWN         equ 2
PRIMITIVE_KIND_DIAMOND              equ 3
PRIMITIVE_KIND_LINE                 equ 4
PRIMITIVE_KIND_RING                 equ 5
PRIMITIVE_KIND_COUNT                equ 6
MESH_DRAW_PUSHED_REGISTER_COUNT     equ 6
MESH_DRAW_ARG5                      equ FRAME_4_ARGS_EVEN_PUSHES_BYTES + 8 * MESH_DRAW_PUSHED_REGISTER_COUNT + CALLEE_ARG5
LINE_VIEW_DRAW_FRAME_BYTES          equ 80
LINE_VIEW_DRAW_LOCAL_X0             equ 40
LINE_VIEW_DRAW_LOCAL_Y0             equ 44
LINE_VIEW_DRAW_LOCAL_Z0             equ 48
LINE_VIEW_DRAW_LOCAL_X1             equ 52
LINE_VIEW_DRAW_LOCAL_Y1             equ 56
LINE_VIEW_DRAW_LOCAL_Z1             equ 60
LINE_VIEW_DRAW_LOCAL_SX0            equ 64
LINE_VIEW_DRAW_LOCAL_SY0            equ 68
GROUND_SHADOW_DRAW_FRAME_BYTES      equ 80
GROUND_SHADOW_DRAW_LOCAL_X          equ 48
GROUND_SHADOW_DRAW_LOCAL_Z          equ 52
GROUND_SHADOW_DRAW_LOCAL_RADIUS     equ 56
GROUND_SHADOW_DRAW_LOCAL_SX         equ 60
GROUND_SHADOW_DRAW_LOCAL_SY         equ 64
GROUND_SHADOW_DRAW_LOCAL_RX         equ 68
GROUND_SHADOW_DRAW_LOCAL_SY_FAR     equ 72
SHADOW_LEVEL                        equ 110

PRIMITIVE STRUCT
    unit_vertices                   QWORD ?
    edges                           QWORD ?
    vertex_count                    DWORD ?
    edge_count                      DWORD ?
PRIMITIVE ENDS

.const
camera_focal_px                     REAL4 200.0
camera_near_u                       REAL4 0.2
screen_center_x_px_float            REAL4 160.0
screen_center_y_px_float            REAL4 120.0
line_coordinate_limit_px            REAL4 4096.0
depth_fade_start_u                  REAL4 7.0
depth_fade_level_per_u              REAL4 5.0
depth_fade_level_min                REAL4 70.0
color_level_full_float              REAL4 256.0
float_sine_b                        REAL4 1.27323954
float_sine_c                        REAL4 -0.40528473
float_sine_p                        REAL4 0.225
camera_gameplay_eye_height_u        REAL4 4.4
camera_gameplay_eye_back_u          REAL4 7.4
camera_gameplay_eye_x_factor        REAL4 0.55
camera_gameplay_target_height_u     REAL4 0.7
camera_gameplay_target_ahead_u      REAL4 7.5
camera_gameplay_target_x_factor     REAL4 0.3
camera_ease_per_tick                REAL4 0.08
camera_select_eye                   VEC3 <0.0, 2.0, -6.8>
camera_select_target                VEC3 <0.0, 1.0, 0.0>
ui_particle_depth_u                 REAL4 4.0

primitive_box_unit_vertices         VEC3 <-1.0, -1.0, -1.0>, <1.0, -1.0, -1.0>, <-1.0, 1.0, -1.0>, <1.0, 1.0, -1.0>
                                    VEC3 <-1.0, -1.0, 1.0>, <1.0, -1.0, 1.0>, <-1.0, 1.0, 1.0>, <1.0, 1.0, 1.0>
primitive_box_edges                 BYTE 0, 1, 2, 3, 4, 5, 6, 7, 0, 2, 1, 3, 4, 6, 5, 7, 0, 4, 1, 5, 2, 6, 3, 7
primitive_pyramid_unit_vertices     VEC3 <-1.0, -1.0, -1.0>, <1.0, -1.0, -1.0>, <1.0, -1.0, 1.0>, <-1.0, -1.0, 1.0>, <0.0, 1.0, 0.0>
primitive_pyramid_down_unit_vertices VEC3 <-1.0, 1.0, -1.0>, <1.0, 1.0, -1.0>, <1.0, 1.0, 1.0>, <-1.0, 1.0, 1.0>, <0.0, -1.0, 0.0>
primitive_pyramid_edges             BYTE 0, 1, 1, 2, 2, 3, 3, 0, 0, 4, 1, 4, 2, 4, 3, 4
primitive_diamond_unit_vertices     VEC3 <1.0, 0.0, 0.0>, <-1.0, 0.0, 0.0>, <0.0, 1.0, 0.0>, <0.0, -1.0, 0.0>, <0.0, 0.0, 1.0>, <0.0, 0.0, -1.0>
primitive_diamond_edges             BYTE 0, 2, 0, 3, 0, 4, 0, 5, 1, 2, 1, 3, 1, 4, 1, 5, 2, 4, 2, 5, 3, 4, 3, 5
primitive_line_unit_vertices        VEC3 <-1.0, -1.0, -1.0>, <1.0, 1.0, 1.0>
primitive_line_edges                BYTE 0, 1
primitive_ring_unit_vertices        VEC3 <1.0, 0.0, 0.0>, <0.8660254, 0.0, 0.5>, <0.5, 0.0, 0.8660254>, <0.0, 0.0, 1.0>
                                    VEC3 <-0.5, 0.0, 0.8660254>, <-0.8660254, 0.0, 0.5>, <-1.0, 0.0, 0.0>, <-0.8660254, 0.0, -0.5>
                                    VEC3 <-0.5, 0.0, -0.8660254>, <0.0, 0.0, -1.0>, <0.5, 0.0, -0.8660254>, <0.8660254, 0.0, -0.5>
primitive_ring_edges                BYTE 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 0

ALIGN 8
primitives                          PRIMITIVE <primitive_box_unit_vertices, primitive_box_edges, 8, 12>
                                    PRIMITIVE <primitive_pyramid_unit_vertices, primitive_pyramid_edges, 5, 8>
                                    PRIMITIVE <primitive_pyramid_down_unit_vertices, primitive_pyramid_edges, 5, 8>
                                    PRIMITIVE <primitive_diamond_unit_vertices, primitive_diamond_edges, 6, 12>
                                    PRIMITIVE <primitive_line_unit_vertices, primitive_line_edges, 2, 1>
                                    PRIMITIVE <primitive_ring_unit_vertices, primitive_ring_edges, 12, 12>
primitives_end                      LABEL QWORD
.ERRNZ (primitives_end - primitives) - PRIMITIVE_KIND_COUNT * SIZEOF PRIMITIVE

.data?
camera_eye                          VEC3 <>
camera_target                       VEC3 <>
camera_right                        VEC3 <>
camera_up                           VEC3 <>
camera_forward                      VEC3 <>
mesh_scratch_vertices               VEC3 MESH_VERTEX_MAX DUP (<>)
mesh_view_vertices                  VEC3 MESH_VERTEX_MAX DUP (<>)
world_line_points                   VEC3 2 DUP (<>)

.code

math_sin PROC
    movaps xmm1, xmm0
    mulss xmm1, float_inverse_two_pi
    cvtss2si eax, xmm1
    cvtsi2ss xmm1, eax
    mulss xmm1, float_two_pi
    subss xmm0, xmm1
    movaps xmm1, xmm0
    andps xmm1, xmmword ptr float_abs_mask_x4
    mulss xmm1, xmm0
    mulss xmm1, float_sine_c
    movaps xmm2, xmm0
    mulss xmm2, float_sine_b
    addss xmm1, xmm2
    movaps xmm2, xmm1
    andps xmm2, xmmword ptr float_abs_mask_x4
    mulss xmm2, xmm1
    subss xmm2, xmm1
    mulss xmm2, float_sine_p
    addss xmm1, xmm2
    movaps xmm0, xmm1
    ret
math_sin ENDP

math_cos PROC
    addss xmm0, float_half_pi
    jmp math_sin
math_cos ENDP

camera_basis_compute PROC
    movss xmm0, camera_target.x
    subss xmm0, camera_eye.x
    movss xmm1, camera_target.y
    subss xmm1, camera_eye.y
    movss xmm2, camera_target.z
    subss xmm2, camera_eye.z
    movaps xmm3, xmm0
    mulss xmm3, xmm0
    movaps xmm4, xmm1
    mulss xmm4, xmm1
    addss xmm3, xmm4
    movaps xmm4, xmm2
    mulss xmm4, xmm2
    addss xmm3, xmm4
    sqrtss xmm3, xmm3
    movss xmm4, float_one
    divss xmm4, xmm3
    mulss xmm0, xmm4
    mulss xmm1, xmm4
    mulss xmm2, xmm4
    movss camera_forward.x, xmm0
    movss camera_forward.y, xmm1
    movss camera_forward.z, xmm2
    movaps xmm3, xmm2
    mulss xmm3, xmm2
    movaps xmm4, xmm0
    mulss xmm4, xmm0
    addss xmm3, xmm4
    sqrtss xmm3, xmm3
    movss xmm4, float_one
    divss xmm4, xmm3
    movaps xmm3, xmm2
    mulss xmm3, xmm4
    movss camera_right.x, xmm3
    xorps xmm5, xmm5
    movss camera_right.y, xmm5
    movaps xmm5, xmm0
    mulss xmm5, xmm4
    xorps xmm5, xmmword ptr float_sign_mask_x4
    movss camera_right.z, xmm5
    movaps xmm4, xmm1
    mulss xmm4, xmm5
    movss camera_up.x, xmm4
    movaps xmm4, xmm2
    mulss xmm4, xmm3
    mulss xmm0, xmm5
    subss xmm4, xmm0
    movss camera_up.y, xmm4
    mulss xmm1, xmm3
    xorps xmm1, xmmword ptr float_sign_mask_x4
    movss camera_up.z, xmm1
    ret
camera_basis_compute ENDP

camera_update_tick PROC
    movss xmm5, xmm0
    cmp match_mode, MATCH_MODE_CHARACTER_SELECT
    jne camera_update_tick_gameplay
    movss xmm0, camera_select_eye.x
    movss xmm1, camera_select_eye.y
    movss xmm2, camera_select_eye.z
    movss xmm3, camera_select_target.x
    movss xmm4, camera_select_target.z
    movss dword ptr [rsp + 8], xmm4
    movss xmm4, camera_select_target.y
    jmp camera_update_tick_ease
camera_update_tick_gameplay:
    lea rax, players[SIZEOF PLAYER * SIDE_NEAR]
    movss xmm0, (PLAYER PTR [rax]).pos_x_u
    mulss xmm0, camera_gameplay_eye_x_factor
    movss xmm1, camera_gameplay_eye_height_u
    movss xmm2, (PLAYER PTR [rax]).pos_z_u
    subss xmm2, camera_gameplay_eye_back_u
    movss xmm3, (PLAYER PTR [rax]).pos_x_u
    mulss xmm3, camera_gameplay_target_x_factor
    movss xmm4, (PLAYER PTR [rax]).pos_z_u
    addss xmm4, camera_gameplay_target_ahead_u
    movss dword ptr [rsp + 8], xmm4
    movss xmm4, camera_gameplay_target_height_u
camera_update_tick_ease:
    subss xmm0, camera_eye.x
    mulss xmm0, xmm5
    addss xmm0, camera_eye.x
    movss camera_eye.x, xmm0
    subss xmm1, camera_eye.y
    mulss xmm1, xmm5
    addss xmm1, camera_eye.y
    movss camera_eye.y, xmm1
    subss xmm2, camera_eye.z
    mulss xmm2, xmm5
    addss xmm2, camera_eye.z
    movss camera_eye.z, xmm2
    subss xmm3, camera_target.x
    mulss xmm3, xmm5
    addss xmm3, camera_target.x
    movss camera_target.x, xmm3
    subss xmm4, camera_target.y
    mulss xmm4, xmm5
    addss xmm4, camera_target.y
    movss camera_target.y, xmm4
    movss xmm4, dword ptr [rsp + 8]
    subss xmm4, camera_target.z
    mulss xmm4, xmm5
    addss xmm4, camera_target.z
    movss camera_target.z, xmm4
    ret
camera_update_tick ENDP

world_to_view PROC
    subss xmm0, camera_eye.x
    subss xmm1, camera_eye.y
    subss xmm2, camera_eye.z
    movaps xmm3, xmm0
    mulss xmm3, camera_right.x
    movaps xmm4, xmm1
    mulss xmm4, camera_right.y
    addss xmm3, xmm4
    movaps xmm4, xmm2
    mulss xmm4, camera_right.z
    addss xmm3, xmm4
    movaps xmm4, xmm0
    mulss xmm4, camera_up.x
    movaps xmm5, xmm1
    mulss xmm5, camera_up.y
    addss xmm4, xmm5
    movaps xmm5, xmm2
    mulss xmm5, camera_up.z
    addss xmm4, xmm5
    mulss xmm0, camera_forward.x
    mulss xmm1, camera_forward.y
    addss xmm0, xmm1
    mulss xmm2, camera_forward.z
    addss xmm0, xmm2
    movaps xmm2, xmm0
    movaps xmm0, xmm3
    movaps xmm1, xmm4
    ret
world_to_view ENDP

view_project PROC
    movss xmm3, camera_focal_px
    divss xmm3, xmm2
    mulss xmm0, xmm3
    addss xmm0, screen_center_x_px_float
    mulss xmm1, xmm3
    movss xmm4, screen_center_y_px_float
    subss xmm4, xmm1
    movaps xmm1, xmm4
    ret
view_project ENDP

screen_position_from_world PROC
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 0, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    call world_to_view
    comiss xmm2, camera_near_u
    jb screen_position_from_world_behind
    call view_project
    subss xmm0, screen_center_x_px_float
    subss xmm1, screen_center_y_px_float
    jmp screen_position_from_world_done
screen_position_from_world_behind:
    xorps xmm0, xmm0
    xorps xmm1, xmm1
screen_position_from_world_done:
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    ret
screen_position_from_world ENDP

world_point_from_screen PROC
    subss xmm0, screen_center_x_px_float
    movss xmm2, screen_center_y_px_float
    subss xmm2, xmm1
    movss xmm3, ui_particle_depth_u
    divss xmm3, camera_focal_px
    mulss xmm0, xmm3
    mulss xmm2, xmm3
    movss xmm3, ui_particle_depth_u
    movaps xmm4, xmm3
    mulss xmm4, camera_forward.x
    addss xmm4, camera_eye.x
    movaps xmm5, xmm0
    mulss xmm5, camera_right.x
    addss xmm4, xmm5
    movaps xmm5, xmm2
    mulss xmm5, camera_up.x
    addss xmm4, xmm5
    movaps xmm1, xmm3
    mulss xmm1, camera_forward.y
    addss xmm1, camera_eye.y
    movaps xmm5, xmm0
    mulss xmm5, camera_right.y
    addss xmm1, xmm5
    movaps xmm5, xmm2
    mulss xmm5, camera_up.y
    addss xmm1, xmm5
    mulss xmm3, camera_forward.z
    addss xmm3, camera_eye.z
    mulss xmm0, camera_right.z
    addss xmm3, xmm0
    mulss xmm2, camera_up.z
    addss xmm3, xmm2
    movaps xmm0, xmm4
    movaps xmm2, xmm3
    ret
world_point_from_screen ENDP

mesh_draw PROC
    push rbx
    push rsi
    push rdi
    push r12
    push r13
    push r14
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check MESH_DRAW_PUSHED_REGISTER_COUNT, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    assert_above_zero_signed edx
    assert_below_unsigned edx, MESH_VERTEX_MAX + 1
    mov r12d, dword ptr [rsp + MESH_DRAW_ARG5]
    mov rsi, r8
    mov r13d, r9d
    mov rbx, rcx
    mov r14d, edx
    lea rdi, mesh_view_vertices
mesh_draw_transform:
    movss xmm0, (VEC3 PTR [rbx]).x
    movss xmm1, (VEC3 PTR [rbx]).y
    movss xmm2, (VEC3 PTR [rbx]).z
    call world_to_view
    movss (VEC3 PTR [rdi]).x, xmm0
    movss (VEC3 PTR [rdi]).y, xmm1
    movss (VEC3 PTR [rdi]).z, xmm2
    add rbx, SIZEOF VEC3
    add rdi, SIZEOF VEC3
    dec r14d
    jnz mesh_draw_transform
mesh_draw_edge:
    test r13d, r13d
    jz mesh_draw_done
    movzx eax, byte ptr [rsi]
    movzx edx, byte ptr [rsi + 1]
    assert_below_unsigned eax, MESH_VERTEX_MAX
    assert_below_unsigned edx, MESH_VERTEX_MAX
    imul eax, eax, SIZEOF VEC3
    imul edx, edx, SIZEOF VEC3
    lea r8, mesh_view_vertices
    lea rcx, [r8 + rax]
    lea rdx, [r8 + rdx]
    mov r8d, r12d
    call line_view_draw
    add rsi, 2
    dec r13d
    jmp mesh_draw_edge
mesh_draw_done:
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    pop r14
    pop r13
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
mesh_draw ENDP

line_view_draw PROC
    push rbx
    sub rsp, LINE_VIEW_DRAW_FRAME_BYTES
    frame_alignment_check 1, LINE_VIEW_DRAW_FRAME_BYTES
    mov ebx, r8d
    movss xmm0, (VEC3 PTR [rcx]).x
    movss dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_X0], xmm0
    movss xmm0, (VEC3 PTR [rcx]).y
    movss dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_Y0], xmm0
    movss xmm0, (VEC3 PTR [rcx]).z
    movss dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_Z0], xmm0
    movss xmm1, (VEC3 PTR [rdx]).x
    movss dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_X1], xmm1
    movss xmm1, (VEC3 PTR [rdx]).y
    movss dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_Y1], xmm1
    movss xmm1, (VEC3 PTR [rdx]).z
    movss dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_Z1], xmm1
    movss xmm2, camera_near_u
    comiss xmm0, xmm2
    jae line_view_draw_start_in_front
    comiss xmm1, xmm2
    jb line_view_draw_done
    movaps xmm3, xmm2
    subss xmm3, xmm0
    subss xmm1, xmm0
    divss xmm3, xmm1
    movss xmm4, dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_X1]
    subss xmm4, dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_X0]
    mulss xmm4, xmm3
    addss xmm4, dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_X0]
    movss dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_X0], xmm4
    movss xmm4, dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_Y1]
    subss xmm4, dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_Y0]
    mulss xmm4, xmm3
    addss xmm4, dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_Y0]
    movss dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_Y0], xmm4
    movss dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_Z0], xmm2
    jmp line_view_draw_fade
line_view_draw_start_in_front:
    comiss xmm1, xmm2
    jae line_view_draw_fade
    movaps xmm3, xmm2
    subss xmm3, xmm1
    subss xmm0, xmm1
    divss xmm3, xmm0
    movss xmm4, dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_X0]
    subss xmm4, dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_X1]
    mulss xmm4, xmm3
    addss xmm4, dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_X1]
    movss dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_X1], xmm4
    movss xmm4, dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_Y0]
    subss xmm4, dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_Y1]
    mulss xmm4, xmm3
    addss xmm4, dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_Y1]
    movss dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_Y1], xmm4
    movss dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_Z1], xmm2

line_view_draw_fade:
    movss xmm0, dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_Z0]
    addss xmm0, dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_Z1]
    mulss xmm0, float_half
    subss xmm0, depth_fade_start_u
    maxss xmm0, float_zero
    mulss xmm0, depth_fade_level_per_u
    movss xmm1, color_level_full_float
    subss xmm1, xmm0
    maxss xmm1, depth_fade_level_min
    cvttss2si edx, xmm1
    mov ecx, ebx
    call color_scale
    mov dword ptr [rsp + CALL_ARG5], eax

    movss xmm0, dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_X0]
    movss xmm1, dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_Y0]
    movss xmm2, dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_Z0]
    call view_project
    float_clamp_symmetric xmm0, xmm3, line_coordinate_limit_px
    float_clamp_symmetric xmm1, xmm3, line_coordinate_limit_px
    cvtss2si eax, xmm0
    mov dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_SX0], eax
    cvtss2si eax, xmm1
    mov dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_SY0], eax
    movss xmm0, dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_X1]
    movss xmm1, dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_Y1]
    movss xmm2, dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_Z1]
    call view_project
    float_clamp_symmetric xmm0, xmm3, line_coordinate_limit_px
    float_clamp_symmetric xmm1, xmm3, line_coordinate_limit_px
    cvtss2si r8d, xmm0
    cvtss2si r9d, xmm1
    mov ecx, dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_SX0]
    mov edx, dword ptr [rsp + LINE_VIEW_DRAW_LOCAL_SY0]
    call framebuffer_line_draw
line_view_draw_done:
    add rsp, LINE_VIEW_DRAW_FRAME_BYTES
    pop rbx
    ret
line_view_draw ENDP

primitive_draw PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_6_ARGS_ODD_PUSHES_BYTES
    assert_below_unsigned ecx, PRIMITIVE_KIND_COUNT
    imul eax, ecx, SIZEOF PRIMITIVE
    lea rbx, primitives
    add rbx, rax
    mov rsi, (PRIMITIVE PTR [rbx]).unit_vertices
    mov ecx, (PRIMITIVE PTR [rbx]).vertex_count
    lea rdi, mesh_scratch_vertices
primitive_draw_vertex:
    movss xmm0, (VEC3 PTR [rsi]).x
    mulss xmm0, (VEC3 PTR [r8]).x
    addss xmm0, (VEC3 PTR [rdx]).x
    movss (VEC3 PTR [rdi]).x, xmm0
    movss xmm0, (VEC3 PTR [rsi]).y
    mulss xmm0, (VEC3 PTR [r8]).y
    addss xmm0, (VEC3 PTR [rdx]).y
    movss (VEC3 PTR [rdi]).y, xmm0
    movss xmm0, (VEC3 PTR [rsi]).z
    mulss xmm0, (VEC3 PTR [r8]).z
    addss xmm0, (VEC3 PTR [rdx]).z
    movss (VEC3 PTR [rdi]).z, xmm0
    add rsi, SIZEOF VEC3
    add rdi, SIZEOF VEC3
    dec ecx
    jnz primitive_draw_vertex
    mov dword ptr [rsp + CALL_ARG5], r9d
    lea rcx, mesh_scratch_vertices
    mov edx, (PRIMITIVE PTR [rbx]).vertex_count
    mov r8, (PRIMITIVE PTR [rbx]).edges
    mov r9d, (PRIMITIVE PTR [rbx]).edge_count
    call mesh_draw
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
primitive_draw ENDP

world_line_draw PROC
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 0, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    mov dword ptr [rsp + CALL_ARG5], edx
    lea r8, primitive_line_edges
    mov r9d, 1
    mov edx, 2
    call mesh_draw
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    ret
world_line_draw ENDP

ground_shadow_draw PROC
    push rbx
    sub rsp, GROUND_SHADOW_DRAW_FRAME_BYTES
    frame_alignment_check 1, GROUND_SHADOW_DRAW_FRAME_BYTES
    movss dword ptr [rsp + GROUND_SHADOW_DRAW_LOCAL_X], xmm0
    movss dword ptr [rsp + GROUND_SHADOW_DRAW_LOCAL_Z], xmm1
    movss dword ptr [rsp + GROUND_SHADOW_DRAW_LOCAL_RADIUS], xmm2
    movaps xmm2, xmm1
    xorps xmm1, xmm1
    call world_to_view
    comiss xmm2, camera_near_u
    jb ground_shadow_draw_done
    movss xmm3, camera_focal_px
    divss xmm3, xmm2
    mulss xmm3, dword ptr [rsp + GROUND_SHADOW_DRAW_LOCAL_RADIUS]
    movss dword ptr [rsp + GROUND_SHADOW_DRAW_LOCAL_RX], xmm3
    call view_project
    movss dword ptr [rsp + GROUND_SHADOW_DRAW_LOCAL_SX], xmm0
    movss dword ptr [rsp + GROUND_SHADOW_DRAW_LOCAL_SY], xmm1
    movss xmm0, dword ptr [rsp + GROUND_SHADOW_DRAW_LOCAL_X]
    xorps xmm1, xmm1
    movss xmm2, dword ptr [rsp + GROUND_SHADOW_DRAW_LOCAL_Z]
    addss xmm2, dword ptr [rsp + GROUND_SHADOW_DRAW_LOCAL_RADIUS]
    call world_to_view
    comiss xmm2, camera_near_u
    jb ground_shadow_draw_done
    call view_project
    movss dword ptr [rsp + GROUND_SHADOW_DRAW_LOCAL_SY_FAR], xmm1
    movss xmm0, dword ptr [rsp + GROUND_SHADOW_DRAW_LOCAL_X]
    xorps xmm1, xmm1
    movss xmm2, dword ptr [rsp + GROUND_SHADOW_DRAW_LOCAL_Z]
    subss xmm2, dword ptr [rsp + GROUND_SHADOW_DRAW_LOCAL_RADIUS]
    call world_to_view
    comiss xmm2, camera_near_u
    jb ground_shadow_draw_done
    call view_project
    subss xmm1, dword ptr [rsp + GROUND_SHADOW_DRAW_LOCAL_SY_FAR]
    andps xmm1, xmmword ptr float_abs_mask_x4
    mulss xmm1, float_half
    float_clamp_symmetric xmm1, xmm3, line_coordinate_limit_px
    cvtss2si r9d, xmm1
    movss xmm0, dword ptr [rsp + GROUND_SHADOW_DRAW_LOCAL_RX]
    float_clamp_symmetric xmm0, xmm3, line_coordinate_limit_px
    cvtss2si r8d, xmm0
    movss xmm0, dword ptr [rsp + GROUND_SHADOW_DRAW_LOCAL_SX]
    float_clamp_symmetric xmm0, xmm3, line_coordinate_limit_px
    cvtss2si ecx, xmm0
    movss xmm0, dword ptr [rsp + GROUND_SHADOW_DRAW_LOCAL_SY]
    float_clamp_symmetric xmm0, xmm3, line_coordinate_limit_px
    cvtss2si edx, xmm0
    mov dword ptr [rsp + CALL_ARG5], SHADOW_LEVEL
    call framebuffer_ellipse_shade
ground_shadow_draw_done:
    add rsp, GROUND_SHADOW_DRAW_FRAME_BYTES
    pop rbx
    ret
ground_shadow_draw ENDP
