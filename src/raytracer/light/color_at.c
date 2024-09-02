/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:33:46 by dcortes           #+#    #+#             */
/*   Updated: 2024/09/02 10:12:08 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_vec3	color_at(t_ray ray, t_scene scene)
{
	t_list			*intersections;
	t_intersection	*hitting;
	t_computation	comps;
	t_vec3			color;

	intersections = NULL;
	intersect_scene(ray, scene, &intersections);
	hitting = hit(intersections);
	if (!hitting)
		return (vec3(0, 0, 0));
	comps = prepare_computation(*hitting, ray, *scene.light_point);
	ft_lstclear_plus(&intersections, &gc_free, &gc_free);
	intersections = NULL;
	color = shade_hit(scene, comps);
	return (color);
}
