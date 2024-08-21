/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:06:05 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/21 08:59:02 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	write_pixel(t_image *image, int x, int y, t_vec3 v_color)
{
	char			*pixel_position;
	unsigned int	uint_color;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	r = (unsigned int)(v_color.data[R] * 255.0f);
	g = (unsigned int)(v_color.data[G] * 255.0f);
	b = (unsigned int)(v_color.data[B] * 255.0f);
	uint_color = (r << 16) | (g << 8) | b;
	pixel_position = image->addr + \
		(y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int *)pixel_position = uint_color;
}
