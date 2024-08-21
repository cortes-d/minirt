/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:26:25 by achappui          #+#    #+#             */
/*   Updated: 2024/08/21 13:54:06 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "raytracer.h"

t_computation	prepare_computation(t_intersection intersection, \
	t_ray ray, t_light_point lp)
{
	t_computation	c;

	c.point = position(ray, intersection.t);
	c.object = intersection.object;
	c.eyev = vec4_inv(ray.v_direction);
	c.lightv = vec4_normalize(vec4_sub(lp.p_origin, c.point));
	c.normalv = normal_at(intersection.object, c.point);
	c.reflectv = reflect(vec4_inv(c.lightv), c.normalv);
	c.lightv_dot_normalv = vec4_dot_product(c.lightv, c.normalv);
	c.reflectv_dot_eyev = vec4_dot_product(c.reflectv, c.eyev);
	c.point_over = vec4_add(c.point, vec4_mul(c.normalv, EPSILON));
	return (c);
}
