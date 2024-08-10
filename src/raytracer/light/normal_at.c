/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:15:11 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/10 14:15:11 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

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
	//if (object.type == SPHERE)
	return (normal_at_sphere(object, world_point));
}
