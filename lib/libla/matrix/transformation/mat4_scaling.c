/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_scaling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:43:23 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:43:23 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_mat4	mat4_scaling(float x, float y, float z)
{
	t_mat4	scaling;

	scaling = mat4(\
		row4(x, 0, 0, 0), \
		row4(0, y, 0, 0), \
		row4(0, 0, z, 0), \
		row4(0, 0, 0, 1));
	return (scaling);
}
