/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vec4_cross_product.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:20:24 by achappui          #+#    #+#             */
/*   Updated: 2024/08/14 16:11:33 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libla.h"

void	test_vec4_cross_product()
{
	t_vec4	v_test1;
	t_vec4	v_test2;
	t_vec4	v_expected;
	t_vec4	res;

	v_test1 = vec4(1, 2, 3, 0);
	v_test2 = vec4(-2, 1, -2, 0);
	v_expected = vec4(-7, -4, 5, 0);
	res = vec4h_cross_product(v_test1, v_test2);
	if (vec4_equal(res, v_expected))
		ft_printf("vec4_cross_product: OK\n");
	else
		ft_printf("vec4_cross_product: KO\n");
}
