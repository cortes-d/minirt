/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_at_index_n.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:56:58 by achappui          #+#    #+#             */
/*   Updated: 2024/08/12 12:05:16 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

const char	*elem_at_index_n(const char *str, unsigned int n)
{
	unsigned int	comma_count;
	unsigned int	i;

	comma_count = 0;
	while (n != comma_count && str[i] != '\0')
	{
		if (str[i] == ',')
			comma_count++;
		i++;
	}
	if (comma_count > 0)
		return (str + i + 1);
	return (str);
}