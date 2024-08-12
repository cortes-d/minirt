/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_float_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:36:28 by achappui          #+#    #+#             */
/*   Updated: 2024/08/12 14:15:37 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raytracer.h"
#define		MAX_DIGITS	7

int	str_float_check(const char **str)
{
	unsigned int	digit_number;

	if (!((**str >= '0' && **str <= '9') || **str == '+' || **str == '-'))
		return (ERROR);
	(*str)++;
	if (!((**str >= '0' && **str <= '9') || **str == '.'))
		return (ERROR);
	while (**str == '0' && *(*str + 1) == '0')
		(*str)++;
	digit_number = 0;
	while (**str >= '0' && **str <= '9')
	{
		if (++digit_number > MAX_DIGITS)
			return (ERROR);
		(*str)++;
	}
	if (**str != '.')
		return (0);
	while (**str >= '0' && **str <= '9')
	{
		if (++digit_number > MAX_DIGITS)
			return (ERROR);
		(*str)++;
	}
	return (0);
}
