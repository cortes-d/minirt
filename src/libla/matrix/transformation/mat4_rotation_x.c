/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotation_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian-cortes <damian-cortes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 11:40:21 by damian-cort       #+#    #+#             */
/*   Updated: 2024/08/04 11:44:17 by damian-cort      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libla.h"

t_mat4  mat4_rotation_x(float r)
{
	t_mat4	rotation_x;

	rotation_x = mat4( \
		row4(1, 0, 0, 0), \
		row4(0, cos(r), -sin(r), 0), \
		row4(0, sin(r), cos(r), 0), \
		row4(0, 0, 0, 1));	
	return (rotation_x);
}