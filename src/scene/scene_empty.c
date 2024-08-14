/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_empty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:48:07 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/14 16:05:40 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_scene	scene_empty(void)
{
	t_scene	new_empty_scene;

	new_empty_scene.camera = NULL;
	new_empty_scene.light_ambient = NULL;
	new_empty_scene.light_point = NULL;
	new_empty_scene.objects = NULL;
	return (new_empty_scene);
}
