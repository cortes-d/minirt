/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:18:35 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/10 14:18:35 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_object	sphere(void)
{
	t_object	object;

	object.type = SPHERE;
	object.material = material();
	object.transform = mat4_identity();
	object.transform_inverse = mat4_inv(object.transform);
	object.u_object.sphere.p_origin = point(0, 0, 0);
	object.u_object.sphere.radius = 1;
	return (object);
}

/*t_object	sphere(t_vec4 p_origin, float radius)
{
	t_object	object;

	object.type = SPHERE;
	object.material = material();
	object.transform = mat4_identity();
	object.u_object.sphere.p_origin = p_origin;
	object.u_object.sphere.radius = radius;
	return (object);
}*/
