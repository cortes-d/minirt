/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_coffactor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:31:06 by achappui          #+#    #+#             */
/*   Updated: 2024/08/01 16:31:06 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

float	mat3_cofactor(const t_mat3 m, unsigned short row, unsigned short col)
{
	if ((row + col) % 2 == 1)
		return (-mat3_minor(m, row, col));
	else
		return (mat3_minor(m, row, col));
}
