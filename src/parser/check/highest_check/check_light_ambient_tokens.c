/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_light_ambient_tokens.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:23:05 by achappui          #+#    #+#             */
/*   Updated: 2024/08/15 09:45:00 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//on fait du >= sans utiliser de equalf a voir

int	check_light_ambient_tokens(char **tokens)
{
	float	ratio_test;

	if (tokens == NULL)
		return (ERROR);
	if (ft_array2d_size((const void **)tokens) != 3)
		return (ERROR);
	if (check_float_token(tokens[1]) == ERROR)
		return (ERROR);
	ratio_test = extract_float(tokens[1]);
	if (!(ratio_test >= 0.0f && ratio_test <= 1.0f))
		return (ERROR);
	if (check_color_token(tokens[2]) == ERROR)
		return (ERROR);
	return (0);
}