/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:39:02 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/13 16:03:19 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "util.h"
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
static void	intersect_sphere(t_ray ray, t_object object, \
	t_list **list_intersections)
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
		intersections(list_intersections, intersection(pair.t[0], object));
		intersections(list_intersections, intersection(pair.t[1], object));
	}
}

static void	intersect_cylinder(t_ray ray, t_object object, \
	t_list **list_intersections)
{
	float				a;
	float				b;
	float				c;
	float				discriminant;
	t_intersection_pair	pair;
	float				y0;
	float				y1;

	(void)object;
	pair = init_intersection_pair();
	a = ray.v_direction.data[X] * ray.v_direction.data[X] + \
		ray.v_direction.data[Z] * ray.v_direction.data[Z];
	if (equalf(a, 0))
		return ;
	b = 2 * ray.p_origin.data[X] * ray.v_direction.data[X] + \
		2 * ray.p_origin.data[Z] * ray.v_direction.data[Z];
	c = ray.p_origin.data[X] * ray.p_origin.data[X] + \
		ray.p_origin.data[Z] * ray.p_origin.data[Z] - 1;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return ;
	pair.count = 2;
	pair.t[0] = (-b - sqrt(discriminant) / (2 * a));
	pair.t[1] = (-b + sqrt(discriminant) / (2 * a));
	if (pair.t[0] > pair.t[1])
		swap(&pair.t[0], &pair.t[1]);
	y0 = ray.p_origin.data[Y] + pair.t[0] * ray.v_direction.data[Y];
	if (object.u_object.cylinder.minimum < y0 && \
		y0 < object.u_object.cylinder.maximum)
		intersections(list_intersections, intersection(pair.t[0], object));
	y1 = ray.p_origin.data[Y] + pair.t[1] * ray.v_direction.data[Y];
	if (object.u_object.cylinder.minimum < y1 && \
		y1 < object.u_object.cylinder.maximum)
		intersections(list_intersections, intersection(pair.t[0], object));
}


static void	intersect_plane(t_ray ray, t_object object, \
	t_list **list_intersections)
{
	t_intersection_pair	pair;

	(void)object;
	pair = init_intersection_pair();
	if (fabs(ray.v_direction.data[Y]) < EPSILON)
		return ;
	pair.count = 1;
	pair.t[0] = -ray.p_origin.data[Y] / ray.v_direction.data[Y];
	//pair.t[1] = pair.t[0];
	intersections(list_intersections, intersection(pair.t[0], object));
	//intersections(list_intersections, intersection(pair.t[1], object));
}

void	intersect(t_ray ray, t_object object, \
	t_list **list_intersections)
{
	t_ray				ray_transformed;

	ray_transformed = ray_transform(ray, mat4_inv(object.transform));
	if (object.type == SPHERE)
		return (intersect_sphere(ray_transformed, object, list_intersections));
	else if (object.type == CYLINDER)
		return (intersect_cylinder(ray, object, list_intersections));
	else
		return (intersect_plane(ray, object, list_intersections));
}
