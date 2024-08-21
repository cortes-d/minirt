/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_float_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:35:45 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/21 11:58:29 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_float_token(const char *str)
{
	check_float(&str);
	if (*str != '\0')
		exit_error("ERROR: check_float_token()\n");
}
