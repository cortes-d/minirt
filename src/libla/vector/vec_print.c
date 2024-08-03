/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:35:18 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/03 07:10:29 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libla.h"

void	vec_print(const void *v, unsigned short size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (size == V3_SIZE)
			printf("%6.2f\n", ((t_vec3 *)v)->data[i]);
		if (size == V4_SIZE)
			printf("%6.2f\n", ((t_vec4 *)v)->data[i]);
		i++;
	}
}
