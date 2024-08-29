/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_computation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:33:40 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/29 08:33:40 by dcortes          ###   ########.ch       */
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
	aspect = camera->hsize / camera->vsize;
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
