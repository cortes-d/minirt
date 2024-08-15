/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_point_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:48:04 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/15 09:23:25 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	create_light_point(char **tokens, t_list **lights)
{
	t_light_point	*new_light_point;
	t_list			*new_node;

	new_light_point = (t_light_point *)malloc(sizeof(t_light_point));
	if (new_light_point == NULL)
		return (ERROR);
	new_node = ft_lstnew(new_light_point);
	if (new_node == NULL)
	{
		free(new_light_point);
		return (ERROR);
	}
	*new_light_point = \
	point_light_from_param(\
	vec3_to_vec4(extract_vec3(tokens[1]), W_POINT), \
	extract_float(tokens[2]), \
	extract_color(tokens[3]));
	ft_lstadd_back(lights, new_node);
	return (0);
}
