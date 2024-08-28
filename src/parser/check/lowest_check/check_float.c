/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:36:28 by achappui          #+#    #+#             */
/*   Updated: 2024/08/28 11:14:59 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_float(const char **str)
{
	unsigned int	digit_number;

	if (!((**str >= '0' && **str <= '9') || **str == '+' || **str == '-'))
		exit_error("invalid float value", "check_float()");
	if (**str == '+' || **str == '-')
		(*str)++;
	if (!((**str >= '0' && **str <= '9') || **str == '.'))
		exit_error("invalid float value", "check_float()");
	while (**str == '0' && *(*str + 1) == '0')
		(*str)++;
	digit_number = 0;
	while (**str >= '0' && **str <= '9')
	{
		if (++digit_number > MAX_FLOAT_DIGIT)
			exit_error("invalid float value(6 digits total is max)", \
			"check_float()");
		(*str)++;
	}
	if (**str != '.')
		return ;
	(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		if (++digit_number > MAX_FLOAT_DIGIT)
			exit_error("invalid float value(6 digits total is max)", \
			"check_float()");
		(*str)++;
	}
}
