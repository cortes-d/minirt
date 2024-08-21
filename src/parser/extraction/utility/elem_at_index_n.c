/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_at_index_n.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:56:58 by achappui          #+#    #+#             */
/*   Updated: 2024/08/21 11:52:47 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

const char	*elem_at_index_n(const char *str, unsigned int n)
{
	unsigned int	comma_count;
	unsigned int	i;

	comma_count = 0;
	i = 0;
	while (n != comma_count && str[i] != '\0')
	{
		if (str[i] == ',')
			comma_count++;
		i++;
	}
	if (comma_count > 0)
		return (str + i);
	return (str);
}
