/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light_ambient.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:43:39 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/16 16:48:12 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	create_light_ambient(char **tokens, t_list **ambient_lights)
{
	t_light_ambient	*new_light_ambient;
	t_list			*new_node;

	new_light_ambient = (t_light_ambient *)malloc(sizeof(t_light_ambient));
	if (new_light_ambient == NULL)
		return (ERROR);
	new_node = ft_lstnew(new_light_ambient);
	if (new_node == NULL)
	{
		free(new_light_ambient);
		return (ERROR);
	}
	*new_light_ambient = \
	light_ambient(\
	extract_float(tokens[1]), \
	extract_color(tokens[2]));
	ft_lstadd_back(ambient_lights, new_node);
	return (0);
}
