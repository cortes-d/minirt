/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 08:59:51 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/06 16:00:45 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# include "libla.h"

// =============================================================================
// Section : Type Definitions
// =============================================================================

// --- Structure : Image ---
typedef struct	s_image {
	void			*img;
	char			*addr;
	unsigned int	bits_per_pixel;
	unsigned int	line_length;
	unsigned int	endian;
}				t_image;

// =============================================================================
// Section : Functions
// =============================================================================

void	write_pixel(t_image *image, unsigned int x, unsigned int y, t_vec3 v_color);

#endif