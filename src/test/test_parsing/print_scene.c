/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:09:36 by achappui          #+#    #+#             */
/*   Updated: 2024/08/14 14:57:37 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	print_scene(t_scene *scene)
{
	unsigned int	i;
	if (scene->camera)
		printf("C\n");
	if (scene->ambient_light)
		printf("A %f %.0f,%.0f,%.0f\n", scene->ambient_light.lighting_ratio,  scene->ambient_light.color.data[R], scene->ambient_light.color.data[G], scene->ambient_light.color.data[B]);
	if (scene->light)
		printf("L %.0f,%.0f,%.0f %f %.0f,%.0f,%.0f\n", scene->light.);
	if (scene->objects)
	{
		i = 0;
		while (scene->objects[i] != NULL)
		{
			if (scene->objects.type == SPHERE)
			{
				printf("sp \n", );
			}
			else if (scene->objects.type == CYLINDER)
			{
				printf("cy \n", );
			}
			else if (scene->objects.type == PLANE)
			{
				printf("pl \n", );
			}
			i++;
		}
	}
}
