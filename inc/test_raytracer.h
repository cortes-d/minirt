/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_raytracer.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:05:00 by achappui          #+#    #+#             */
/*   Updated: 2024/08/20 15:43:36 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_RAYTRACER_H
# define TEST_RAYTRACER_H

// =============================================================================
// Section : Includes
// =============================================================================
# include "raytracer.h"
# include "scene.h"
# include "libft.h"
# include "libla.h"
# include "mlx.h"
# include "graphic.h"
# include <math.h>

// =============================================================================
// Section : Constants and Macros
// =============================================================================

# define WIDTH			500
# define HEIGHT			500
# define HALF_WIDTH		250
# define HALF_HEIGHT	250
# define PIXEL_SIZE		1.25 / 250
# define CANVA_Z_POS	5

// =============================================================================
// Section : Type Definitions
// =============================================================================

// =============================================================================
// Section : Functions
// =============================================================================

int		test_raytracer_phong(void);
int		test_raytracer_red_circle(void);
t_ray	test_ray_for_pixel(unsigned int px, unsigned int py);
int		test_raytracer_color_axe(void);
int		test_raytracer_scene(void);
int		test_raytracer_scene_camera(void);

#endif