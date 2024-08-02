/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libla.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:55:30 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/01 09:55:30 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLA_H
# define LIBLA_H

# include <stdbool.h>
# include <math.h>

// =============================================================================
// Section : Constants and Macros
// =============================================================================

# define V3_SIZE 3
# define V4_SIZE 4

# define M2_SIZE 2
# define M3_SIZE 3
# define M4_SIZE 4

# define EPSILON 0.00001f

// =============================================================================
// Section : Type Definitions
// =============================================================================

// --- Enum ---
enum	e_vec3_index
{
	R,
	G,
	B
};

enum	e_vec4_index
{
	X,
	Y,
	Z,
	W
};

// --- Structure : Vector ---
typedef struct s_vec4
{
	double	data[4];
}	t_vec4;

typedef struct s_vec3
{
	double	data[3];
}	t_vec3;

// --- Structure : Matrix ---
typedef struct s_mat4
{
	double	data[4][4];
}	t_mat4;

typedef struct s_mat3
{
	double	data[3][3];
}	t_mat3;

typedef struct s_mat2
{
	double	data[2][2];
}	t_mat2;

// =============================================================================
// Section : General
// =============================================================================

bool	equalf(double a, double b);

// =============================================================================
// Section : Vector
// =============================================================================

void	vec_print(const void *v, short size);

// --- Equality ---
bool	vec3_equal(const t_vec3 *v1, const t_vec3 *v2);
bool	vec4_equal(const t_vec4 *v1, const t_vec4 *v2);

// --- Addition ---
t_vec3	vec3_add(const t_vec3 *a, const t_vec3 *b);
t_vec4	vec4_add(const t_vec4 *a, const t_vec4 *b);

// --- Subtraction ---
t_vec3	vec3_sub(const t_vec3 *a, const t_vec3 *b);
t_vec4	vec4_sub(const t_vec4 *a, const t_vec4 *b);

// --- Multiplication ---
t_vec3	vec3_hadamard_product(const t_vec3 *v1, const t_vec3 *v2);
t_vec3	vec3_mul(const t_vec3 *v, double scalar);
t_vec4	vec4_mul(const t_vec4 *v, double scalar);

// --- Division ---
t_vec4	vec4_div(const t_vec4 *v, double scalar);

// --- Inversion ---
t_vec4	vec4_inv(const t_vec4 *v);

// --- Magnitude ---
double	vec4_magnitude(const t_vec4 *v);

// --- Normalization ---
t_vec4	vec4_normalize(const t_vec4 *v);

// --- Dot Product ---
double	vec4_dot_product(const t_vec4 *v1, const t_vec4 *v2);

// --- Cross Product ---
t_vec4	vec4h_cross_product(const t_vec4 *v1, const t_vec4 *v2);

// =============================================================================
// Section : Matrix
// =============================================================================

void	mat_print(const void *m, short size);

// --- Equality ---
bool	mat4_equal(const t_mat4 *a, const t_mat4 *b);
bool	mat3_equal(const t_mat3 *a, const t_mat3 *b);
bool	mat2_equal(const t_mat2 *a, const t_mat2 *b);

// --- Submatrix ---
t_mat3	mat4_submatrix(const t_mat4 *m, short row, short col);
t_mat2	mat3_submatrix(const t_mat3 *m, short row, short col);

// --- Determinant ---
double	mat2_det(const t_mat2 *a);
double	mat3_det(const t_mat3 *a);
double	mat4_det(const t_mat4 *a);

// --- Inversion ---
t_mat4	mat4_inv(const t_mat4 *a);

// --- Minor ---
double	mat3_minor(const t_mat3 *m, short row, short col);
double	mat4_minor(const t_mat4 *m, short row, short col);

// --- Cofactor ---
double	mat4_cofactor(const t_mat4 *a, short row, short col);
double	mat3_cofactor(const t_mat3 *a, short row, short col);

// --- Multiplication ---
t_mat4	mat4_mul(const t_mat4 *a, double scalar);
t_mat4	mat4_mat4_mul(const t_mat4 *a, const t_mat4 *b);
t_vec4	mat4_vec4_mul(const t_mat4 *a, const t_vec4 *b);

// --- Division ---
t_mat4	mat4_div(const t_mat4 *a, double scalar);

// --- Transpose ---
t_mat4	mat4_transpose(const t_mat4 *a);

#endif