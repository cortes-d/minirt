/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:25:18 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/13 14:12:06 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static t_vec4	normal_at_plane(t_object object, t_vec4 world_point)
{
	(void) object;
	(void) world_point;
	return (vector(0, 1, 0));
}

static t_vec4	normal_at_cylinder(t_object object, t_vec4 world_point)
{
	(void) object;
	return (vector(world_point.data[X], 0, world_point.data[Z]));
}

static t_vec4	normal_at_sphere(t_object object, t_vec4 world_point)
{
	t_vec4	object_point;
	t_vec4	object_normal;
	t_vec4	world_normal;

	object_point = mat4_vec4_mul(object.transform_inverse, world_point);
	object_normal = vec4_sub(object_point, point(0, 0, 0));
	world_normal = mat4_vec4_mul(mat4_transpose(object.transform_inverse), \
		object_normal);
	world_normal.data[W] = 0;
	return (vec4_normalize(world_normal));
}

t_vec4	normal_at(t_object object, t_vec4 world_point)
{
	if (object.type == SPHERE)
		return (normal_at_sphere(object, world_point));
	else if (object.type == CYLINDER)
		return (normal_at_cylinder(object, world_point));
	else
		return (normal_at_plane(object, world_point));
}
