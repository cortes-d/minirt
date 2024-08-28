/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:39:36 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:39:40 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_vec4	vec4_div(t_vec4 v, float scalar)
{
	t_vec4	res;

	res.data[X] = v.data[X] / scalar;
	res.data[Y] = v.data[Y] / scalar;
	res.data[Z] = v.data[Z] / scalar;
	res.data[W] = v.data[W] / scalar;
	return (res);
}
