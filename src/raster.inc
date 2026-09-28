TEXTURE_SIZE_TEXELS                 equ 8
TEXTURE_SIZE_SHIFT                  equ 3
TEXTURE_TEXEL_MASK                  equ TEXTURE_SIZE_TEXELS - 1
TEXTURE_TEXEL_COUNT                 equ TEXTURE_SIZE_TEXELS * TEXTURE_SIZE_TEXELS
TEXTURE_PLAIN                       equ 0
TEXTURE_METAL                       equ 1
TEXTURE_CLOTH                       equ 2
TEXTURE_LEATHER                     equ 3
TEXTURE_SKIN                        equ 4
TEXTURE_WOOD                        equ 5
TEXTURE_ROBE                        equ 6
TEXTURE_GEM                         equ 7
TEXTURE_SAND                        equ 8
TEXTURE_GRASS                       equ 9
TEXTURE_COUNT                       equ 10
TEXEL_LUMINANCE_MAX                 equ 255
TEXTURE_NOISE_SHIFT                 equ 7
TEXTURE_NOISE_SMALL                 equ 5
TEXTURE_NOISE_MEDIUM                equ 12
DEPTH_MODE_TEST_AND_WRITE           equ 0
DEPTH_MODE_NONE                     equ 1
DEPTH_MODE_COUNT                    equ 2
FACE_LIGHT_LEVEL_MIN                equ 150
FACE_LIGHT_LEVEL_RANGE              equ COLOR_LEVEL_FULL - FACE_LIGHT_LEVEL_MIN
MESH_FACES_DRAW_PUSHED_REGISTER_COUNT equ 7
MESH_FACES_DRAW_FRAME_BYTES         equ FRAME_6_ARGS_ODD_PUSHES_BYTES
MESH_FACES_DRAW_ARG5                equ MESH_FACES_DRAW_FRAME_BYTES + 8 * MESH_FACES_DRAW_PUSHED_REGISTER_COUNT + CALLEE_ARG5
MESH_FACES_DRAW_ARG6                equ MESH_FACES_DRAW_ARG5 + 8
MESH_FACES_DRAW_LOCAL_EDGE_X        equ CALL_ARG5
MESH_OUTLINE_LEVEL                  equ 110
RASTER_DX_WEIGHTS_FROM_ROW_BYTES    equ 32
RASTER_DY_WEIGHTS_FROM_ROW_BYTES    equ 64
PRIMITIVE_SOLID_DRAW_PUSHED_REGISTER_COUNT equ 3
PRIMITIVE_SOLID_DRAW_ARG5           equ FRAME_6_ARGS_ODD_PUSHES_BYTES + 8 * PRIMITIVE_SOLID_DRAW_PUSHED_REGISTER_COUNT + CALLEE_ARG5
MESH_FACES_DRAW_LOCAL_EDGE_Y        equ CALL_ARG5 + 4

FACE STRUCT
    index_a                         BYTE ?
    index_b                         BYTE ?
    index_c                         BYTE ?
    texel_u_a                       BYTE ?
    texel_v_a                       BYTE ?
    texel_u_b                       BYTE ?
    texel_v_b                       BYTE ?
    texel_u_c                       BYTE ?
    texel_v_c                       BYTE ?
    face_padding_a                  BYTE ?
    face_padding_b                  BYTE ?
    face_padding_c                  BYTE ?
FACE ENDS
.ERRNZ SIZEOF FACE - 12

SCREEN_VERTEX STRUCT
    x_px                            REAL4 ?
    y_px                            REAL4 ?
    inverse_z                       REAL4 ?
    in_front                        DWORD ?
SCREEN_VERTEX ENDS

TRIANGLE_VERTEX STRUCT
    x_px                            REAL4 ?
    y_px                            REAL4 ?
    inverse_z                       REAL4 ?
    texel_u                         REAL4 ?
    texel_v                         REAL4 ?
    triangle_vertex_padding         REAL4 ?
TRIANGLE_VERTEX ENDS

face_quad MACRO a, b, c, d
    FACE <a, b, c, 0, TEXTURE_SIZE_TEXELS, TEXTURE_SIZE_TEXELS, TEXTURE_SIZE_TEXELS, TEXTURE_SIZE_TEXELS, 0, 0, 0, 0>
    FACE <a, c, d, 0, TEXTURE_SIZE_TEXELS, TEXTURE_SIZE_TEXELS, 0, 0, 0, 0, 0, 0>
ENDM

face_apex MACRO a, b, apex
    FACE <a, b, apex, 0, TEXTURE_SIZE_TEXELS, TEXTURE_SIZE_TEXELS, TEXTURE_SIZE_TEXELS, TEXTURE_SIZE_TEXELS / 2, 0, 0, 0, 0>
ENDM

.const
raster_area_min_px2                 REAL4 0.5
raster_pixel_center_offset          REAL4 0.5
depth_edge_bias                     REAL4 1.006
face_light_direction                VEC3 <-0.35, 0.85, -0.4>
face_light_level_range_float        REAL4 106.0
.ERRNZ FACE_LIGHT_LEVEL_RANGE - 106
face_normal_length_min              REAL4 1.0e-7
triangle_vertex_count_float         REAL4 3.0
primitive_box_faces                 LABEL FACE
    face_quad 0, 4, 6, 2
    face_quad 1, 5, 7, 3
    face_quad 0, 1, 3, 2
    face_quad 4, 5, 7, 6
    face_quad 0, 1, 5, 4
    face_quad 2, 3, 7, 6
