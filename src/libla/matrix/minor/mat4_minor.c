/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_minor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:14:44 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/02 12:40:00 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

float	mat4_minor(const t_mat4 *m, short row, short col)
{
	t_mat3	submatrix;

	submatrix = mat4_submatrix(m, row, col);
	return (mat3_det(&submatrix));
}
