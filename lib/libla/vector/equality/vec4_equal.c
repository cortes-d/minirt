/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_equal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:40:04 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:40:04 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

bool	vec4_equal(t_vec4 v1, t_vec4 v2)
{
	unsigned short	r;

	r = 0;
	while (r < 4)
	{
		if (!equalf(v1.data[r], v2.data[r]))
			return (0);
		r++;
	}
	return (1);
}
