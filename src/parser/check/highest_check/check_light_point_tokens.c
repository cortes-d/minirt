/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_light_point_tokens.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:44:19 by achappui          #+#    #+#             */
/*   Updated: 2024/08/15 09:45:02 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//on fait du >= sans utiliser de equalf a voir

int	check_light_point_tokens(char **tokens)
{
	float	ratio_test;

	if (tokens == NULL)
		return (ERROR);
	if (ft_array2d_size((const void **)tokens) != 4)
		return (ERROR);
	if (check_vec3_token(tokens[1]) == ERROR)
		return (ERROR);
	if (check_float_token(tokens[2]) == ERROR)
		return (ERROR);
	ratio_test = extract_float(tokens[2]);
	if (!(ratio_test >= 0.0f && ratio_test <= 1.0f))
		return (ERROR);
	if (check_color_token(tokens[3]) == ERROR)
		return (ERROR);
	return (0);
}