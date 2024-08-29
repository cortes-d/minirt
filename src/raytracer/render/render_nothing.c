/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_nothing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:25:42 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/29 08:25:42 by dcortes          ###   ########.ch       */
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
