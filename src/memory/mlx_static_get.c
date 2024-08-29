/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_static_get.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:55:56 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/29 08:55:56 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "memory2.h"

t_mlx_static	**mlx_static_get(void)
{
	static t_mlx_static	*mlx_static = NULL;

	return (&mlx_static);
}
