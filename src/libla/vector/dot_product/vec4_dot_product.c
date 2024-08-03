/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_dot_product.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:41:53 by achappui          #+#    #+#             */
/*   Updated: 2024/08/01 15:41:53 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

float	vec4_dot_product(const t_vec4 *v1, const t_vec4 *v2)
{
	return (v1->data[X] * v2->data[X] + \
			v1->data[Y] * v2->data[Y] + \
			v1->data[Z] * v2->data[Z] + \
			v1->data[W] * v2->data[W]);
}
