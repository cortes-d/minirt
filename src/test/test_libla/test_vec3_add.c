/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vec3_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:20:24 by achappui          #+#    #+#             */
/*   Updated: 2024/08/14 16:14:16 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libla.h"

void	test_vec3_add()
{
	t_vec3	v_test1;
	t_vec3	v_test2;
	t_vec3	v_expected;
	t_vec3	res;

	v_test1 = vec3(1, 2, 3);
	v_test2 = vec3(-2, 1, -2);
	v_expected = vec3(-1, 3, 1);
	res = vec3_add(v_test1, v_test2);
	if (vec3_equal(res, v_expected))
		ft_printf("vec3_sub: OK\n");
	else
		ft_printf("vec3_sub: KO\n");
}
