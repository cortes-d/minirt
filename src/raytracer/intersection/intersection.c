/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:53:38 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/06 15:30:44 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "raytracer.h"

/*
 * Associates one intersection (t-value) to the object being intersected.
 */
t_intersection	intersection(float t, t_object object)
{
	t_intersection	intersection;

	intersection.t = t;
	intersection.object = object;
	return (intersection);
}

/*
 * Aggregates an intersection to a list of intersections.
 */
void	intersections(t_list **intersections, t_intersection *intersection)
{
	t_list	*new;

	new = ft_lstnew((void *) intersection);
	ft_lstadd_back(intersections, new);
}
