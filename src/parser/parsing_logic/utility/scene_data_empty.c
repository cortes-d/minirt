/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_data_empty.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:48:04 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/26 17:00:41 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_scene_data	scene_data_empty()
{
	t_scene_data	new_empty_scene_data;

	new_empty_scene_data.objects = NULL;
	new_empty_scene_data.light_points = NULL;
	new_empty_scene_data.light_ambients = NULL;
	new_empty_scene_data.cameras = NULL;
	return (new_empty_scene_data);
}
