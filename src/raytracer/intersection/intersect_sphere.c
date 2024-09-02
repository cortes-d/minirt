/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:12:30 by dcortes           #+#    #+#             */
/*   Updated: 2024/09/02 13:07:47 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	intersect_sphere(t_ray ray, t_object *object, \
	t_list **intersections)
{
	t_context_intersect_sphere	ctx;

	ctx.pair = init_intersection_pair();
	ctx.object_to_ray = vec4_sub(ray.p_origin, point(0, 0, 0));
	ctx.a = vec4_dot_product(ray.v_direction, ray.v_direction);
	ctx.b = 2 * vec4_dot_product(ray.v_direction, ctx.object_to_ray);
	ctx.c = vec4_dot_product(ctx.object_to_ray, ctx.object_to_ray) - 1;
	ctx.discriminant = (ctx.b * ctx.b) - 4 * ctx.a * ctx.c;
	if (ctx.discriminant >= 0)
	{
		ctx.pair.count = 2;
		if (ctx.discriminant == 0)
			ctx.pair.count = 1;
		ctx.pair.t[0] = (-ctx.b - sqrt(ctx.discriminant)) / (2 * ctx.a);
		ctx.pair.t[1] = (-ctx.b + sqrt(ctx.discriminant)) / (2 * ctx.a);
		intersection_add_to_list(intersections, \
			intersection_create(ctx.pair.t[0], object));
		intersection_add_to_list(intersections, \
			intersection_create(ctx.pair.t[1], object));
	}
}
