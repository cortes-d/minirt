NAME = minirt
TEST_NAME = test_minirt

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
DIR_TEST = $(DIR_SRC)/test
DIR_GRAPHIC = $(DIR_SRC)/graphic

DIR_RAYTRACER = $(DIR_SRC)/raytracer
DIR_RAYTRACER_CAMERA = $(DIR_RAYTRACER)/camera
DIR_RAYTRACER_LIGHT = $(DIR_RAYTRACER)/light
DIR_RAYTRACER_INTERSECTION = $(DIR_RAYTRACER)/intersection
DIR_RAYTRACER_MATERIAL = $(DIR_RAYTRACER)/material
DIR_RAYTRACER_GEOMETRY = $(DIR_RAYTRACER)/geometry
DIR_RAYTRACER_RAY = $(DIR_RAYTRACER)/ray
DIR_RAYTRACER_TRANSFORMATION = $(DIR_RAYTRACER)/transformation

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
SRC_GRAPHIC =					$(DIR_GRAPHIC)/write_pixel.c
SRC_RAYTRACER =					$(DIR_RAYTRACER)/test_phong.c \
								$(DIR_RAYTRACER_CAMERA)/camera.c \
								$(DIR_RAYTRACER_CAMERA)/view_transform.c \
								$(DIR_RAYTRACER_LIGHT)/light_point.c \
								$(DIR_RAYTRACER_LIGHT)/lighting.c \
								$(DIR_RAYTRACER_LIGHT)/normal_at.c \
								$(DIR_RAYTRACER_LIGHT)/reflect.c \
								$(DIR_RAYTRACER_INTERSECTION)/intersect.c \
								$(DIR_RAYTRACER_INTERSECTION)/intersection.c \
								$(DIR_RAYTRACER_INTERSECTION)/hit.c \
								$(DIR_RAYTRACER_MATERIAL)/color_rgb_i.c \
								$(DIR_RAYTRACER_MATERIAL)/color_rgb_f.c \
								$(DIR_RAYTRACER_MATERIAL)/material.c \
								$(DIR_RAYTRACER_GEOMETRY)/point.c \
								$(DIR_RAYTRACER_GEOMETRY)/vector.c \
								$(DIR_RAYTRACER_GEOMETRY)/sphere.c \
								$(DIR_RAYTRACER_RAY)/ray.c \
								$(DIR_RAYTRACER_RAY)/ray_for_pixel.c \
								$(DIR_RAYTRACER_RAY)/position.c \
								$(DIR_RAYTRACER_TRANSFORMATION)/ray_transform.c \
								$(DIR_RAYTRACER_TRANSFORMATION)/set_transform.c \
								$(DIR_RAYTRACER_TRANSFORMATION)/add_transform.c
SRC_TEST = test.c \
		   test_mat_determinant.c \
		   test_mat_identity.c \
		   test_mat_inversion.c \
		   test_mat_multiplication.c \
		   test_mat_submatrix.c \
		   test_mat_transposition.c \
		   test_vector.c
SRC_MAIN := $(addprefix $(DIR_SRC)/, $(SRC_MAIN))
SRC_TEST := $(addprefix $(DIR_TEST)/, $(SRC_TEST))

# --- Combine all source files ---
SRC = $(SRC_MAIN) $(SRC_GRAPHIC) $(SRC_RAYTRACER)
SRC_TEST_ALL = $(SRC_TEST)

# =============================================================================
# Section : Object files
# =============================================================================

OBJ = $(SRC:.c=.o)
OBJ_TEST = $(SRC_TEST_ALL:.c=.o)

# =============================================================================
# Section : Libraries
# =============================================================================

# --- libft ---
LIBFT_DIR = $(DIR_SRC)/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I $(LIBFT_DIR)
LIBFT_LINK = -L$(LIBFT_DIR) -lft

# --- libla ---
LIBLA_DIR = $(DIR_SRC)/libla
LIBLA_LIB = $(LIBLA_DIR)/libla.a
LIBLA_INC = -I $(LIBLA_DIR)
LIBLA_LINK = -L$(LIBLA_DIR) -lla

# --- mlx ---
MLX_DIR = $(DIR_SRC)/minilibx_opengl
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
test: $(LIB) $(TEST_NAME)

# --- Build the test executable ---
$(TEST_NAME): $(OBJ_TEST)
	@echo "$(COLOR_GREEN)Compiling $(TEST_NAME)...$(COLOR_RESET)"
	$(CC) $(CFLAGS) $(OBJ_TEST) $(LIB_LINK) -o $(TEST_NAME)
	@echo "$(COLOR_GREEN)Compilation of $(TEST_NAME) completed successfully.$(COLOR_RESET)"

# --- Mark rules as phony (not file names) ---
.PHONY: all clean fclean re test