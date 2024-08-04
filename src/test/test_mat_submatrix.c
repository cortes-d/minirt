/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mat_submatrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian-cortes <damian-cortes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:43:22 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/04 11:13:45 by damian-cort      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libla.h"

void	test_mat_submatrix(void)
{
	t_mat4	m4;
	t_mat3	sub_m3;

	m4 = mat4( \
		row4(1.0F, 2.0F, 6.0F, 4.0F), \
		row4(-5.0F, 8.0F, -4.0F, 3.0F), \
		row4(2.0F, 6.0F, 4.0F, 1.0F), \
		row4(4.0F, 8.0F, 1.0F, 1.0F));
	mat_print((void *)&m4, M4_SIZE);
	sub_m3 = mat4_submatrix(&m4, 4, 4);
	printf("\n");
	mat_print((void *)&sub_m3, M3_SIZE);
}
