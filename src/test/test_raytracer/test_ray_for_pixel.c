/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ray_for_pixel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:20:31 by achappui          #+#    #+#             */
/*   Updated: 2024/08/14 16:21:31 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_raytracer.h"

t_ray	test_ray_for_pixel(unsigned int px, unsigned int py)
{
	t_vec4	origin;
	float	world_x;
	float	world_y;

	world_x = PIXEL_SIZE * HALF_WIDTH - (px + 0.5) * PIXEL_SIZE;
	world_y = PIXEL_SIZE * HALF_HEIGHT - (py + 0.5) * PIXEL_SIZE;
	origin = point(world_x, world_y, CANVA_Z_POS);
	return (ray(origin, vector(0, 0, -1)));
}
