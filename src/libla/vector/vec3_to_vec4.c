/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_to_vec4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:02:37 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 11:04:52 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_vec4	vec3_to_vec4(t_vec3 v, float w)
{
	t_vec4	v;

	v.data[X] = v.data[X];
	v.data[Y] = v.data[Y];
	v.data[Z] = v.data[X];
	v.data[W] = w;
	return (v);
}
