COLOR_STAR_BGRA                     equ PALETTE_WHITE_BGRA
COLOR_NET_BGRA                      equ PALETTE_WHITE_BGRA
COLOR_NET_MESH_BGRA                 equ PALETTE_SLATE_BGRA
COLOR_GRASS_BGRA                    equ PALETTE_LIME_BGRA
COLOR_GRASS_DARK_BGRA               equ PALETTE_GREEN_BGRA
COLOR_ROCK_BGRA                     equ PALETTE_SILVER_BGRA
COLOR_ROCK_DARK_BGRA                equ PALETTE_SLATE_BGRA
COLOR_FLOOR_COURT_BGRA              equ PALETTE_ORANGE_BGRA
COLOR_FLOOR_GROUT_BGRA              equ PALETTE_RED_BGRA
COLOR_FLOOR_GRASS_BGRA              equ PALETTE_GREEN_BGRA
COLOR_FLOOR_LINE_BGRA               equ PALETTE_WHITE_BGRA
COLOR_SUN_TOP_BGRA                  equ PALETTE_YELLOW_BGRA
COLOR_SUN_BOTTOM_BGRA               equ PALETTE_RED_BGRA
SKY_KEY_COUNT                       equ 5
SKY_TINT_LEVEL_PER_MULTIPLIER       equ 18
.ERRE SKY_TINT_LEVEL_PER_MULTIPLIER * RALLY_MULTIPLIER_MAX LE COLOR_LEVEL_FULL
SKY_FLASH_LEVEL_PER_TICK            equ 14
.ERRE SKY_FLASH_LEVEL_PER_TICK * BACKGROUND_FLASH_TICKS LE COLOR_LEVEL_FULL
SKY_HUE_SHIFT                       equ 4
SUN_RADIUS_PX                       equ 26
SUN_STRIPE_MASK                     equ 3
STAR_COUNT                          equ 60
STAR_SKY_ROWS_NUMERATOR             equ 9
STAR_SKY_ROWS_SHIFT                 equ 4
STAR_LEVEL_BASE                     equ 120
STAR_LEVEL_PER_TRIANGLE_STEP        equ 8
STAR_TWINKLE_PHASE_PER_STAR         equ 7
SCATTER_COUNT                       equ 420
SCATTER_ROCK_CHANCE_MASK            equ 7
SCATTER_ROCK_CHANCE_BELOW           equ 3
SCATTER_DARK_HASH_BIT               equ 100h
NET_LINE_SEGMENT_COUNT              equ 7
NET_MESH_VERTICAL_COUNT             equ 45
TUFT_VERTEX_COUNT                   equ 4
TUFT_EDGE_COUNT                     equ 3
FLOOR_FIXED_SHIFT                   equ 16
FLOOR_TILE_SHIFT                    equ FLOOR_FIXED_SHIFT + 2
FLOOR_TILE_FIXED                    equ 1 SHL FLOOR_TILE_SHIFT
FLOOR_GROUT_WIDTH_FIXED             equ 5200
FLOOR_COURT_TEXEL_SHIFT             equ FLOOR_FIXED_SHIFT - 2
FLOOR_GRASS_TEXEL_SHIFT             equ FLOOR_FIXED_SHIFT - 1
COURT_HALF_WIDTH_U                  equ 12
COURT_HALF_LENGTH_U                 equ 18
COURT_ATTACK_LINE_U                 equ 6
COURT_HALF_WIDTH_FIXED              equ COURT_HALF_WIDTH_U SHL FLOOR_FIXED_SHIFT
COURT_HALF_LENGTH_FIXED             equ COURT_HALF_LENGTH_U SHL FLOOR_FIXED_SHIFT
COURT_ATTACK_LINE_FIXED             equ COURT_ATTACK_LINE_U SHL FLOOR_FIXED_SHIFT
COURT_LINE_HALF_WIDTH_FIXED         equ 10000
FLOOR_DRAW_PUSHED_REGISTER_COUNT    equ 7
FLOOR_DRAW_FRAME_BYTES              equ 64
FLOOR_DRAW_LOCAL_COURT              equ 32
FLOOR_DRAW_LOCAL_GROUT              equ 36
FLOOR_DRAW_LOCAL_GRASS              equ 40
FLOOR_DRAW_LOCAL_LINE               equ 44
FLOOR_DRAW_LOCAL_FOG_LEVEL          equ 48
FLOOR_DRAW_LOCAL_FIRST_COLUMN_X     equ 52
SUN_DRAW_LOCAL_HALF_WIDTH           equ CALL_ARG6

