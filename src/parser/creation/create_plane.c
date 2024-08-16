/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:40:49 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/16 15:56:25 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	create_plane(char **tokens, t_list **objects)
{
	t_object	*new_plane;
	t_list		*new_node;

	new_plane = (t_object *)malloc(sizeof(t_object));
	if (new_plane == NULL)
		return (ERROR);
	new_node = ft_lstnew(new_plane);
	if (new_node == NULL)
	{
		free(new_plane);
		return (ERROR);
	}
	*new_plane = \
	plane(\
	vec3_to_vec4(extract_vec3(tokens[1]), W_POINT), \
	vec3_to_vec4(extract_vec3(tokens[2]), W_VECTOR));
	set_object_color(&new_plane, extract_color(tokens[3]));
	ft_lstadd_back(objects, new_node);
	return (0);
}
