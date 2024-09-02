/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:32:50 by dcortes           #+#    #+#             */
/*   Updated: 2024/09/02 10:12:43 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_light_point	light_point(t_vec4 position, float ratio, t_vec3 color)
{
	t_light_point	new_light_point;

	new_light_point.p_origin = position;
	new_light_point.ratio = ratio;
	new_light_point.color = color;
	return (new_light_point);
}
