/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:49:17 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/21 12:23:16 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_object	sphere(t_vec4 p_origin, float radius)
{
	t_object	s;

	s = sphere_default();
	add_transform(&s, mat4_translation(p_origin.data[X], p_origin.data[Y], p_origin.data[Z]));
	add_transform(&s, mat4_scaling(radius, radius, radius));
	s.u_object.sphere.p_origin = p_origin;
	s.u_object.sphere.radius = radius;
	return (s);
}