primitive_box_faces_end             LABEL FACE
.ERRNZ (primitive_box_faces_end - primitive_box_faces) - PRIMITIVE_BOX_FACE_COUNT * SIZEOF FACE
primitive_pyramid_faces             LABEL FACE
    face_quad 0, 1, 2, 3
    face_apex 0, 1, 4
    face_apex 1, 2, 4
    face_apex 2, 3, 4
    face_apex 3, 0, 4
primitive_pyramid_faces_end         LABEL FACE
.ERRNZ (primitive_pyramid_faces_end - primitive_pyramid_faces) - PRIMITIVE_PYRAMID_FACE_COUNT * SIZEOF FACE
primitive_diamond_faces             LABEL FACE
    face_apex 0, 4, 2
    face_apex 4, 1, 2
    face_apex 1, 5, 2
    face_apex 5, 0, 2
    face_apex 0, 4, 3
    face_apex 4, 1, 3
    face_apex 1, 5, 3
    face_apex 5, 0, 3
primitive_diamond_faces_end         LABEL FACE
.ERRNZ (primitive_diamond_faces_end - primitive_diamond_faces) - PRIMITIVE_DIAMOND_FACE_COUNT * SIZEOF FACE

.data?
ALIGN 16
zbuffer_inverse_z                   REAL4 SCREEN_PIXEL_COUNT DUP (?)
raster_row_weights                  XMMWORD ?
raster_row_uv                       XMMWORD ?
raster_dx_weights                   XMMWORD ?
raster_dx_uv                        XMMWORD ?
raster_dy_weights                   XMMWORD ?
raster_dy_uv                        XMMWORD ?
raster_lit_color_words              XMMWORD ?
.ERRNZ (raster_dx_weights - raster_row_weights) - RASTER_DX_WEIGHTS_FROM_ROW_BYTES
.ERRNZ (raster_dy_weights - raster_row_weights) - RASTER_DY_WEIGHTS_FROM_ROW_BYTES
textures                            BYTE TEXTURE_COUNT * TEXTURE_TEXEL_COUNT DUP (?)
mesh_screen_vertices                SCREEN_VERTEX MESH_VERTEX_MAX DUP (<>)
raster_triangle                     TRIANGLE_VERTEX 3 DUP (<>)

.code

textures_generate PROC
    push rbx
    push rsi
    push rdi
    lea rdi, textures
    xor ebx, ebx
textures_generate_texture:
    xor esi, esi
textures_generate_texel:
    random_next_to_eax
    sar eax, 24
    mov r9d, eax
    mov edx, esi
    and edx, TEXTURE_TEXEL_MASK
    mov r8d, esi
    shr r8d, TEXTURE_SIZE_SHIFT
    cmp ebx, TEXTURE_METAL
    je textures_generate_metal
    cmp ebx, TEXTURE_CLOTH
    je textures_generate_cloth
    cmp ebx, TEXTURE_LEATHER
    je textures_generate_leather
    cmp ebx, TEXTURE_SKIN
    je textures_generate_skin
    cmp ebx, TEXTURE_WOOD
    je textures_generate_wood
    cmp ebx, TEXTURE_ROBE
    je textures_generate_robe
    cmp ebx, TEXTURE_GEM
    je textures_generate_gem
    cmp ebx, TEXTURE_SAND
    je textures_generate_sand
    cmp ebx, TEXTURE_GRASS
    je textures_generate_grass
    imul eax, r9d, TEXTURE_NOISE_SMALL
    sar eax, TEXTURE_NOISE_SHIFT
    add eax, 245
    jmp textures_generate_store
textures_generate_metal:
    imul eax, r9d, TEXTURE_NOISE_SMALL
    sar eax, TEXTURE_NOISE_SHIFT
    add eax, 215
    cmp r8d, 0
    jne textures_generate_metal_bottom
    mov eax, 252
textures_generate_metal_bottom:
    cmp r8d, TEXTURE_TEXEL_MASK
    jne textures_generate_metal_rivet
    mov eax, 170
textures_generate_metal_rivet:
    cmp edx, 1
    je textures_generate_metal_rivet_column
    cmp edx, TEXTURE_TEXEL_MASK - 1
    jne textures_generate_store
textures_generate_metal_rivet_column:
    cmp r8d, 1
    je textures_generate_metal_rivet_set
    cmp r8d, TEXTURE_TEXEL_MASK - 1
    jne textures_generate_store
textures_generate_metal_rivet_set:
    mov eax, TEXEL_LUMINANCE_MAX
    jmp textures_generate_store
textures_generate_cloth:
    imul eax, r9d, TEXTURE_NOISE_SMALL
    sar eax, TEXTURE_NOISE_SHIFT
    mov ecx, edx
    xor ecx, r8d
    and ecx, 1
    imul ecx, ecx, 30
    add eax, 205
    add eax, ecx
    jmp textures_generate_store
textures_generate_leather:
    imul eax, r9d, TEXTURE_NOISE_MEDIUM
    sar eax, TEXTURE_NOISE_SHIFT
    add eax, 195
    cmp r8d, 3
    jne textures_generate_store
    test edx, 1
    jnz textures_generate_store
    mov eax, 250
    jmp textures_generate_store
textures_generate_skin:
    imul eax, r9d, TEXTURE_NOISE_SMALL
    sar eax, TEXTURE_NOISE_SHIFT
    add eax, 240
    jmp textures_generate_store
textures_generate_wood:
    imul eax, r9d, TEXTURE_NOISE_SMALL
    sar eax, TEXTURE_NOISE_SHIFT
    mov ecx, r8d
    shr ecx, 2
    add ecx, edx
    and ecx, 1
    imul ecx, ecx, 45
    add eax, 195
    add eax, ecx
    jmp textures_generate_store
