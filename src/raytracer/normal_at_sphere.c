/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:39:54 by achappui          #+#    #+#             */
/*   Updated: 2024/08/07 14:14:15 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_vec4    normal_at_sphere(t_object object, t_vec4 world_point)
{
	t_vec4	object_point;
	t_vec4	normal;
	t_vec4	object_normal;
	t_vec4	world_normal;
	
	object_point = mat4_vec4_mul(mat4_inv(object.transform), world_point);
	object_normal = vec4_sub(object_point, point(0, 0, 0));
	world_normal = mat4_vec4_mul(mat4_transpose(mat4_inv(object.transform)), object_normal);
	world_normal.data[W] = 0;
	return (vec4_normalize(world_normal));
}