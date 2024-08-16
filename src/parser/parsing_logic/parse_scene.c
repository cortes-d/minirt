/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:09:36 by achappui          #+#    #+#             */
/*   Updated: 2024/08/16 15:53:21 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse_scene(char *file_name, t_scene *scene)
{
	t_scene_data	scene_data;
	int				fd;

	scene_data = scene_data_empty();
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ERROR);
	if (parsing_loop(&scene_data, fd) == ERROR)
	{
		if (close(fd) == -1)
			return (ERROR);
		return (ERROR);
	}
	if (close(fd) == -1)
		return (ERROR);
	if (scene_data_to_scene(&scene_data, scene) == ERROR)
		return (ERROR);
	free_scene_data(&scene_data);
	return (0);
}
