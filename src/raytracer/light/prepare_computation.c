/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:26:25 by achappui          #+#    #+#             */
/*   Updated: 2024/08/16 15:21:25 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_prepare_computation	prepare_computation(t_intersection intersection, t_ray ray, t_light_point lp)
{
	t_prepare_computation	pc;
	t_vec4					hit_point;

	hit_point = position(ray, intersection.t);
	pc.eyev = vec4_inv(ray.v_direction);
	pc.lightv = vec4_normalize(vec4_sub(lp.p_origin, hit_point));
	pc.normalv = normal_at(intersection.object, hit_point);
	pc.reflectv = reflect(vec4_inv(pc.lightv), pc.normalv);
	pc.lightv_dot_normalv = vec4_dot_product(pc.lightv, pc.normalv);
	pc.reflectv_dot_eyev = vec4_dot_product(pc.reflectv, pc.eyev);
	return (pc);
}