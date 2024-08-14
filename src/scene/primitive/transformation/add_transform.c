/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 09:53:16 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 09:55:08 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	add_transform(t_object *object, t_mat4 transformation)
{
	object->transform = mat4_mat4_mul(transformation, object->transform);
	object->transform_inverse = mat4_inv(transformation);
}
