COLOR_SKY_BGRA                      equ 00302058h
COLOR_GROUND_BGRA                   equ 00205828h
COLOR_HORIZON_BGRA                  equ 006048A0h
COLOR_STAR_BGRA                     equ 00A0B0E0h
COLOR_COURT_LINE_BGRA               equ 00D8D8E0h
COLOR_NET_BGRA                      equ 00E0E0E8h
COLOR_NET_MESH_BGRA                 equ 00787890h
COLOR_GRASS_BGRA                    equ 0058C058h
COLOR_GRASS_DARK_BGRA               equ 00409040h
COLOR_ROCK_BGRA                     equ 00888890h
SKY_LEVEL_TOP                       equ 60
SKY_LEVEL_TINT_BASE                 equ 30
SKY_LEVEL_TINT_PER_MULTIPLIER       equ 12
SKY_HUE_SHIFT                       equ 4
GROUND_LEVEL_FAR                    equ 90
HORIZON_GLOW_ROWS                   equ 2
STAR_COUNT                          equ 48
STAR_LEVEL_BASE                     equ 120
STAR_LEVEL_PER_TRIANGLE_STEP        equ 8
STAR_TWINKLE_PHASE_PER_STAR         equ 7
SCATTER_COUNT                       equ 180
SCATTER_ROCK_CHANCE_MASK            equ 7
SCATTER_ROCK_CHANCE_BELOW           equ 2
SCATTER_DARK_GRASS_HASH_BIT         equ 100h
COURT_LINE_SEGMENT_COUNT            equ 7
NET_LINE_SEGMENT_COUNT              equ 7
NET_MESH_VERTICAL_COUNT             equ 23
TUFT_VERTEX_COUNT                   equ 4
TUFT_EDGE_COUNT                     equ 3

.const
court_half_width_u                  REAL4 6.0
court_half_length_u                 REAL4 9.0
court_edge_margin_u                 REAL4 0.4
net_top_u                           REAL4 1.6
net_band_u                          REAL4 1.42
net_bottom_u                        REAL4 0.7
net_half_width_u                    REAL4 6.6
net_mesh_spacing_u                  REAL4 0.6
horizon_distance_u                  REAL4 1000.0
star_parallax_px_per_u              REAL4 -8.0
scatter_half_x_u                    REAL4 20.0
scatter_half_z_u                    REAL4 24.0
scatter_hash_to_unit                REAL4 0.0000305176
scatter_size_min                    REAL4 0.7
scatter_size_range_per_step         REAL4 0.003125
rock_half_x_u                       REAL4 0.24
rock_half_y_u                       REAL4 0.16
rock_half_z_u                       REAL4 0.2
tuft_tip_offsets_u                  VEC3 <-0.09, 0.3, 0.02>, <0.02, 0.38, -0.03>, <0.1, 0.27, 0.03>
tuft_edges                          BYTE 0, 1, 0, 2, 0, 3
court_line_points                   VEC3 <-6.0, 0.01, -9.0>, <6.0, 0.01, -9.0>, <-6.0, 0.01, 9.0>, <6.0, 0.01, 9.0>
                                    VEC3 <-6.0, 0.01, -9.0>, <-6.0, 0.01, 9.0>, <6.0, 0.01, -9.0>, <6.0, 0.01, 9.0>
                                    VEC3 <-6.0, 0.01, 0.0>, <6.0, 0.01, 0.0>, <-6.0, 0.01, -3.0>, <6.0, 0.01, -3.0>
                                    VEC3 <-6.0, 0.01, 3.0>, <6.0, 0.01, 3.0>
court_line_points_end               LABEL DWORD
.ERRNZ (court_line_points_end - court_line_points) - 2 * COURT_LINE_SEGMENT_COUNT * SIZEOF VEC3
net_line_points                     VEC3 <-6.6, 0.0, 0.0>, <-6.6, 1.6, 0.0>, <6.6, 0.0, 0.0>, <6.6, 1.6, 0.0>
                                    VEC3 <-6.6, 1.6, 0.0>, <6.6, 1.6, 0.0>, <-6.6, 1.42, 0.0>, <6.6, 1.42, 0.0>
                                    VEC3 <-6.6, 0.7, 0.0>, <6.6, 0.7, 0.0>, <-6.6, 0.95, 0.0>, <6.6, 0.95, 0.0>
                                    VEC3 <-6.6, 1.2, 0.0>, <6.6, 1.2, 0.0>
