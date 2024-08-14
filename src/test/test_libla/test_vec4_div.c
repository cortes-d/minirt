/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vec4_div.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:20:24 by achappui          #+#    #+#             */
/*   Updated: 2024/08/14 16:11:27 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libla.h"

void	test_vec4_div()
{
	t_vec4	v_test1;
	float	scalar;
	t_vec4	v_expected;
	t_vec4	res;

	v_test1 = vec4(2.5, 2, 3, -4);
	scalar = 2.5;
	v_expected = vec4(1, 0.8, 1.2, -1.6);
	res = vec4_div(v_test1, scalar);
	if (vec4_equal(res, v_expected))
		ft_printf("vec4_div: OK\n");
	else
		ft_printf("vec4_div: KO\n");
}
