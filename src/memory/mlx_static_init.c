/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_static_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:57:17 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/29 08:57:17 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "memory2.h"

void	mlx_static_init(void)
{
	t_mlx_static	**true_d;
	t_mlx_static	*d;

	true_d = mlx_static_get();
	*true_d = (t_mlx_static *)malloc(sizeof(t_mlx_static));
	if (!*true_d)
		exit_error("malloc failed", "mlx_static_init()");
	d = *true_d;
	d->mlx_img = (t_image *)malloc(sizeof(t_image));
	if (!d->mlx_img)
		exit_error("malloc failed", "mlx_static_init()");
	d->mlx_ptr = mlx_init();
	if (!d->mlx_ptr)
		exit_error("mlx_init failed", "mlx_static_init()");
	d->mlx_win = mlx_new_window(d->mlx_ptr, WIN_HSIZE, WIN_VSIZE, WIN_TITLE);
	if (!d->mlx_win)
		exit_error("mlx_new_window failed", "mlx_static_init()");
	d->mlx_img->img = mlx_new_image(d->mlx_ptr, WIN_HSIZE, WIN_VSIZE);
	if (!d->mlx_img->img)
		exit_error("mlx_new_image failed", "mlx_static_init()");
	d->mlx_img->addr = mlx_get_data_addr(d->mlx_img->img, \
	&d->mlx_img->bits_per_pixel, &d->mlx_img->line_length, \
	&d->mlx_img->endian);
	if (!d->mlx_img->addr)
		exit_error("mlx_get_data_addr failed", "mlx_static_init()");
}
