/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_static_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:57:24 by achappui          #+#    #+#             */
/*   Updated: 2024/08/22 17:07:59 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	scene_static_init(char *path)
{
	t_scene_static	**true_d;
	t_scene_static	*d;

	true_d = scene_static_get();
	*true_d = (t_scene_static *)malloc(sizeof(t_scene_static));
	if (!*true_d)
		exit_error("ERROR: scene_static_init()\n");
	d = *true_d;
	d->scene = scene_empty();
	d->path = path;
	d->fd = -1;
	parse_scene(d->path, &d->scene);
}