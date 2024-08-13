/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:39:02 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/13 14:17:52 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#define NO_INTERSECTION -1

static t_intersection_pair	init_intersection_pair(void)
{
	t_intersection_pair	pair;

	pair.count = 0;
	pair.t[0] = NO_INTERSECTION;
	pair.t[1] = NO_INTERSECTION;
	return (pair);
}

/*
 * Finds the intersection(s) between a ray and an object.
 * The intersection is a t-value 
 * that represents a position parameter on the ray vector.
 * There can be 0, 1 or 2 intersections.
 */
static t_intersection_pair	intersect_sphere(t_ray ray, t_object object)
{
	t_intersection_pair	pair;
	t_vec4				object_to_ray;
	float				a;
	float				b;
	float				c;
	float				discriminant;

	(void)object;
	pair = init_intersection_pair();
	object_to_ray = vec4_sub(ray.p_origin, point(0, 0, 0));
	a = vec4_dot_product(ray.v_direction, ray.v_direction);
	b = 2 * vec4_dot_product(ray.v_direction, object_to_ray);
	c = vec4_dot_product(object_to_ray, object_to_ray) - 1;
	discriminant = (b * b) - 4 * a * c;
	if (discriminant >= 0)
	{
		pair.count = 2;
		if (discriminant == 0)
			pair.count = 1;
		pair.t[0] = (-b - sqrt(discriminant)) / (2 * a);
		pair.t[1] = (-b + sqrt(discriminant)) / (2 * a);
	}
	return (pair);
}

static	t_intersection_pair	intersect_cylinder(t_ray ray, t_object object)
{
	float				a;
	float				b;
	float				c;
	float				discriminant;
	t_intersection_pair	pair;

	(void)object;
	pair = init_intersection_pair();
	a = ray.v_direction.data[X] * ray.v_direction.data[X] + \
		ray.v_direction.data[Z] * ray.v_direction.data[Z];
	if (equalf(a, 0))
		return (pair);
	b = 2 * ray.p_origin.data[X] * ray.v_direction.data[X] + \
		2 * ray.p_origin.data[Z] * ray.v_direction.data[Z];
	c = ray.p_origin.data[X] * ray.p_origin.data[X] + \
		ray.p_origin.data[Z] * ray.p_origin.data[Z] - 1;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (pair);
	pair.count = 2;
	pair.t[0] = (-b - sqrt(discriminant) / (2 * a));
	pair.t[1] = (-b + sqrt(discriminant) / (2 * a));
	return (pair);
}


static	t_intersection_pair	intersect_plane(t_ray ray, t_object object)
{
	t_intersection_pair	pair;

	(void)object;
	pair = init_intersection_pair();
	if (fabs(ray.v_direction.data[Y]) < EPSILON)
		return (pair);
	pair.count = 1;
	pair.t[0] = -ray.p_origin.data[Y] / ray.v_direction.data[Y];
	pair.t[1] = pair.t[0];
	return (pair);
}

t_intersection_pair	intersect(t_ray ray, t_object object)
{
	t_ray				ray_transformed;

	ray_transformed = ray_transform(ray, mat4_inv(object.transform));

	if (object.type == SPHERE)
		return (intersect_sphere(ray_transformed, object));
	else if (object.type == CYLINDER)
		return (intersect_cylinder(ray, object));
	else
		return (intersect_plane(ray, object));
}
