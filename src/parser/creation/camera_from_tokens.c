/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_from_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:45:53 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/11 11:47:46 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	camera_from_tokens(t_list *tokens)
{
	t_list	*current;
	t_token	*params[COUNT_PARAMS_CAMERA];
	vec3    camera_viewpoint;
	vec3	camera_orientation;
	float   camera_fov;

	if (!tokens)
		return ;
	if (ft_lstsize(tokens) != COUNT_PARAMS_CAMERA + 1)
		return ;
	params_from_tokens(tokens, params, COUNT_PARAMS_CAMERA);
	camera_viewpoint = str_to_vec3(params[0]->chunk);
	camera_orientation = str_to_vec3(params[1]->chunk);
	camera_fov = str_to_float(params[2]->chunk);
	/*
	 * At this stage we have all the required parameters to create the camera
	 * We need to implement the function to create the camera
	 */
}