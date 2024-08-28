/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_light_point_tokens.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:44:19 by achappui          #+#    #+#             */
/*   Updated: 2024/08/28 11:12:56 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_light_point_tokens(char **tokens)
{
	float	ratio_test;

	if (tokens == NULL)
		exit_error("NULL parameter", "check_light_point_tokens()");
	if (ft_array2d_size((const void **)tokens) != 4)
		exit_error("light has incorrect number of arguments", \
		"check_light_point_tokens()");
	check_vec3_token(tokens[1]);
	check_float_token(tokens[2]);
	ratio_test = extract_float(tokens[2]);
	if (!(ratio_test >= 0.0f && ratio_test <= 1.0f))
		exit_error("light ratio must be between 0 and 1", \
		"check_light_point_tokens()");
	check_color_token(tokens[3]);
}