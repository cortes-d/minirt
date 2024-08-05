/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_equal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 08:36:51 by achappui          #+#    #+#             */
/*   Updated: 2024/08/05 15:02:13 by achappui         ###   ########.fr       */
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