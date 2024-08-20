/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:07:57 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/20 15:42:14 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "raytracer.h"

/*
 * The hit is always the lowest nonnegative intersection.
 */
t_intersection	*hit(t_list *intersections)
{
	t_list			*current;
	t_intersection	*intersection;
	t_intersection	*hit;
	float			smallest_positive_t;

	hit = NULL;
	current = intersections;
	smallest_positive_t = __FLT_MAX__;
	while (current)
	{
		intersection = (t_intersection *)current->content;
		if (intersection->t > 0 && intersection->t < smallest_positive_t)
		{
			smallest_positive_t = intersection->t;
			hit = intersection;
		}
		current = current->next;
	}
	return (hit);
}
