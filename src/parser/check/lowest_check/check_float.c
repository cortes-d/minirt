/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:36:28 by achappui          #+#    #+#             */
/*   Updated: 2024/08/21 11:43:37 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_float(const char **str)
{
	unsigned int	digit_number;

	if (!((**str >= '0' && **str <= '9') || **str == '+' || **str == '-'))
		exit_error("ERROR: check_float()\n");
	if (**str == '+' || **str == '-')
		(*str)++;
	if (!((**str >= '0' && **str <= '9') || **str == '.'))
		exit_error("ERROR: check_float()\n");
	while (**str == '0' && *(*str + 1) == '0')
		(*str)++;
	digit_number = 0;
	while (**str >= '0' && **str <= '9')
	{
		if (++digit_number > MAX_FLOAT_DIGIT)
			exit_error("ERROR: check_float()\n");
		(*str)++;
	}
	if (**str != '.')
		return ;
	(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		if (++digit_number > MAX_FLOAT_DIGIT)
			exit_error("ERROR: check_float()\n");
		(*str)++;
	}
}
