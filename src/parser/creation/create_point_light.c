/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_point_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:48:04 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/13 16:06:56 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	create_point_light(char **tokens, t_list **lights)
{
	t_point_light	*new_point_light;
	t_list			*new_node;

	new_point_light = (t_point_light *)malloc(sizeof(t_point_light));
	if (new_point_light == NULL)
		return (ERROR);
	new_node = ft_lstnew(new_point_light);
	if (new_node == NULL)
	{
		free(new_point_light);
		return (ERROR);
	}
	*new_point_light = \
	point_light_from_param(\
	vec3_to_vec4(extract_vec3(tokens[1]), W_POINT), \
	extract_float(tokens[2]), \
	extract_color(tokens[3]));
	ft_lstadd_back(lights, new_node);
	return (0);
}
