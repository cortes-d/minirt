/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:13:17 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/14 10:33:29 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	intersect_plane(t_ray ray, t_object object, \
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