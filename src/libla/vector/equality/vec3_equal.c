/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_equal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 08:36:51 by achappui          #+#    #+#             */
/*   Updated: 2024/08/02 16:13:09 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

bool	vec3_equal(const t_vec3 *v1, const t_vec3 *v2)
{
	unsigned short	r;

	r = 0;
	while (r < 3)
	{
		if (!equalf(v1->data[r], v2->data[r]))
			return (0);
		r++;
	}
	return (1);
}