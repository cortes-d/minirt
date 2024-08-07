/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:19:08 by achappui          #+#    #+#             */
/*   Updated: 2024/08/05 15:19:11 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

void	mat4_print(t_mat4 a)
{
	unsigned short	r;
	unsigned short	c;

	r = 0;
	while (r < M4_SIZE)
	{
		c = 0;
		while (c < M4_SIZE)
		{
			if (c == M4_SIZE - 1)
				printf("%6.2f\n", a.data[r][c]);
			else
				printf("%6.2f\t", a.data[r][c]);
			c++;
		}
		r++;
	}
}