/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:48:04 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:30:15 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	create_light_point(char **tokens, t_list **light_points)
{
	t_light_point	*new_light_point;
	t_list			*new_node;

	new_light_point = gc_add((t_light_point *)malloc(sizeof(t_light_point)), 0);
	if (new_light_point == NULL)
		exit_error("gc_add failed", "create_light_point()");
	new_node = gc_add(ft_lstnew(new_light_point), 0);
	if (new_node == NULL)
		exit_error("ft_lstnew failed", "create_light_point()");
	*new_light_point = \
	light_point(\
	vec3_to_vec4(extract_vec3(tokens[1]), W_POINT), \
	extract_float(tokens[2]), \
	extract_color(tokens[3]));
	ft_lstadd_back(light_points, new_node);
}
