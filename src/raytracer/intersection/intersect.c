/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:27:57 by dcortes           #+#    #+#             */
/*   Updated: 2024/09/02 10:11:35 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	intersect(t_ray ray, t_object *object, \
	t_list **list_intersections)
{
	t_ray				ray_transformed;

	ray_transformed = ray_transform(ray, object->transform_inverse);
	if (object->type == SPHERE)
		return (intersect_sphere(ray_transformed, object, list_intersections));
	else if (object->type == CYLINDER)
		return (intersect_cylinder(ray_transformed, object, \
			list_intersections));
	else
		return (intersect_plane(ray_transformed, object, list_intersections));
}
