/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:16:29 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/27 10:22:20 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_object plane(t_vec4 p_point, t_vec4 v_normal)
{
	t_object object;
	float theta_x;
	float theta_z;

	object = plane_default();
	//object.u_object.plane.v_normal = v_normal;
	//object.u_object.plane.p_point = p_point;
	theta_z = atan2f(v_normal.data[X], v_normal.data[Y]);
	theta_x = atan2f(v_normal.data[Z], sqrtf(v_normal.data[X] * v_normal.data[X] + v_normal.data[Y] * v_normal.data[Y]));
	add_transform(&object, mat4_rotation_z(theta_z));
	add_transform(&object, mat4_rotation_x(theta_x));
	add_transform(&object, mat4_translation(p_point.data[X], p_point.data[Y], p_point.data[Z]));
	return (object);
}