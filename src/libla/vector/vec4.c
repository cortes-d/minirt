/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian-cortes <damian-cortes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:16:31 by damian-cort       #+#    #+#             */
/*   Updated: 2024/08/03 12:20:14 by damian-cort      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_vec4  vec4(float a, float b, float c, float d)
{
	t_vec4	v;

	v.data[0] = a;
	v.data[1] = b;
	v.data[2] = c;
	v.data[3] = d;
	return (v);
}