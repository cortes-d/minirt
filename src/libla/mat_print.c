/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:58:32 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/01 12:59:07 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libla.h"

void	mat_print(void *m, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (size == 2)
				printf("%0.1f\t", ((t_mat2 *)m)->data[i][j]);
			if (size == 3)
				printf("%0.1f\t", ((t_mat3 *)m)->data[i][j]);
			if (size == 4)
				printf("%0.1f\t", ((t_mat3 *)m)->data[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
