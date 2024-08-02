/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_cross_product.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:45:09 by achappui          #+#    #+#             */
/*   Updated: 2024/08/01 15:45:09 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_vec4	vec4h_cross_product(const t_vec4 *v1, const t_vec4 *v2)
{
	t_vec4	res;

	res.data[X] = \
	v1->data[Y] * v2->data[Z] + v1->data[Z] * v2->data[Y];
	res.data[Y] = \
	v1->data[Z] * v2->data[X] + v1->data[X] * v2->data[Z];
	res.data[Z] = \
	v1->data[X] * v2->data[Y] + v1->data[Y] * v2->data[X];
	return (res);
}
