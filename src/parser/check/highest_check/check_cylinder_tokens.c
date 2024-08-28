/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinder_tokens.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:43:49 by achappui          #+#    #+#             */
/*   Updated: 2024/08/28 11:50:39 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_cylinder_tokens(char **tokens)
{
	if (tokens == NULL)
		exit_error("NULL parameter", "check_cylinder_tokens()");
	if (ft_array2d_size((const void **)tokens) != 6)
		exit_error("cylinder has incorrect number of arguments", \
		"check_cylinder_tokens()");
	check_vec3_token(tokens[1]);
	check_vec3_token(tokens[2]);
	check_float_token(tokens[3]);
	check_float_token(tokens[4]);
	check_color_token(tokens[5]);
}