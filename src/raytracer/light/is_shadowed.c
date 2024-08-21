/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadowed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:28:26 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/21 13:14:39 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "raytracer.h"

int	is_shadowed(t_scene scene, t_vec4 point, t_list **intersections)
{
	t_vec4			v;
	float			distance;
	t_vec4			direction;
	t_ray			r;
	t_intersection	*h;

	v = vec4_sub(scene.light_point->p_origin, point);
	distance = vec4_magnitude(v);
	direction = vec4_normalize(v);
	r = ray(point, direction);
	intersect_scene(r, scene, intersections);
	h = hit(*intersections);
	if (h && h->t < distance)
		return (1);
	return (0);
}
