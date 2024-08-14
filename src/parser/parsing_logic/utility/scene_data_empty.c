/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_data_empty.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:48:04 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/14 14:20:15 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_scene_data	scene_data_empty()
{
	t_scene_data	new_empty_scene_data;

	new_empty_scene_data.objects = NULL;
	new_empty_scene_data.lights = NULL;
	new_empty_scene_data.ambient_lights = NULL;
	new_empty_scene_data.cameras = NULL;
	return (new_empty_scene_data);
}
