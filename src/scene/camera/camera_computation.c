/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_computation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:25:56 by achappui          #+#    #+#             */
/*   Updated: 2024/08/16 16:42:50 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	camera_computation(t_camera *camera)
{
	float		aspect;
	float		half_view;

	camera->hsize = CAMERA_HSIZE;
	camera->vsize = CAMERA_VSIZE;
	half_view = tan(camera->h_fov / 2);
	aspect = camera->hsize / camera->vsize; //et si vsize est 0 ? est-ce possible
	if (aspect >= 1)
	{
		camera->half_width = half_view;
		camera->half_height = half_view / aspect;
	}
	else
	{
		camera->half_width = half_view * aspect;
		camera->half_height = half_view;
	}
	camera->pixel_size = (camera->half_width * 2) / camera->hsize;
}