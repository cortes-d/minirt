/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sphere_tokens.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:44:29 by achappui          #+#    #+#             */
/*   Updated: 2024/08/13 14:56:01 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_sphere_tokens(char **tokens)
{
	if (tokens == NULL)
		return (ERROR);
	if (array_2d_size(tokens) != 4)
		return (ERROR);
	if (check_vec3_token(tokens[1]) == ERROR)
		return (ERROR);
	if (check_float_token(tokens[2]) == ERROR)
		return (ERROR);
	if (check_color_token(tokens[3]) == ERROR)
		return (ERROR);
	return (0);
}