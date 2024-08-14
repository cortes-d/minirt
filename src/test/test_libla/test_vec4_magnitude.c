/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vec4_magnitude.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:20:24 by achappui          #+#    #+#             */
/*   Updated: 2024/08/14 16:13:14 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libla.h"

void	test_vec4_magnitude()
{
	t_vec4	v_test;
	float	v_expected;
	float	res;

	v_test = vec4(1, -2, 3, 3.31662479036);
	v_expected = 5;
	res = vec4_magnitude(v_test);
	if (equalf(res, v_expected))
		ft_printf("vec4_magnitude: OK\n");
	else
		ft_printf("vec4_magnitude: KO\n");
}
