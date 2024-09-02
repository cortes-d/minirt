/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:12:47 by dcortes           #+#    #+#             */
/*   Updated: 2024/09/02 13:07:42 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static int	check_cap(t_ray ray, float t)
{
	float	x;
	float	z;

	x = ray.p_origin.data[X] + t * ray.v_direction.data[X];
	z = ray.p_origin.data[Z] + t * ray.v_direction.data[Z];
	return ((x * x + z * z) <= 1);
}

static void	intersect_caps(t_object *object, t_ray ray, t_list **intersections)
{
	float	t;

	if (!object->u_object.cylinder.closed || equalf(ray.v_direction.data[Y], 0))
		return ;
	t = (object->u_object.cylinder.minimum - ray.p_origin.data[Y]) \
		/ ray.v_direction.data[Y];
	if (check_cap(ray, t))
		intersection_add_to_list(intersections, intersection_create(t, object));
	t = (object->u_object.cylinder.maximum - ray.p_origin.data[Y]) \
		/ ray.v_direction.data[Y];
	if (check_cap(ray, t))
		intersection_add_to_list(intersections, intersection_create(t, object));
}

static float	calculate_discriminant(t_ray ray, \
	t_context_intersect_cylinder *ctx)
{
	ctx->a = ray.v_direction.data[X] * ray.v_direction.data[X] + \
		ray.v_direction.data[Z] * ray.v_direction.data[Z];
	if (equalf(ctx->a, 0))
		return (-1);
	ctx->b = 2 * ray.p_origin.data[X] * ray.v_direction.data[X] + \
		2 * ray.p_origin.data[Z] * ray.v_direction.data[Z];
	ctx->c = ray.p_origin.data[X] * ray.p_origin.data[X] + \
		ray.p_origin.data[Z] * ray.p_origin.data[Z] - 1;
	ctx->discriminant = ctx->b * ctx->b - 4 * ctx->a * ctx->c;
	return (ctx->discriminant);
}

void	intersect_cylinder(t_ray ray, t_object *object, \
	t_list **intersections)
{
	t_context_intersect_cylinder	ctx;

	ctx.pair = init_intersection_pair();
	ctx.discriminant = calculate_discriminant(ray, &ctx);
	if (ctx.discriminant < 0)
		return ;
	ctx.pair.count = 2;
	ctx.pair.t[0] = (-ctx.b - sqrt(ctx.discriminant)) / (2 * ctx.a);
	ctx.pair.t[1] = (-ctx.b + sqrt(ctx.discriminant)) / (2 * ctx.a);
	if (ctx.pair.t[0] > ctx.pair.t[1])
		swap(&ctx.pair.t[0], &ctx.pair.t[1]);
	ctx.y0 = ray.p_origin.data[Y] + ctx.pair.t[0] * ray.v_direction.data[Y];
	if (object->u_object.cylinder.minimum < ctx.y0 && \
		ctx.y0 < object->u_object.cylinder.maximum)
		intersection_add_to_list(intersections, \
			intersection_create(ctx.pair.t[0], object));
	ctx.y1 = ray.p_origin.data[Y] + ctx.pair.t[1] * ray.v_direction.data[Y];
	if (object->u_object.cylinder.minimum < ctx.y1 && \
		ctx.y1 < object->u_object.cylinder.maximum)
		intersection_add_to_list(intersections, \
			intersection_create(ctx.pair.t[1], object));
	intersect_caps(object, ray, intersections);
}
