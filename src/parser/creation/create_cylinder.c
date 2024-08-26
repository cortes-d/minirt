/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:40:12 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/26 14:26:10 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	create_cylinder(char **tokens, t_list **objects)
{
	t_object	*new_cylinder;
	t_list		*new_node;

	new_cylinder = gc_add((t_object *)malloc(sizeof(t_object)), 0);
	if (new_cylinder == NULL)
		exit_error("ERROR: create_cylinder()\n");
	new_node = gc_add(ft_lstnew(new_cylinder), 0);
	if (new_node == NULL)
		exit_error("ERROR: create_cylinder()\n");
	*new_cylinder = \
	cylinder(\
	vec3_to_vec4(extract_vec3(tokens[1]), W_POINT), \
	vec3_to_vec4(extract_vec3(tokens[2]), W_VECTOR), \
	extract_float(tokens[3]), \
	extract_float(tokens[4]));
	set_object_color(new_cylinder, extract_color(tokens[5]));
	ft_lstadd_back(objects, new_node);
}