floor_row_color_set MACRO local_offset, base_color
    mov ecx, base_color
    mov edx, COLOR_FOG_BGRA
    mov r8d, dword ptr [rsp + FLOOR_DRAW_LOCAL_FOG_LEVEL]
    call color_lerp
    mov dword ptr [rsp + local_offset], eax
ENDM

fixed_abs_to_eax MACRO
    cdq
    xor eax, edx
    sub eax, edx
ENDM

.const
court_half_width_u                  REAL4 12.0
court_half_length_u                 REAL4 18.0
court_edge_margin_u                 REAL4 0.6
net_top_u                           REAL4 1.6
net_band_u                          REAL4 1.42
net_bottom_u                        REAL4 0.7
net_half_width_u                    REAL4 13.2
net_mesh_spacing_u                  REAL4 0.6
horizon_distance_u                  REAL4 1000.0
sun_distance_u                      REAL4 1000.0
sun_height_u                        REAL4 60.0
star_parallax_px_per_u              REAL4 -8.0
scatter_half_x_u                    REAL4 40.0
scatter_half_z_u                    REAL4 48.0
scatter_hash_to_unit                REAL4 0.0000305176
scatter_size_min                    REAL4 0.7
scatter_size_range_per_step         REAL4 0.004
rock_half_x_u                       REAL4 0.26
rock_half_y_u                       REAL4 0.2
rock_half_z_u                       REAL4 0.22
floor_dir_y_max                     REAL4 -0.002
floor_distance_max_u                REAL4 300.0
floor_fixed_one                     REAL4 65536.0
tuft_tip_offsets_u                  VEC3 <-0.09, 0.3, 0.02>, <0.02, 0.38, -0.03>, <0.1, 0.27, 0.03>
tuft_edges                          BYTE 0, 1, 0, 2, 0, 3
net_line_points                     VEC3 <-13.2, 0.0, 0.0>, <-13.2, 1.6, 0.0>, <13.2, 0.0, 0.0>, <13.2, 1.6, 0.0>
                                    VEC3 <-13.2, 1.6, 0.0>, <13.2, 1.6, 0.0>, <-13.2, 1.42, 0.0>, <13.2, 1.42, 0.0>
                                    VEC3 <-13.2, 0.7, 0.0>, <13.2, 0.7, 0.0>, <-13.2, 0.95, 0.0>, <13.2, 0.95, 0.0>
                                    VEC3 <-13.2, 1.2, 0.0>, <13.2, 1.2, 0.0>
net_line_points_end                 LABEL DWORD
.ERRNZ (net_line_points_end - net_line_points) - 2 * NET_LINE_SEGMENT_COUNT * SIZEOF VEC3
sky_key_bgra                        DWORD PALETTE_NIGHT_BGRA, PALETTE_NAVY_BGRA, PALETTE_PLUM_BGRA, PALETTE_RED_BGRA, PALETTE_ORANGE_BGRA
.ERRNZ LENGTHOF sky_key_bgra - SKY_KEY_COUNT

.data?
arena_horizon_row                   DWORD ?
arena_primitive_center              VEC3 <>
arena_primitive_half                VEC3 <>

.code

arena_draw PROC
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 0, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    call sky_draw
    call sun_draw
    call stars_draw
    call floor_draw
    call scatter_draw
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    ret
arena_draw ENDP

