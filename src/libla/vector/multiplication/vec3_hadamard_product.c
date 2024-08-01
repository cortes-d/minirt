/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_hadamard_product.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:25:39 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/01 22:27:47 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_vec3	vec3_hadamard_product(const t_vec3 *v1, const t_vec3 *v2)
{
	t_vec3	res;

	res.data[R] = v1->data[R] * v2->data[R];
	res.data[G] = v1->data[G] * v2->data[R];
	res.data[B] = v1->data[B] * v2->data[R];
	return (res);
}
