/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:46:51 by achappui          #+#    #+#             */
/*   Updated: 2024/08/21 11:10:24 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	mlx_data_init(void)
{
	t_mlx_data	**mlx_data;

	mlx_data = mlx_data_get();
	*mlx_data = (t_mlx_data *)malloc(sizeof(t_mlx_data));
	if (!mlx_data)
		exit_error("ERROR: malloc()\n");
	(*mlx_data)->ptr = mlx_init();
	if ((*mlx_data)->ptr == NULL)
		exit_error("ERROR: mlx_init()\n");
	(*mlx_data)->win = mlx_new_window((*mlx_data)->ptr, WIN_HSIZE, WIN_VSIZE, WIN_TITLE);
	if ((*mlx_data)->ptr == NULL)
		exit_error("ERROR: mlx_new_window()\n");
	(*mlx_data)->img = mlx_new_image((*mlx_data)->ptr, WIN_HSIZE, WIN_VSIZE);
	if ((*mlx_data)->ptr == NULL)
		exit_error("ERROR: mlx_new_image()\n");
}