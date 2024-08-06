/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:53:38 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/06 09:51:14 by dcortes          ###   ########.fr       */
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
 * Adds an intersection to the list of intersections.
 */
void	intersections(t_list **intersections, t_intersection *intersection)
{
	t_list	*new;

	new = ft_lstnew((void *) intersection);
	ft_lstadd_back(intersections, new);
}
