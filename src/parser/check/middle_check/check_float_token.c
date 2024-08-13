/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_float_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:35:45 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 14:13:25 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_float_token(const char *str)
{
	if (str_float_check(&str) == ERROR)
		return (ERROR);
	if (*str != '\0')
		return (ERROR);
	return (0);
}
