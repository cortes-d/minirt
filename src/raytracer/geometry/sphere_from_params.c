/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_from_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:49:17 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 10:51:01 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_object	sphere_from_params(t_vec4 p_origin, float radius)
{
	t_object	s;

	s = sphere();
	add_transform(&s, mat4_translation(\
		p_origin.data[X], \
		p_origin.data[Y], \
		p_origin.data[Z]));
	add_transform(&s, mat4_scaling(radius, radius, radius));
	return (s);
}
