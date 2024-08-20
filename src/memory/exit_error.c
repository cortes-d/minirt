/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:58:56 by achappui          #+#    #+#             */
/*   Updated: 2024/08/20 16:48:46 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_data.h"

void	exit_error(char *msg)
{
	gc_sweep();
	free_mlx();
	printf(msg);
	exit(1);
}