/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sphere_tokens.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:48:56 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/29 08:48:56 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_sphere_tokens(char **tokens)
{
	if (tokens == NULL)
		exit_error("NULL parameter", "check_sphere_tokens()");
	if (ft_array2d_size((const void **)tokens) != 4)
		exit_error("sphere has incorrect number of arguments", \
		"check_sphere_tokens()");
	check_vec3_token(tokens[1]);
	check_float_token(tokens[2]);
	check_color_token(tokens[3]);
}
