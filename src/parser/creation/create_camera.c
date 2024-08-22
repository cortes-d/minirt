/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:45:53 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/22 11:02:54 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	create_camera(char **tokens, t_list **cameras)
{
	t_camera	*new_camera;
	t_list		*new_node;

	new_camera = gc_add((t_camera *)malloc(sizeof(t_camera)), 1);
	if (new_camera == NULL)
		exit_error("ERROR: create_camera()\n");
	new_node = gc_add(ft_lstnew(new_camera), 1);
	if (new_node == NULL)
		exit_error("ERROR: create_camera()\n");
	*new_camera = \
	camera(\
	vec4_normalize(vec3_to_vec4(extract_vec3(tokens[1]), W_POINT)), \
	vec3_to_vec4(extract_vec3(tokens[2]), W_VECTOR), \
	extract_float(tokens[3]));
	ft_lstadd_back(cameras, new_node);
}
