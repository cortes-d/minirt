/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_static_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:40:15 by achappui          #+#    #+#             */
/*   Updated: 2024/08/26 16:52:55 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory2.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:48:04 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/16 15:19:16 by achappui         ###   ########.fr       */
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