/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_det.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:12:43 by achappui          #+#    #+#             */
/*   Updated: 2024/08/01 14:12:43 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

float	mat3_det(const t_mat3 m)
{
	return (m.data[0][0] * mat3_cofactor(m, 0, 0) + \
			m.data[0][1] * mat3_cofactor(m, 0, 1) + \
			m.data[0][2] * mat3_cofactor(m, 0, 2));
}

