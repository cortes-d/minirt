/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_color_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:48:07 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 14:13:29 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_color_token(const char *str)
{
	if (str_uchar_check(&str) == ERROR)
		return (ERROR);
	if (*str != ',')
		return (ERROR);
	str++;
	if (str_uchar_check(&str) == ERROR)
		return (ERROR);
	if (*str != ',')
		return (ERROR);
	str++;
	if (str_uchar_check(&str) == ERROR)
		return (ERROR);
	if (*str != '\0')
		return (ERROR);
	return (0);
}
