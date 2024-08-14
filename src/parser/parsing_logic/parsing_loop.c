/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:09:36 by achappui          #+#    #+#             */
/*   Updated: 2024/08/13 14:07:05 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parsing_loop(t_scene_data *scene_data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (errno != 0)
		return (ERROR);
	else if (line == NULL)
		return (0);
	while (line)
	{
		if (parse_line(scene_data, line) == ERROR)
		{
			free(line);
			return (ERROR);
		}
		free(line);
		line = get_next_line(fd);
		if (errno != 0)
			return (ERROR);
		else if (line == NULL)
			return (0);
	}
	return (0);
}
