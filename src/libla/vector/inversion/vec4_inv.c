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

t_vec4	vec4_inv(const t_vec4 *v)
{
	t_vec4	res;

	res.data[X] = -v->data[X];
	res.data[Y] = -v->data[Y];
	res.data[Z] = -v->data[Z];
	res.data[W] = -v->data[W];
	return (res);
}
