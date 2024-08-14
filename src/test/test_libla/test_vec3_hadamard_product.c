/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vec3_hadamard_product.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:20:24 by achappui          #+#    #+#             */
/*   Updated: 2024/08/14 16:14:49 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libla.h"

void	test_vec3_hadamard_product()
{
	t_vec3	v_test1;
	t_vec3	v_test2;
	t_vec3	v_expected;
	t_vec3	res;

	v_test1 = vec3(2, 2, 5);
	v_test2 = vec3(-2, 3, -2);
	v_expected = vec3(-4, 6, -10);
	res = vec3_hadamard_product(v_test1, v_test2);
	if (vec3_equal(res, v_expected))
		ft_printf("vec3_hadamard_product: OK\n");
	else
		ft_printf("vec3_hadamard_product: KO\n");
}
