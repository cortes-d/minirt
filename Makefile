NAME = minirt

# =============================================================================
# Section : ANSI color codes
# =============================================================================

COLOR_GREEN = \033[0;32m
COLOR_RESET = \033[0m

# =============================================================================
# Section : Directories
# =============================================================================

DIR_INC = inc
DIR_SRC = src
DIR_LIB = lib

DIR_GRAPHIC = $(DIR_SRC)/graphic
DIR_PARSER = $(DIR_SRC)/parser
DIR_RAYTRACER = $(DIR_SRC)/raytracer
DIR_SCENE = $(DIR_SRC)/scene
DIR_MEMORY = $(DIR_SRC)/memory
DIR_HOOK = $(DIR_SRC)/hook
DIR_UTIL = $(DIR_SRC)/util

# =============================================================================
# Section : Compiler and flags
# =============================================================================

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(DIR_INC)
RM = rm -f

# =============================================================================
# Section : Source files
# =============================================================================

SRC_MAIN = 						minirt.c

SRC_GRAPHIC =					write_pixel.c

SRC_RAYTRACER =					intersection/intersect.c \
								intersection/intersect_sphere.c \
								intersection/intersect_cylinder.c \
								intersection/intersect_plane.c \
								intersection/intersect_scene.c \
								intersection/intersection_pair_init.c \
								intersection/intersection_create.c \
								intersection/intersection_add_to_list.c \
								intersection/hit.c \
								light/prepare_computation.c \
								light/lighting.c \
								light/normal_at.c \
								light/reflect.c \
								light/color_at.c \
								light/shade_hit.c \
								light/is_shadowed.c \
								ray/ray.c \
								ray/ray_for_pixel.c \
								ray/position.c \
								ray/ray_transform.c \
								render/render.c \
								render/render_nothing.c

SRC_SCENE =						scene_empty.c \
								camera/camera.c \
								camera/camera_default.c \
								camera/camera_computation.c \
								camera/view_transform.c \
								light/light_point.c \
								light/light_ambient.c \
								material/material_default.c \
								material/material_from_color.c \
								material/set_object_color.c \
								primitive/sphere.c \
								primitive/sphere_default.c \
								primitive/cylinder.c \
								primitive/cylinder_default.c \
								primitive/plane.c \
								primitive/plane_default.c \
								primitive/transformation/add_transform.c \
								primitive/transformation/set_transform.c

SRC_PARSER =					check/highest_check/check_light_ambient_tokens.c \
								check/highest_check/check_camera_tokens.c \
								check/highest_check/check_cylinder_tokens.c \
								check/highest_check/check_plane_tokens.c \
								check/highest_check/check_light_point_tokens.c \
								check/highest_check/check_sphere_tokens.c \
								check/lowest_check/check_float.c \
								check/lowest_check/check_uchar.c \
								check/middle_check/check_color_token.c \
								check/middle_check/check_float_token.c \
								check/middle_check/check_vec3_token.c \
								check/check_main_arguments.c \
								creation/create_camera.c \
								creation/create_cylinder.c \
								creation/create_light_ambient.c \
								creation/create_light_point.c \
								creation/create_plane.c \
								creation/create_sphere.c \
								extraction/utility/elem_at_index_n.c \
								extraction/extract_color.c \
								extraction/extract_float.c \
								extraction/extract_vec3.c \
								parsing_logic/utility/scene_data_empty.c \
								parsing_logic/utility/scene_data_free.c \
								parsing_logic/parse_line.c \
								parsing_logic/parse_scene.c \
								parsing_logic/parsing_loop.c \
								parsing_logic/scene_data_to_scene.c \
								parsing_logic/type_interpreter.c

SRC_MEMORY =					exit_error.c \
								exit_minirt.c \
								mlx_static_get.c \
								mlx_static_free.c \
								mlx_static_init.c \
								scene_static_get.c \
								scene_static_free.c \
								scene_static_init.c

SRC_HOOK =						hook_cross_pressed.c \
								hook_key_released.c \
								reload_scene.c

SRC_UTIL = 						swap.c

# ·············································································
# Sub-section : Add directories as prefix
# ·············································································

SRC_MAIN := $(addprefix $(DIR_SRC)/, $(SRC_MAIN))
SRC_GRAPHIC := $(addprefix $(DIR_GRAPHIC)/, $(SRC_GRAPHIC))
SRC_RAYTRACER := $(addprefix $(DIR_RAYTRACER)/, $(SRC_RAYTRACER))
SRC_SCENE := $(addprefix $(DIR_SCENE)/, $(SRC_SCENE))
SRC_PARSER := $(addprefix $(DIR_PARSER)/, $(SRC_PARSER))
SRC_MEMORY := $(addprefix $(DIR_MEMORY)/, $(SRC_MEMORY))
SRC_HOOK := $(addprefix $(DIR_HOOK)/, $(SRC_HOOK))
SRC_UTIL := $(addprefix $(DIR_UTIL)/, $(SRC_UTIL))

# ·············································································
# Sub-section : Combine all source files
# ·············································································

SRC = 							$(SRC_MAIN) \
								$(SRC_GRAPHIC) \
								$(SRC_RAYTRACER) \
								$(SRC_SCENE) \
								$(SRC_PARSER) \
								$(SRC_MEMORY) \
								$(SRC_HOOK) \
								$(SRC_UTIL)

# =============================================================================
# Section : Object files
# =============================================================================

OBJ = $(SRC:.c=.o)

# =============================================================================
# Section : Libraries
# =============================================================================

# --- libft ---
LIBFT_DIR = $(DIR_LIB)/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I $(LIBFT_DIR)
LIBFT_LINK = -L$(LIBFT_DIR) -lft

# --- libla ---
LIBLA_DIR = $(DIR_LIB)/libla
LIBLA_LIB = $(LIBLA_DIR)/libla.a
LIBLA_INC = -I $(LIBLA_DIR)
LIBLA_LINK = -L$(LIBLA_DIR) -lla

# --- libgc ---
LIBGC_DIR = $(DIR_LIB)/libgc
LIBGC_LIB = $(LIBGC_DIR)/libgc.a
LIBGC_INC = -I $(LIBGC_DIR)
LIBGC_LINK = -L$(LIBGC_DIR) -lgc

# --- mlx ---
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = -I $(MLX_DIR)
ifeq ($(shell uname), Darwin)
    MLX_DIR = $(DIR_LIB)/minilibx_opengl
    MLX_LINK = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
    MLX_DIR = $(DIR_LIB)/minilibx_linux
    MLX_LINK = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
endif

# --- Combine all library settings ---
LIB = $(LIBFT_LIB) $(LIBLA_LIB) $(LIBGC_LIB) $(MLX_LIB)
LIB_INC = $(LIBFT_INC) $(LIBLA_INC) $(LIBGC_INC) $(MLX_INC)
LIB_LINK = $(LIBFT_LINK) $(LIBLA_LINK) $(LIBGC_LINK) $(MLX_LINK)
LIB_DIR = $(LIBFT_DIR) $(LIBLA_DIR) $(LIBGC_DIR) $(MLX_DIR)

# =============================================================================
# Section : Targets
# =============================================================================

# -- Main compilation rule ---
all: $(LIB) $(NAME)

# --- Build the project executable ---
$(NAME): $(OBJ)
	@echo "$(COLOR_GREEN)Compiling $(NAME)...$(COLOR_RESET)"
	$(CC) $(CFLAGS) $(OBJ) $(LIB_LINK) -o $(NAME)
	@echo "$(COLOR_GREEN)Compilation of $(NAME) completed successfully.$(COLOR_RESET)"

# --- Compile each library if not already present ---
$(LIBFT_LIB):
	@echo "$(COLOR_GREEN)Compiling libft...$(COLOR_RESET)"
	@make -C $(LIBFT_DIR)
$(LIBLA_LIB):
	@echo "$(COLOR_GREEN)Compiling libla...$(COLOR_RESET)"
	@make -C $(LIBLA_DIR)
$(LIBGC_LIB):
	@echo "$(COLOR_GREEN)Compiling libgc...$(COLOR_RESET)"
	@make -C $(LIBGC_DIR)
$(MLX_LIB):
	@echo "$(COLOR_GREEN)Compiling MLX...$(COLOR_RESET)"
	@make -C $(MLX_DIR)

# --- Pattern rule for object files ---
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIB_INC)

# --- Rule to clean up object files and libraries ---
clean:
	$(RM) $(OBJ)
	for dir in $(LIB_DIR); do \
		echo "$(COLOR_GREEN)Cleaning $$dir...$(COLOR_RESET)"; \
		make -C $$dir clean; \
	done
	@echo "$(COLOR_GREEN)Clean-up completed.$(COLOR_RESET)"

# --- Rule to fully clean the project (includes removing the library) ---
fclean: clean
	$(RM) $(NAME)
	for dir in $(LIB_DIR); do \
		echo "$(COLOR_GREEN)Full cleaning $$dir...$(COLOR_RESET)"; \
		if make -C $$dir fclean; then \
			echo "$(COLOR_GREEN)Full clean of $$dir completed.$(COLOR_RESET)"; \
		else \
			echo "$(COLOR_GREEN)fclean not available for $$dir, performing clean instead.$(COLOR_RESET)"; \
			make -C $$dir clean; \
		fi \
	done
	@echo "$(COLOR_GREEN)Full clean-up completed.$(COLOR_RESET)"

# --- Rule to run norminette on all file except minilibx ones ---
norminette:
	@echo "$(COLOR_GREEN)Starting libft norminette.$(COLOR_RESET)"
	@norminette $(LIBFT_DIR) || true
	@echo "$(COLOR_GREEN)Starting libla norminette.$(COLOR_RESET)"
	@norminette $(LIBLA_DIR) || true
	@echo "$(COLOR_GREEN)Starting libgc norminette.$(COLOR_RESET)"
	@norminette $(LIBGC_DIR) || true
	@echo "$(COLOR_GREEN)Starting inc norminette.$(COLOR_RESET)"
	@norminette $(DIR_INC) || true
	@echo "$(COLOR_GREEN)Starting inc norminette.$(COLOR_RESET)"
	@norminette $(DIR_SRC) || true

# --- Rule to recompile everything from scratch ---
re: fclean all

# --- Mark rules as phony (not file names) ---
.PHONY: all clean fclean re norminette