/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mat_transposition.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:41:45 by damian-cort       #+#    #+#             */
/*   Updated: 2024/08/14 10:00:39 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libla.h"

void	test_mat_transposition(void)
{
	t_mat4	m;
	t_mat4  m_transposition;
	t_mat4	m_test_transposition;

	m = mat4( \
		row4(3.14F, 7.89F, -5.67F, 2.45F), \
		row4(-1.23F, 4.56F, 8.90F, -7.34F), \
		row4(6.78F, -9.01F, 3.21F, 5.43F), \
		row4(-4.56F, 2.34F, -8.76F, 1.98F));
	m_transposition = mat4( \
		row4(3.14F, -1.23F, 6.78F, -4.56F), \
		row4(7.89F, 4.56F, -9.01F, 2.34F), \
		row4(-5.67F, 8.90F, 3.21F, -8.76F), \
		row4(2.45F, -7.34F, 5.43F, 1.98F));
	printf("--- testing matrix transposition ---\n");
	m_test_transposition = mat4_transpose(m);
	if (mat4_equal(m_test_transposition, m_transposition))
		printf("transposition: OK\n");
	else
		printf("transposition: KO\n");
}
