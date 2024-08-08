/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:22:35 by achappui          #+#    #+#             */
/*   Updated: 2024/08/08 10:00:11 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_world	world(void)
{
	t_world	new_world;

	new_world.lights_nb = 0;
	new_world.objects_nb = 0;
	new_world.lights = NULL;
	new_world.objects = NULL;
	return (new_world);
}
