/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_empty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:48:07 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/14 14:14:54 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_scene	scene_empty()
{
	t_scene	new_empty_scene;

	new_empty_scene.camera = NULL;
	new_empty_scene.ambient_light = NULL;
	new_empty_scene.light = NULL;
	new_empty_scene.objects = NULL;
	return (new_empty_scene);
}
