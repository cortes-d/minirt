/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:07:48 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/01 10:07:48 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_vec4	vec4_add(t_vec4 *a, t_vec4 *b)
{
	t_vec4	sum;

	sum.data[X] = a->data[X] + b->data[X];
	sum.data[Y] = a->data[Y] + b->data[Y];
	sum.data[Z] = a->data[Z] + b->data[Z];
	sum.data[W] = a->data[W] + b->data[W];
	return (sum);
}
