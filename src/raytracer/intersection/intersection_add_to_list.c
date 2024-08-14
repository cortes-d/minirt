/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_add_to_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:23:40 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/14 10:28:26 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	intersection_add_to_list(t_list **intersections, \
	t_intersection *intersection)
{
	t_list	*new;

	new = ft_lstnew((void *) intersection);
	ft_lstadd_back(intersections, new);
}
