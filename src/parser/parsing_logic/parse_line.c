/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:06:06 by achappui          #+#    #+#             */
/*   Updated: 2024/08/14 07:30:53 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse_line(t_scene_data *scene_data, const char *line)
{
	char	**tokens;

	tokens = ft_split(line, " \n");
	if (tokens == NULL)
		return (ERROR);
	else if (*tokens == NULL)
	{
		free_array2d(tokens);
		return (0);
	}
	if (type_interpreter(tokens, scene_data) == ERROR)
		return (ERROR);
	free_array2d(tokens);
	return (0);
}