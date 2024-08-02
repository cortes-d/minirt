NAME = libla.a

# =============================================================================
# Section : Directories
# =============================================================================

DIR_VECTOR = vector
DIR_MATRIX = matrix

# --- Vector directories ---
DIR_VECTOR_EQUALITY = $(DIR_VECTOR)/equality
DIR_VECTOR_ADDITION = $(DIR_VECTOR)/addition
DIR_VECTOR_SUBTRACTION = $(DIR_VECTOR)/subtraction
DIR_VECTOR_MULTIPLICATION = $(DIR_VECTOR)/multiplication
DIR_VECTOR_DIVISION = $(DIR_VECTOR)/division
DIR_VECTOR_INVERSION = $(DIR_VECTOR)/inversion
DIR_VECTOR_MAGNITUDE = $(DIR_VECTOR)/magnitude
DIR_VECTOR_NORMALIZATION = $(DIR_VECTOR)/normalization
DIR_VECTOR_DOT_PRODUCT = $(DIR_VECTOR)/dot_product
DIR_VECTOR_CROSS_PRODUCT = $(DIR_VECTOR)/cross_product

# --- Matrix directories ---
DIR_MATRIX_EQUALITY = $(DIR_MATRIX)/equality
DIR_MATRIX_SUBMATRIX = $(DIR_MATRIX)/submatrix
DIR_MATRIX_DETERMINANT = $(DIR_MATRIX)/determinant
DIR_MATRIX_INVERSION = $(DIR_MATRIX)/inversion
DIR_MATRIX_MINOR = $(DIR_MATRIX)/minor
DIR_MATRIX_COFACTOR = $(DIR_MATRIX)/cofactor
DIR_MATRIX_MULTIPLICATION = $(DIR_MATRIX)/multiplication
DIR_MATRIX_DIVISION = $(DIR_MATRIX)/division
DIR_MATRIX_TRANSPOSE = $(DIR_MATRIX)/transpose

# =============================================================================
# Section : Source files
# =============================================================================

SRC = 	equalf.c \
		$(DIR_VECTOR)/vec_print.c \
		$(DIR_VECTOR_EQUALITY)/vec3_equal.c \
		$(DIR_VECTOR_EQUALITY)/vec4_equal.c \
		$(DIR_VECTOR_ADDITION)/vec3_add.c \
		$(DIR_VECTOR_ADDITION)/vec4_add.c \
		$(DIR_VECTOR_SUBTRACTION)/vec3_sub.c \
		$(DIR_VECTOR_SUBTRACTION)/vec4_sub.c \
		$(DIR_VECTOR_MULTIPLICATION)/vec3_hadamard_product.c \
		$(DIR_VECTOR_MULTIPLICATION)/vec3_mul.c \
		$(DIR_VECTOR_MULTIPLICATION)/vec4_mul.c \
		$(DIR_VECTOR_DIVISION)/vec4_div.c \
		$(DIR_VECTOR_INVERSION)/vec4_inv.c \
		$(DIR_VECTOR_MAGNITUDE)/vec4_magnitude.c \
		$(DIR_VECTOR_NORMALIZATION)/vec4_normalize.c \
		$(DIR_VECTOR_DOT_PRODUCT)/vec4_dot_product.c \
		$(DIR_VECTOR_CROSS_PRODUCT)/vec4h_cross_product.c \
		$(DIR_MATRIX)/mat_print.c \
		$(DIR_MATRIX_EQUALITY)/mat4_equal.c \
		$(DIR_MATRIX_SUBMATRIX)/mat3_submatrix.c \
		$(DIR_MATRIX_SUBMATRIX)/mat4_submatrix.c \
		$(DIR_MATRIX_DETERMINANT)/mat2_det.c \
		$(DIR_MATRIX_DETERMINANT)/mat3_det.c \
		$(DIR_MATRIX_DETERMINANT)/mat4_det.c \
		$(DIR_MATRIX_INVERSION)/mat4_inv.c \
		$(DIR_MATRIX_MINOR)/mat3_minor.c \
		$(DIR_MATRIX_MINOR)/mat4_minor.c \
		$(DIR_MATRIX_COFACTOR)/mat4_cofactor.c \
		$(DIR_MATRIX_MULTIPLICATION)/mat4_mul.c \
		$(DIR_MATRIX_MULTIPLICATION)/mat4_mat4_mul.c \
		$(DIR_MATRIX_MULTIPLICATION)/mat4_vec4_mul.c \
		$(DIR_MATRIX_DIVISION)/mat4_div.c \
		$(DIR_MATRIX_TRANSPOSE)/mat4_transpose.c \

# =============================================================================
# Section : Object files
# =============================================================================

OBJ = $(SRC:.c=.o)

# =============================================================================
# Section : Compiler and flags
# =============================================================================

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I .
AR = ar -rcs
RM = rm -f

# =============================================================================
# Section : Targets
# =============================================================================

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
