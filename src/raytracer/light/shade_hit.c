/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:44:48 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/20 13:59:58 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_vec3	shade_hit(t_scene scene, t_computation comps)
{
	return (lighting(\
		comps, \
		*scene.light_point, \
		*scene.light_ambient, \
		comps.object.material));
}
