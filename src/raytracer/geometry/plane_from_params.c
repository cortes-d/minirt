/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_from_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:03:06 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 13:08:23 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_object	plane_from_params(t_vec4 p_point, t_vec4 v_normal)
{
	t_object	p;
	float		theta_x;
	float		theta_y;
	float		theta_z;

	theta_x = atan2(v_normal.data[Z], v_normal.data[Y]);
	theta_y = atan2(v_normal.data[X], v_normal.data[Z]);
	theta_z = atan2(v_normal.data[Y], v_normal.data[X]);
	p = plane();
	add_transform(&p, mat4_rotation_x(theta_x));
	add_transform(&p, mat4_rotation_y(theta_y));
	add_transform(&p, mat4_rotation_z(theta_z));
	add_transform(&p, mat4_translation(\
		p_point.data[X], \
		p_point.data[Y], \
		p_point.data[Z]));
	return (p);
}
