/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_hadamard_product.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:25:39 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/05 15:02:13 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_vec3	vec3_hadamard_product(t_vec3 v1, t_vec3 v2)
{
	t_vec3	res;

	res.data[R] = v1.data[R] * v2.data[R];
	res.data[G] = v1.data[G] * v2.data[G];
	res.data[B] = v1.data[B] * v2.data[B];
	return (res);
}
