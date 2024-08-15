NAME = minirt
TEST_RAYTRACER_NAME = test_raytracer
TEST_LIBLA_NAME = test_libla
TEST_PARSING_NAME = test_parsing

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
DIR_UTIL = $(DIR_SRC)/util
DIR_TEST_RAYTRACER = $(DIR_SRC)/test/test_raytracer
DIR_TEST_LIBLA = $(DIR_SRC)/test/test_libla
DIR_TEST_PARSING = $(DIR_SRC)/test/test_parsing

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
								intersection/intersection_pair_init.c \
								intersection/intersection_create.c \
								intersection/intersection_add_to_list.c \
								intersection/hit.c \
								light/lighting.c \
								light/normal_at.c \
								light/reflect.c \
								ray/ray.c \
								ray/ray_for_pixel.c \
								ray/position.c \
								ray/ray_transform.c

SRC_SCENE =						scene_empty.c \
								scene_free.c \
								camera/camera.c \
								camera/view_transform.c \
								light/light_point.c \
								material/material.c \
								material/material_from_color.c \
								material/set_object_color.c \
								primitive/sphere.c \
								primitive/sphere_from_params.c \
								primitive/cylinder.c \
								primitive/cylinder_from_params.c \
								primitive/plane.c \
								primitive/plane_from_params.c \
								primitive/transformation/add_transform.c \
								primitive/transformation/set_transform.c

SRC_UTIL = 						clamp.c \
								swap.c

SRC_TEST_RAYTRACER = 			test_raytracer.c \
								test_ray_for_pixel.c \
								test_raytracer_phong.c \
								test_raytracer_red_circle.c

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

SRC_TEST_PARSING =				test_parsing.c \
								test_print_scene.c
								

# ·············································································
# Sub-section : Add directories as prefix
# ·············································································

SRC_MAIN := $(addprefix $(DIR_SRC)/, $(SRC_MAIN))
SRC_GRAPHIC := $(addprefix $(DIR_GRAPHIC)/, $(SRC_GRAPHIC))
SRC_RAYTRACER := $(addprefix $(DIR_RAYTRACER)/, $(SRC_RAYTRACER))
SRC_SCENE := $(addprefix $(DIR_SCENE)/, $(SRC_SCENE))
SRC_UTIL := $(addprefix $(DIR_UTIL)/, $(SRC_UTIL))
SRC_TEST_RAYTRACER := $(addprefix $(DIR_TEST_RAYTRACER)/, $(SRC_TEST_RAYTRACER))
SRC_TEST_LIBLA := $(addprefix $(DIR_TEST_LIBLA)/, $(SRC_TEST_LIBLA))
SRC_TEST_PARSING := $(addprefix $(DIR_TEST_PARSING)/, $(SRC_TEST_PARSING))

# ·············································································
# Sub-section : Combine all source files
# ·············································································

SRC = 							$(SRC_MAIN) \
								$(SRC_GRAPHIC) \
								$(SRC_RAYTRACER) \
								$(SRC_SCENE) \
								$(SRC_UTIL)

SRC_TEST_ALL = 					$(SRC) \
								$(SRC_TEST_RAYTRACER) \
								$(SRC_TEST_LIBLA) \
								$(SRC_TEST_PARSING)

# =============================================================================
# Section : Object files
# =============================================================================

OBJ = $(SRC:.c=.o)
OBJ_TEST_RAYTRACER = $(SRC_TEST_RAYTRACER:.c=.o)
OBJ_TEST_LIBLA = $(SRC_TEST_LIBLA:.c=.o)
OBJ_TEST_PARSING = $(SRC_TEST_PARSING:.c=.o)

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

# --- mlx ---
MLX_DIR = $(DIR_LIB)/minilibx_opengl
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = -I $(MLX_DIR)
MLX_LINK = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# --- Combine all library settings ---
LIB = $(LIBFT_LIB) $(LIBLA_LIB) $(MLX_LIB)
LIB_INC = $(LIBFT_INC) $(LIBLA_INC) $(MLX_INC)
LIB_LINK = $(LIBFT_LINK) $(LIBLA_LINK) $(MLX_LINK)
LIB_DIR = $(LIBFT_DIR) $(LIBLA_DIR) $(MLX_DIR)

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
$(MLX_LIB):
	@echo "$(COLOR_GREEN)Compiling MLX...$(COLOR_RESET)"
	@make -C $(MLX_DIR)

# --- Pattern rule for object files ---
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIB_INC)

# --- Rule to clean up object files and libraries ---
clean:
	$(RM) $(OBJ) $(OBJ_TEST)
	for dir in $(LIB_DIR); do \
		echo "$(COLOR_GREEN)Cleaning $$dir...$(COLOR_RESET)"; \
		make -C $$dir clean; \
	done
	@echo "$(COLOR_GREEN)Clean-up completed.$(COLOR_RESET)"

# --- Rule to fully clean the project (includes removing the library) ---
fclean: clean
	$(RM) $(NAME) $(TEST_NAME)
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
test: $(LIB) $(TEST_LIBLA_NAME) $(TEST_RAYTRACER_NAME) $(TEST_PARSING_NAME)

# --- Build the test_raytracer executable ---
$(TEST_RAYTRACER_NAME): $(OBJ_TEST_RAYTRACER)
	@echo "$(COLOR_GREEN)Compiling $(TEST_RAYTRACER_NAME)...$(COLOR_RESET)"
	$(CC) $(CFLAGS) $(OBJ_TEST_RAYTRACER) $(LIB_LINK) -o $(TEST_RAYTRACER_NAME)
	@echo "$(COLOR_GREEN)Compilation of $(TEST_RAYTRACER_NAME) completed successfully.$(COLOR_RESET)"

# --- Build the test_libla executable ---
$(TEST_LIBLA_NAME): $(OBJ_TEST_LIBLA)
	@echo "$(COLOR_GREEN)Compiling $(TEST_LIBLA_NAME)...$(COLOR_RESET)"
	$(CC) $(CFLAGS) $(OBJ_TEST_LIBLA) $(LIB_LINK) -o $(TEST_LIBLA_NAME)
	@echo "$(COLOR_GREEN)Compilation of $(TEST_LIBLA_NAME) completed successfully.$(COLOR_RESET)"

# --- Build the test_parsing executable ---
$(TEST_PARSING_NAME): $(OBJ_TEST_PARSING)
	@echo "$(COLOR_GREEN)Compiling $(TEST_PARSING_NAME)...$(COLOR_RESET)"
	$(CC) $(CFLAGS) $(OBJ_TEST_PARSING) $(LIB_LINK) -o $(TEST_PARSING_NAME)
	@echo "$(COLOR_GREEN)Compilation of $(TEST_PARSING_NAME) completed successfully.$(COLOR_RESET)"

# --- Mark rules as phony (not file names) ---
.PHONY: all clean fclean re test