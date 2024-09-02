/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:33:00 by dcortes           #+#    #+#             */
/*   Updated: 2024/09/02 10:13:27 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	add_transform(t_object *object, t_mat4 transformation)
{
	object->transform = mat4_mat4_mul(transformation, object->transform);
	object->transform_inverse = mat4_mat4_mul(object->transform_inverse, \
		mat4_inv(transformation));
}
