/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:46:51 by achappui          #+#    #+#             */
/*   Updated: 2024/08/20 16:54:40 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_data.h"

void	init_mlx(void)
{
	t_mlx_data	**mlx_data;

	mlx_data = get_mlx_data();
	*mlx_data = (t_mlx_data *)malloc(sizeof(t_mlx_data));
	if (!mlx_data)
		exit_error("ERROR: malloc() failed\n");
	mlx_data->ptr = mlx_init();
	if (mlx_data->ptr == NULL)
		exit_error("ERROR: mlx_init() failed\n");
	mlx_data->win = mlx_new_window(mlx_data->ptr, HSIZE, VSIZE, TITLE);
	if (mlx_data->ptr == NULL)
		exit_error("ERROR: mlx_new_window() failed\n");
	mlx_data->img = mlx_new_image(mlx_data->ptr, HSIZE, VSIZE);
	if (mlx_data->ptr == NULL)
		exit_error("ERROR: mlx_new_image() failed\n");
}