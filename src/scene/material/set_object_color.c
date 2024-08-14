/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:56:50 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 10:59:07 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	set_object_color(t_object *object, t_vec3 color)
{
	object->material = material_from_color(\
		color.data[R], \
		color.data[G], \
		color.data[B]);
}
