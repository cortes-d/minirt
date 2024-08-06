/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:38:31 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/06 12:56:04 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_object	sphere(void)
{
	t_object	object;

	object.type = SPHERE;
	object.material = material(color(0.8, 0.8, 0.8), 0.5, 0.5, 0.5);
	object.transform = mat4_identity();
	object.u_object.sphere.p_origin = point(0, 0, 0);
	object.u_object.sphere.radius = 1;
	return (object);
}

/*t_object	sphere(t_vec4 p_origin, float radius)
{
	t_object	object;

	object.type = SPHERE;
	object.material = material(color(0.8, 0.8, 0.8), 0.5, 0.5, 0.5);
	object.transform = mat4_identity();
	object.u_object.sphere.p_origin = p_origin;
	object.u_object.sphere.radius = radius;
	return (object);
}*/
