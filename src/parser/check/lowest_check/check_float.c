/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:36:28 by achappui          #+#    #+#             */
/*   Updated: 2024/09/02 12:14:41 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	check_before_dot(const char **str, unsigned int *digit_number)
{
	if (!((**str >= '0' && **str <= '9') || **str == '+' || **str == '-'))
		exit_error("invalid float value", "check_float()");
	if (**str == '+' || **str == '-')
		(*str)++;
	if (!((**str >= '0' && **str <= '9') || **str == '.'))
		exit_error("invalid float value", "check_float()");
	while (**str == '0' && *(*str + 1) == '0')
		(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		if (++(*digit_number) > MAX_FLOAT_DIGIT)
			exit_error("invalid float value(6 digits total is max)", \
			"check_float()");
		(*str)++;
	}
}

static void	check_after_dot(const char **str, unsigned int *digit_number)
{
	while (**str >= '0' && **str <= '9')
	{
		if (++(*digit_number) > MAX_FLOAT_DIGIT)
			exit_error("invalid float value(6 digits total is max)", \
			"check_float()");
		(*str)++;
	}
}

void	check_float(const char **str)
{
	unsigned int	digit_number;

	digit_number = 0;
	check_before_dot(str, &digit_number);
	if (**str != '.')
		return ;
	(*str)++;
	check_after_dot(str, &digit_number);
}
