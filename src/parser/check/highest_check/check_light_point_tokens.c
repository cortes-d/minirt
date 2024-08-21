/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_light_point_tokens.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:44:19 by achappui          #+#    #+#             */
/*   Updated: 2024/08/21 11:04:57 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//on fait du >= sans utiliser de equalf a voir

void	check_light_point_tokens(char **tokens)
{
	float	ratio_test;

	if (tokens == NULL)
		exit_error("ERROR: check_light_point_tokens()\n");
	if (ft_array2d_size((const void **)tokens) != 4)
		exit_error("ERROR: check_light_point_tokens()\n");
	check_vec3_token(tokens[1]);
	check_float_token(tokens[2]);
	ratio_test = extract_float(tokens[2]);
	if (!(ratio_test >= 0.0f && ratio_test <= 1.0f))
		exit_error("ERROR: check_light_point_tokens()\n");
	check_color_token(tokens[3]);
}