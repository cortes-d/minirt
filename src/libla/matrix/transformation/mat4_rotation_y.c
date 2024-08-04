/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotation_y.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian-cortes <damian-cortes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 11:40:21 by damian-cort       #+#    #+#             */
/*   Updated: 2024/08/04 11:50:07 by damian-cort      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libla.h"

t_mat4  mat4_rotation_y(float r)
{
	t_mat4	rotation_y;

	rotation_y = mat4( \
		row4(cos(r), 0, sin(r), 0), \
		row4(0, 1, 0, 0), \
		row4(-sin(r), 0, cos(r), 0), \
		row4(0, 0, 0, 1));
	return (rotation_y);
}
