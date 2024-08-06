/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:14:28 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/06 11:15:55 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

/*
 * Finds the intersection(s) between a ray and an object.
 * The intersection is a t-value 
 * that represents a position parameter on the ray vector.
 * There can be 0, 1 or 2 intersections.
 */
t_intersection_pair	intersect(t_ray ray, t_object object)
{
	t_intersection_pair	pair;
	t_vec4				object_to_ray;
	float				a;
	float				b;
	float				c;
	float				discriminant;
	t_ray				ray_transformed;

	ray_transformed = transform(ray, mat4_inv(object.transform));
	pair.count = 0;
	if (object.type == SPHERE)
	{
		object_to_ray = vec4_sub(ray_transformed.p_origin, point(0, 0, 0));
		a = vec4_dot_product(ray_transformed.v_direction, ray_transformed.v_direction);
		b = 2 * vec4_dot_product(ray_transformed.v_direction, object_to_ray);
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
	}
	return (pair);
}
