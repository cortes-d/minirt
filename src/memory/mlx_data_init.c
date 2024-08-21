/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:46:51 by achappui          #+#    #+#             */
/*   Updated: 2024/08/21 15:39:08 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	mlx_data_init(void)
{
	t_mlx_data	*mlx;

	*mlx_data_get() = (t_mlx_data *)malloc(sizeof(t_mlx_data));
	mlx = *mlx_data_get();
	if (!mlx)
		exit_error("ERROR: malloc()\n");
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		exit_error("ERROR: mlx_init()\n");
	mlx->win = mlx_new_window(mlx->ptr, WIN_HSIZE, WIN_VSIZE, WIN_TITLE);
	if (mlx->win == NULL)
		exit_error("ERROR: mlx_new_window()\n");
	mlx->img.img = mlx_new_image(mlx->ptr, WIN_HSIZE, WIN_VSIZE);
	if (mlx->img.img == NULL)
		exit_error("ERROR: mlx_new_image()\n");
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
}