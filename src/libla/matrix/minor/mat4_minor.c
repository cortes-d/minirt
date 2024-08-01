/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_minor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:14:44 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/01 17:48:56 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

float	mat4_minor(const t_mat4 *m, const row, const col)
{
	t_mat3	submatrix;

	submatrix = mat4_submatrix(m, &row, &col);
	return (mat3_det(&submatrix));
}
