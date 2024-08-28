/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_magnitude.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:41:42 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:41:46 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

float	vec4_magnitude(t_vec4 v)
{
	return (sqrt(v.data[X] * v.data[X] + \
			v.data[Y] * v.data[Y] + \
			v.data[Z] * v.data[Z] + \
			v.data[W] * v.data[W]));
}
