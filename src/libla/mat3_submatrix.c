/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_submatrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:59:51 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/01 13:06:35 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libla.h"

t_mat2	mat3_submatrix(const t_mat3 m, int row, int col)
{
	t_mat2	submatrix;
	int		i;
	int		j;
	int		sub_i;
	int		sub_j;

	i = 0;
	sub_i = 0;
	while (i < 3)
	{
		if (i != row)
		{
			j = 0;
			sub_j = 0;
			while (j < 3)
			{
				if (j != col)
				{
					submatrix.data[sub_i][sub_j] = m.data[i][j];
					sub_j++;
				}
				j++;
			}
			sub_i++;
		}
		i++;
	}
	return (submatrix);
}
