/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:44:48 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 13:22:45 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_vec3	shade_hit(t_scene scene, t_computation comps)
{
	return (lighting(\
		comps, \
		*scene.light_point, \
		*scene.light_ambient, \
		comps.object->material, \
		is_shadowed(scene, &comps) \
	));
}
