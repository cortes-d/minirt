/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ambient_light.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:43:39 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/13 16:06:47 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	create_ambient_light(char **tokens, t_ambient_light **ambient_lights)
{
	t_point_light	*new_ambient_light;
	t_list			*new_node;

	new_ambient_light = (t_point_light *)malloc(sizeof(t_point_light));
	if (new_ambient_light == NULL)
		return (ERROR);
	new_node = ft_lstnew(new_ambient_light);
	if (new_node == NULL)
	{
		free(new_ambient_light);
		return (ERROR);
	}
	*new_ambient_light = \
	ambient_light_from_param(\
	extract_float(tokens[1]), \
	extract_color(tokens[2]));
	ft_lstadd_back(ambient_lights, new_node);
	return (0);
}
