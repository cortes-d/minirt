/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_from_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:48:04 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 10:40:48 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_scene(t_scene *scene)
{
	unsigned int	i;

	if (scene->camera)
		free(scene->camera);
	if (scene->ambient_light)
		free(scene->ambient_light);
	if (scene->light)
		free(scene->light);
	if (scene->objects)
		free_array_2d(scene->objects);
}
