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

t_vec4	vec4_normalize(const t_vec4 *v)
{
	t_vec4	res;
	double	magnitude;
	
	magnitude = vec4_magnitude(v);
	res.data[X] = v->data[X] / magnitude;
	res.data[Y] = v->data[Y] / magnitude;
	res.data[Z] = v->data[Z] / magnitude;
	res.data[W] = v->data[W] / magnitude;
	return (res);
}