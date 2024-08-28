/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:09:36 by achappui          #+#    #+#             */
/*   Updated: 2024/08/28 11:24:26 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_scene(void)
{
	t_scene_static	*scene_static;
	t_scene_data	scene_data;

	scene_static = *scene_static_get();
	scene_data = scene_data_empty();
	scene_static->fd = open(scene_static->path, O_RDONLY);
	if (scene_static->fd == -1)
		exit_error("open failed", "parse_scene()");
	parsing_loop(&scene_data, scene_static->fd);
	if (close(scene_static->fd) == -1)
		exit_error("close failed", "parse_scene()");
	scene_data_to_scene(&scene_data);
	scene_data_free(&scene_data);
}
