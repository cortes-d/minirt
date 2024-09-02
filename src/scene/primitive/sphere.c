/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:25:51 by dcortes           #+#    #+#             */
/*   Updated: 2024/09/02 10:13:45 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_object	sphere(t_vec4 p_origin, float radius)
{
	t_object	s;

	s = sphere_default();
	add_transform(&s, mat4_scaling(radius, radius, radius));
	add_transform(&s, \
		mat4_translation(p_origin.data[X], p_origin.data[Y], p_origin.data[Z]));
	s.transform_inverse = mat4_inv(s.transform);
	s.u_object.sphere.p_origin = p_origin;
	s.u_object.sphere.radius = radius;
	return (s);
}
