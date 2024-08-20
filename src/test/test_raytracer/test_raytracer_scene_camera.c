/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_raytracer_scene_camera.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:18:56 by achappui          #+#    #+#             */
/*   Updated: 2024/08/20 15:57:46 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "test_raytracer.h"

int	test_raytracer_scene_camera(void)
{
	void				*mlx_ptr;
	void				*mlx_win;
	t_image				img;
    t_scene             scene;

	// mlx
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "TEST_PHONG");
	img.img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);


	// scene
    scene = scene_default();

	*scene.camera = camera_default();
	render(scene, &img);
	mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}