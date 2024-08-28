/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_equal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:39:56 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:39:56 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

bool	vec3_equal(t_vec3 v1, t_vec3 v2)
{
	unsigned short	r;

	r = 0;
	while (r < 3)
	{
		if (!equalf(v1.data[r], v2.data[r]))
			return (0);
		r++;
	}
	return (1);
}
