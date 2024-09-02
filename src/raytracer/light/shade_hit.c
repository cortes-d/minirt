/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:44:48 by dcortes           #+#    #+#             */
/*   Updated: 2024/09/02 13:11:11 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_vec3	shade_hit(t_scene scene, t_computation comps)
{
	return (lighting(\
		comps, \
		*scene.light_point, \
		*scene.light_ambient, \
		comps.object->material) \
		);
}
