/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_static_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:44:35 by achappui          #+#    #+#             */
/*   Updated: 2024/08/26 16:53:03 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory2.h"

t_scene_static	**scene_static_get(void)
{
	static t_scene_static	*scene_static = NULL;

	return (&scene_static);
}
