/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:31:23 by achappui          #+#    #+#             */
/*   Updated: 2024/08/21 09:28:34 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

t_mlx_data	**mlx_data_get(void)
{
	static t_mlx_data	*mlx_data = NULL;

	return (&mlx_data);
}