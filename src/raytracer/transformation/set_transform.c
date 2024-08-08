/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:08:04 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/08 10:16:25 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	set_transform(t_object *object, t_mat4 transformation)
{
	object->transform = transformation;
	object->transform_inverse = mat4_inv(transformation);
}
