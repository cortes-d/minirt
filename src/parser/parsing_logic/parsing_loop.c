/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:09:36 by achappui          #+#    #+#             */
/*   Updated: 2024/08/26 14:25:28 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parsing_loop(t_scene_data *scene_data, int fd)
{
	char	*line;


	line = get_next_line(fd);
	if (line == (void *)-1)
		exit_error("ERROR: parsing_loop()\n");
	else if (line == NULL)
		return ;
	if (gc_add(line, 0) == NULL)
		exit_error("ERROR: parsing_loop()\n");
	while (line)
	{
		parse_line(scene_data, line);
		gc_free(line);
		line = get_next_line(fd);
		if (line == (void *)-1)
			exit_error("ERROR: parsing_loop()\n");
		else if (line == NULL)
			return ;
		if (gc_add(line, 0) == NULL)
			exit_error("ERROR: parsing_loop()\n");
	}
}
