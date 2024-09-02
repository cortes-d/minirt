/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_data_to_scene.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:08:50 by achappui          #+#    #+#             */
/*   Updated: 2024/09/02 10:09:21 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	move_objects(unsigned int size, \
	t_scene_data *scene_data, t_scene *scene)
{
	unsigned int	i;
	t_list			*current;

	i = 0;
	current = scene_data->objects;
	while (i < size)
	{
		scene->objects[i] = current->content;
		current->content = NULL;
		current = current->next;
		i++;
	}
}

static void	move_camera(t_scene_data *scene_data, t_scene *scene)
{
	if (scene_data->cameras)
	{
		scene->camera = scene_data->cameras->content;
		scene_data->cameras->content = NULL;
	}
}

static void	move_light_point(t_scene_data *scene_data, t_scene *scene)
{
	if (scene_data->light_points)
	{
		scene->light_point = scene_data->light_points->content;
		scene_data->light_points->content = NULL;
	}
}

static void	move_light_ambient(t_scene_data *scene_data, t_scene *scene)
{
	if (scene_data->light_ambients)
	{
		scene->light_ambient = scene_data->light_ambients->content;
		scene_data->light_ambients->content = NULL;
	}
}

void	scene_data_to_scene(t_scene_data *scene_data)
{
	t_scene_static	*scene_static;
	unsigned int	size;

	scene_static = *scene_static_get();
	size = ft_lstsize(scene_data->objects);
	scene_static->scene.objects = gc_add(\
	(t_object **)malloc((size + 1) * sizeof(t_object *)), 1);
	if (scene_static->scene.objects == NULL)
		exit_error("malloc failed", "scene_data_to_scene()");
	scene_static->scene.objects[size] = NULL;
	move_objects(size, scene_data, &scene_static->scene);
	move_camera(scene_data, &scene_static->scene);
	move_light_point(scene_data, &scene_static->scene);
	move_light_ambient(scene_data, &scene_static->scene);
}
