/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_static_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:56:32 by dcortes           #+#    #+#             */
/*   Updated: 2024/09/02 11:07:12 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory2.h"

void	mlx_static_free(void)
{
	t_mlx_static	**true_d;
	t_mlx_static	*d;

	true_d = mlx_static_get();
	d = *true_d;
	if (d)
	{
		if (d->mlx_img && d->mlx_img->img)
			mlx_destroy_image(d->mlx_ptr, d->mlx_img->img);
		if (d->mlx_img)
			free(d->mlx_img);
		if (d->mlx_win)
			mlx_destroy_window(d->mlx_ptr, d->mlx_win);
		if (d->mlx_ptr)
			mlx_destroy_display(d->mlx_ptr);
		if (d->mlx_ptr)
			free(d->mlx_ptr);
		free(*true_d);
		*true_d = NULL;
	}
}
