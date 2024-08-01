/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_minor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:04:22 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/01 23:11:43 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

float	mat3_minor(const t_mat3 *m, const int row, int const col)
{
	t_mat2	submatrix;

	submatrix = mat3_submatrix(m, row, col);
	return (mat2_det(&submatrix));
}
