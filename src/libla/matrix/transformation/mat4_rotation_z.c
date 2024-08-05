/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotation_z.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 11:40:21 by damian-cort       #+#    #+#             */
/*   Updated: 2024/08/05 15:30:18 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libla.h"

t_mat4	mat4_rotation_z(float r)
{
	t_mat4	rotation_z;

	rotation_z = mat4(\
		row4(cos(r), -sin(r), 0, 0), \
		row4(sin(r), cos(r), 0, 0), \
		row4(0, 0, 1, 0), \
		row4(0, 0, 0, 1));
	return (rotation_z);
}
