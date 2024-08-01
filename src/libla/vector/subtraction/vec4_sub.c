/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:21:02 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/01 22:21:02 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_vec4	vec4_sub(const t_vec4 *a, const t_vec4 *b)
{
	t_vec4	res;

	res.data[X] = a->data[X] - b->data[X];
	res.data[Y] = a->data[Y] - b->data[Y];
	res.data[Z] = a->data[Z] - b->data[Z];
	res.data[W] = a->data[W] - b->data[W];
	return (res);
}
