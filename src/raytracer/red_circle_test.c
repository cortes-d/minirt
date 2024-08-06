/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_circle_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:33:05 by achappui          #+#    #+#             */
/*   Updated: 2024/08/06 15:28:45 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

# define HALF_WIDTH		250
# define HALF_HEIGHT	250
# define PIXEL_SIZE		1.25 / 250
# define CANVA_Z_POS	5


t_ray	ray_for_pixel_test(unsigned int px, unsigned int py)
{
	t_vec4	pixel;
	t_vec4	origin;
	t_vec4	direction;
	float	world_x;
	float	world_y;

	world_x = HALF_WIDTH - (px + 0.5) * PIXEL_SIZE;
	world_y = HALF_HEIGHT - (py + 0.5) * PIXEL_SIZE;
	pixel = point(world_x, world_y, CANVA_Z_POS);
	origin = point(0, 0, 0);
	direction = vec4_normalize(vec4_sub(pixel, origin));
	return (ray(origin, direction));
}

int	main()
{
	t_object	my_sphere;

	my_sphere = sphere();
	my_sphere.material.color = vec3(255, 0, 0);

	



}