/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_static_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:56:10 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/29 14:05:17 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory2.h"

void	scene_static_free(void)
{
	t_scene_static	**true_d;
	t_scene_static	*d;

	true_d = scene_static_get();
	d = *true_d;
	if (d)
	{
		if (d->fd != -1)
			close(d->fd);
		gc_free(*true_d);
		*true_d = NULL;
	}
}
