/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:18:19 by achappui          #+#    #+#             */
/*   Updated: 2024/08/05 15:18:41 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

void	mat3_print(t_mat3 a)
{
	unsigned short	r;
	unsigned short	c;

	r = 0;
	while (r < M3_SIZE)
	{
		c = 0;
		while (c < M3_SIZE)
		{
			if (c == M3_SIZE - 1)
				printf("%6.2f\n", a.data[r][c]);
			else
				printf("%6.2f\t", a.data[r][c]);
			c++;
		}
		r++;
	}
}