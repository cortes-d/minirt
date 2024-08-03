/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_mul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:24:06 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/01 22:24:06 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_vec3	vec3_mul(const t_vec3 *v, float scalar)
{
	t_vec3	res;

	res.data[R] = v->data[R] * scalar;
	res.data[G] = v->data[G] * scalar;
	res.data[B] = v->data[B] * scalar;
	return (res);
}