sky_draw PROC
    push rbx
    push rsi
    push rdi
    push r12
    sub rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    frame_alignment_check 4, FRAME_4_ARGS_EVEN_PUSHES_BYTES
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
    jb sky_draw_horizon_ready
    call view_project
    float_clamp_symmetric xmm1, xmm3, line_coordinate_limit_px
    cvtss2si ebx, xmm1
    xor eax, eax
    test ebx, ebx
    cmovl ebx, eax
    mov eax, SCREEN_HEIGHT_PX
    cmp ebx, eax
    cmovg ebx, eax
sky_draw_horizon_ready:
    mov arena_horizon_row, ebx

    xor r12d, r12d
    xor esi, esi
    cmp match_mode, MATCH_MODE_RALLY
    jne sky_draw_flash
    call rally_multiplier_get
    cmp eax, 2
    jb sky_draw_flash
    imul r12d, eax, SKY_TINT_LEVEL_PER_MULTIPLIER
    mov eax, effects_ticks
    shr eax, SKY_HUE_SHIFT
    rainbow_color_from_eax esi
sky_draw_flash:
    mov eax, background_flash_ticks_left
    test eax, eax
    jz sky_draw_rows
    imul r12d, eax, SKY_FLASH_LEVEL_PER_TICK
    mov eax, match_point_loser_side
    xor eax, SIDE_FLIP
    side_color_load esi, rax

sky_draw_rows:
    xor edi, edi
sky_draw_row:
    cmp edi, ebx
    jae sky_draw_done
    imul eax, edi, (SKY_KEY_COUNT - 1) * COLOR_LEVEL_FULL
    xor edx, edx
    div ebx
    mov r8d, eax
    and r8d, COLOR_LEVEL_FULL - 1
    shr eax, COLOR_LEVEL_SHIFT
    lea r9, sky_key_bgra
    mov ecx, dword ptr [r9 + rax * 4]
    mov edx, dword ptr [r9 + rax * 4 + 4]
    call color_lerp
    test r12d, r12d
    jz sky_draw_row_fill
    mov ecx, eax
    mov edx, esi
    mov r8d, r12d
    call color_lerp
sky_draw_row_fill:
    mov ecx, eax
    mov edx, edi
    lea r8d, [rdi + 1]
    call framebuffer_rows_fill
    inc edi
    jmp sky_draw_row
sky_draw_done:
    add rsp, FRAME_4_ARGS_EVEN_PUSHES_BYTES
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
sky_draw ENDP

sun_draw PROC
    push rbx
    push rsi
    push rdi
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    frame_alignment_check 3, FRAME_6_ARGS_ODD_PUSHES_BYTES
    movss xmm0, camera_eye.x
    movss xmm1, camera_eye.y
    addss xmm1, sun_height_u
    movss xmm2, camera_eye.z
    addss xmm2, sun_distance_u
    call world_to_view
    comiss xmm2, camera_near_u
    jb sun_draw_done
    call view_project
    float_clamp_symmetric xmm0, xmm3, line_coordinate_limit_px
    float_clamp_symmetric xmm1, xmm3, line_coordinate_limit_px
    cvtss2si esi, xmm0
    cvtss2si edi, xmm1
    mov ebx, -SUN_RADIUS_PX
sun_draw_row:
    cmp ebx, SUN_RADIUS_PX
    jg sun_draw_done
    test ebx, ebx
    jle sun_draw_row_solid
    test ebx, SUN_STRIPE_MASK
    jz sun_draw_row_next
sun_draw_row_solid:
    mov eax, ebx
    imul eax, eax
    mov ecx, SUN_RADIUS_PX * SUN_RADIUS_PX
    sub ecx, eax
    cvtsi2ss xmm0, ecx
    sqrtss xmm0, xmm0
    cvttss2si eax, xmm0
    mov dword ptr [rsp + SUN_DRAW_LOCAL_HALF_WIDTH], eax
    lea eax, [rbx + SUN_RADIUS_PX]
    imul eax, eax, COLOR_LEVEL_FULL
    xor edx, edx
    mov ecx, 2 * SUN_RADIUS_PX + 1
    div ecx
    mov r8d, eax
    mov ecx, COLOR_SUN_TOP_BGRA
    mov edx, COLOR_SUN_BOTTOM_BGRA
    call color_lerp
    mov dword ptr [rsp + CALL_ARG5], eax
    mov r8d, dword ptr [rsp + SUN_DRAW_LOCAL_HALF_WIDTH]
    mov ecx, esi
    sub ecx, r8d
    lea r8d, [r8 + r8 + 1]
    lea edx, [rdi + rbx]
    mov r9d, 1
    call framebuffer_rect_fill
