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

#include <stdbool.h>
#include <math.h>
#define EPSILON 0.00001f

enum	e_vec4_index
{
	X,
	Y,
	Z,
	W
};

typedef struct s_vec4
{
	float	data[4];
}	t_vec4;

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

bool	equalf(float a, float b);

void	mat_print(void *m, int size);
t_mat3	mat4_submatrix(const t_mat4 *m, int row, int col);
t_mat2	mat3_submatrix(const t_mat3 *m, int row, int col);

bool	equalf(const float a, const float b);
float	mat2_det(t_mat2 *a);
float	mat3_det(t_mat3 *a);
float	mat4_det(t_mat4 *a);
t_mat4	mat4_mat4_mul(const t_mat4 *a, const t_mat4 *b);
t_mat4	mat4_transpose(t_mat4 *a);
t_vec4	mat4_vec4_mul(const t_mat4 *a, const t_vec4 *b);
t_mat4	mat4_inv(t_mat4 *a);
t_mat4	mat4_div(t_mat4 *a, float scalar);
t_mat4	mat4_mul(t_mat4 *a, float scalar);
float	mat4_cofactor(t_mat4 *a, short row, short col);

t_vec4	vec4_add(const t_vec4 *a, const t_vec4 *b);
t_vec4	vec4_div(const t_vec4 *v, const float scalar);
t_vec4	vec4_inv(const t_vec4 *v);
float	vec4_magnitude(const t_vec4 *v);
t_vec4	vec4_mul(const t_vec4 *v, const float scalar);
t_vec4	vec4_normalize(const t_vec4 *v);
t_vec4	vec4_sub(const t_vec4 *a, const t_vec4 *b);

#endif