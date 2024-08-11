/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_from_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:40:49 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/11 11:42:24 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	plane_from_tokens(t_list *tokens)
{
	t_list	*current;
	t_token	*params[COUNT_PARAMS_PLANE];
	vec3	plane_point;
	vec3	plane_normal;
	color	plane_color;

	if (!tokens)
		return ;
	if (ft_lstsize(tokens) != COUNT_PARAMS_PLANE + 1)
		return ;
	params_from_tokens(tokens, params, COUNT_PARAMS_PLANE);
	plane_point = str_to_vec3(params[0]->chunk);
	plane_normal = str_to_vec3(params[1]->chunk);
	plane_color = str_to_color(params[2]->chunk);
	/*
	 * At this stage we have all the required parameters to create the plane
	 * We need to implement the function to create the plane
	 */
}