sun_draw_row_next:
    inc ebx
    jmp sun_draw_row
sun_draw_done:
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES
    pop rdi
    pop rsi
    pop rbx
    ret
sun_draw ENDP

stars_draw PROC
    push rbx
    push rsi
    push rdi
    push r12
    sub rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES + 8
    frame_alignment_check 4, FRAME_6_ARGS_ODD_PUSHES_BYTES + 8
    mov r12d, arena_horizon_row
    imul r12d, r12d, STAR_SKY_ROWS_NUMERATOR
    shr r12d, STAR_SKY_ROWS_SHIFT
    test r12d, r12d
    jz stars_draw_done
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
    imul edx, r12d
    shr edx, 16
    mov r8d, 1
    mov r9d, 1
    call framebuffer_rect_fill
    inc ebx
    cmp ebx, STAR_COUNT
    jb stars_draw_star
stars_draw_done:
    add rsp, FRAME_6_ARGS_ODD_PUSHES_BYTES + 8
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
stars_draw ENDP

floor_draw PROC
    push rbx
    push rsi
    push rdi
    push r12
    push r13
    push r14
    push r15
    sub rsp, FLOOR_DRAW_FRAME_BYTES
    frame_alignment_check FLOOR_DRAW_PUSHED_REGISTER_COUNT, FLOOR_DRAW_FRAME_BYTES
    cvtsi2ss xmm0, screen_shake_offset_x_px
    addss xmm0, screen_center_x_px_float
    movss xmm1, raster_pixel_center_offset
    subss xmm1, xmm0
    divss xmm1, camera_focal_px
    movss dword ptr [rsp + FLOOR_DRAW_LOCAL_FIRST_COLUMN_X], xmm1
    lea rsi, textures
    xor edi, edi
floor_draw_row:
    cmp edi, SCREEN_HEIGHT_PX
    jae floor_draw_done
    mov eax, edi
    sub eax, screen_shake_offset_y_px
    cvtsi2ss xmm0, eax
    addss xmm0, raster_pixel_center_offset
    movss xmm1, screen_center_y_px_float
    subss xmm1, xmm0
    divss xmm1, camera_focal_px
    movss xmm2, camera_up.y
    mulss xmm2, xmm1
    addss xmm2, camera_forward.y
    comiss xmm2, floor_dir_y_max
    jb floor_draw_row_hit
    cmp edi, arena_horizon_row
    jb floor_draw_row_next
    mov ecx, dword ptr sky_key_bgra[4 * (SKY_KEY_COUNT - 1)]
    mov edx, edi
    lea r8d, [rdi + 1]
    call framebuffer_rows_fill
    jmp floor_draw_row_next
