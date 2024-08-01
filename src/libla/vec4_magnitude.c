/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_magnitude.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:08:02 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/01 10:08:02 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

float	vec4_magnitude(t_vec4 *v)
{
	return (sqrt(v->data[X] * v->data[X] + \
			v->data[Y] * v->data[Y] + \
			v->data[Z] * v->data[Z] + \
			v->data[W] * v->data[W]));
}
