/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:40:12 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/13 16:06:54 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	create_cylinder(char **tokens, t_list **objects)
{
	t_point_light	*new_cylinder;
	t_list			*new_node;

	new_cylinder = (t_object *)malloc(sizeof(t_object));
	if (new_cylinder == NULL)
		return (ERROR);
	new_node = ft_lstnew(new_cylinder);
	if (new_node == NULL)
	{
		free(new_cylinder);
		return (ERROR);
	}
	*new_cylinder = \
	cylinder_from_params(\
	vec3_to_vec4(extract_vec3(tokens[1]), W_POINT), \
	vec3_to_vec4(extract_vec3(tokens[2]), W_VECTOR), \
	extract_float(tokens[3]), \
	extract_float(tokens[4]));
	set_object_color(&new_cylinder, extract_color(tokens[5]));
	ft_lstadd_back(objects, new_node);
	return (0);
}
