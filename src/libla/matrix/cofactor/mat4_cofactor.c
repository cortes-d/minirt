/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_coffactor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:31:06 by achappui          #+#    #+#             */
/*   Updated: 2024/08/01 16:31:06 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

float	mat4_cofactor(const t_mat4 *m, short row, short col)
{
	short	sign;

	sign = 1;
	if ((row + col) % 2 == 1)
		sign = -1;
	return (sign * mat4_minor(m, row, col));
}
