/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:53:38 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/14 10:24:49 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "raytracer.h"

/*
 * Associates one intersection (t-value) to the object being intersected.
 */
t_intersection	*intersection_create(float t, t_object object)
{
	t_intersection	*intersection;

	intersection = malloc(sizeof(t_intersection));
	intersection->t = t;
	intersection->object = object;
	return (intersection);
}
