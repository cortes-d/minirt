/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:32:27 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/08 10:35:55 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_light_point	light_point(t_vec4 position, t_vec3 color)
{
	t_light_point	light;

	light.p_origin = position;
	light.color = color;
	return (light);
}

