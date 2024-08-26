/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:52:40 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/26 16:48:08 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "raytracer.h"

void	render(t_scene scene, t_image *image)
{
	unsigned int	x;
	unsigned int	y;
	t_ray			r;
	t_vec3			c;

	if (scene.camera == NULL)
	{
		render_nothing(image);
		return ;
	}
	y = 0;
	while (y < scene.camera->vsize)
	{
		x = 0;
		while (x < scene.camera->hsize)
		{
			r = ray_for_pixel(*scene.camera, x, y);
			c = color_at(r, scene);
			write_pixel(image, x, y, c);
			x++;
		}
		y++;
	}
}
