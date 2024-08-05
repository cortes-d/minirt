/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:14:28 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/05 16:51:36 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_intersection_pair	intersect(t_ray ray, t_object object)
{
	t_intersection_pair	pair;
	t_vec4				object_to_ray;
	float				a;
	float				b;
	float				c;
	float				discriminant;

	pair.count = 0;
	if (object.type == SPHERE)
	{
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
	}
	return (pair);
}
