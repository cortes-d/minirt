/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_from_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:48:04 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/11 11:49:16 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	light_from_tokens(t_list *tokens)
{
	t_list	*current;
	t_token	*params[COUNT_PARAMS_LIGHT];
	vec3    light_point;
	float	light_brightness;

	if (!tokens)
		return ;
	if (ft_lstsize(tokens) != COUNT_PARAMS_LIGHT + 1)
		return ;
	params_from_tokens(tokens, params, COUNT_PARAMS_LIGHT);
	light_point = str_to_vec3(params[0]->chunk);
	light_brightness = str_to_float(params[1]->chunk);
	/*
	 * At this stage we have all the required parameters to create the light
	 * We need to implement the function to create the light
	 */
}