/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:38:31 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/07 15:41:45 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_object	sphere(void)
{
	t_object	object;

	object.type = SPHERE;
	object.material = material(color(0.8, 0.8, 0.8), 0.1, 0.9, 0.9, 200);
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
