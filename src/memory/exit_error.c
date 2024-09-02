/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:58:56 by achappui          #+#    #+#             */
/*   Updated: 2024/09/02 11:13:38 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory2.h"

void	exit_error(char *msg, char *function_name)
{
	mlx_static_free();
	scene_static_free();
	gc_sweep();
	printf("ERROR: %s\nLOCATION: %s\n", msg, function_name);
	exit(1);
}