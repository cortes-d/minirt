/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:58:24 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/02 14:59:05 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	vec4_div_test();
	vec4_add_test();
	vec4_cross_product_test();
	vec4_mul_test();
	vec4_normalize_test();
	vec4_magnitude_test();
	vec4_inv_test();
	vec4_equal_test();
	vec4_dot_product_test();
	vec4_sub_test();
	ft_printf("\n\n");
	vec3_equal_test();
	vec3_sub_test();
	vec3_mul_test();
	vec3_hadamard_product_test();
	vec3_add_test();
}
