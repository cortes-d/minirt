/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:12:47 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/14 10:32:48 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "raytracer.h"

void	intersect_cylinder(t_ray ray, t_object object, \
	t_list **intersections)
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
		intersection_add_to_list(intersections, \
			intersection_create(pair.t[0], object));
	y1 = ray.p_origin.data[Y] + pair.t[1] * ray.v_direction.data[Y];
	if (object.u_object.cylinder.minimum < y1 && \
		y1 < object.u_object.cylinder.maximum)
		intersection_add_to_list(intersections, \
			intersection_create(pair.t[0], object));
}
