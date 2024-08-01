/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:22:56 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/01 22:22:56 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_vec3	vec3_sub(const t_vec3 *a, const t_vec3 *b)
{
	t_vec3	res;

	res.data[R] = a->data[R] - b->data[R];
	res.data[G] = a->data[G] - b->data[G];
	res.data[B] = a->data[B] - b->data[B];
	return (res);
}
