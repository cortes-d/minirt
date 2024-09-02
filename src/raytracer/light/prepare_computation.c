/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:26:25 by achappui          #+#    #+#             */
/*   Updated: 2024/09/02 12:51:30 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_computation	prepare_computation(t_intersection intersection, \
									t_scene scene, t_ray ray)
{
	t_computation	c;

	c.point = position(ray, intersection.t);
	c.object = intersection.object;
	c.eyev = vec4_inv(ray.v_direction);
	c.lightv = vec4_normalize(vec4_sub(scene.light_point->p_origin, c.point));
	c.normalv = normal_at(intersection.object, c.point);
	c.reflectv = reflect(vec4_inv(c.lightv), c.normalv);
	c.lightv_dot_normalv = vec4_dot_product(c.lightv, c.normalv);
	c.reflectv_dot_eyev = vec4_dot_product(c.reflectv, c.eyev);
	c.point_over = vec4_add(c.point, vec4_mul(c.normalv, EPSILON));
	c.in_shadow = is_shadowed(scene, &c);
	return (c);
}
