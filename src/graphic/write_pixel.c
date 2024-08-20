/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:06:05 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/20 15:56:36 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

/*void	write_pixel(t_image *image, int x, int y, t_vec3 v_color)
{
	char			*pixel_position;
	unsigned int	uint_color;

	uint_color = 0;
	uint_color = \
	(unsigned int)v_color.data[R] << 16 | \
	(unsigned int)v_color.data[G] << 8 | \
	(unsigned int)v_color.data[B];
	pixel_position = \
	image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	// *(unsigned int *)pixel_position = 0xFFFFFFFF;
	*(unsigned int *)pixel_position = uint_color;
}*/

void	write_pixel(t_image *image, int x, int y, t_vec3 v_color)
{
	char			*pixel_position;
	unsigned int	uint_color;

	// Convert float values (0 to 1) to unsigned int values (0 to 255)
	unsigned int r = (unsigned int)(v_color.data[R] * 255.0f);
	unsigned int g = (unsigned int)(v_color.data[G] * 255.0f);
	unsigned int b = (unsigned int)(v_color.data[B] * 255.0f);

	// Construct the color value
	uint_color = (r << 16) | (g << 8) | b;

	// Calculate the pixel position in the image buffer
	pixel_position = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));

	// Write the color to the pixel position
	*(unsigned int *)pixel_position = uint_color;
}