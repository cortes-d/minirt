/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:53:38 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 13:21:47 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "raytracer.h"

/*
 * Associates one intersection (t-value) to the object being intersected.
 */
t_intersection	*intersection_create(float t, t_object *object)
{
	t_intersection	*intersection;

	intersection = malloc(sizeof(t_intersection));
	if (intersection == NULL)
		exit_error("malloc failed", "intersection_create()");
	intersection->t = t;
	intersection->object = object;
	return (intersection);
}
