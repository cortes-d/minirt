/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:26:58 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/10 15:26:58 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	set_transform(t_object *object, t_mat4 transformation)
{
	object->transform = transformation;
	object->transform_inverse = mat4_inv(transformation);
}
