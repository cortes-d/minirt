/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mat_identity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:58:31 by damian-cort       #+#    #+#             */
/*   Updated: 2024/08/14 10:00:30 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libla.h"

void	test_mat_identity(void)
{
	t_mat4	m4_test_identity;
	t_mat3	m3_test_identity;
	t_mat2	m2_test_identity;
	
	printf("--- testing matrix identity size 4 ---\n");
	m4_test_identity = mat4_identity();
	mat4_print(m4_test_identity);

	printf("--- testing matrix identity size 3 ---\n");
	m3_test_identity = mat3_identity();
	mat3_print(m3_test_identity);

	printf("--- testing matrix identity size 2 ---\n");	
	m2_test_identity = mat2_identity();
	mat2_print(m2_test_identity);
}