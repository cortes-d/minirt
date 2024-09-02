/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:52:59 by dcortes           #+#    #+#             */
/*   Updated: 2024/09/02 10:11:30 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	intersect_scene(t_ray ray, t_scene scene, t_list **intersections)
{
	int	i;

	if (scene.objects == NULL)
		return ;
	i = 0;
	while (scene.objects[i])
	{
		intersect(ray, &(*scene.objects[i]), intersections);
		i++;
	}
}
