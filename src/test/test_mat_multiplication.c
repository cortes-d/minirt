/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mat_multiplication.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:51:15 by damian-cort       #+#    #+#             */
/*   Updated: 2024/08/05 15:31:54 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_mat_multiplication(void)
{
	t_mat4	m_a;
	t_mat4	m_b;
	t_mat4	m_mult_a_b;
	t_mat4	m_test_mult_a_b;
	t_mat4	m_test_mult_a_scalar;
	t_vec4	v;
	t_vec4	v_test_multiplication;
	t_vec4	v_multiplication;

	m_a = mat4( \
		row4(3.14F, 7.89F, -5.67F, 2.45F), \
		row4(-1.23F, 4.56F, 8.90F, -7.34F), \
		row4(6.78F, -9.01F, 3.21F, 5.43F), \
		row4(-4.56F, 2.34F, -8.76F, 1.98F));
	m_b = mat4( \
		row4(-2.54F, 5.68F, 9.87F, -3.45F), \
		row4(6.23F, -7.89F, 4.56F, 2.78F), \
		row4(-1.12F, 3.45F, -6.78F, 7.09F), \
		row4(5.67F, -8.90F, 2.34F, -4.56F));
	m_mult_a_b = mat4( \
		row4(61.421F, -85.7834F, 111.1458F, -40.2711F), \
		row4(-20.0528F, 53.0662F, -68.8641F, 113.4917F), \
		row4(-46.1606F, 72.3468F, 16.7754F, -50.4407F), \
		row4(47.1984F, -92.2074F, 29.6892F, -48.9F));
	printf("--- testing matrix multiplication ---\n");
	m_test_mult_a_b = mat4_mat4_mul(m_a, m_b);
	if (mat4_equal(m_test_mult_a_b, m_mult_a_b))
		printf("matrix multiplication: OK\n");
	else
		printf("matrix multiplication: KO\n");
	
	v = vec4(7.15, 8.13, 9.52, 1.45);
	v_multiplication = vec4(36.1708, 102.3633, 13.6584, -94.104);
	printf("--- testing matrix-vector multiplication ---\n");
	v_test_multiplication = mat4_vec4_mul(m_a, v);
	if (vec4_equal(v_test_multiplication, v_multiplication))
		printf("vector_multiplication: OK\n");
	else
		printf("vector_multiplication: KO\n");

	printf("--- testing matrix-scalar multiplication ---\n");
	m_test_mult_a_scalar = mat4_mul(m_a, 0);
	mat4_print(m_test_mult_a_scalar);
}
