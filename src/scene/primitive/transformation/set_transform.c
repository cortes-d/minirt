/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:26:58 by dcortes           #+#    #+#             */
/*   Updated: 2024/09/02 10:13:30 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	set_transform(t_object *object, t_mat4 transformation)
{
	object->transform = transformation;
	object->transform_inverse = mat4_inv(transformation);
}
