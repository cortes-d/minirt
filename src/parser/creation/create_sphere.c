/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:31:45 by dcortes           #+#    #+#             */
<<<<<<< Updated upstream:src/parser/creation/create_sphere.c
/*   Updated: 2024/08/13 16:06:57 by achappui         ###   ########.fr       */
=======
/*   Updated: 2024/08/13 11:04:11 by dcortes          ###   ########.fr       */
>>>>>>> Stashed changes:src/parser/creation/sphere_from_tokens.c
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	create_sphere(char **tokens, t_list **objects)
{
	t_object	*new_sphere;
	t_list		*new_node;

<<<<<<< Updated upstream:src/parser/creation/create_sphere.c
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
=======
	if (!tokens)
		return ;
	if (ft_lstsize(tokens) != COUNT_PARAMS_SPHERE + 1)
		return ;
	params_from_tokens(tokens, params, COUNT_PARAMS_SPHERE);
	s = sphere_from_params(\
		vec3_to_vec4(str_to_vec3(params[0]->chunk), W_POINT), \
		str_to_float(params[1]->chunk));
	set_object_color(&s, str_to_color(params[2]->chunk));
	/*
	 * At this stage we must add the sphere to the world
	 */
}
>>>>>>> Stashed changes:src/parser/creation/sphere_from_tokens.c
