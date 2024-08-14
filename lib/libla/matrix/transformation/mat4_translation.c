/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_translation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian-cortes <damian-cortes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 11:26:01 by damian-cort       #+#    #+#             */
/*   Updated: 2024/08/04 11:29:56 by damian-cort      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_mat4	mat4_translation(float x, float y, float z)
{
	t_mat4	translation;

	translation = mat4( \
		row4(1, 0, 0, x), \
		row4(0, 1, 0, y), \
		row4(0, 0, 1, z), \
		row4(0, 0, 0, 1));
	return (translation);
}