net_line_points_end                 LABEL DWORD
.ERRNZ (net_line_points_end - net_line_points) - 2 * NET_LINE_SEGMENT_COUNT * SIZEOF VEC3

.data?
arena_horizon_row                   DWORD ?
arena_primitive_center              VEC3 <>
arena_primitive_half                VEC3 <>

.code

arena_draw PROC
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 0, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    call sky_ground_draw
    call stars_draw
    call scatter_draw
    lea rcx, court_line_points
    mov edx, COURT_LINE_SEGMENT_COUNT
    mov r8d, COLOR_COURT_LINE_BGRA
    call segments_draw
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    ret
arena_draw ENDP

sky_ground_draw PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_4_ARGS_ODD_PUSHES_BYTES
    movss xmm0, camera_forward.x
    movss xmm2, camera_forward.z
    movaps xmm3, xmm0
    mulss xmm3, xmm0
    movaps xmm4, xmm2
    mulss xmm4, xmm2
    addss xmm3, xmm4
    sqrtss xmm3, xmm3
    movss xmm4, horizon_distance_u
    divss xmm4, xmm3
    mulss xmm0, xmm4
    mulss xmm2, xmm4
    addss xmm0, camera_eye.x
    addss xmm2, camera_eye.z
    movss xmm1, camera_eye.y
    call world_to_view
    xor ebx, ebx
    comiss xmm2, camera_near_u
    jb sky_ground_draw_horizon_ready
    call view_project
    float_clamp_symmetric xmm1, xmm3, line_coordinate_limit_px
    cvtss2si ebx, xmm1
    xor eax, eax
    test ebx, ebx
    cmovl ebx, eax
    mov eax, SCREEN_HEIGHT_PX
    cmp ebx, eax
    cmovg ebx, eax
sky_ground_draw_horizon_ready:
    mov arena_horizon_row, ebx

    mov esi, COLOR_SKY_BGRA
    cmp match_mode, MATCH_MODE_RALLY
    jne sky_ground_draw_flash
    call rally_multiplier_get
    cmp eax, 2
    jb sky_ground_draw_flash
    imul edx, eax, SKY_LEVEL_TINT_PER_MULTIPLIER
    add edx, SKY_LEVEL_TINT_BASE
    mov eax, effects_ticks
    shr eax, SKY_HUE_SHIFT
    rainbow_color_from_eax ecx
    call color_scale
    mov esi, eax
sky_ground_draw_flash:
    mov edx, background_flash_ticks_left
    test edx, edx
    jz sky_ground_draw_sky
    imul edx, edx, BACKGROUND_FLASH_LEVEL_PER_TICK * 2
    mov eax, match_point_loser_side
    xor eax, SIDE_FLIP
    side_color_load ecx, rax
    call color_scale
    mov esi, eax

sky_ground_draw_sky:
    xor edi, edi
sky_ground_draw_sky_row:
    cmp edi, ebx
    jae sky_ground_draw_ground
    mov eax, COLOR_LEVEL_FULL - SKY_LEVEL_TOP
    imul eax, edi
    xor edx, edx
    div ebx
    lea edx, [rax + SKY_LEVEL_TOP]
    mov ecx, esi
    call color_scale
    mov ecx, eax
    mov edx, edi
    lea r8d, [rdi + 1]
    call framebuffer_rows_fill
    inc edi
    jmp sky_ground_draw_sky_row

sky_ground_draw_ground:
    mov edi, ebx
sky_ground_draw_ground_row:
    cmp edi, SCREEN_HEIGHT_PX
    jae sky_ground_draw_glow
    mov eax, edi
    sub eax, ebx
    imul eax, eax, COLOR_LEVEL_FULL - GROUND_LEVEL_FAR
    mov ecx, SCREEN_HEIGHT_PX
    sub ecx, ebx
    xor edx, edx
    div ecx
    lea edx, [rax + GROUND_LEVEL_FAR]
    mov ecx, COLOR_GROUND_BGRA
    call color_scale
    mov ecx, eax
    mov edx, edi
    lea r8d, [rdi + 1]
    call framebuffer_rows_fill
    inc edi
    jmp sky_ground_draw_ground_row

