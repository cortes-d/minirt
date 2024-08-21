/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:44:48 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/21 13:03:59 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_vec3	shade_hit(t_scene scene, t_computation comps, t_list **intersections)
{
	return (lighting(\
		comps, \
		*scene.light_point, \
		*scene.light_ambient, \
		comps.object.material, \
		is_shadowed(scene, comps.point_over, intersections) \
	));
}
