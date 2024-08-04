/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian-cortes <damian-cortes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:58:24 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/04 11:14:01 by damian-cort      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	test_mat_determinant();
	test_mat_identity();
	test_mat_inversion();
	test_mat_multiplication();
	test_mat_submatrix();
	test_mat_transposition();
	vec4_div_test();
	vec4_add_test();
	vec4_cross_product_test();
	vec4_mul_test();
	vec4_normalize_test();
	vec4_magnitude_test();
	vec4_inv_test();
	vec4_equal_test();
	vec4_dot_product_test();
	vec4_sub_test();
	vec3_equal_test();
	vec3_sub_test();
	vec3_mul_test();
	vec3_hadamard_product_test();
	vec3_add_test();
}
