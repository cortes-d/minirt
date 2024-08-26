/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_nothing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:35:25 by achappui          #+#    #+#             */
/*   Updated: 2024/08/26 15:39:31 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	render_nothing(t_image *image)
{
	unsigned int	x;
	unsigned int	y;
	t_vec3			c;

	c = color_rgb_f(0, 0, 0);
	y = 0;
	while (y < WIN_VSIZE)
	{
		x = 0;
		while (x < WIN_HSIZE)
		{
			write_pixel(image, x, y, c);
			x++;
		}
		y++;
	}
}