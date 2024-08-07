/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:22:35 by achappui          #+#    #+#             */
/*   Updated: 2024/08/07 15:31:52 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_world	world()
{
	t_world	new_world;

	new_world.lights_nb = 0;
	new_world.objects_nb = 0;
	new_world.lights = NULL;
	new_world.objects = NULL;
	return (new_world);
}