/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:45:31 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/22 13:32:54 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_object	plane_default(void)
{
	t_object	object;

	object.type = PLANE;
	object.material = material_default();
	object.transform = mat4_identity();
	object.transform_inverse = mat4_identity();
	object.u_object.plane.p_point = point(0, 0, 0);
	object.u_object.plane.v_normal = vector(0, 1, 0);
	return (object);
}
