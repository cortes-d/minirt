/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_inv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:07:33 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/01 10:07:33 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_vec4	vec4_inv(t_vec4 *v)
{
	t_vec4	inv;

	inv.data[X] = -v->data[X];
	inv.data[Y] = -v->data[Y];
	inv.data[Z] = -v->data[Z];
	inv.data[X] = -v->data[W];
	return (inv);
}
