/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_translation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:44:54 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:44:54 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_mat4	mat4_translation(float x, float y, float z)
{
	t_mat4	translation;

	translation = mat4(\
		row4(1, 0, 0, x), \
		row4(0, 1, 0, y), \
		row4(0, 0, 1, z), \
		row4(0, 0, 0, 1));
	return (translation);
}