textures_generate_robe:
    imul eax, r9d, TEXTURE_NOISE_SMALL
    sar eax, TEXTURE_NOISE_SHIFT
    add eax, 205
    lea ecx, [rdx + r8]
    and ecx, 3
    jnz textures_generate_robe_star
    add eax, 50
textures_generate_robe_star:
    cmp edx, 5
    jne textures_generate_store
    cmp r8d, 2
    jne textures_generate_store
    mov eax, TEXEL_LUMINANCE_MAX
    jmp textures_generate_store
textures_generate_gem:
    lea eax, [rdx + rdx - TEXTURE_TEXEL_MASK]
    cdq
    xor eax, edx
    sub eax, edx
    mov ecx, eax
    lea eax, [r8 + r8 - TEXTURE_TEXEL_MASK]
    cdq
    xor eax, edx
    sub eax, edx
    add eax, ecx
    imul eax, eax, -9
    add eax, TEXEL_LUMINANCE_MAX
    jmp textures_generate_store
textures_generate_sand:
    imul eax, r9d, TEXTURE_NOISE_SMALL
    sar eax, TEXTURE_NOISE_SHIFT
    add eax, 240
    cmp eax, 237
    jge textures_generate_store
    mov eax, 222
    jmp textures_generate_store
textures_generate_grass:
    imul eax, r9d, TEXTURE_NOISE_MEDIUM
    sar eax, TEXTURE_NOISE_SHIFT
    add eax, 215
    lea ecx, [rdx + r8 * 2]
    and ecx, TEXTURE_TEXEL_MASK
    jnz textures_generate_store
    mov eax, 250
textures_generate_store:
    xor ecx, ecx
    test eax, eax
    cmovl eax, ecx
    mov ecx, TEXEL_LUMINANCE_MAX
    cmp eax, ecx
    cmovg eax, ecx
    mov byte ptr [rdi], al
    inc rdi
    inc esi
    cmp esi, TEXTURE_TEXEL_COUNT
    jb textures_generate_texel
    inc ebx
    cmp ebx, TEXTURE_COUNT
    jb textures_generate_texture
    pop rdi
    pop rsi
    pop rbx
    ret
textures_generate ENDP

zbuffer_clear PROC
    push rdi
    lea rdi, zbuffer_inverse_z
    mov ecx, SCREEN_PIXEL_COUNT
    xor eax, eax
    rep stosd
    pop rdi
    ret
zbuffer_clear ENDP

mesh_project PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_4_ARGS_ODD_PUSHES_BYTES
    assert_above_zero_signed edx
    assert_below_unsigned edx, MESH_VERTEX_MAX + 1
    mov rbx, rcx
    mov esi, edx
    lea rdi, mesh_screen_vertices
mesh_project_vertex:
    movss xmm0, (VEC3 PTR [rbx]).x
    movss xmm1, (VEC3 PTR [rbx]).y
    movss xmm2, (VEC3 PTR [rbx]).z
    call world_to_view
    mov (SCREEN_VERTEX PTR [rdi]).in_front, 0
    comiss xmm2, camera_near_u
    jb mesh_project_next
    mov (SCREEN_VERTEX PTR [rdi]).in_front, 1
    movss xmm3, float_one
    divss xmm3, xmm2
    movss (SCREEN_VERTEX PTR [rdi]).inverse_z, xmm3
    call view_project
    float_clamp_symmetric xmm0, xmm3, line_coordinate_limit_px
    float_clamp_symmetric xmm1, xmm3, line_coordinate_limit_px
    cvtss2si eax, xmm0
    add eax, screen_shake_offset_x_px
    cvtsi2ss xmm0, eax
    movss (SCREEN_VERTEX PTR [rdi]).x_px, xmm0
    cvtss2si eax, xmm1
    add eax, screen_shake_offset_y_px
    cvtsi2ss xmm1, eax
    movss (SCREEN_VERTEX PTR [rdi]).y_px, xmm1
mesh_project_next:
    add rbx, SIZEOF VEC3
    add rdi, SIZEOF SCREEN_VERTEX
    dec esi
    jnz mesh_project_vertex
    add rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
mesh_project ENDP

mesh_faces_draw PROC
    push rbx
    push rsi
    push rdi
    push r12
    push r13
    push r14
    push r15
    sub rsp, MESH_FACES_DRAW_FRAME_BYTES
    frame_alignment_check MESH_FACES_DRAW_PUSHED_REGISTER_COUNT, MESH_FACES_DRAW_FRAME_BYTES
    mov rbx, rcx
    mov rsi, rdx
    mov r12d, r8d
    mov r13d, r9d
    mov r14, qword ptr [rsp + MESH_FACES_DRAW_ARG5]
    mov r15d, dword ptr [rsp + MESH_FACES_DRAW_ARG6]
    assert_below_unsigned r15d, DEPTH_MODE_COUNT
