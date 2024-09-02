/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_clamp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:43:53 by dcortes           #+#    #+#             */
/*   Updated: 2024/09/02 11:00:31 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_vec3	vec3_clamp(t_vec3 v, float max_value)
{
	t_vec3	res;

	res.data[X] = clamp(v.data[X], max_value);
	res.data[Y] = clamp(v.data[Y], max_value);
	res.data[Z] = clamp(v.data[Z], max_value);
	return (res);
}
