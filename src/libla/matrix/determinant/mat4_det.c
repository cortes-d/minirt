/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_det.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:12:53 by achappui          #+#    #+#             */
/*   Updated: 2024/08/01 14:12:53 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

float	mat4_det(t_mat4 m)
{
	return (m.data[0][0] * mat4_cofactor(m, 0, 0) + \
			m.data[0][1] * mat4_cofactor(m, 0, 1) + \
			m.data[0][2] * mat4_cofactor(m, 0, 2) + \
			m.data[0][3] * mat4_cofactor(m, 0, 3));
}
