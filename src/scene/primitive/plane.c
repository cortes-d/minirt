/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:26:00 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/29 11:51:53 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_object	plane(t_vec4 p_point, t_vec4 v_normal)
{
	t_object	object;
	float		theta_x;
	float		theta_z;

	object = plane_default();
	theta_z = atan2f(v_normal.data[X], v_normal.data[Y]);
	theta_x = atan2f(v_normal.data[Z], \
		sqrtf(v_normal.data[X] * v_normal.data[X] + \
		v_normal.data[Y] * v_normal.data[Y]));
	add_transform(&object, mat4_rotation_z(theta_z));
	add_transform(&object, mat4_rotation_x(theta_x));
	add_transform(&object, \
		mat4_translation(p_point.data[X], p_point.data[Y], p_point.data[Z]));
	return (object);
}
