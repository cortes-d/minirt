/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:21:55 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/27 10:21:55 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static t_vec4	normal_at_plane(t_object object, t_vec4 world_point)
{
	(void) object;
	(void) world_point;
	return (vector(0, 1, 0));
}

/*static t_vec4	normal_at_plane(t_object object, t_vec4 world_point)
{
    (void) world_point;
    return (vec4_normalize(mat4_vec4_mul(object.transform, object.u_object.plane.v_normal)));
}*/

static t_vec4	normal_at_cylinder(t_object object, t_vec4 world_point)
{
	float	dist;

	dist = world_point.data[X] * world_point.data[X] + \
		world_point.data[Z] * world_point.data[Z];
	if (dist < 1 && world_point.data[Y] >= \
		object.u_object.cylinder.maximum - EPSILON)
		return (vector(0, 1, 0));
	if (dist < 1 && world_point.data[Y] <= \
		object.u_object.cylinder.minimum + EPSILON)
		return (vector(0, -1, 0));
	return (vec4_normalize(vector(world_point.data[X], 0, \
		world_point.data[Z])));
}

static t_vec4	normal_at_sphere(t_object object, t_vec4 object_point)
{
	(void) object;
    return (vec4_sub(object_point, point(0, 0, 0)));
}

t_vec4	normal_at(t_object object, t_vec4 world_point)
{
	t_vec4	object_point;
	t_vec4	object_normal;
	t_vec4	world_normal;

	object_point = mat4_vec4_mul(object.transform_inverse, world_point);
	if (object.type == SPHERE)
		object_normal = normal_at_sphere(object, object_point);
	else if (object.type == CYLINDER)
		object_normal = normal_at_cylinder(object, object_point);
	else
		object_normal = normal_at_plane(object, object_point);
	world_normal = mat4_vec4_mul(mat4_transpose(object.transform_inverse), object_normal);
	world_normal.data[W] = 0;
	return (vec4_normalize(world_normal));
}
