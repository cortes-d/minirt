/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vec3_mul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:20:24 by achappui          #+#    #+#             */
/*   Updated: 2024/08/14 16:14:33 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libla.h"

void	test_vec3_mul()
{
	t_vec3	v_test1;
	float	scalar;
	t_vec3	v_expected;
	t_vec3	res;

	v_test1 = vec3(2.5, 2, 3);
	scalar = 2.5;
	v_expected = vec3(6.25, 5, 7.5);
	res = vec3_mul(v_test1, scalar);
	if (vec3_equal(res, v_expected))
		ft_printf("vec3_mul: OK\n");
	else
		ft_printf("vec3_mul: KO\n");
}
