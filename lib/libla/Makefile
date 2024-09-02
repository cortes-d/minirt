NAME = libla.a

# =============================================================================
# Section : Directories
# =============================================================================

DIR_VECTOR = vector
DIR_MATRIX = matrix

# =============================================================================
# Section : Source files
# =============================================================================

SRC =	equalf.c \
		$(DIR_VECTOR)/addition/vec3_add.c \
		$(DIR_VECTOR)/addition/vec4_add.c \
		$(DIR_VECTOR)/conversion/vec3_to_vec4.c \
		$(DIR_VECTOR)/cross_product/vec4h_cross_product.c \
		$(DIR_VECTOR)/division/vec4_div.c \
		$(DIR_VECTOR)/dot_product/vec4_dot_product.c \
		$(DIR_VECTOR)/equality/vec3_equal.c \
		$(DIR_VECTOR)/equality/vec4_equal.c \
		$(DIR_VECTOR)/inversion/vec4_inv.c \
		$(DIR_VECTOR)/magnitude/vec3_magnitude.c \
		$(DIR_VECTOR)/magnitude/vec4_magnitude.c \
		$(DIR_VECTOR)/multiplication/vec3_hadamard_product.c \
		$(DIR_VECTOR)/multiplication/vec3_mul.c \
		$(DIR_VECTOR)/multiplication/vec4_mul.c \
		$(DIR_VECTOR)/normalization/vec4_normalize.c \
		$(DIR_VECTOR)/printer/vec3_print.c \
		$(DIR_VECTOR)/printer/vec4_print.c \
		$(DIR_VECTOR)/subtraction/vec3_sub.c \
		$(DIR_VECTOR)/subtraction/vec4_sub.c \
		$(DIR_VECTOR)/clamping/vec3_clamp.c \
		$(DIR_VECTOR)/type/vector.c \
		$(DIR_VECTOR)/type/point.c \
		$(DIR_VECTOR)/type/color_rgb_f.c \
		$(DIR_VECTOR)/type/color_rgb_i.c \
		$(DIR_VECTOR)/type/color_mix.c \
		$(DIR_VECTOR)/vec3.c \
		$(DIR_VECTOR)/vec4.c \
		$(DIR_MATRIX)/cofactor/mat3_cofactor.c \
		$(DIR_MATRIX)/cofactor/mat4_cofactor.c \
		$(DIR_MATRIX)/determinant/mat2_det.c \
		$(DIR_MATRIX)/determinant/mat3_det.c \
		$(DIR_MATRIX)/determinant/mat4_det.c \
		$(DIR_MATRIX)/division/mat4_div.c \
		$(DIR_MATRIX)/equality/mat2_equal.c \
		$(DIR_MATRIX)/equality/mat3_equal.c \
		$(DIR_MATRIX)/equality/mat4_equal.c \
		$(DIR_MATRIX)/identity/mat2_identity.c \
		$(DIR_MATRIX)/identity/mat3_identity.c \
		$(DIR_MATRIX)/identity/mat4_identity.c \
		$(DIR_MATRIX)/inversion/mat4_inv.c \
		$(DIR_MATRIX)/mat4.c \
		$(DIR_MATRIX)/minor/mat3_minor.c \
		$(DIR_MATRIX)/minor/mat4_minor.c \
		$(DIR_MATRIX)/multiplication/mat4_mat4_mul.c \
		$(DIR_MATRIX)/multiplication/mat4_mul.c \
		$(DIR_MATRIX)/multiplication/mat4_vec4_mul.c \
		$(DIR_MATRIX)/printer/mat2_print.c \
		$(DIR_MATRIX)/printer/mat3_print.c \
		$(DIR_MATRIX)/printer/mat4_print.c \
		$(DIR_MATRIX)/row4.c \
		$(DIR_MATRIX)/submatrix/mat3_submatrix.c \
		$(DIR_MATRIX)/submatrix/mat4_submatrix.c \
		$(DIR_MATRIX)/transformation/mat4_rotation_x.c \
		$(DIR_MATRIX)/transformation/mat4_rotation_y.c \
		$(DIR_MATRIX)/transformation/mat4_rotation_z.c \
		$(DIR_MATRIX)/transformation/mat4_scaling.c \
		$(DIR_MATRIX)/transformation/mat4_translation.c \
		$(DIR_MATRIX)/transpose/mat4_transpose.c

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
