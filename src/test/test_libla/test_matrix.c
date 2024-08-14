/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:26:23 by achappui          #+#    #+#             */
/*   Updated: 2024/08/14 16:26:59 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libla.h"

int	test_matrix()
{
	test_mat_determinant();
	test_mat_identity();
	test_mat_inversion();
	test_mat_multiplication();
	test_mat_submatrix();
	test_mat_transposition();
	return (0);
}