/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:48:07 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:16:28 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_color_token(const char *str)
{
	check_uchar(&str);
	if (*str != ',')
		exit_error("invalid color format", "check_color_token()");
	str++;
	check_uchar(&str);
	if (*str != ',')
		exit_error("invalid color format", "check_color_token()");
	str++;
	check_uchar(&str);
	if (*str != '\0')
		exit_error("invalid color format", "check_color_token()");
}
