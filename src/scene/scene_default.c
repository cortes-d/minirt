/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:14:56 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/16 15:39:08 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "scene.h"

t_scene	scene_default(void)
{
	t_scene			scene;
	t_light_point	*light;
	t_object		*s1;
	t_object		*s2;

	light = malloc(sizeof(t_light_point));
	*light = light_point(point(-10, 10, -10), 1, color_rgb_f(1, 1, 1));
	s1 = malloc(sizeof(t_object));
	*s1 = cylinder_default();
	s1->material.color = color_rgb_f(0.8, 1.0, 0.6);
	s1->material.diffuse = 0.7;
	s1->material.specular = 0.2;
	s2 = malloc(sizeof(t_object));
	*s2 = sphere_default();
	add_transform(s2, mat4_scaling(0.5, 0.5, 0.5));

	scene.light_point = light;
	scene.objects = malloc(sizeof(t_object *) * 3);
	scene.objects[0] = s1;
	scene.objects[1] = s2;
	scene.objects[2] = NULL;
	return (scene);
}
