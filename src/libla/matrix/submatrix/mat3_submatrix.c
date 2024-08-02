/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_submatrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:59:51 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/02 12:40:20 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libla.h"

t_mat2	mat3_submatrix(const t_mat3 *m, short row, short col)
{
	t_mat2	submatrix;
	short	i;
	short	j;
	short	sub_i;
	short	sub_j;

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
					submatrix.data[sub_i][sub_j++] = m->data[i][j];
				j++;
			}
			sub_i++;
		}
		i++;
	}
	return (submatrix);
}
