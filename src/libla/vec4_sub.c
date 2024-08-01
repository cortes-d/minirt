/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:08:08 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/01 10:08:08 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_vec4	vec4_sub(t_vec4 *a, t_vec4 *b)
{
	t_vec4	diff;

	diff.data[X] = a->data[X] - b->data[X];
	diff.data[Y] = a->data[Y] - b->data[Y];
	diff.data[Z] = a->data[Z] - b->data[Z];
	diff.data[W] = a->data[W] - b->data[W];
	return (diff);
}
