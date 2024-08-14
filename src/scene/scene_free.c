/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:48:04 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/14 16:07:44 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "scene.h"

void	scene_free(t_scene *scene)
{
	//unsigned int	i;

	if (scene->camera)
		free(scene->camera);
	if (scene->light_ambient)
		free(scene->light_ambient);
	if (scene->light_point)
		free(scene->light_point);
	/*if (scene->objects)
		free_array_2d(scene->objects);*/
}