mesh_faces_draw_face:
    test r12d, r12d
    jz mesh_faces_draw_done
    movzx eax, (FACE PTR [rsi]).index_a
    movzx ecx, (FACE PTR [rsi]).index_b
    movzx edx, (FACE PTR [rsi]).index_c
    assert_below_unsigned eax, MESH_VERTEX_MAX
    assert_below_unsigned ecx, MESH_VERTEX_MAX
    assert_below_unsigned edx, MESH_VERTEX_MAX
    shl eax, 4
    shl ecx, 4
    shl edx, 4
    .ERRNZ SIZEOF SCREEN_VERTEX - 16
    lea rdi, mesh_screen_vertices
    cmp (SCREEN_VERTEX PTR [rdi + rax]).in_front, 0
    je mesh_faces_draw_next
    cmp (SCREEN_VERTEX PTR [rdi + rcx]).in_front, 0
    je mesh_faces_draw_next
    cmp (SCREEN_VERTEX PTR [rdi + rdx]).in_front, 0
    je mesh_faces_draw_next
    lea r8, raster_triangle
    movss xmm0, (SCREEN_VERTEX PTR [rdi + rax]).x_px
    movss (TRIANGLE_VERTEX PTR [r8]).x_px, xmm0
    movss xmm0, (SCREEN_VERTEX PTR [rdi + rax]).y_px
    movss (TRIANGLE_VERTEX PTR [r8]).y_px, xmm0
    movss xmm0, (SCREEN_VERTEX PTR [rdi + rax]).inverse_z
    movss (TRIANGLE_VERTEX PTR [r8]).inverse_z, xmm0
    movss xmm0, (SCREEN_VERTEX PTR [rdi + rcx]).x_px
    movss (TRIANGLE_VERTEX PTR [r8 + SIZEOF TRIANGLE_VERTEX]).x_px, xmm0
    movss xmm0, (SCREEN_VERTEX PTR [rdi + rcx]).y_px
    movss (TRIANGLE_VERTEX PTR [r8 + SIZEOF TRIANGLE_VERTEX]).y_px, xmm0
    movss xmm0, (SCREEN_VERTEX PTR [rdi + rcx]).inverse_z
    movss (TRIANGLE_VERTEX PTR [r8 + SIZEOF TRIANGLE_VERTEX]).inverse_z, xmm0
    movss xmm0, (SCREEN_VERTEX PTR [rdi + rdx]).x_px
    movss (TRIANGLE_VERTEX PTR [r8 + 2 * SIZEOF TRIANGLE_VERTEX]).x_px, xmm0
    movss xmm0, (SCREEN_VERTEX PTR [rdi + rdx]).y_px
    movss (TRIANGLE_VERTEX PTR [r8 + 2 * SIZEOF TRIANGLE_VERTEX]).y_px, xmm0
    movss xmm0, (SCREEN_VERTEX PTR [rdi + rdx]).inverse_z
    movss (TRIANGLE_VERTEX PTR [r8 + 2 * SIZEOF TRIANGLE_VERTEX]).inverse_z, xmm0
    movzx r9d, (FACE PTR [rsi]).texel_u_a
    cvtsi2ss xmm0, r9d
    movss (TRIANGLE_VERTEX PTR [r8]).texel_u, xmm0
    movzx r9d, (FACE PTR [rsi]).texel_v_a
    cvtsi2ss xmm0, r9d
    movss (TRIANGLE_VERTEX PTR [r8]).texel_v, xmm0
    movzx r9d, (FACE PTR [rsi]).texel_u_b
    cvtsi2ss xmm0, r9d
    movss (TRIANGLE_VERTEX PTR [r8 + SIZEOF TRIANGLE_VERTEX]).texel_u, xmm0
    movzx r9d, (FACE PTR [rsi]).texel_v_b
    cvtsi2ss xmm0, r9d
    movss (TRIANGLE_VERTEX PTR [r8 + SIZEOF TRIANGLE_VERTEX]).texel_v, xmm0
    movzx r9d, (FACE PTR [rsi]).texel_u_c
    cvtsi2ss xmm0, r9d
    movss (TRIANGLE_VERTEX PTR [r8 + 2 * SIZEOF TRIANGLE_VERTEX]).texel_u, xmm0
    movzx r9d, (FACE PTR [rsi]).texel_v_c
    cvtsi2ss xmm0, r9d
    movss (TRIANGLE_VERTEX PTR [r8 + 2 * SIZEOF TRIANGLE_VERTEX]).texel_v, xmm0

    movzx eax, (FACE PTR [rsi]).index_a
    movzx ecx, (FACE PTR [rsi]).index_b
    movzx edx, (FACE PTR [rsi]).index_c
    imul eax, eax, SIZEOF VEC3
    imul ecx, ecx, SIZEOF VEC3
    imul edx, edx, SIZEOF VEC3
    movss xmm0, (VEC3 PTR [rbx + rcx]).x
    subss xmm0, (VEC3 PTR [rbx + rax]).x
    movss xmm1, (VEC3 PTR [rbx + rcx]).y
    subss xmm1, (VEC3 PTR [rbx + rax]).y
    movss xmm2, (VEC3 PTR [rbx + rcx]).z
    subss xmm2, (VEC3 PTR [rbx + rax]).z
    movss xmm3, (VEC3 PTR [rbx + rdx]).x
    subss xmm3, (VEC3 PTR [rbx + rax]).x
    movss xmm4, (VEC3 PTR [rbx + rdx]).y
    subss xmm4, (VEC3 PTR [rbx + rax]).y
    movss xmm5, (VEC3 PTR [rbx + rdx]).z
    subss xmm5, (VEC3 PTR [rbx + rax]).z
    movss dword ptr [rsp + MESH_FACES_DRAW_LOCAL_EDGE_X], xmm0
    movss dword ptr [rsp + MESH_FACES_DRAW_LOCAL_EDGE_Y], xmm1
    movaps xmm0, xmm1
    mulss xmm0, xmm5
    movaps xmm1, xmm2
    mulss xmm1, xmm4
    subss xmm0, xmm1
    mulss xmm2, xmm3
    movss xmm1, dword ptr [rsp + MESH_FACES_DRAW_LOCAL_EDGE_X]
    mulss xmm1, xmm5
    subss xmm2, xmm1
    movss xmm1, dword ptr [rsp + MESH_FACES_DRAW_LOCAL_EDGE_X]
    mulss xmm1, xmm4
    movss xmm5, dword ptr [rsp + MESH_FACES_DRAW_LOCAL_EDGE_Y]
    mulss xmm5, xmm3
    subss xmm1, xmm5
    movaps xmm3, xmm2
    movaps xmm2, xmm1
    movaps xmm1, xmm3
    movaps xmm3, xmm0
    mulss xmm3, xmm0
    movaps xmm4, xmm1
    mulss xmm4, xmm1
    addss xmm3, xmm4
    movaps xmm4, xmm2
    mulss xmm4, xmm2
    addss xmm3, xmm4
    sqrtss xmm3, xmm3
    comiss xmm3, face_normal_length_min
    jb mesh_faces_draw_next
    divss xmm0, xmm3
    divss xmm1, xmm3
    divss xmm2, xmm3
    movss xmm3, camera_eye.x
    subss xmm3, (VEC3 PTR [rbx + rax]).x
    mulss xmm3, xmm0
    movss xmm4, camera_eye.y
    subss xmm4, (VEC3 PTR [rbx + rax]).y
    mulss xmm4, xmm1
    addss xmm3, xmm4
    movss xmm4, camera_eye.z
    subss xmm4, (VEC3 PTR [rbx + rax]).z
    mulss xmm4, xmm2
    addss xmm3, xmm4
    comiss xmm3, float_zero
    jae mesh_faces_draw_normal_ready
    xorps xmm0, xmmword ptr float_sign_mask_x4
    xorps xmm1, xmmword ptr float_sign_mask_x4
    xorps xmm2, xmmword ptr float_sign_mask_x4
