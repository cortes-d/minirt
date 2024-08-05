/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat2_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:09:47 by achappui          #+#    #+#             */
/*   Updated: 2024/08/05 15:18:47 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

void	mat2_print(t_mat2 a)
{
	unsigned short	r;
	unsigned short	c;

	r = 0;
	while (r < M2_SIZE)
	{
		c = 0;
		while (c < M2_SIZE)
		{
			if (c == M2_SIZE - 1)
				printf("%6.2f\n", a.data[r][c]);
			else
				printf("%6.2f\t", a.data[r][c]);
			c++;
		}
		r++;
	}
}
