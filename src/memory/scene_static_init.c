/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_static_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:57:24 by achappui          #+#    #+#             */
/*   Updated: 2024/08/28 11:03:37 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory2.h"

static void	scene_add_black_light(t_scene_static *d)
{
	d->scene.light_point = \
	gc_add((t_light_point *)malloc(sizeof(t_light_point)), 0);
	if (!d->scene.light_point)
		exit_error("malloc failed", "scene_add_black_light()");
	*d->scene.light_point = light_point(point(0, 0, 0), 0, color_rgb_f(0, 0, 0));
}

static void	scene_add_black_ambient(t_scene_static *d)
{
	d->scene.light_ambient = \
	gc_add((t_light_ambient *)malloc(sizeof(t_light_ambient)), 0);
	if (!d->scene.light_ambient)
		exit_error("malloc failed", "scene_add_black_ambient()");
	*d->scene.light_ambient = light_ambient(0, color_rgb_f(0, 0, 0));
}

void	scene_static_init(char *path)
{
	t_scene_static	**true_d;
	t_scene_static	*d;

	true_d = scene_static_get();
	*true_d = gc_add((t_scene_static *)malloc(sizeof(t_scene_static)), 0);
	if (!*true_d)
		exit_error("malloc failed", "scene_static_init()");
	d = *true_d;
	d->scene = scene_empty();
	d->path = path;
	d->fd = -1;
	parse_scene();
	if (d->scene.light_point == NULL)
		scene_add_black_light(d);
	if (d->scene.light_ambient == NULL)
		scene_add_black_ambient(d);
}
