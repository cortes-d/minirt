/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:20:48 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/21 13:11:14 by dcortes          ###   ########.fr       */
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
	color = shade_hit(scene, comps, &intersections);
	ft_lstclear_plus(&intersections, &gc_free, &gc_free);
	return (color);
}
