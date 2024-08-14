/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vec3_equal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:20:24 by achappui          #+#    #+#             */
/*   Updated: 2024/08/14 16:13:49 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libla.h"

void	test_vec3_equal()
{
	t_vec3	v_test1;
	t_vec3	v_test2;
	bool	v_expected;
	bool	res;

	v_test1 = vec3(1.56241444, 2, 0);
	v_test2 = vec3(1.56241443, 2, 0);
	v_expected = 1;
	res = vec3_equal(v_test1, v_test2);
	if (v_expected == res)
		ft_printf("vec3_equal: OK\n");
	else
		ft_printf("vec3_equal: KO\n");
}
