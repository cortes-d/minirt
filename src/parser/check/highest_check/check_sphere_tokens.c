/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sphere_tokens.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:44:29 by achappui          #+#    #+#             */
/*   Updated: 2024/08/15 09:45:07 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_sphere_tokens(char **tokens)
{
	if (tokens == NULL)
		return (ERROR);
	if (ft_array2d_size((const void **)tokens) != 4)
		return (ERROR);
	if (check_vec3_token(tokens[1]) == ERROR)
		return (ERROR);
	if (check_float_token(tokens[2]) == ERROR)
		return (ERROR);
	if (check_color_token(tokens[3]) == ERROR)
		return (ERROR);
	return (0);
}