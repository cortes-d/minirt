/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:23:20 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/29 11:51:46 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_object	cylinder(t_vec4 p_origin, \
t_vec4 v_axis, float diameter, float height)
{
	t_object	c;
	float		theta_x;
	float		theta_y;
	float		theta_z;

	theta_x = atan2(v_axis.data[Z], v_axis.data[X]);
	theta_y = atan2(v_axis.data[Y], v_axis.data[Z]);
	theta_z = atan2(v_axis.data[X], v_axis.data[Y]);
	c = cylinder_default();
	add_transform(&c, mat4_rotation_x(theta_x));
	add_transform(&c, mat4_rotation_y(theta_y));
	add_transform(&c, mat4_rotation_z(theta_z));
	add_transform(&c, mat4_scaling(diameter / 2, height, diameter / 2));
	add_transform(&c, \
	mat4_translation(p_origin.data[X], p_origin.data[Y], p_origin.data[Z]));
	c.transform_inverse = mat4_inv(c.transform);
	c.u_object.cylinder.p_origin = p_origin;
	c.u_object.cylinder.v_axis = v_axis;
	c.u_object.cylinder.diameter = diameter;
	c.u_object.cylinder.height = height;
	c.u_object.cylinder.minimum = -height / 2;
	c.u_object.cylinder.maximum = height / 2;
	return (c);
}
