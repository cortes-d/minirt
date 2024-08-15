/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_interpreter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:25:31 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/15 09:43:19 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//partout  ou il y a une erreur il faudrait aussi free l'integralite de scene_data
int	type_interpreter(char **tokens, t_scene_data *scene_data)
{
	if (!tokens || !scene_data)
		return (ERROR); // line with error in the rt file : we should display an error
	if (ft_strequiv(tokens[0], "A") && tokens[0][1] == '\0')
	{
		if (ft_lstsize(scene_data->ambient_lights) > 0) //this if allows us to check if UPPERCASE object are unique
			return (ERROR);
		if (check_light_ambient_tokens(tokens) == ERROR)
			return (ERROR);
		if (create_light_ambient(tokens, &scene_data->ambient_lights) == ERROR)
			return (ERROR);
	}
	else if (ft_strequiv(tokens[0], "L") && tokens[0][1] == '\0')
	{
		if (ft_lstsize(scene_data->lights) > 0) //this if allows us to check if UPPERCASE object are unique
			return (ERROR);
		if (check_light_point_tokens(tokens) == ERROR)
			return (ERROR);
		if (create_light_point(tokens, &scene_data->lights) == ERROR)
			return (ERROR);
	}
	else if (ft_strequiv(tokens[0], "C") && tokens[0][1] == '\0')
	{
		if (ft_lstsize(scene_data->cameras) > 0) //this if allows us to check if UPPERCASE object are unique
			return (ERROR);
		if (check_camera_tokens(tokens) == ERROR)
			return (ERROR);
		if (create_camera(tokens, &scene_data->cameras) == ERROR)
			return (ERROR);
	}
	else if (ft_strequiv(tokens[0], "sp") && tokens[0][1] == '\0')
	{
		if (check_sphere_tokens(tokens) == ERROR)
			return (ERROR);
		if (create_sphere(tokens, &scene_data->objects) == ERROR)
			return (ERROR);
	}
	else if (ft_strequiv(tokens[0], "pl") && tokens[0][1] == '\0')
	{
		if (check_plane_tokens(tokens) == ERROR)
			return (ERROR);
		if (create_plane(tokens, &scene_data->objects) == ERROR)
			return (ERROR);
	}
	else if (ft_strequiv(tokens[0], "cy") && tokens[0][1] == '\0')
	{
		if (check_cylinder_tokens(tokens) == ERROR)
			return (ERROR);
		if (create_cylinder(tokens, &scene_data->objects) == ERROR)
			return (ERROR);
	}
	else
		return (ERROR);
	return (0);
}
