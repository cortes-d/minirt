/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_add_to_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:23:40 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:41:44 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	intersection_add_to_list(t_list **intersections, \
	t_intersection *intersection)
{
	t_list	*new;

	new = ft_lstnew((void *) intersection);
	if (new == NULL)
		exit_error("ft_lstnew failed", "intersection_add_to_list()");
	ft_lstadd_back(intersections, new);
}