mesh_faces_draw_normal_ready:
    mulss xmm0, face_light_direction.x
    mulss xmm1, face_light_direction.y
    addss xmm0, xmm1
    mulss xmm2, face_light_direction.z
    addss xmm0, xmm2
    maxss xmm0, float_zero
    mulss xmm0, face_light_level_range_float
    cvttss2si edx, xmm0
    add edx, FACE_LIGHT_LEVEL_MIN
    mov ecx, r13d
    call color_scale
    mov ecx, eax
    lea rax, raster_triangle
    movss xmm0, (TRIANGLE_VERTEX PTR [rax]).inverse_z
    addss xmm0, (TRIANGLE_VERTEX PTR [rax + SIZEOF TRIANGLE_VERTEX]).inverse_z
    addss xmm0, (TRIANGLE_VERTEX PTR [rax + 2 * SIZEOF TRIANGLE_VERTEX]).inverse_z
    movss xmm1, triangle_vertex_count_float
    divss xmm1, xmm0
    call fog_color_apply
    lea rcx, raster_triangle
    mov rdx, r14
    mov r8d, eax
    mov r9d, r15d
    call triangle_draw
mesh_faces_draw_next:
    add rsi, SIZEOF FACE
    dec r12d
    jmp mesh_faces_draw_face
mesh_faces_draw_done:
    add rsp, MESH_FACES_DRAW_FRAME_BYTES
    pop r15
    pop r14
    pop r13
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
mesh_faces_draw ENDP

mesh_edges_depth_draw PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_4_ARGS_ODD_PUSHES_BYTES
    mov rbx, rcx
    mov esi, edx
    mov edi, r8d
mesh_edges_depth_draw_edge:
    test esi, esi
    jz mesh_edges_depth_draw_done
    movzx eax, byte ptr [rbx]
    movzx edx, byte ptr [rbx + 1]
    assert_below_unsigned eax, MESH_VERTEX_MAX
    assert_below_unsigned edx, MESH_VERTEX_MAX
    shl eax, 4
    shl edx, 4
    lea rcx, mesh_screen_vertices
    add rdx, rcx
    add rcx, rax
    cmp (SCREEN_VERTEX PTR [rcx]).in_front, 0
    je mesh_edges_depth_draw_next
    cmp (SCREEN_VERTEX PTR [rdx]).in_front, 0
    je mesh_edges_depth_draw_next
    mov r8d, edi
    call framebuffer_line_depth_draw
mesh_edges_depth_draw_next:
    add rbx, 2
    dec esi
    jmp mesh_edges_depth_draw_edge
mesh_edges_depth_draw_done:
    add rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
mesh_edges_depth_draw ENDP

framebuffer_line_depth_draw PROC
    push rbx
    push rsi
    push rdi
    push r12
    push r13
    push r14
    push r15
    mov r10d, r8d
    assert_bits_clear r10d, COLOR_ALPHA_MASK
    cvtss2si r14d, (SCREEN_VERTEX PTR [rcx]).x_px
    cvtss2si r15d, (SCREEN_VERTEX PTR [rcx]).y_px
    cvtss2si r8d, (SCREEN_VERTEX PTR [rdx]).x_px
    cvtss2si r9d, (SCREEN_VERTEX PTR [rdx]).y_px
    movss xmm0, (SCREEN_VERTEX PTR [rcx]).inverse_z
    movss xmm1, (SCREEN_VERTEX PTR [rdx]).inverse_z
    mov ecx, r14d
    mov edx, r15d
    mov r11d, r8d
    sub r11d, ecx
    mov esi, 1
    jns framebuffer_line_depth_draw_dx_ready
    neg r11d
    mov esi, -1
