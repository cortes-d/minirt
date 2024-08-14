/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vec4_normalize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:20:24 by achappui          #+#    #+#             */
/*   Updated: 2024/08/14 16:13:33 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libla.h"

void	test_vec4_normalize()
{
	t_vec4	v_test;
	t_vec4	v_expected;
	t_vec4	res;

	v_test = vec4(1, -2, 3, 3.31662479036);
	v_expected = vec4(0.2, -0.4, 0.6, 0.66332495807);
	res = vec4_normalize(v_test);
	if (vec4_equal(res, v_expected))
		ft_printf("vec4_normalize: OK\n");
	else
		ft_printf("vec4_normalize: KO\n");
}
