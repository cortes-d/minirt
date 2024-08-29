/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:33:22 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/29 08:33:26 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_mat4	view_transform(t_vec4 p_origin, t_vec4 forward, t_vec4 up)
{
	t_mat4	view_transform_matrix;
	t_vec4	upn;
	t_vec4	left;
	t_vec4	true_up;

	upn = vec4_normalize(up);
	left = vec4h_cross_product(forward, upn);
	true_up = vec4h_cross_product(left, forward);
	view_transform_matrix = mat4(\
			row4(left.data[X], left.data[Y], left.data[Z], 0), \
			row4(true_up.data[X], true_up.data[Y], true_up.data[Z], 0), \
			row4(-forward.data[X], -forward.data[Y], -forward.data[Z], 0), \
			row4(0, 0, 0, 1));
	return (mat4_mat4_mul(view_transform_matrix, \
	mat4_translation(-p_origin.data[X], -p_origin.data[Y], -p_origin.data[Z])));
}
