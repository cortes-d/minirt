/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotation_y.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:45:03 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:45:03 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libla.h"

t_mat4	mat4_rotation_y(float r)
{
	t_mat4	rotation_y;

	rotation_y = mat4(\
		row4(cos(r), 0, sin(r), 0), \
		row4(0, 1, 0, 0), \
		row4(-sin(r), 0, cos(r), 0), \
		row4(0, 0, 0, 1));
	return (rotation_y);
}
