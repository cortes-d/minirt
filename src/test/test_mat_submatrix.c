/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mat_submatrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:43:22 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/01 23:31:27 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libla.h"

void	test_mat_submatrix(void)
{
	t_mat4	m4;
	t_mat3	sub_m3;

	m4.data[0][0] = 1.0f;
	m4.data[0][1] = 2.0f;
	m4.data[0][2] = 6.0f;
	m4.data[0][3] = 4.0f;
	m4.data[1][0] = -5.0f;
	m4.data[1][1] = 8.0f;
	m4.data[1][2] = -4.0f;
	m4.data[1][3] = 3.0f;
	m4.data[2][0] = 2.0f;
	m4.data[2][1] = 6.0f;
	m4.data[2][2] = 4.0f;
	m4.data[2][3] = 1.0f;
	m4.data[3][0] = 4.0f;
	m4.data[3][1] = 8.0f;
	m4.data[3][2] = 1.0f;
	m4.data[3][3] = 1.0f;
	mat_print((void *)&m4, M4_SIZE);
	sub_m3 = mat4_submatrix(&m4, 4, 4);
	printf("\n");
	mat_print((void *)&sub_m3, M3_SIZE);
}
