/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:31:45 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/13 16:06:57 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	create_sphere(char **tokens, t_list **objects)
{
	t_object	*new_sphere;
	t_list		*new_node;

	new_sphere = (t_object *)malloc(sizeof(t_object));
	if (new_sphere == NULL)
		return (ERROR);
	new_node = ft_lstnew(new_sphere);
	if (new_node == NULL)
	{
		free(new_sphere);
		return (ERROR);
	}
	*new_sphere = \
	sphere_from_params(\
	vec3_to_vec4(extract_vec3(tokens[1]), W_POINT), \
	extract_float(tokens[2]));
	set_object_color(&new_sphere, extract_color(tokens[3]));
	ft_lstadd_back(objects, new_node);
	return (0);
}
