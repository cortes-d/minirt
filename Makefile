NAME = minirt
TEST_RAYTRACER_NAME = test_raytracer
TEST_LIBLA_NAME = test_libla
TEST_PARSER_NAME = test_parser

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
DIR_UTIL = $(DIR_SRC)/util
DIR_TEST_RAYTRACER = $(DIR_SRC)/test/test_raytracer
DIR_TEST_LIBLA = $(DIR_SRC)/test/test_libla
DIR_TEST_PARSER = $(DIR_SRC)/test/test_parser

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
								ray/ray.c \
								ray/ray_for_pixel.c \
								ray/position.c \
								ray/ray_transform.c \
								render/render.c

SRC_SCENE =						scene_empty.c \
								scene_default.c \
								scene_free.c \
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
								mlx_data_free.c \
								mlx_data_get.c \
								mlx_data_init.c

SRC_UTIL = 						clamp.c \
								swap.c

SRC_TEST_RAYTRACER =			test_raytracer.c \
								test_ray_for_pixel.c \
								test_raytracer_phong.c \
								test_raytracer_red_circle.c \
								test_raytracer_color_axe.c \
								test_raytracer_scene.c \
								test_raytracer_scene_camera.c

SRC_TEST_LIBLA = 				test_libla.c \
								test_matrix.c \
								test_vector.c \
								test_mat_determinant.c \
		   						test_mat_identity.c \
		   						test_mat_inversion.c \
		  						test_mat_multiplication.c \
		  						test_mat_submatrix.c \
								test_mat_transposition.c \
		   						test_vec3_add.c \
								test_vec3_equal.c \
								test_vec3_hadamard_product.c \
								test_vec3_mul.c \
								test_vec3_sub.c \
								test_vec4_add.c \
								test_vec4_cross_product.c \
								test_vec4_div.c \
								test_vec4_dot_product.c \
								test_vec4_equal.c \
								test_vec4_inv.c \
								test_vec4_magnitude.c \
								test_vec4_mul.c \
								test_vec4_normalize.c \
								test_vec4_sub.c

SRC_TEST_PARSER =				test_parser.c \
								test_print_scene.c
								

# ·············································································
# Sub-section : Add directories as prefix
# ·············································································

SRC_MAIN := $(addprefix $(DIR_SRC)/, $(SRC_MAIN))
SRC_GRAPHIC := $(addprefix $(DIR_GRAPHIC)/, $(SRC_GRAPHIC))
SRC_RAYTRACER := $(addprefix $(DIR_RAYTRACER)/, $(SRC_RAYTRACER))
SRC_SCENE := $(addprefix $(DIR_SCENE)/, $(SRC_SCENE))
SRC_PARSER := $(addprefix $(DIR_PARSER)/, $(SRC_PARSER))
SRC_MEMORY := $(addprefix $(DIR_MEMORY)/, $(SRC_MEMORY))
SRC_UTIL := $(addprefix $(DIR_UTIL)/, $(SRC_UTIL))
SRC_TEST_RAYTRACER := $(addprefix $(DIR_TEST_RAYTRACER)/, $(SRC_TEST_RAYTRACER))
SRC_TEST_LIBLA := $(addprefix $(DIR_TEST_LIBLA)/, $(SRC_TEST_LIBLA))
SRC_TEST_PARSER := $(addprefix $(DIR_TEST_PARSER)/, $(SRC_TEST_PARSER))

# ·············································································
# Sub-section : Combine all source files
# ·············································································

SRC = 							$(SRC_MAIN) \
								$(SRC_GRAPHIC) \
								$(SRC_RAYTRACER) \
								$(SRC_SCENE) \
								$(SRC_PARSER) \
								$(SRC_MEMORY) \
								$(SRC_UTIL)

SRC_TEST_ALL = 					$(SRC) \
								$(SRC_TEST_RAYTRACER) \
								$(SRC_TEST_LIBLA) \
								$(SRC_TEST_PARSER)

# =============================================================================
# Section : Object files
# =============================================================================

OBJ = $(SRC:.c=.o)
OBJ_TEST_RAYTRACER = $(SRC_TEST_RAYTRACER:.c=.o)
OBJ_TEST_LIBLA = $(SRC_TEST_LIBLA:.c=.o)
OBJ_TEST_PARSER = $(SRC_TEST_PARSER:.c=.o)

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
	$(RM) $(OBJ) $(OBJ_TEST_RAYTRACER) $(OBJ_TEST_LIBLA) $(OBJ_TEST_PARSER)
	for dir in $(LIB_DIR); do \
		echo "$(COLOR_GREEN)Cleaning $$dir...$(COLOR_RESET)"; \
		make -C $$dir clean; \
	done
	@echo "$(COLOR_GREEN)Clean-up completed.$(COLOR_RESET)"

# --- Rule to fully clean the project (includes removing the library) ---
fclean: clean
	$(RM) $(NAME) $(TEST_RAYTRACER_NAME) $(TEST_LIBLA_NAME) $(TEST_PARSER_NAME)
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

# --- Rule to recompile everything from scratch ---
re: fclean all

# --- Rule to compile the tests ---
test: $(LIB) $(TEST_LIBLA_NAME) $(TEST_PARSER_NAME) $(TEST_RAYTRACER_NAME)

# --- Build the test_raytracer executable ---
$(TEST_RAYTRACER_NAME): $(OBJ) $(OBJ_TEST_RAYTRACER)
	@echo "$(COLOR_GREEN)Compiling $(TEST_RAYTRACER_NAME)...$(COLOR_RESET)"
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_TEST_RAYTRACER) $(LIB_LINK) -o $(TEST_RAYTRACER_NAME)
	@echo "$(COLOR_GREEN)Compilation of $(TEST_RAYTRACER_NAME) completed successfully.$(COLOR_RESET)"

# --- Build the test_libla executable ---
$(TEST_LIBLA_NAME): $(OBJ) $(OBJ_TEST_LIBLA)
	@echo "$(COLOR_GREEN)Compiling $(TEST_LIBLA_NAME)...$(COLOR_RESET)"
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_TEST_LIBLA) $(LIB_LINK) -o $(TEST_LIBLA_NAME)
	@echo "$(COLOR_GREEN)Compilation of $(TEST_LIBLA_NAME) completed successfully.$(COLOR_RESET)"

# --- Build the test_parser executable ---
$(TEST_PARSER_NAME): $(OBJ) $(OBJ_TEST_PARSER)
	@echo "$(COLOR_GREEN)Compiling $(TEST_PARSER_NAME)...$(COLOR_RESET)"
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_TEST_PARSER) $(LIB_LINK) -o $(TEST_PARSER_NAME)
	@echo "$(COLOR_GREEN)Compilation of $(TEST_PARSER_NAME) completed successfully.$(COLOR_RESET)"

# --- Mark rules as phony (not file names) ---
.PHONY: all clean fclean re test