framebuffer_line_depth_draw_dx_ready:
    mov r12d, r9d
    sub r12d, edx
    mov edi, 1
    jns framebuffer_line_depth_draw_dy_ready
    neg r12d
    mov edi, -1
framebuffer_line_depth_draw_dy_ready:
    mov eax, r11d
    cmp eax, r12d
    cmovl eax, r12d
    test eax, eax
    jnz framebuffer_line_depth_draw_steps_ready
    mov eax, 1
framebuffer_line_depth_draw_steps_ready:
    cvtsi2ss xmm2, eax
    subss xmm1, xmm0
    divss xmm1, xmm2
    movss xmm2, depth_edge_bias
    neg r12d
    lea r13d, [r11 + r12]
    lea rbx, framebuffer_bgra
    lea r14, zbuffer_inverse_z
framebuffer_line_depth_draw_pixel:
    cmp ecx, SCREEN_WIDTH_PX
    jae framebuffer_line_depth_draw_step_check
    cmp edx, SCREEN_HEIGHT_PX
    jae framebuffer_line_depth_draw_step_check
    imul eax, edx, SCREEN_WIDTH_PX
    add eax, ecx
    movaps xmm3, xmm0
    mulss xmm3, xmm2
    comiss xmm3, dword ptr [r14 + rax * 4]
    jb framebuffer_line_depth_draw_step_check
    mov dword ptr [rbx + rax * 4], r10d
framebuffer_line_depth_draw_step_check:
    cmp ecx, r8d
    jne framebuffer_line_depth_draw_step
    cmp edx, r9d
    je framebuffer_line_depth_draw_done
framebuffer_line_depth_draw_step:
    addss xmm0, xmm1
    lea eax, [r13 + r13]
    cmp eax, r12d
    jl framebuffer_line_depth_draw_step_y
    add r13d, r12d
    add ecx, esi
framebuffer_line_depth_draw_step_y:
    cmp eax, r11d
    jg framebuffer_line_depth_draw_pixel
    add r13d, r11d
    add edx, edi
    jmp framebuffer_line_depth_draw_pixel
framebuffer_line_depth_draw_done:
    pop r15
    pop r14
    pop r13
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
framebuffer_line_depth_draw ENDP

