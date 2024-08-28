/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:07:39 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 10:04:07 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
    t_scene_static	*scene_static;
	t_mlx_static	*mlx_static;

	check_main_arguments(argv, argc);
	mlx_static_init();
	mlx_static = *mlx_static_get();
	scene_static_init(argv[1]);
	scene_static = *scene_static_get();
	render(scene_static->scene, mlx_static->mlx_img);
	mlx_put_image_to_window(mlx_static->mlx_ptr, mlx_static->mlx_win, mlx_static->mlx_img->img, 0, 0);
	mlx_hook(mlx_static->mlx_win, 2, 0, &hook_key_released, NULL);
	mlx_hook(mlx_static->mlx_win, 17, 0, &hook_cross_pressed, NULL);
	mlx_loop(mlx_static->mlx_ptr);
	return (0);
}
