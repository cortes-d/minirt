/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light_ambient.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:43:39 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:30:15 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	create_light_ambient(char **tokens, t_list **light_ambients)
{
	t_light_ambient	*new_light_ambient;
	t_list			*new_node;

	new_light_ambient = gc_add((t_light_ambient *)malloc(sizeof(t_light_ambient)), 0);
	if (new_light_ambient == NULL)
		exit_error("gc_add failed", "create_light_ambient()");
	new_node = gc_add(ft_lstnew(new_light_ambient), 0);
	if (new_node == NULL)
		exit_error("ft_lstnew failed", "create_light_ambient()");
	*new_light_ambient = \
	light_ambient(\
	extract_float(tokens[1]), \
	extract_color(tokens[2]));
	ft_lstadd_back(light_ambients, new_node);
}
