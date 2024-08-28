/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotation_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:43:55 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:43:59 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libla.h"

t_mat4	mat4_rotation_x(float r)
{
	t_mat4	rotation_x;

	rotation_x = mat4(\
		row4(1, 0, 0, 0), \
		row4(0, cos(r), -sin(r), 0), \
		row4(0, sin(r), cos(r), 0), \
		row4(0, 0, 0, 1));
	return (rotation_x);
}