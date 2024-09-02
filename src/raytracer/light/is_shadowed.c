/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadowed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:34:14 by dcortes           #+#    #+#             */
/*   Updated: 2024/09/02 13:11:33 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

bool	is_shadowed(t_scene scene, t_computation *c)
{
	t_vec4			v;
	t_vec4			direction;
	t_ray			r;
	t_list			*intersections;
	t_intersection	*h;

	intersections = NULL;
	v = vec4_sub(c->point, scene.light_point->p_origin);
	direction = vec4_normalize(v);
	r = ray(scene.light_point->p_origin, direction);
	intersect_scene(r, scene, &intersections);
	h = hit(intersections);
	if (h && c->object != h->object)
	{
		ft_lstclear_plus(&intersections, &gc_free, &gc_free);
		return (1);
	}
	ft_lstclear_plus(&intersections, &gc_free, &gc_free);
	return (0);
}
