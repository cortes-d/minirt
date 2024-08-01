/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_submatrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:59:51 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/01 15:23:21 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libla.h"

t_mat3	mat4_submatrix(const t_mat4 m, int row, int col)
{
	t_mat3	submatrix;
	int		i;
	int		j;
	int		sub_i;
	int		sub_j;

	i = 0;
	sub_i = 0;
	while (i < 4)
	{
		if (i != row)
		{
			j = 0;
			sub_j = 0;
			while (j < 4)
			{
				if (j != col)
					submatrix.data[sub_i][sub_j++] = m.data[i][j];
				j++;
			}
			sub_i++;
		}
		i++;
	}
	return (submatrix);
}
