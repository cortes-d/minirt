/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:45:31 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 12:59:44 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_object	plane(void)
{
	t_object	object;

	object.type = PLANE;
	object.material = material();
	object.transform = mat4_identity();
	object.transform_inverse = mat4_inv(object.transform);
	object.u_object.plane.p_point = point(0, 0, 0);
	object.u_object.plane.v_normal = vector(0, 1, 0);
	return (object);
}
