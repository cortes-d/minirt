/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equalf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:38:47 by achappui          #+#    #+#             */
/*   Updated: 2024/07/31 15:38:47 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_vec4	vec4_add(const t_vec4 *a, const t_vec4 *b)
{
	t_vec4	res;

	res.data[X] = a->data[X] + b->data[X];
	res.data[Y] = a->data[Y] + b->data[Y];
	res.data[Z] = a->data[Z] + b->data[Z];
	res.data[W] = a->data[W] + b->data[W];
	return (res);
}
