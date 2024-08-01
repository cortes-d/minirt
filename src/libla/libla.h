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