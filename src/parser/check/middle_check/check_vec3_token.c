/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vec3_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:11:22 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/21 11:05:30 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_vec3_token(const char *str)
{
	check_float(&str);
	if (*str != ',')
		exit_error("ERROR: check_vec3_token()\n");
	str++;
	check_float(&str);
	if (*str != ',')
		exit_error("ERROR: check_vec3_token()\n");
	str++;
	check_float(&str);
	if (*str != '\0')
		exit_error("ERROR: check_vec3_token()\n");
}
