/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:39:31 by achappui          #+#    #+#             */
/*   Updated: 2024/08/06 17:07:06 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	write_pixel(t_image *image, int x, int y, t_vec3 v_color)
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
}