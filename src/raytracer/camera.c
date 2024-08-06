/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:26:33 by achappui          #+#    #+#             */
/*   Updated: 2024/08/06 10:33:38 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

/*
Exemple pour creer une camera

pas tout a fait sur
my_camera = camera(126, 20, 1.25, view_transform(point(2,2,2), vector(1,-2,7), vector(0,1,0)));
*/

t_camera	camera(unsigned int hsize, unsigned int vsize, float field_of_view, t_mat4 view_transform)
{
	t_camera	camera;
	float		pixel_size;
	float		aspect;
	float		half_view;

	camera.view_transform = view_transform;
	camera.hsize = hsize;
	camera.vsize = vsize;
	half_view = tan(field_of_view / 2);
	aspect = camera.hsize / camera.vsize; //et si vsize est 0 ? est-ce possible
	if (aspect >= 1)
	{
		camera.half_width = half_view;
		camera.half_height = half_view / aspect;
	}
	else
	{
		camera.half_width = half_view * aspect;
		camera.half_height = half_view;
	}
	camera.pixel_size = (camera.half_width * 2) / camera.hsize;
	return (camera);
}