/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_uchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:39:54 by achappui          #+#    #+#             */
/*   Updated: 2024/08/28 11:15:56 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_uchar(const char **str)
{
	unsigned int	size_test;

	if (!((**str >= '0' && **str <= '9') || **str == '+'))
		exit_error("invalid color value", "check_uchar()");
	if (**str == '+')
		(*str)++;
	if (!(**str >= '0' && **str <= '9'))
		exit_error("invalid color value", "check_uchar()");
	while (**str == '0' && *(*str + 1) == '0')
		(*str)++;
	size_test = 0;
	while (**str >= '0' && **str <= '9')
	{
		size_test *= 10;
		size_test += **str - 48;
		if (size_test > 255)
			exit_error("invalid color value(must be between 0 and 255)", \
			"check_uchar()");
		(*str)++;
	}
}
