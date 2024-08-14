/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mat_submatrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:43:22 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/14 16:02:54 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libla.h"

void	test_mat_submatrix(void)
{
	t_mat4	m4;
	t_mat3	sub_m3;

	m4 = mat4( \
		row4(1.0F, 2.0F, 6.0F, 4.0F), \
		row4(-5.0F, 8.0F, -4.0F, 3.0F), \
		row4(2.0F, 6.0F, 4.0F, 1.0F), \
		row4(4.0F, 8.0F, 1.0F, 1.0F));
	printf("--- testing submatrix ---\n");
	mat4_print(m4);
	sub_m3 = mat4_submatrix(m4, 4, 4);
	printf("\n");
	mat3_print(sub_m3);
}
