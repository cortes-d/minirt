/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_minirt_beta.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:55:18 by achappui          #+#    #+#             */
/*   Updated: 2024/08/21 15:52:40 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_raytracer.h"

int	test_minirt_beta(int argc, char **argv)
{
    t_scene             scene;
	t_mlx_data			*mlx;

	check_main_arguments(argv, argc);
	scene = scene_empty();
	parse_scene(argv[1], &scene);
	test_print_scene(&scene);
	mlx_data_init();
	mlx = *mlx_data_get();
	render(scene, &mlx->img);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img, 0, 0);
	mlx_loop(mlx->ptr);
	return (0);
}
