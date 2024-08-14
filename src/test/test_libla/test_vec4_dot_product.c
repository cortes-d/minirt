/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vec4_dot_product.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:20:24 by achappui          #+#    #+#             */
/*   Updated: 2024/08/14 16:12:31 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libla.h"

void	test_vec4_dot_product()
{
	t_vec4	v_test1;
	t_vec4	v_test2;
	float	v_expected;
	float	res;

	v_test1 = vec4(1, 2, 3, 6);
	v_test2 = vec4(-2, 1, -2, 3);
	v_expected = 12;
	res = vec4_dot_product(v_test1, v_test2);
	if (equalf(res, v_expected))
		ft_printf("vec4_dot_product: OK\n");
	else
		ft_printf("vec4_dot_product: KO\n");
}
