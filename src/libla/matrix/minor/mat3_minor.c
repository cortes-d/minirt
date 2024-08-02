/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_minor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:04:22 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/02 16:13:09 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

double	mat3_minor(const t_mat3 *m, unsigned short row, unsigned short col)
{
	t_mat2	submatrix;

	submatrix = mat3_submatrix(m, row, col);
	return (mat2_det(&submatrix));
}