triangle_draw PROC
    push rbx
    push rsi
    push rdi
    push r12
    push r13
    push r14
    push r15
    mov rsi, rcx
    mov rdi, rdx
    mov r15d, r9d
    assert_bits_clear r8d, COLOR_ALPHA_MASK
    movd xmm0, r8d
    pxor xmm1, xmm1
    punpcklbw xmm0, xmm1
    movdqa raster_lit_color_words, xmm0

    movss xmm0, (TRIANGLE_VERTEX PTR [rsi + SIZEOF TRIANGLE_VERTEX]).x_px
    subss xmm0, (TRIANGLE_VERTEX PTR [rsi]).x_px
    movss xmm1, (TRIANGLE_VERTEX PTR [rsi + 2 * SIZEOF TRIANGLE_VERTEX]).y_px
    subss xmm1, (TRIANGLE_VERTEX PTR [rsi]).y_px
    mulss xmm0, xmm1
    movss xmm1, (TRIANGLE_VERTEX PTR [rsi + 2 * SIZEOF TRIANGLE_VERTEX]).x_px
    subss xmm1, (TRIANGLE_VERTEX PTR [rsi]).x_px
    movss xmm2, (TRIANGLE_VERTEX PTR [rsi + SIZEOF TRIANGLE_VERTEX]).y_px
    subss xmm2, (TRIANGLE_VERTEX PTR [rsi]).y_px
    mulss xmm1, xmm2
    subss xmm0, xmm1
    movaps xmm1, xmm0
    andps xmm1, xmmword ptr float_abs_mask_x4
    comiss xmm1, raster_area_min_px2
    jb triangle_draw_done
    movss xmm5, float_one
    divss xmm5, xmm0

    movss xmm0, (TRIANGLE_VERTEX PTR [rsi]).x_px
    minss xmm0, (TRIANGLE_VERTEX PTR [rsi + SIZEOF TRIANGLE_VERTEX]).x_px
    minss xmm0, (TRIANGLE_VERTEX PTR [rsi + 2 * SIZEOF TRIANGLE_VERTEX]).x_px
    cvttss2si r8d, xmm0
    xor eax, eax
    test r8d, r8d
    cmovl r8d, eax
    movss xmm0, (TRIANGLE_VERTEX PTR [rsi]).x_px
    maxss xmm0, (TRIANGLE_VERTEX PTR [rsi + SIZEOF TRIANGLE_VERTEX]).x_px
    maxss xmm0, (TRIANGLE_VERTEX PTR [rsi + 2 * SIZEOF TRIANGLE_VERTEX]).x_px
    cvttss2si r9d, xmm0
    mov eax, SCREEN_WIDTH_PX - 1
    cmp r9d, eax
    cmovg r9d, eax
    movss xmm0, (TRIANGLE_VERTEX PTR [rsi]).y_px
    minss xmm0, (TRIANGLE_VERTEX PTR [rsi + SIZEOF TRIANGLE_VERTEX]).y_px
    minss xmm0, (TRIANGLE_VERTEX PTR [rsi + 2 * SIZEOF TRIANGLE_VERTEX]).y_px
    cvttss2si r10d, xmm0
    xor eax, eax
    test r10d, r10d
    cmovl r10d, eax
    movss xmm0, (TRIANGLE_VERTEX PTR [rsi]).y_px
    maxss xmm0, (TRIANGLE_VERTEX PTR [rsi + SIZEOF TRIANGLE_VERTEX]).y_px
    maxss xmm0, (TRIANGLE_VERTEX PTR [rsi + 2 * SIZEOF TRIANGLE_VERTEX]).y_px
    cvttss2si r11d, xmm0
    mov eax, SCREEN_HEIGHT_PX - 1
    cmp r11d, eax
    cmovg r11d, eax
    cmp r8d, r9d
    jg triangle_draw_done
    cmp r10d, r11d
    jg triangle_draw_done

    movss xmm0, (TRIANGLE_VERTEX PTR [rsi + SIZEOF TRIANGLE_VERTEX]).y_px
    subss xmm0, (TRIANGLE_VERTEX PTR [rsi + 2 * SIZEOF TRIANGLE_VERTEX]).y_px
    mulss xmm0, xmm5
    movss dword ptr raster_dx_weights, xmm0
    movss xmm0, (TRIANGLE_VERTEX PTR [rsi + 2 * SIZEOF TRIANGLE_VERTEX]).x_px
    subss xmm0, (TRIANGLE_VERTEX PTR [rsi + SIZEOF TRIANGLE_VERTEX]).x_px
    mulss xmm0, xmm5
    movss dword ptr raster_dy_weights, xmm0
    movss xmm0, (TRIANGLE_VERTEX PTR [rsi + 2 * SIZEOF TRIANGLE_VERTEX]).y_px
    subss xmm0, (TRIANGLE_VERTEX PTR [rsi]).y_px
    mulss xmm0, xmm5
    movss dword ptr raster_dx_weights + 4, xmm0
    movss xmm0, (TRIANGLE_VERTEX PTR [rsi]).x_px
    subss xmm0, (TRIANGLE_VERTEX PTR [rsi + 2 * SIZEOF TRIANGLE_VERTEX]).x_px
    mulss xmm0, xmm5
    movss dword ptr raster_dy_weights + 4, xmm0

    cvtsi2ss xmm3, r8d
    addss xmm3, raster_pixel_center_offset
    cvtsi2ss xmm4, r10d
    addss xmm4, raster_pixel_center_offset
    movss xmm0, (TRIANGLE_VERTEX PTR [rsi + SIZEOF TRIANGLE_VERTEX]).x_px
    subss xmm0, xmm3
    movss xmm1, (TRIANGLE_VERTEX PTR [rsi + 2 * SIZEOF TRIANGLE_VERTEX]).y_px
    subss xmm1, xmm4
    mulss xmm0, xmm1
    movss xmm1, (TRIANGLE_VERTEX PTR [rsi + 2 * SIZEOF TRIANGLE_VERTEX]).x_px
    subss xmm1, xmm3
    movss xmm2, (TRIANGLE_VERTEX PTR [rsi + SIZEOF TRIANGLE_VERTEX]).y_px
    subss xmm2, xmm4
    mulss xmm1, xmm2
    subss xmm0, xmm1
    mulss xmm0, xmm5
    movss dword ptr raster_row_weights, xmm0
    movss xmm0, (TRIANGLE_VERTEX PTR [rsi + 2 * SIZEOF TRIANGLE_VERTEX]).x_px
    subss xmm0, xmm3
    movss xmm1, (TRIANGLE_VERTEX PTR [rsi]).y_px
    subss xmm1, xmm4
    mulss xmm0, xmm1
    movss xmm1, (TRIANGLE_VERTEX PTR [rsi]).x_px
    subss xmm1, xmm3
    movss xmm2, (TRIANGLE_VERTEX PTR [rsi + 2 * SIZEOF TRIANGLE_VERTEX]).y_px
    subss xmm2, xmm4
    mulss xmm1, xmm2
    subss xmm0, xmm1
    mulss xmm0, xmm5
    movss dword ptr raster_row_weights + 4, xmm0

    movss xmm0, float_one
    subss xmm0, dword ptr raster_row_weights
    subss xmm0, dword ptr raster_row_weights + 4
    movss dword ptr raster_row_weights + 8, xmm0
    movss xmm0, dword ptr raster_dx_weights
    addss xmm0, dword ptr raster_dx_weights + 4
    xorps xmm0, xmmword ptr float_sign_mask_x4
    movss dword ptr raster_dx_weights + 8, xmm0
    movss xmm0, dword ptr raster_dy_weights
    addss xmm0, dword ptr raster_dy_weights + 4
    xorps xmm0, xmmword ptr float_sign_mask_x4
    movss dword ptr raster_dy_weights + 8, xmm0

    lea rcx, raster_row_weights
    lea rdx, [rsi + TRIANGLE_VERTEX.inverse_z]
    call triangle_attribute_plane
    movss dword ptr raster_row_weights + 12, xmm0
    movss dword ptr raster_dx_weights + 12, xmm1
    movss dword ptr raster_dy_weights + 12, xmm2
    lea rdx, [rsi + TRIANGLE_VERTEX.texel_u]
    call triangle_attribute_plane
    movss dword ptr raster_row_uv, xmm0
    movss dword ptr raster_dx_uv, xmm1
    movss dword ptr raster_dy_uv, xmm2
    lea rdx, [rsi + TRIANGLE_VERTEX.texel_v]
    call triangle_attribute_plane
    movss dword ptr raster_row_uv + 4, xmm0
    movss dword ptr raster_dx_uv + 4, xmm1
    movss dword ptr raster_dy_uv + 4, xmm2

    movaps xmm2, raster_dx_weights
    movaps xmm3, raster_dx_uv
    lea rbx, framebuffer_bgra
    lea r14, zbuffer_inverse_z
    mov r12d, r10d
