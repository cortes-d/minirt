/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:40:49 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/21 11:06:14 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	create_plane(char **tokens, t_list **objects)
{
	t_object	*new_plane;
	t_list		*new_node;

	new_plane = gc_add((t_object *)malloc(sizeof(t_object)), 1);
	if (new_plane == NULL)
		exit_error("ERROR: create_plane()\n");
	new_node = gc_add(ft_lstnew(new_plane), 1);
	if (new_node == NULL)
		exit_error("ERROR: create_plane()\n");
	*new_plane = \
	plane(\
	vec3_to_vec4(extract_vec3(tokens[1]), W_POINT), \
	vec3_to_vec4(extract_vec3(tokens[2]), W_VECTOR));
	set_object_color(new_plane, extract_color(tokens[3]));
	ft_lstadd_back(objects, new_node);
}
