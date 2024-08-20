/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:20:48 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/20 15:45:26 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "graphic.h"


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
	ft_lstclear(&intersections, free);
	return (color);
}
