/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_det.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:56:55 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/29 08:56:55 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

float	mat3_det(const t_mat3 m)
{
	return (m.data[0][0] * mat3_cofactor(m, 0, 0) + \
			m.data[0][1] * mat3_cofactor(m, 0, 1) + \
			m.data[0][2] * mat3_cofactor(m, 0, 2));
}
