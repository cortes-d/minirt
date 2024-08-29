/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_light_ambient_tokens.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:48:46 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/29 08:48:46 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_light_ambient_tokens(char **tokens)
{
	float	ratio_test;

	if (tokens == NULL)
		exit_error("NULL parameter", "check_light_ambient_tokens()");
	if (ft_array2d_size((const void **)tokens) != 3)
		exit_error("ambient light has incorrect number of arguments", \
		"check_light_ambient_tokens()");
	check_float_token(tokens[1]);
	ratio_test = extract_float(tokens[1]);
	if (!(ratio_test >= 0.0f && ratio_test <= 1.0f))
		exit_error("abmient light ratio must be between 0 and 1", \
		"check_light_ambient_tokens()");
	check_color_token(tokens[2]);
}
