/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:58:48 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/02 14:59:25 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"
#include "libft.h"

t_vec4	test_vec4(float x, float y, float z, float w)
{
	t_vec4	vector;

	vector.data[X] = x;
	vector.data[Y] = y;
	vector.data[Z] = z;
	vector.data[W] = w;
	return (vector);
}

void	vec4_add_test()
{
	t_vec4	v_test1;
	t_vec4	v_test2;
	t_vec4	v_expected;
	t_vec4	res;

	v_test1 = test_vec4(1, 2, 3, 4);
	v_test2 = test_vec4(-2, 1, -2, 1);
	v_expected = test_vec4(-1, 3, 1, 5);
	res = vec4_add(&v_test1, &v_test2);
	if (vec4_equal(&res, &v_expected))
		ft_printf("vec4_add_test: OK\n");
	else
		ft_printf("vec4_add_test: KO\n");
}

void	vec4_cross_product_test()
{
	t_vec4	v_test1;
	t_vec4	v_test2;
	t_vec4	v_expected;
	t_vec4	res;

	v_test1 = test_vec4(1, 2, 3, 0);
	v_test2 = test_vec4(-2, 1, -2, 0);
	v_expected = test_vec4(-7, -4, 5, 0);
	vec_print(&res, 4);
	res = vec4h_cross_product(&v_test1, &v_test2);
	if (vec4_equal(&res, &v_expected))
		ft_printf("vec4_cross_product_test: OK\n");
	else
		ft_printf("vec4_cross_product_test: KO\n");
}

void	vec4_div_test()
{
	t_vec4	v_test1;
	float	scalar;
	t_vec4	v_expected;
	t_vec4	res;

	v_test1 = test_vec4(2.5, 2, 3, -4);
	scalar = 2.5;
	v_expected = test_vec4(1, 0.8, 1.2, -1.6);
	res = vec4_div(&v_test1, scalar);
	if (vec4_equal(&res, &v_expected))
		ft_printf("vec4_div_test: OK\n");
	else
		ft_printf("vec4_div_test: KO\n");
}

void	vec4_mul_test()
{
	t_vec4	v_test1;
	float	scalar;
	t_vec4	v_expected;
	t_vec4	res;

	v_test1 = test_vec4(2.5, 2, 3, 4);
	scalar = 2.5;
	v_expected = test_vec4(6.25, 5, 7.5, 10);
	res = vec4_mul(&v_test1, scalar);
	if (vec4_equal(&res, &v_expected))
		ft_printf("vec4_mul_test: OK\n");
	else
		ft_printf("vec4_mul_test: KO\n");
}

void	vec4_sub_test()
{
	t_vec4	v_test1;
	t_vec4	v_test2;
	t_vec4	v_expected;
	t_vec4	res;

	v_test1 = test_vec4(1, 2, 3, 4);
	v_test2 = test_vec4(-2, 1, -2, 1);
	v_expected = test_vec4(3, 1, 5, 3);
	res = vec4_sub(&v_test1, &v_test2);
	if (vec4_equal(&res, &v_expected))
		ft_printf("vec4_sub_test: OK\n");
	else
		ft_printf("vec4_sub_test: KO\n");
}

void	vec4_dot_product_test()
{
	t_vec4	v_test1;
	t_vec4	v_test2;
	float	v_expected;
	float	res;

	v_test1 = test_vec4(1, 2, 3, 6);
	v_test2 = test_vec4(-2, 1, -2, 3);
	v_expected = 12;
	res = vec4_dot_product(&v_test1, &v_test2);
	if (equalf(res, v_expected))
		ft_printf("vec4_dot_product_test: OK\n");
	else
		ft_printf("vec4_dot_product_test: KO\n");
}

void	vec4_equal_test()
{
	t_vec4	v_test1;
	t_vec4	v_test2;
	bool	v_expected;
	bool	res;

	v_test1 = test_vec4(1.56241444, 2, 1, 0);
	v_test2 = test_vec4(1.56241443, 2, 1, 0);
	v_expected = 1;
	res = vec4_equal(&v_test1, &v_test2);
	if (v_expected == res)
		ft_printf("vec4_equal_test: OK\n");
	else
		ft_printf("vec4_equal_test: KO\n");
}

void	vec4_inv_test()
{
	t_vec4	v_test;
	t_vec4	v_expected;
	t_vec4	res;

	v_test = test_vec4(1, -2, 3, 7);
	v_expected = test_vec4(-1, 2, -3, -7);
	res = vec4_inv(&v_test);
	if (vec4_equal(&res, &v_expected))
		ft_printf("vec4_inv_test: OK\n");
	else
		ft_printf("vec4_inv_test: KO\n");
}

void	vec4_magnitude_test()
{
	t_vec4	v_test;
	float	v_expected;
	float	res;

	v_test = test_vec4(1, -2, 3, 3.31662479036);
	v_expected = 5;
	res = vec4_magnitude(&v_test);
	printf("%f\n", res);
	if (equalf(res, v_expected))
		ft_printf("vec4_magnitude_test: OK\n");
	else
		ft_printf("vec4_magnitude_test: KO\n");
}

void	vec4_normalize_test()
{
	t_vec4	v_test;
	t_vec4	v_expected;
	t_vec4	res;

	v_test = test_vec4(1, -2, 3, 3.31662479036);
	v_expected = test_vec4(0.2, -0.4, 0.6, 0.66332495807);
	res = vec4_normalize(&v_test);
	vec_print(&res, 4);
	if (vec4_equal(&res, &v_expected))
		ft_printf("vec4_normalize_test: OK\n");
	else
		ft_printf("vec4_normalize_test: KO\n");
}

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
	if (vec3_equal(&res, &v_expected))
		ft_printf("vec3_sub_test: OK\n");
	else
		ft_printf("vec3_sub_test: KO\n");
}

void	vec3_add_test()
{
	t_vec3	v_test1;
	t_vec3	v_test2;
	t_vec3	v_expected;
	t_vec3	res;

	v_test1 = test_vec3(1, 2, 3);
	v_test2 = test_vec3(-2, 1, -2);
	v_expected = test_vec3(-1, 3, 1);
	res = vec3_add(&v_test1, &v_test2);
	if (vec3_equal(&res, &v_expected))
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
	if (vec3_equal(&res, &v_expected))
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
	if (vec3_equal(&res, &v_expected))
		ft_printf("vec3_hadamard_product: OK\n");
	else
		ft_printf("vec3_hadamard_product: KO\n");
}
