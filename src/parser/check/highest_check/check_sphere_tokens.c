/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sphere_tokens.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:44:29 by achappui          #+#    #+#             */
/*   Updated: 2024/08/21 11:05:03 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_sphere_tokens(char **tokens)
{
	if (tokens == NULL)
		exit_error("ERROR: check_sphere_tokens()\n");
	if (ft_array2d_size((const void **)tokens) != 4)
		exit_error("ERROR: check_sphere_tokens()\n");
	check_vec3_token(tokens[1]);
	check_float_token(tokens[2]);
	check_color_token(tokens[3]);
}