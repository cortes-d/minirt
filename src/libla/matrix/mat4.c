/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian-cortes <damian-cortes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:50:49 by damian-cort       #+#    #+#             */
/*   Updated: 2024/08/03 11:57:14 by damian-cort      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_mat4	mat4(t_row4 a, t_row4 b, t_row4 c, t_row4 d)
{
	t_mat4	m;
	int		i;

	i = 0;
	while (i < 4)
	{
		m.data[0][i] = a.data[i];
		m.data[1][i] = b.data[i];
		m.data[2][i] = c.data[i];
		m.data[3][i] = d.data[i];
		i++;
	}
	return (m);
}
