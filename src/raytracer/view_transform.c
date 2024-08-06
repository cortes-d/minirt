/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:25:26 by achappui          #+#    #+#             */
/*   Updated: 2024/08/06 10:26:24 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_mat4	view_transform(t_vec4 p_origin, t_vec4 forward, t_vec4 up)
{
	t_mat4	view_transform_matrix;
	t_vec4	upn;
	t_vec4	left;
	t_vec4	true_up;

	view_transform_matrix = mat4_identity();
	upn = vec4_normalize(up);
	left = vec4h_cross_product(forward, upn);
	true_up = vec4h_cross_product(left, forward);
	view_transform_matrix.data[0][0] = left.data[X];
	view_transform_matrix.data[0][1] = left.data[Y];
	view_transform_matrix.data[0][2] = left.data[Z];
	view_transform_matrix.data[1][0] = true_up.data[X];
	view_transform_matrix.data[1][1] = true_up.data[Y];
	view_transform_matrix.data[1][2] = true_up.data[Z];
	view_transform_matrix.data[2][0] = -forward.data[X];
	view_transform_matrix.data[2][1] = -forward.data[Y];
	view_transform_matrix.data[2][2] = -forward.data[Z];
	// view_transform_matrix.data[0][3] = -p_origin.data[X];
	// view_transform_matrix.data[1][3] = -p_origin.data[Y];
	// view_transform_matrix.data[2][3] = -p_origin.data[Z];
	//return (view_transform_matrix);
	return (mat4_mat4_mul(view_transform_matrix, \
	mat4_translation(-p_origin.data[X], -p_origin.data[Y], -p_origin.data[Z])));
}