/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_light_ambient_tokens.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:23:05 by achappui          #+#    #+#             */
/*   Updated: 2024/08/21 11:04:54 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//on fait du >= sans utiliser de equalf a voir

void	check_light_ambient_tokens(char **tokens)
{
	float	ratio_test;

	if (tokens == NULL)
		exit_error("ERROR: check_light_ambient_tokens()\n");
	if (ft_array2d_size((const void **)tokens) != 3)
		exit_error("ERROR: check_light_ambient_tokens()\n");
	check_float_token(tokens[1]);
	ratio_test = extract_float(tokens[1]);
	if (!(ratio_test >= 0.0f && ratio_test <= 1.0f))
		exit_error("ERROR: check_light_ambient_tokens()\n");
	check_color_token(tokens[2]);
}