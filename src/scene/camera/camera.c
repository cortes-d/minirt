/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:26:33 by achappui          #+#    #+#             */
/*   Updated: 2024/08/16 16:41:22 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

/*
Exemple pour creer une camera

pas tout a fait sur
my_camera = camera(126, 20, 1.25, view_transform(point(2,2,2), vector(1,-2,7), vector(0,1,0)));
*/

t_camera	camera(t_vec4 p_origin, t_vec4 v_orientation, float h_fov)
{
	t_camera	camera;

	camera.p_origin = p_origin;
	camera.v_orientation = v_orientation;
	camera.h_fov = ft_deg_to_rad(h_fov);
	camera.view_transform = view_transform(p_origin, \
	v_orientation, vector(UP_VECTOR_X, UP_VECTOR_Y, UP_VECTOR_Z));
	camera_computation(&camera);
	return (camera);
}


// t_camera	camera(unsigned int hsize, unsigned int vsize, float field_of_view, t_mat4 transform)
// {
// 	t_camera	camera;
// 	float		aspect;
// 	float		half_view;

// 	camera.transform = transform;
// 	camera.hsize = hsize;
// 	camera.vsize = vsize;
// 	half_view = tan(field_of_view / 2);
// 	aspect = camera.hsize / camera.vsize; //et si vsize est 0 ? est-ce possible
// 	if (aspect >= 1)
// 	{
// 		camera.half_width = half_view;
// 		camera.half_height = half_view / aspect;
// 	}
// 	else
// 	{
// 		camera.half_width = half_view * aspect;
// 		camera.half_height = half_view;
// 	}
// 	camera.pixel_size = (camera.half_width * 2) / camera.hsize;
// 	return (camera);
// }