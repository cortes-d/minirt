/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mlx_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:31:23 by achappui          #+#    #+#             */
/*   Updated: 2024/08/20 16:50:18 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_data.h"

t_mlx_data	**get_mlx_data(void)
{
	static t_mlx_data	*mlx_data = NULL;

	return (&mlx_data);
}