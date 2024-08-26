/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:58:56 by achappui          #+#    #+#             */
/*   Updated: 2024/08/26 14:33:37 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	exit_error(char *msg)
{
	mlx_static_free();
	scene_static_free();
	gc_sweep();
	printf("%s\n", msg);
	exit(1);
}