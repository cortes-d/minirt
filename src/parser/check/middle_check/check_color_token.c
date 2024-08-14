/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:48:07 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/14 09:23:38 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_color_token(const char *str)
{
	if (check_uchar(&str) == ERROR)
		return (ERROR);
	if (*str != ',')
		return (ERROR);
	str++;
	if (check_uchar(&str) == ERROR)
		return (ERROR);
	if (*str != ',')
		return (ERROR);
	str++;
	if (check_uchar(&str) == ERROR)
		return (ERROR);
	if (*str != '\0')
		return (ERROR);
	return (0);
}
