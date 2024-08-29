/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_minirt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:56:27 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/29 08:56:27 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "memory2.h"

void	exit_minirt(void)
{
	mlx_static_free();
	scene_static_free();
	gc_sweep();
	exit(0);
}
