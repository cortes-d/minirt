/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:48:07 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/21 11:59:33 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_color_token(const char *str)
{
	check_uchar(&str);
	if (*str != ',')
		exit_error("ERROR: check_color_token()\n");
	str++;
	check_uchar(&str);
	if (*str != ',')
		exit_error("ERROR: check_color_token()\n");
	str++;
	check_uchar(&str);
	if (*str != '\0')
		exit_error("ERROR: check_color_token()\n");
}
