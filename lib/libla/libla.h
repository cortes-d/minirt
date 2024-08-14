/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libla.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:19 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/02 14:49:19 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLA_H
# define LIBLA_H

// =============================================================================
// Section : Includes
// =============================================================================

# include <stdbool.h>
# include <math.h>
# include <stdio.h>

// =============================================================================
// Section : Constants and Macros
// =============================================================================

# define W_POINT 1
# define W_VECTOR 0

# define V3_SIZE 3
# define V4_SIZE 4

# define M2_SIZE 2
# define M3_SIZE 3
# define M4_SIZE 4

# define EPSILON 0.001f

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
	float	data[4];
}	t_vec4;

typedef struct s_vec3
{
	float	data[3];
}	t_vec3;

// --- Structure : Matrix ---
typedef struct s_row4
{
	float data[4];
}	t_row4;

typedef struct s_mat4
{
	float	data[4][4];
}	t_mat4;

typedef struct s_mat3
{
	float	data[3][3];
}	t_mat3;

typedef struct s_mat2
{
	float	data[2][2];
}	t_mat2;

// =============================================================================
// Section : General
// =============================================================================

bool	equalf(float a, float b);

// =============================================================================
// Section : Vector
// =============================================================================

// --- Base vector types ---
t_vec4	vec4(float a, float b, float c, float d);
t_vec3	vec3(float a, float b, float c);

// --- Specialized vector types ---
t_vec4	point(float x, float y, float z);
t_vec4	vector(float x, float y, float z);

// --- Specialized vector types : color ---
t_vec3	color_rgb_f(float r, float g, float b);
t_vec3	color_rgb_i(int r, int g, int b);

// --- Conversion ---
t_vec4	vec3_to_vec4(t_vec3 v, float w);

// --- Printer ---
void	vec4_print(t_vec4 v);
void	vec3_print(t_vec3 v);

// --- Equality ---
bool	vec3_equal(t_vec3 v1, t_vec3 v2);
bool	vec4_equal(t_vec4 v1, t_vec4 v2);

// --- Addition ---
t_vec3	vec3_add(t_vec3 a, t_vec3 b);
t_vec4	vec4_add(t_vec4 a, t_vec4 b);

// --- Subtraction ---
t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
t_vec4	vec4_sub(t_vec4 a, t_vec4 b);

// --- Multiplication ---
t_vec3	vec3_hadamard_product(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_mul(t_vec3 v, float scalar);
t_vec4	vec4_mul(t_vec4 v, float scalar);

// --- Division ---
t_vec4	vec4_div(t_vec4 v, float scalar);

// --- Inversion ---
t_vec4	vec4_inv(t_vec4 v);

// --- Magnitude ---
float	vec4_magnitude(t_vec4 v);
float	vec3_magnitude(t_vec3 v);

// --- Normalization ---
t_vec4	vec4_normalize(t_vec4 v);

// --- Dot Product ---
float	vec4_dot_product(t_vec4 v1, t_vec4 v2);

// --- Cross Product ---
t_vec4	vec4h_cross_product(t_vec4 v1, t_vec4 v2);

// =============================================================================
// Section : Matrix
// =============================================================================

t_row4	row4(float a, float b, float c, float d);
t_mat4	mat4(t_row4 a, t_row4 b, t_row4 c, t_row4 d);

// --- Printer ---
void	mat2_print(t_mat2 a);
void	mat3_print(t_mat3 a);
void	mat4_print(t_mat4 a);

// --- Identity ---
t_mat2	mat2_identity(void);
t_mat3	mat3_identity(void);
t_mat4	mat4_identity(void);

// --- Equality ---
bool	mat4_equal(t_mat4 a, t_mat4 b);
bool	mat3_equal(const t_mat3 a, const t_mat3 b);
bool	mat2_equal(const t_mat2 a, const t_mat2 b);

// --- Submatrix ---
t_mat3	mat4_submatrix(t_mat4 m, unsigned short row, unsigned short col);
t_mat2	mat3_submatrix(const t_mat3 m, unsigned short row, unsigned short col);

// --- Determinant ---
float	mat2_det(const t_mat2 a);
float	mat3_det(const t_mat3 a);
float	mat4_det(t_mat4 a);

// --- Inversion ---
t_mat4	mat4_inv(t_mat4 a);

// --- Minor ---
float	mat3_minor(const t_mat3 m, unsigned short row, unsigned short col);
float	mat4_minor(t_mat4 m, unsigned short row, unsigned short col);

// --- Cofactor ---
float	mat4_cofactor(t_mat4 a, unsigned short row, unsigned short col);
float	mat3_cofactor(const t_mat3 a, unsigned short row, unsigned short col);

// --- Multiplication ---
t_mat4	mat4_mul(t_mat4 a, float scalar);
t_mat4	mat4_mat4_mul(t_mat4 a, t_mat4 b);
t_vec4	mat4_vec4_mul(t_mat4 a, t_vec4 b);

// --- Division ---
t_mat4	mat4_div(t_mat4 a, float scalar);

// --- Transpose ---
t_mat4	mat4_transpose(t_mat4 a);

// --- Transformation ---
t_mat4	mat4_translation(float x, float y, float z);
t_mat4	mat4_scaling(float x, float y, float z);
t_mat4	mat4_rotation_x(float r);
t_mat4	mat4_rotation_y(float r);
t_mat4	mat4_rotation_z(float r);

#endif