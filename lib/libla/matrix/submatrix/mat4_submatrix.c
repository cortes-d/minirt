/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_submatrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:41:21 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:41:24 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libla.h"

t_mat3	mat4_submatrix(t_mat4 m, unsigned short row, unsigned short col)
{
	t_mat3			submatrix;
	unsigned short	i;
	unsigned short	j;
	unsigned short	sub_i;
	unsigned short	sub_j;

	i = 0;
	sub_i = 0;
	while (i < M4_SIZE)
	{
		if (i != row)
		{
			j = 0;
			sub_j = 0;
			while (j < M4_SIZE)
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
