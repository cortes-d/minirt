/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_default.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:37:01 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/15 14:37:21 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_object	cylinder_default(void)
{
	t_object	object;

	object.type = CYLINDER;
	object.material = material_default();
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
