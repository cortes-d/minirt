/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_minirt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:45:23 by achappui          #+#    #+#             */
/*   Updated: 2024/08/26 14:33:43 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	exit_minirt(void)
{
	mlx_static_free();
	scene_static_free();
	gc_sweep();
	exit(0);
}