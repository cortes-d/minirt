/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_interpreter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:25:31 by dcortes           #+#    #+#             */
/*   Updated: 2024/09/02 12:16:12 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	type_interpreter_unique_entities(char **tokens, \
											t_scene_data *scene_data)
{
	if (ft_strequiv(tokens[0], "A") && tokens[0][1] == '\0')
	{
		if (ft_lstsize(scene_data->light_ambients) > 0)
			exit_error("A can only appear once", "type_interpreter()");
		check_light_ambient_tokens(tokens);
		create_light_ambient(tokens, &scene_data->light_ambients);
		return (1);
	}
	else if (ft_strequiv(tokens[0], "L") && tokens[0][1] == '\0')
	{
		if (ft_lstsize(scene_data->light_points) > 0)
			exit_error("L can only appear once", "type_interpreter()");
		check_light_point_tokens(tokens);
		create_light_point(tokens, &scene_data->light_points);
		return (1);
	}
	else if (ft_strequiv(tokens[0], "C") && tokens[0][1] == '\0')
	{
		if (ft_lstsize(scene_data->cameras) > 0)
			exit_error("C can only appear once", "type_interpreter()");
		check_camera_tokens(tokens);
		create_camera(tokens, &scene_data->cameras);
		return (1);
	}
	return (0);
}

static int	type_interpreter_entities(char **tokens, t_scene_data *scene_data)
{
	if (ft_strequiv(tokens[0], "sp") && tokens[0][2] == '\0')
	{
		check_sphere_tokens(tokens);
		create_sphere(tokens, &scene_data->objects);
		return (1);
	}
	else if (ft_strequiv(tokens[0], "pl") && tokens[0][2] == '\0')
	{
		check_plane_tokens(tokens);
		create_plane(tokens, &scene_data->objects);
		return (1);
	}
	else if (ft_strequiv(tokens[0], "cy") && tokens[0][2] == '\0')
	{
		check_cylinder_tokens(tokens);
		create_cylinder(tokens, &scene_data->objects);
		return (1);
	}
	return (0);
}

void	type_interpreter(char **tokens, t_scene_data *scene_data)
{
	if (!tokens || !scene_data)
		exit_error("NULL parameter", "type_interpreter()");
	if (type_interpreter_unique_entities(tokens, scene_data) == 0 && \
		type_interpreter_entities(tokens, scene_data) == 0)
	{
		exit_error("inexisting element type (expected: A L C sp pl cy)", \
		"type_interpreter()");
	}
}
