/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:39:31 by achappui          #+#    #+#             */
/*   Updated: 2024/08/06 15:30:46 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	write_pixel(t_image *image, unsigned int x, unsigned int y, t_vec3 v_color)
{
	char			*pixel_position;
	unsigned int	uint_color;

	uint_color = 0;
	uint_color = \
	(unsigned int)v_color[R] << 24 | \
	(unsigned int)v_color[G] << 16 | \
	(unsigned int)v_color[B] << 8;
	pixel_position = \
	image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int *)pixel_position = uint_color;
}