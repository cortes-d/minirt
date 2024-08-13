/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_uchar_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:39:54 by achappui          #+#    #+#             */
/*   Updated: 2024/08/12 13:58:47 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_uchar(const char **str)
{
	unsigned int	size_test;

	if (!((**str >= '0' && **str <= '9') || **str == '+'))
		return (ERROR);
	(*str)++;
	if (!(**str >= '0' && **str <= '9'))
		return (ERROR);
	while (**str == '0' && *(*str + 1) == '0')
		(*str)++;
	size_test = 0;
	while (**str >= '0' && **str <= '9')
	{
		size_test *= 10;
		size_test += **str - 48;
		if (size_test > 255)
			return (ERROR);
		(*str)++;
	}
	return (0);
}
