/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:35:18 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/21 09:31:53 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

void	vec3_print(t_vec3 v)
{
	int		i;

	i = 0;
	printf("(");
	while (i < V3_SIZE)
	{
		printf("%.2f", v.data[i]);
		if (i != V3_SIZE - 1)
			printf(", ");
		i++;
	}
	printf(")");
	printf("\n");
}
