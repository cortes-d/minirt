/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:45:53 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/16 16:48:09 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	create_camera(char **tokens, t_list **cameras)
{
	t_camera	*new_camera;
	t_list		*new_node;

	new_camera = (t_camera *)malloc(sizeof(t_camera));
	if (new_camera == NULL)
		return (ERROR);
	new_node = ft_lstnew(new_camera);
	if (new_node == NULL)
	{
		free(new_camera);
		return (ERROR);
	}
	*new_camera = \
	camera(\
	vec3_to_vec4(extract_vec3(tokens[1]), W_POINT), \
	vec3_to_vec4(extract_vec3(tokens[2]), W_VECTOR), \
	extract_float(tokens[3]));
	ft_lstadd_back(cameras, new_node);
	return (0);
}
