/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mat_identity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian-cortes <damian-cortes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:58:31 by damian-cort       #+#    #+#             */
/*   Updated: 2024/08/04 11:00:37 by damian-cort      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_mat_identity(void)
{
	t_mat4	m4_test_identity;
	t_mat3	m3_test_identity;
	t_mat2	m2_test_identity;
	
	printf("--- testing matrix identity size 4 ---\n");
	m4_test_identity = mat4_identity();
	mat_print(&m4_test_identity, 4);

	printf("--- testing matrix identity size 3 ---\n");
	m3_test_identity = mat3_identity();
	mat_print(&m3_test_identity, 3);

	printf("--- testing matrix identity size 2 ---\n");	
	m2_test_identity = mat2_identity();
	mat_print(&m2_test_identity, 2);
}