/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:01:41 by achappui          #+#    #+#             */
/*   Updated: 2024/08/21 11:25:59 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	mlx_data_free(void)
{
	t_mlx_data	**mlx_data;

	mlx_data = mlx_data_get();
	if (*mlx_data)
	{
		if ((*mlx_data)->img)
			mlx_destroy_image((*mlx_data)->ptr, (*mlx_data)->img);
		if ((*mlx_data)->win)
			mlx_destroy_window((*mlx_data)->ptr, (*mlx_data)->win);
		if ((*mlx_data)->ptr)
			free((*mlx_data)->ptr); //il n'y a pas de fonction destroy pour ca je ne comprend pas
	}
}