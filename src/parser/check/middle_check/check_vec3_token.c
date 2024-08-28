/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vec3_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:11:22 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:16:41 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_vec3_token(const char *str)
{
	check_float(&str);
	if (*str != ',')
		exit_error("invalid vector format", "check_vec3_token()");
	str++;
	check_float(&str);
	if (*str != ',')
		exit_error("invalid vector format", "check_vec3_token()");
	str++;
	check_float(&str);
	if (*str != '\0')
		exit_error("invalid vector format", "check_vec3_token()");
}
