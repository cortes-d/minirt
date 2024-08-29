/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_data_empty.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:50:00 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/29 08:50:00 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_scene_data	scene_data_empty(void)
{
	t_scene_data	new_empty_scene_data;

	new_empty_scene_data.objects = NULL;
	new_empty_scene_data.light_points = NULL;
	new_empty_scene_data.light_ambients = NULL;
	new_empty_scene_data.cameras = NULL;
	return (new_empty_scene_data);
}
