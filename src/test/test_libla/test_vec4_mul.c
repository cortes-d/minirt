/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vec4_mul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:20:24 by achappui          #+#    #+#             */
/*   Updated: 2024/08/14 16:11:23 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libla.h"

void	test_vec4_mul()
{
	t_vec4	v_test1;
	float	scalar;
	t_vec4	v_expected;
	t_vec4	res;

	v_test1 = vec4(2.5, 2, 3, 4);
	scalar = 2.5;
	v_expected = vec4(6.25, 5, 7.5, 10);
	res = vec4_mul(v_test1, scalar);
	if (vec4_equal(res, v_expected))
		ft_printf("vec4_mul: OK\n");
	else
		ft_printf("vec4_mul: KO\n");
}