sky_ground_draw_glow:
    lea r8d, [rbx + HORIZON_GLOW_ROWS]
    mov eax, SCREEN_HEIGHT_PX
    cmp r8d, eax
    cmova r8d, eax
    mov edx, ebx
    mov ecx, COLOR_HORIZON_BGRA
    call framebuffer_rows_fill
    add rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
sky_ground_draw ENDP

stars_draw PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_6_ARGS_ODD_PUSHES_BYTES
    cmp arena_horizon_row, 0
    je stars_draw_done
    movss xmm0, camera_eye.x
    mulss xmm0, star_parallax_px_per_u
    cvtss2si edi, xmm0
    xor ebx, ebx
stars_draw_star:
    lea esi, [rbx + 1]
    imul esi, esi, HASH_MULTIPLIER
    imul eax, ebx, STAR_TWINKLE_PHASE_PER_STAR
    add eax, effects_ticks
    triangle_wave_from_eax
    imul edx, eax, STAR_LEVEL_PER_TRIANGLE_STEP
    add edx, STAR_LEVEL_BASE
    mov ecx, COLOR_STAR_BGRA
    call color_scale
    mov dword ptr [rsp + CALL_ARG5], eax
    movzx eax, si
    imul eax, eax, SCREEN_WIDTH_PX
    shr eax, 16
    add eax, edi
    cdq
    mov ecx, SCREEN_WIDTH_PX
    idiv ecx
    mov ecx, edx
    test ecx, ecx
    jns stars_draw_x_ready
    add ecx, SCREEN_WIDTH_PX
stars_draw_x_ready:
    mov edx, esi
    shr edx, 16
    imul edx, arena_horizon_row
    shr edx, 16
    mov r8d, 1
    mov r9d, 1
    call framebuffer_rect_fill
    inc ebx
    cmp ebx, STAR_COUNT
    jb stars_draw_star
stars_draw_done:
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
stars_draw ENDP

scatter_draw PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_6_ARGS_ODD_PUSHES_BYTES
    xor ebx, ebx
scatter_draw_item:
    lea esi, [rbx + 1]
    imul esi, esi, HASH_MULTIPLIER
    mov edi, esi
    imul edi, edi, HASH_MULTIPLIER
    add edi, ebx
    movzx eax, si
    cvtsi2ss xmm4, eax
    mulss xmm4, scatter_hash_to_unit
    subss xmm4, float_one
    mulss xmm4, scatter_half_x_u
    mov eax, esi
    shr eax, 16
    cvtsi2ss xmm5, eax
    mulss xmm5, scatter_hash_to_unit
    subss xmm5, float_one
    mulss xmm5, scatter_half_z_u
    mov eax, edi
    shr eax, 24
    cvtsi2ss xmm3, eax
    mulss xmm3, scatter_size_range_per_step
    addss xmm3, scatter_size_min
    mov eax, edi
    and eax, SCATTER_ROCK_CHANCE_MASK
    cmp eax, SCATTER_ROCK_CHANCE_BELOW
    jae scatter_draw_tuft

    movaps xmm0, xmm4
    andps xmm0, xmmword ptr float_abs_mask_x4
    movss xmm1, court_half_width_u
    addss xmm1, court_edge_margin_u
    comiss xmm0, xmm1
    ja scatter_draw_rock
    movaps xmm0, xmm5
    andps xmm0, xmmword ptr float_abs_mask_x4
    movss xmm1, court_half_length_u
    addss xmm1, court_edge_margin_u
    comiss xmm0, xmm1
    jbe scatter_draw_next
