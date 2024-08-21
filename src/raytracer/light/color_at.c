/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:20:48 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/21 12:53:35 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "raytracer.h"
#include "graphic.h"
#include "libgc.h"


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
	color = shade_hit(scene, comps);
	ft_lstclear_plus(&intersections, &gc_free, &gc_free);
	return (color);
}