triangle_draw_row:
    cmp r12d, r11d
    jg triangle_draw_done
    movaps xmm0, raster_row_weights
    movaps xmm1, raster_row_uv
    imul r13d, r12d, SCREEN_WIDTH_PX
    mov ecx, r8d
triangle_draw_pixel:
    cmp ecx, r9d
    jg triangle_draw_row_next
    xorps xmm5, xmm5
    movaps xmm4, xmm0
    cmpltps xmm4, xmm5
    movmskps eax, xmm4
    test eax, 7
    jnz triangle_draw_pixel_next
    lea edx, [r13 + rcx]
    cmp r15d, DEPTH_MODE_NONE
    je triangle_draw_pixel_color
    pshufd xmm4, xmm0, 0FFh
    comiss xmm4, dword ptr [r14 + rdx * 4]
    jbe triangle_draw_pixel_next
    movss dword ptr [r14 + rdx * 4], xmm4
triangle_draw_pixel_color:
    cvttps2dq xmm4, xmm1
    movd eax, xmm4
    psrldq xmm4, 4
    movd r10d, xmm4
    and eax, TEXTURE_TEXEL_MASK
    and r10d, TEXTURE_TEXEL_MASK
    shl r10d, TEXTURE_SIZE_SHIFT
    add eax, r10d
    movzx eax, byte ptr [rdi + rax]
    movd xmm4, eax
    pshuflw xmm4, xmm4, 0
    pmullw xmm4, raster_lit_color_words
    psrlw xmm4, COLOR_LEVEL_SHIFT
    packuswb xmm4, xmm4
    movd dword ptr [rbx + rdx * 4], xmm4
triangle_draw_pixel_next:
    addps xmm0, xmm2
    addps xmm1, xmm3
    inc ecx
    jmp triangle_draw_pixel
triangle_draw_row_next:
    movaps xmm0, raster_row_weights
    addps xmm0, raster_dy_weights
    movaps raster_row_weights, xmm0
    movaps xmm1, raster_row_uv
    addps xmm1, raster_dy_uv
    movaps raster_row_uv, xmm1
    inc r12d
    jmp triangle_draw_row
triangle_draw_done:
    pop r15
    pop r14
    pop r13
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
triangle_draw ENDP

triangle_attribute_plane PROC
    movss xmm3, dword ptr [rdx]
    movss xmm4, dword ptr [rdx + SIZEOF TRIANGLE_VERTEX]
    movss xmm5, dword ptr [rdx + 2 * SIZEOF TRIANGLE_VERTEX]
    movss xmm0, dword ptr [rcx]
    mulss xmm0, xmm3
    movss xmm1, dword ptr [rcx + 4]
    mulss xmm1, xmm4
    addss xmm0, xmm1
    movss xmm1, dword ptr [rcx + 8]
    mulss xmm1, xmm5
    addss xmm0, xmm1
    movss xmm1, dword ptr [rcx + RASTER_DX_WEIGHTS_FROM_ROW_BYTES]
    mulss xmm1, xmm3
    movss xmm2, dword ptr [rcx + RASTER_DX_WEIGHTS_FROM_ROW_BYTES + 4]
    mulss xmm2, xmm4
    addss xmm1, xmm2
    movss xmm2, dword ptr [rcx + RASTER_DX_WEIGHTS_FROM_ROW_BYTES + 8]
    mulss xmm2, xmm5
    addss xmm1, xmm2
    movss xmm2, dword ptr [rcx + RASTER_DY_WEIGHTS_FROM_ROW_BYTES]
    mulss xmm2, xmm3
    mulss xmm4, dword ptr [rcx + RASTER_DY_WEIGHTS_FROM_ROW_BYTES + 4]
    addss xmm2, xmm4
    mulss xmm5, dword ptr [rcx + RASTER_DY_WEIGHTS_FROM_ROW_BYTES + 8]
    addss xmm2, xmm5
    ret
triangle_attribute_plane ENDP

primitive_solid_draw PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check PRIMITIVE_SOLID_DRAW_PUSHED_REGISTER_COUNT, FRAME_6_ARGS_ODD_PUSHES_BYTES
    mov edi, r9d
    mov esi, dword ptr [rsp + PRIMITIVE_SOLID_DRAW_ARG5]
    assert_below_unsigned esi, TEXTURE_COUNT
    call primitive_vertices_build
    mov rbx, rax
    assert_above_zero_signed (PRIMITIVE PTR [rbx]).face_count
    lea rcx, mesh_scratch_vertices
    mov edx, (PRIMITIVE PTR [rbx]).vertex_count
    call mesh_project
    imul eax, esi, TEXTURE_TEXEL_COUNT
    lea rcx, textures
    add rax, rcx
    mov qword ptr [rsp + CALL_ARG5], rax
    mov dword ptr [rsp + CALL_ARG6], DEPTH_MODE_TEST_AND_WRITE
    lea rcx, mesh_scratch_vertices
    mov rdx, (PRIMITIVE PTR [rbx]).faces
    mov r8d, (PRIMITIVE PTR [rbx]).face_count
    mov r9d, edi
    call mesh_faces_draw
    mov ecx, edi
    mov edx, MESH_OUTLINE_LEVEL
    call color_scale
    mov r8d, eax
    mov rcx, (PRIMITIVE PTR [rbx]).edges
    mov edx, (PRIMITIVE PTR [rbx]).edge_count
    call mesh_edges_depth_draw
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
primitive_solid_draw ENDP
