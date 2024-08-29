/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:55:53 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/29 08:55:53 by dcortes          ###   ########.ch       */
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
