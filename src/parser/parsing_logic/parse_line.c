/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:06:06 by achappui          #+#    #+#             */
/*   Updated: 2024/08/16 16:53:11 by achappui         ###   ########.fr       */
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
		ft_free_array2d((void **)tokens);
		return (0);
	}
	if (type_interpreter(tokens, scene_data) == ERROR)
		return (ERROR);
	ft_free_array2d((void **)tokens);
	return (0);
}