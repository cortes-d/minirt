/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:44:39 by achappui          #+#    #+#             */
/*   Updated: 2024/08/21 15:52:34 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_raytracer.h"

void	test_print_scene(t_scene *scene)
{
	unsigned int	i;

	if (scene->light_ambient)
		printf("A %.3f %.0f,%.0f,%.0f\n", scene->light_ambient->ratio, \
		scene->light_ambient->color.data[R] * 255, scene->light_ambient->color.data[G] * 255, scene->light_ambient->color.data[B] * 255);
	if (scene->camera)
		printf("C %.0f,%.0f,%.0f %.0f,%.0f,%.0f %.3f\n", \
		scene->camera->p_origin.data[X], scene->camera->p_origin.data[Y], scene->camera->p_origin.data[Z], \
		scene->camera->v_orientation.data[X], scene->camera->v_orientation.data[Y], scene->camera->v_orientation.data[Z], \
		scene->camera->h_fov * 180 / M_PI);
	if (scene->light_point)
		printf("L %.0f,%.0f,%.0f %.3f %.0f,%.0f,%.0f\n", \
		scene->light_point->p_origin.data[X], scene->light_point->p_origin.data[Y], scene->light_point->p_origin.data[Z], \
		scene->light_point->ratio, \
		scene->light_point->color.data[R] * 255, scene->light_point->color.data[G] * 255, scene->light_point->color.data[B] * 255);
	if (scene->objects)
	{
		i = 0;
		while (scene->objects[i] != NULL)
		{
			if (scene->objects[i]->type == SPHERE)
			{
				printf("sp %.0f,%.0f,%.0f %.3f %.0f,%.0f,%.0f\n", \
				scene->objects[i]->u_object.sphere.p_origin.data[X], scene->objects[i]->u_object.sphere.p_origin.data[Y], scene->objects[i]->u_object.sphere.p_origin.data[Z], \
				scene->objects[i]->u_object.sphere.radius, \
				scene->objects[i]->material.color.data[R] * 255, scene->objects[i]->material.color.data[G] * 255, scene->objects[i]->material.color.data[B] * 255);
			}
			else if (scene->objects[i]->type == CYLINDER)
			{
				printf("cy %.0f,%.0f,%.0f %.0f,%.0f,%.0f %.3f %.3f %.0f,%.0f,%.0f\n", \
				scene->objects[i]->u_object.cylinder.p_origin.data[X], scene->objects[i]->u_object.cylinder.p_origin.data[Y], scene->objects[i]->u_object.cylinder.p_origin.data[Z], \
				scene->objects[i]->u_object.cylinder.v_axis.data[X], scene->objects[i]->u_object.cylinder.v_axis.data[Y], scene->objects[i]->u_object.cylinder.v_axis.data[Z], \
				scene->objects[i]->u_object.cylinder.diameter, \
				scene->objects[i]->u_object.cylinder.height, \
				scene->objects[i]->material.color.data[R] * 255, scene->objects[i]->material.color.data[G] * 255, scene->objects[i]->material.color.data[B] * 255);
			}
			else if (scene->objects[i]->type == PLANE)
			{
				printf("pl %.0f,%.0f,%.0f %.0f,%.0f,%.0f %.0f,%.0f,%.0f\n", \
				scene->objects[i]->u_object.plane.p_point.data[X], scene->objects[i]->u_object.plane.p_point.data[Y], scene->objects[i]->u_object.plane.p_point.data[Z], \
				scene->objects[i]->u_object.plane.v_normal.data[X], scene->objects[i]->u_object.plane.v_normal.data[Y], scene->objects[i]->u_object.plane.v_normal.data[Z], \
				scene->objects[i]->material.color.data[R] * 255, scene->objects[i]->material.color.data[G] * 255, scene->objects[i]->material.color.data[B] * 255);
			}
			i++;
		}
	}
}