/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_float_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:35:45 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/14 09:23:44 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_float_token(const char *str)
{
	if (check_float(&str) == ERROR)
		return (ERROR);
	if (*str != '\0')
		return (ERROR);
	return (0);
}
