/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_magnitude.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:40:12 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:40:21 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

float	vec3_magnitude(t_vec3 v)
{
	return (sqrt(v.data[X] * v.data[X] + \
			v.data[Y] * v.data[Y] + \
			v.data[Z] * v.data[Z]));
}
