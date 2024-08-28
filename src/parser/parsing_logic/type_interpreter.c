/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_interpreter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:25:31 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:29:25 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	type_interpreter(char **tokens, t_scene_data *scene_data)
{
	if (!tokens || !scene_data)
		exit_error("NULL parameter", "type_interpreter()");
	if (ft_strequiv(tokens[0], "A") && tokens[0][1] == '\0')
	{
		if (ft_lstsize(scene_data->light_ambients) > 0)
			exit_error("you can't have more than 1 ambient light", \
			"type_interpreter()");
		check_light_ambient_tokens(tokens);
		create_light_ambient(tokens, &scene_data->light_ambients);
	}
	else if (ft_strequiv(tokens[0], "L") && tokens[0][1] == '\0')
	{
		if (ft_lstsize(scene_data->light_points) > 0)
			exit_error("you can't have more than 1 light", \
			"type_interpreter()");
		check_light_point_tokens(tokens);
		create_light_point(tokens, &scene_data->light_points);
	}
	else if (ft_strequiv(tokens[0], "C") && tokens[0][1] == '\0')
	{
		if (ft_lstsize(scene_data->cameras) > 0)
			exit_error("you can't have more than 1 camera", \
			"type_interpreter()");
		check_camera_tokens(tokens);
		create_camera(tokens, &scene_data->cameras);
	}
	else if (ft_strequiv(tokens[0], "sp") && tokens[0][2] == '\0')
	{
		check_sphere_tokens(tokens);
		create_sphere(tokens, &scene_data->objects);
	}
	else if (ft_strequiv(tokens[0], "pl") && tokens[0][2] == '\0')
	{
		check_plane_tokens(tokens);
		create_plane(tokens, &scene_data->objects);
	}
	else if (ft_strequiv(tokens[0], "cy") && tokens[0][2] == '\0')
	{
		check_cylinder_tokens(tokens);
		create_cylinder(tokens, &scene_data->objects);
	}
	else
		exit_error("inexisting element type (expected: A L C sp pl cy)", \
		"type_interpreter()");
}
