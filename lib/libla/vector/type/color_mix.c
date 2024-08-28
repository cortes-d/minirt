/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:28:33 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 10:28:33 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_vec3	color_mix(t_vec3 color1, t_vec3 color2, float weight)
{
	t_vec3	result;

	result.data[R] = color1.data[R] * weight + \
		color2.data[R] * (1.0f - weight);
	result.data[G] = color1.data[G] * weight + \
		color2.data[G] * (1.0f - weight);
	result.data[B] = color1.data[B] * weight + \
		color2.data[B] * (1.0f - weight);
	return (result);
}
