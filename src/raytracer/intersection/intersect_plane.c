/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:21:40 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 13:20:47 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	intersect_plane(t_ray ray, t_object *object, \
	t_list **intersections)
{
	t_intersection_pair	pair;

	(void)object;
	pair = init_intersection_pair();
	if (fabs(ray.v_direction.data[Y]) < EPSILON)
		return ;
	pair.count = 1;
	pair.t[0] = -ray.p_origin.data[Y] / ray.v_direction.data[Y];
	//pair.t[1] = pair.t[0];
	intersection_add_to_list(intersections, intersection_create(pair.t[0], object));
	//intersections(list_intersections, intersection(pair.t[1], object));
}

#include "raytracer.h"

/*void intersect_plane(t_ray ray, t_object object, t_list **intersections)
{
	t_ray trans;
	double dot_prod;
	double t;
	t_intersection_pair pair;

	// Transform the ray into the plane's local space
	//trans = ray_transform(ray, object.transform_inverse);

	trans = ray;

	// Calculate the dot product of the plane's normal and the ray's direction
	dot_prod = vec4_dot_product(normal_at(object, trans.p_origin), trans.v_direction);

	// Initialize the intersection pair
	pair = init_intersection_pair();

	// Check if the ray is parallel to the plane
	if (fabs(dot_prod) < EPSILON)
		return;

	// Calculate the intersection point
	t = -trans.p_origin.data[Y] / trans.v_direction.data[Y];

	// Add the intersection if it is in front of the ray
	if (t >= 0)
	{
		pair.count = 1;
		pair.t[0] = t;
		intersection_add_to_list(intersections, intersection_create(pair.t[0], object));
	}
}*/