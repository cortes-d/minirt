/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:31:12 by achappui          #+#    #+#             */
/*   Updated: 2024/08/16 16:04:51 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_parser.h"
/*
void	test_print_scene(t_scene *scene)
{
	unsigned int	i;

	if (scene->camera)
		printf("C\n");
	if (scene->light_ambient)
		printf("A %f %.0f,%.0f,%.0f\n", scene->light_ambient->lightning_ratio, \
		scene->light_ambient->color.data[R], scene->light_ambient->color.data[G], scene->light_ambient->color.data[B]);
	if (scene->light_point)
		printf("L %.0f,%.0f,%.0f %f %.0f,%.0f,%.0f\n", \
		scene->light_point->p_origin.data[X], scene->light_point->p_origin.data[Y], scene->light_point->p_origin.data[Z], \
		scene->light_point->brightness, \
		scene->light_point->color.data[R], scene->light_point->color.data[G], scene->light_point->color.data[B]);
	if (scene->objects)
	{
		i = 0;
		while (scene->objects[i] != NULL)
		{
			if (scene->objects[i]->type == SPHERE)
			{
				printf("sp %.0f,%.0f,%.0f %f %.0f,%.0f,%.0f\n", \
				scene->objects[i]->u_object.sphere.p_origin.data[X], scene->objects[i]->u_object.sphere.p_origin.data[Y], scene->objects[i]->u_object.sphere.p_origin.data[Z], \
				scene->objects[i]->u_object.sphere.radius, \
				scene->objects[i]->material.color.data[R], scene->objects[i]->material.color.data[G], scene->objects[i]->material.color.data[B]);
			}
			else if (scene->objects[i]->type == CYLINDER)
			{
				printf("cy %.0f,%.0f,%.0f %.0f,%.0f,%.0f %f %f %.0f,%.0f,%.0f\n", \
				scene->objects[i]->u_object.cylinder.p_origin.data[X], scene->objects[i]->u_object.cylinder.p_origin.data[Y], scene->objects[i]->u_object.cylinder.p_origin.data[Z], \
				scene->objects[i]->u_object.cylinder.v_axis.data[X], scene->objects[i]->u_object.cylinder.v_axis.data[Y], scene->objects[i]->u_object.cylinder.v_axis.data[Z], \
				scene->objects[i]->u_object.cylinder.diameter, \
				scene->objects[i]->u_object.cylinder.height, \
				scene->objects[i]->material.color.data[R], scene->objects[i]->material.color.data[G], scene->objects[i]->material.color.data[B]);
			}
			else if (scene->objects[i]->type == PLANE)
			{
				printf("pl %.0f,%.0f,%.0f %.0f,%.0f,%.0f %.0f,%.0f,%.0f\n", \
				scene->objects[i]->u_object.plane.p_point.data[X], scene->objects[i]->u_object.plane.p_point.data[Y], scene->objects[i]->u_object.plane.p_point.data[Z], \
				scene->objects[i]->u_object.plane.v_normal.data[X], scene->objects[i]->u_object.plane.v_normal.data[Y], scene->objects[i]->u_object.plane.v_normal.data[Z], \
				scene->objects[i]->material.color.data[R], scene->objects[i]->material.color.data[G], scene->objects[i]->material.color.data[B]);
			}
			i++;
		}
	}
}
*/