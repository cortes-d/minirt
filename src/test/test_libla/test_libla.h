/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libla.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:02:59 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/14 09:56:09 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

#include "libft.h"
#include "libla.h"

t_vec4	test_vec4(float x, float y, float z, float w);
void	vec4_add_test();
void	vec4_cross_product_test();
void	vec4_div_test();
void	vec4_mul_test();
void	vec4_sub_test();
void	vec4_dot_product_test();
void	vec4_equal_test();
void	vec4_inv_test();
void	vec4_magnitude_test();
void	vec4_normalize_test();
t_vec3	test_vec3(float x, float y, float z);
void	vec3_equal_test();
void	vec3_sub_test();
void	vec3_add_test();
void	vec3_mul_test();
void	vec3_hadamard_product_test();

void	test_mat_determinant(void);
void	test_mat_identity(void);
void	test_mat_inversion(void);
void	test_mat_multiplication(void);
void	test_mat_transposition(void);
void	test_mat_submatrix(void);

#endif