scatter_draw_rock:
    movss arena_primitive_center.x, xmm4
    movss arena_primitive_center.z, xmm5
    movss xmm0, rock_half_y_u
    mulss xmm0, xmm3
    movss arena_primitive_center.y, xmm0
    movss arena_primitive_half.y, xmm0
    movss xmm0, rock_half_x_u
    mulss xmm0, xmm3
    movss arena_primitive_half.x, xmm0
    movss xmm0, rock_half_z_u
    mulss xmm0, xmm3
    movss arena_primitive_half.z, xmm0
    mov ecx, PRIMITIVE_KIND_PYRAMID
    lea rdx, arena_primitive_center
    lea r8, arena_primitive_half
    mov r9d, COLOR_ROCK_BGRA
    call primitive_draw
    jmp scatter_draw_next

scatter_draw_tuft:
    lea rcx, mesh_scratch_vertices
    movss (VEC3 PTR [rcx]).x, xmm4
    xorps xmm0, xmm0
    movss (VEC3 PTR [rcx]).y, xmm0
    movss (VEC3 PTR [rcx]).z, xmm5
    lea rdx, tuft_tip_offsets_u
    mov eax, TUFT_VERTEX_COUNT - 1
scatter_draw_tuft_tip:
    add rcx, SIZEOF VEC3
    movss xmm0, (VEC3 PTR [rdx]).x
    mulss xmm0, xmm3
    addss xmm0, xmm4
    movss (VEC3 PTR [rcx]).x, xmm0
    movss xmm0, (VEC3 PTR [rdx]).y
    mulss xmm0, xmm3
    movss (VEC3 PTR [rcx]).y, xmm0
    movss xmm0, (VEC3 PTR [rdx]).z
    mulss xmm0, xmm3
    addss xmm0, xmm5
    movss (VEC3 PTR [rcx]).z, xmm0
    add rdx, SIZEOF VEC3
    dec eax
    jnz scatter_draw_tuft_tip
    mov eax, COLOR_GRASS_BGRA
    test edi, SCATTER_DARK_GRASS_HASH_BIT
    jz scatter_draw_tuft_color_ready
    mov eax, COLOR_GRASS_DARK_BGRA
scatter_draw_tuft_color_ready:
    mov dword ptr [rsp + CALL_ARG5], eax
    lea rcx, mesh_scratch_vertices
    mov edx, TUFT_VERTEX_COUNT
    lea r8, tuft_edges
    mov r9d, TUFT_EDGE_COUNT
    call mesh_draw

scatter_draw_next:
    inc ebx
    cmp ebx, SCATTER_COUNT
    jb scatter_draw_item
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
scatter_draw ENDP

segments_draw PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_4_ARGS_ODD_PUSHES_BYTES
    mov rbx, rcx
    mov esi, edx
    mov edi, r8d
segments_draw_segment:
    test esi, esi
    jz segments_draw_done
    mov rcx, rbx
    mov edx, edi
    call world_line_draw
    add rbx, 2 * SIZEOF VEC3
    dec esi
    jmp segments_draw_segment
segments_draw_done:
    add rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
segments_draw ENDP

net_draw PROC
    push rbx
    sub rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 1, FRAME_4_ARGS_ODD_PUSHES_BYTES
    lea rcx, net_line_points
    mov edx, NET_LINE_SEGMENT_COUNT
    mov r8d, COLOR_NET_BGRA
    call segments_draw
    xor ebx, ebx
net_draw_mesh_line:
    cvtsi2ss xmm0, ebx
    mulss xmm0, net_mesh_spacing_u
    subss xmm0, net_half_width_u
    lea rcx, world_line_points
    movss (VEC3 PTR [rcx]).x, xmm0
    movss (VEC3 PTR [rcx + SIZEOF VEC3]).x, xmm0
    movss xmm1, net_bottom_u
    movss (VEC3 PTR [rcx]).y, xmm1
    movss xmm1, net_band_u
    movss (VEC3 PTR [rcx + SIZEOF VEC3]).y, xmm1
    xorps xmm1, xmm1
    movss (VEC3 PTR [rcx]).z, xmm1
    movss (VEC3 PTR [rcx + SIZEOF VEC3]).z, xmm1
    mov edx, COLOR_NET_MESH_BGRA
    call world_line_draw
    inc ebx
    cmp ebx, NET_MESH_VERTICAL_COUNT
    jb net_draw_mesh_line
    add rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    pop rbx
    ret
net_draw ENDP
