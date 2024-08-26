/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:09:36 by achappui          #+#    #+#             */
/*   Updated: 2024/08/26 09:24:51 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_scene(char *file_name, t_scene *scene)
{
	t_scene_static	*scene_static;
	t_scene_data	scene_data;

	scene_static = *scene_static_get();
	scene_data = scene_data_empty();
	scene_static->fd = open(file_name, O_RDONLY);
	if (scene_static->fd == -1)
		exit_error("ERROR: parse_scene()\n");
	parsing_loop(&scene_data, scene_static->fd);
	if (close(scene_static->fd) == -1)
		exit_error("ERROR: parse_scene()\n");
	scene_data_to_scene(&scene_data, scene);
	scene_data_free(&scene_data);
}
