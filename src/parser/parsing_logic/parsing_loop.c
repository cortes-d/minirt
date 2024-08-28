/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:09:36 by achappui          #+#    #+#             */
/*   Updated: 2024/08/28 11:25:16 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parsing_loop(t_scene_data *scene_data, int fd)
{
	char	*line;


	line = get_next_line(fd);
	if (line == (void *)-1)
		exit_error("get_next_line failed", "parsing_loop()");
	else if (line == NULL)
		return ;
	if (gc_add(line, 0) == NULL)
		exit_error("gc_add failed", "parsing_loop()");
	while (line)
	{
		parse_line(scene_data, line);
		gc_free(line);
		line = get_next_line(fd);
		if (line == (void *)-1)
			exit_error("get_next_line failed", "parsing_loop()");
		else if (line == NULL)
			return ;
		if (gc_add(line, 0) == NULL)
			exit_error("gc_add failed", "parsing_loop()");
	}
}
