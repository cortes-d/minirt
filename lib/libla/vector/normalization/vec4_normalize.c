/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:39:47 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:39:47 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_vec4	vec4_normalize(t_vec4 v)
{
	t_vec4	res;
	float	magnitude;

	magnitude = vec4_magnitude(v);
	res.data[X] = v.data[X] / magnitude;
	res.data[Y] = v.data[Y] / magnitude;
	res.data[Z] = v.data[Z] / magnitude;
	res.data[W] = v.data[W] / magnitude;
	return (res);
}
