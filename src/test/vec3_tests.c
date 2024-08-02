/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:11:42 by achappui          #+#    #+#             */
/*   Updated: 2024/08/02 11:58:15 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_vec3	test_vec3(float x, float y, float z)
{
	t_vec3	vector;

	vector.data[X] = x;
	vector.data[Y] = y;
	vector.data[Z] = z;
	return (vector);
}

void	vec3_equal_test()
{
	t_vec3	v_test1;
	t_vec3	v_test2;
	bool	v_expected;
	bool	res;

	v_test1 = test_vec3(1.56241444, 2, 0);
	v_test2 = test_vec3(1.56241443, 2, 0);
	v_expected = 1;
	res = vec3_equal(&v_test1, &v_test2);
	if (v_expected == res)
		ft_printf("vec3_equal_test: OK\n");
	else
		ft_printf("vec3_equal_test: KO\n");
}

void	vec3_sub_test()
{
	t_vec3	v_test1;
	t_vec3	v_test2;
	t_vec3	v_expected;
	t_vec3	res;

	v_test1 = test_vec3(1, 2, 3);
	v_test2 = test_vec3(-2, 1, -2);
	v_expected = test_vec3(3, 1, 5);
	res = vec3_sub(&v_test1, &v_test2);
	if (vec3_equal(&res, v_expected))
		ft_printf("vec3_sub_test: OK\n");
	else
		ft_printf("vec3_sub_test: KO\n");
}

void	vec3_mul_test()
{
	t_vec3	v_test1;
	float	scalar;
	t_vec3	v_expected;
	t_vec3	res;

	v_test1 = test_vec3(2.5, 2, 3);
	scalar = 2.5;
	v_expected = test_vec3(6.25, 5, 7.5);
	res = vec3_mul(&v_test1, scalar);
	if (vec3_equal(&res, v_expected))
		ft_printf("vec3_mul_test: OK\n");
	else
		ft_printf("vec3_mul_test: KO\n");
}

void	vec3_hadamard_product_test()
{
	t_vec3	v_test1;
	t_vec3	v_test2;
	t_vec3	v_expected;
	t_vec3	res;

	v_test1 = test_vec3(2, 2, 5);
	v_test2 = test_vec3(-2, 3, -2);
	v_expected = test_vec3(-4, 6, -10);
	res = vec3_hadamard_product(&v_test1, &v_test2);
	if (vec3_equal(&res, v_expected))
		ft_printf("vec3_hadamard_product: OK\n");
	else
		ft_printf("vec3_hadamard_product: KO\n");
}