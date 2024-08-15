/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:37:01 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/15 08:54:55 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_object	cylinder(void)
{
	t_object	object;

	object.type = CYLINDER;
	object.material = material();
	object.transform = mat4_identity();
	object.transform_inverse = mat4_inv(object.transform);
	object.u_object.cylinder.p_origin = point(0, 0, 0);
	object.u_object.cylinder.v_axis = vector(0, 1, 0);
	object.u_object.cylinder.height = 1;
	object.u_object.cylinder.diameter = 1;
	object.u_object.cylinder.minimum = __FLT_MIN__;
	object.u_object.cylinder.maximum = __FLT_MAX__;
	object.u_object.cylinder.closed = 1;
	return (object);
}
