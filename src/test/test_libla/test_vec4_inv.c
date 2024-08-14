/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vec4_inv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:20:24 by achappui          #+#    #+#             */
/*   Updated: 2024/08/14 16:13:02 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libla.h"

void	test_vec4_inv()
{
	t_vec4	v_test;
	t_vec4	v_expected;
	t_vec4	res;

	v_test = vec4(1, -2, 3, 7);
	v_expected = vec4(-1, 2, -3, -7);
	res = vec4_inv(v_test);
	if (vec4_equal(res, v_expected))
		ft_printf("vec4_inv: OK\n");
	else
		ft_printf("vec4_inv: KO\n");
}
