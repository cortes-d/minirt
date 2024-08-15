/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:52:59 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/15 16:28:13 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "scene.h"

void	intersect_scene(t_ray ray, t_scene scene, t_list **intersections)
{
	int	i;

	if (scene.objects == NULL)
		return ;
	i = 0;
	while (scene.objects[i])
	{
		intersect(ray, *scene.objects[i], intersections);
		i++;
	}
}
