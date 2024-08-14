/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vec3_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:11:22 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/14 09:23:48 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_vec3_token(const char *str)
{
	if (check_float(&str) == ERROR)
		return (ERROR);
	if (*str != ',')
		return (ERROR);
	str++;
	if (check_float(&str) == ERROR)
		return (ERROR);
	if (*str != ',')
		return (ERROR);
	str++;
	if (check_float(&str) == ERROR)
		return (ERROR);
	if (*str != '\0')
		return (ERROR);
	return (0);
}
