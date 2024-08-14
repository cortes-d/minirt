/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:26:23 by achappui          #+#    #+#             */
/*   Updated: 2024/08/14 16:27:18 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libla.h"

int	test_vector()
{
	test_vec4_div();
	test_vec4_add();
	test_vec4_cross_product();
	test_vec4_mul();
	test_vec4_normalize();
	test_vec4_magnitude();
	test_vec4_inv();
	test_vec4_equal();
	test_vec4_dot_product();
	test_vec4_sub();
	test_vec3_equal();
	test_vec3_sub();
	test_vec3_mul();
	test_vec3_hadamard_product();
	test_vec3_add();
	return (0);
}