floor_draw_row_hit:
    movss xmm3, camera_eye.y
    divss xmm3, xmm2
    xorps xmm3, xmmword ptr float_sign_mask_x4
    minss xmm3, floor_distance_max_u
    movaps xmm0, xmm3
    subss xmm0, depth_fade_start_u
    maxss xmm0, float_zero
    mulss xmm0, depth_fade_level_per_u
    minss xmm0, depth_fade_level_max
    cvttss2si eax, xmm0
    mov dword ptr [rsp + FLOOR_DRAW_LOCAL_FOG_LEVEL], eax

    movss xmm0, camera_up.x
    mulss xmm0, xmm1
    addss xmm0, camera_forward.x
    movss xmm4, camera_right.x
    mulss xmm4, dword ptr [rsp + FLOOR_DRAW_LOCAL_FIRST_COLUMN_X]
    addss xmm0, xmm4
    mulss xmm0, xmm3
    addss xmm0, camera_eye.x
    mulss xmm0, floor_fixed_one
    cvtss2si r8d, xmm0
    movss xmm0, camera_up.z
    mulss xmm0, xmm1
    addss xmm0, camera_forward.z
    movss xmm4, camera_right.z
    mulss xmm4, dword ptr [rsp + FLOOR_DRAW_LOCAL_FIRST_COLUMN_X]
    addss xmm0, xmm4
    mulss xmm0, xmm3
    addss xmm0, camera_eye.z
    mulss xmm0, floor_fixed_one
    cvtss2si r9d, xmm0
    movss xmm0, camera_right.x
    mulss xmm0, xmm3
    divss xmm0, camera_focal_px
    mulss xmm0, floor_fixed_one
    cvtss2si r10d, xmm0
    movss xmm0, camera_right.z
    mulss xmm0, xmm3
    divss xmm0, camera_focal_px
    mulss xmm0, floor_fixed_one
    cvtss2si r11d, xmm0
    mov r12d, r8d
    mov r13d, r9d
    mov r14d, r10d
    mov r15d, r11d
    floor_row_color_set FLOOR_DRAW_LOCAL_COURT, COLOR_FLOOR_COURT_BGRA
    floor_row_color_set FLOOR_DRAW_LOCAL_GROUT, COLOR_FLOOR_GROUT_BGRA
    floor_row_color_set FLOOR_DRAW_LOCAL_GRASS, COLOR_FLOOR_GRASS_BGRA
    floor_row_color_set FLOOR_DRAW_LOCAL_LINE, COLOR_FLOOR_LINE_BGRA
    mov r8d, r12d
    mov r9d, r13d
    mov r10d, r14d
    mov r11d, r15d
    imul eax, edi, SCREEN_WIDTH_PX
    lea rbx, framebuffer_bgra
    lea rbx, [rbx + rax * 4]
    mov r12d, SCREEN_WIDTH_PX
    pxor xmm5, xmm5
floor_draw_pixel:
    mov eax, r8d
    fixed_abs_to_eax
    mov r14d, eax
    mov eax, r9d
    fixed_abs_to_eax
    mov r15d, eax
    cmp r14d, COURT_HALF_WIDTH_FIXED + COURT_LINE_HALF_WIDTH_FIXED
    jae floor_draw_pixel_grass
    cmp r15d, COURT_HALF_LENGTH_FIXED + COURT_LINE_HALF_WIDTH_FIXED
    jae floor_draw_pixel_grass
    mov eax, r14d
    sub eax, COURT_HALF_WIDTH_FIXED
    fixed_abs_to_eax
    cmp eax, COURT_LINE_HALF_WIDTH_FIXED
    jb floor_draw_pixel_line
    mov eax, r15d
    sub eax, COURT_HALF_LENGTH_FIXED
    fixed_abs_to_eax
    cmp eax, COURT_LINE_HALF_WIDTH_FIXED
    jb floor_draw_pixel_line
    cmp r15d, COURT_LINE_HALF_WIDTH_FIXED
    jb floor_draw_pixel_line
    mov eax, r15d
    sub eax, COURT_ATTACK_LINE_FIXED
    fixed_abs_to_eax
    cmp eax, COURT_LINE_HALF_WIDTH_FIXED
    jb floor_draw_pixel_line
    mov eax, r8d
    and eax, FLOOR_TILE_FIXED - 1
    cmp eax, FLOOR_GROUT_WIDTH_FIXED
    jb floor_draw_pixel_grout
    mov eax, r9d
    and eax, FLOOR_TILE_FIXED - 1
    cmp eax, FLOOR_GROUT_WIDTH_FIXED
    jb floor_draw_pixel_grout
    mov edx, dword ptr [rsp + FLOOR_DRAW_LOCAL_COURT]
    mov eax, r8d
    sar eax, FLOOR_COURT_TEXEL_SHIFT
    and eax, TEXTURE_TEXEL_MASK
    mov ecx, r9d
    sar ecx, FLOOR_COURT_TEXEL_SHIFT - TEXTURE_SIZE_SHIFT
    and ecx, TEXTURE_TEXEL_MASK SHL TEXTURE_SIZE_SHIFT
    add eax, ecx
    movzx eax, byte ptr [rsi + rax + TEXTURE_SAND * TEXTURE_TEXEL_COUNT]
    jmp floor_draw_pixel_shade
