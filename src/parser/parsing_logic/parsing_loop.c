/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:09:36 by achappui          #+#    #+#             */
/*   Updated: 2024/08/21 11:34:08 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parsing_loop(t_scene_data *scene_data, int fd)
{
	char	*line;

	line = gc_add(get_next_line(fd), 1);
	if (line == (void *)-1)
		exit_error("ERROR: parsing_loop()\n");
	else if (line == NULL)
		return ;
	while (line)
	{
		parse_line(scene_data, line);
		gc_free(line);
		line = gc_add(get_next_line(fd), 1);
		if (line == (void *)-1)
			exit_error("ERROR: parsing_loop()\n");
		else if (line == NULL)
			return ;
	}
}
