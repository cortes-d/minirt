/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:22:08 by achappui          #+#    #+#             */
/*   Updated: 2024/08/21 09:34:03 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

void	vec4_print(t_vec4 v)
{
	int		i;

	i = 0;
	printf("(");
	while (i < V4_SIZE)
	{
		printf("%.2f", v.data[i]);
		if (i != V4_SIZE - 1)
			printf(", ");
		i++;
	}
	printf(")");
	printf("\n");
}
