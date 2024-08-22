/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_static_get.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:31:23 by achappui          #+#    #+#             */
/*   Updated: 2024/08/22 16:46:42 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

t_mlx_static	**mlx_static_get(void)
{
	static t_mlx_static	*mlx_static = NULL;

	return (&mlx_static);
}