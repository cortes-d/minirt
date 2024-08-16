/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:48:04 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/16 15:19:16 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	scene_free(t_scene *scene)
{
	if (scene->camera)
		free(scene->camera);
	if (scene->light_ambient)
		free(scene->light_ambient);
	if (scene->light_point)
		free(scene->light_point);
	if (scene->objects)
		ft_free_array2d((void **)scene->objects);
}
