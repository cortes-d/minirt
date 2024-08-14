/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_scaling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian-cortes <damian-cortes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 11:36:00 by damian-cort       #+#    #+#             */
/*   Updated: 2024/08/04 11:37:59 by damian-cort      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_mat4	mat4_scaling(float x, float y, float z)
{
	t_mat4	scaling;

	scaling = mat4( \
		row4(x, 0, 0, 0), \
		row4(0, y, 0, 0), \
		row4(0, 0, z, 0), \
		row4(0, 0, 0, 1));
	return (scaling);
}
