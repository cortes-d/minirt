/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 07:35:19 by achappui          #+#    #+#             */
/*   Updated: 2024/08/26 14:25:44 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	create_sphere(char **tokens, t_list **objects)
{
	t_object	*new_sphere;
	t_list		*new_node;

	new_sphere = gc_add((t_object *)malloc(sizeof(t_object)), 0);
	if (new_sphere == NULL)
		exit_error("ERROR: create_sphere()\n");
	new_node = gc_add(ft_lstnew(new_sphere), 0);
	if (new_node == NULL)
		exit_error("ERROR: create_sphere()\n");
	*new_sphere = \
	sphere(\
	vec3_to_vec4(extract_vec3(tokens[1]), W_POINT), \
	extract_float(tokens[2]));
	set_object_color(new_sphere, extract_color(tokens[3]));
	ft_lstadd_back(objects, new_node);
}
