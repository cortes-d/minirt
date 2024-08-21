/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_uchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:39:54 by achappui          #+#    #+#             */
/*   Updated: 2024/08/21 11:55:36 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_uchar(const char **str)
{
	unsigned int	size_test;

	if (!((**str >= '0' && **str <= '9') || **str == '+'))
		exit_error("ERROR: check_uchar()\n");
	if (**str == '+')
		(*str)++;
	if (!(**str >= '0' && **str <= '9'))
		exit_error("ERROR: check_uchar()\n");
	while (**str == '0' && *(*str + 1) == '0')
		(*str)++;
	size_test = 0;
	while (**str >= '0' && **str <= '9')
	{
		size_test *= 10;
		size_test += **str - 48;
		if (size_test > 255)
			exit_error("ERROR: check_uchar()\n");
		(*str)++;
	}
}
