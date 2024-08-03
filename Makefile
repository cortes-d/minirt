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

# =============================================================================
# Section : Compiler and flags
# =============================================================================

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(DIR_INC)
RM = rm -f

# =============================================================================
# Section : Source files
# =============================================================================

SRC_MAIN = minirt.c
SRC_TEST = test.c \
		   test_mat_submatrix.c \
		   test_vector.c
SRC_MAIN := $(addprefix $(DIR_SRC)/, $(SRC_MAIN))
SRC_TEST := $(addprefix $(DIR_TEST)/, $(SRC_TEST))

# --- Combine all source files ---
SRC = $(SRC_MAIN)
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