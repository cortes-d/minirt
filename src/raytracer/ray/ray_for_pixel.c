/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_for_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:37:17 by achappui          #+#    #+#             */
/*   Updated: 2024/08/06 11:42:48 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_ray	ray_for_pixel(t_camera camera, unsigned int px, unsigned int py)
{
	t_vec4	pixel;
	t_vec4	origin;
	t_vec4	direction;
	float	world_x;
	float	world_y;

	world_x = camera.half_width - (px + 0.5) * camera.pixel_size;
	world_y = camera.half_height - (py + 0.5) * camera.pixel_size;
	pixel = mat4_vec4_mul(mat4_inv(camera.transform), \
	point(world_x, world_y, -1));
	origin = mat4_vec4_mul(mat4_inv(camera.transform), point(0, 0, 0));
	direction = vec4_normalize(vec4_sub(pixel, origin));
	return (ray(origin, direction));
}