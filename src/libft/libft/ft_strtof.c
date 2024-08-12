/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:17:40 by achappui          #+#    #+#             */
/*   Updated: 2024/08/12 12:53:13 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static float	integer_part(const char **str)
{
	float	int_part;

	int_part = 0;
	while (**str >= '0' && **str <= '9')
	{
		int_part = int_part * 10 + **str - 48;
		(*str)++;
	}
	return (int_part);
}

static float	decimal_part(const char **str)
{
	float	dec_part;
	float	divider;

	dec_part = 0;
	divider = 10;
	while (**str >= '0' && **str <= '9')
	{
		dec_part += (**str - 48) / divider;
		divider *= 10;
		(*str)++;
	}
	return (dec_part);
}

float	ft_strtof(const char *str, char **endptr)
{
	int		sign;
	float	number;

	number = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	number += integer_part(&str);
	if (*str == '.')
	{
		str++;
		number += decimal_part(&str);
	}
	if (endptr)
		*endptr = (char *)str;
	return (number * sign);
}
