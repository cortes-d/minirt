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

#include	"libla.h"

t_vec4	vec4_div(const t_vec4 *v, double scalar)
{
	t_vec4	res;

	res.data[X] = v->data[X] / scalar;
	res.data[Y] = v->data[Y] / scalar;
	res.data[Z] = v->data[Z] / scalar;
	res.data[W] = v->data[W] / scalar;
	return (res);
}