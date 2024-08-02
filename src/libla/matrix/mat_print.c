/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:58:32 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/02 12:40:59 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libla.h"

void	mat_print(const void *m, short size)
{
	short	i;
	short	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (size == M2_SIZE)
				printf("%6.1f\t", ((t_mat2 *)m)->data[i][j]);
			if (size == M3_SIZE)
				printf("%6.1f\t", ((t_mat3 *)m)->data[i][j]);
			if (size == M4_SIZE)
				printf("%6.1f\t", ((t_mat4 *)m)->data[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
