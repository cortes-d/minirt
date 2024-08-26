/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:24:31 by achappui          #+#    #+#             */
/*   Updated: 2024/08/26 14:40:43 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int	reload_scene(void)
{
	t_scene_static	*scene_static;
	t_mlx_static	*mlx_static;
	char			*path;

	mlx_static = *mlx_static_get();
	path = (*scene_static_get())->path;
	scene_static_free();
	scene_static_init(path);
	scene_static = *scene_static_get();
	render(scene_static->scene, mlx_static->mlx_img);
	mlx_put_image_to_window(mlx_static->mlx_ptr, mlx_static->mlx_win, mlx_static->mlx_img->img, 0, 0);
	return (0);
}