floor_draw_pixel_grass:
    mov edx, dword ptr [rsp + FLOOR_DRAW_LOCAL_GRASS]
    mov eax, r8d
    sar eax, FLOOR_GRASS_TEXEL_SHIFT
    and eax, TEXTURE_TEXEL_MASK
    mov ecx, r9d
    sar ecx, FLOOR_GRASS_TEXEL_SHIFT - TEXTURE_SIZE_SHIFT
    and ecx, TEXTURE_TEXEL_MASK SHL TEXTURE_SIZE_SHIFT
    add eax, ecx
    movzx eax, byte ptr [rsi + rax + TEXTURE_GRASS * TEXTURE_TEXEL_COUNT]
floor_draw_pixel_shade:
    movd xmm0, edx
    punpcklbw xmm0, xmm5
    movd xmm1, eax
    pshuflw xmm1, xmm1, 0
    pmullw xmm0, xmm1
    psrlw xmm0, COLOR_LEVEL_SHIFT
    packuswb xmm0, xmm5
    movd dword ptr [rbx], xmm0
    jmp floor_draw_pixel_next
floor_draw_pixel_line:
    mov eax, dword ptr [rsp + FLOOR_DRAW_LOCAL_LINE]
    mov dword ptr [rbx], eax
    jmp floor_draw_pixel_next
floor_draw_pixel_grout:
    mov eax, dword ptr [rsp + FLOOR_DRAW_LOCAL_GROUT]
    mov dword ptr [rbx], eax
floor_draw_pixel_next:
    add r8d, r10d
    add r9d, r11d
    add rbx, 4
    dec r12d
    jnz floor_draw_pixel
floor_draw_row_next:
    inc edi
    jmp floor_draw_row
floor_draw_done:
    add rsp, FLOOR_DRAW_FRAME_BYTES
    pop r15
    pop r14
    pop r13
    pop r12
    pop rdi
    pop rsi
    pop rbx
    ret
floor_draw ENDP

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
    movaps xmm0, xmm4
    andps xmm0, xmmword ptr float_abs_mask_x4
    movss xmm1, court_half_width_u
    addss xmm1, court_edge_margin_u
    comiss xmm0, xmm1
    ja scatter_draw_outside
    movaps xmm0, xmm5
    andps xmm0, xmmword ptr float_abs_mask_x4
    movss xmm1, court_half_length_u
    addss xmm1, court_edge_margin_u
    comiss xmm0, xmm1
    jbe scatter_draw_next
scatter_draw_outside:
    mov eax, edi
    shr eax, 24
    cvtsi2ss xmm3, eax
    mulss xmm3, scatter_size_range_per_step
    addss xmm3, scatter_size_min
    mov eax, edi
    and eax, SCATTER_ROCK_CHANCE_MASK
    cmp eax, SCATTER_ROCK_CHANCE_BELOW
    jae scatter_draw_tuft

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
    mov r9d, COLOR_ROCK_BGRA
    test edi, SCATTER_DARK_HASH_BIT
    jz scatter_draw_rock_color_ready
    mov r9d, COLOR_ROCK_DARK_BGRA
scatter_draw_rock_color_ready:
    mov dword ptr [rsp + CALL_ARG5], TEXTURE_SAND
    mov ecx, PRIMITIVE_KIND_PYRAMID
    lea rdx, arena_primitive_center
    lea r8, arena_primitive_half
    call primitive_solid_draw
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
    test edi, SCATTER_DARK_HASH_BIT
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
    lea rcx, net_line_points
    mov edx, NET_LINE_SEGMENT_COUNT
    mov r8d, COLOR_NET_BGRA
    call segments_draw
    add rsp, FRAME_4_ARGS_ODD_PUSHES_BYTES
    pop rbx
    ret
net_draw ENDP
