/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:45:53 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/13 16:06:52 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	create_camera(char **tokens, t_camera **cameras)
{
	t_point_light	*new_camera;
	t_list			*new_node;

	new_camera = (t_object *)malloc(sizeof(t_object));
	if (new_camera == NULL)
		return (ERROR);
	new_node = ft_lstnew(new_camera);
	if (new_node == NULL)
	{
		free(new_camera);
		return (ERROR);
	}
	*new_camera = \
	camera_from_param(\
	vec3_to_vec4(extract_vec3(tokens[1]), W_POINT), \
	vec3_to_vec4(extract_vec3(tokens[2]), W_VECTOR), \
	extract_float(tokens[3]));
	ft_lstadd_back(cameras, new_node);
	return (0);
}
