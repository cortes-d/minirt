/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_data_empty.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:48:04 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/14 14:15:30 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_scene_data	scene_data_empty()
{
	t_scene_data	new_empty_scene_data;
	unsigned int	i;

	new_empty_scene_data.objects = NULL;
	new_empty_scene_data.light = NULL;
	new_empty_scene_data.ambient_light = NULL;
	new_empty_scene_data.camera = NULL;
	i = 0;
	while (i < UPPERCASE_NB)
	{
		new_empty_scene_data.uppercase_check[i] = 0;
		i++;
	}
}
