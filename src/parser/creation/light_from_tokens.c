/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_from_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:48:04 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 10:40:48 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	light_from_tokens(t_object light, t_list *tokens)
{
	t_list	*current;
	t_token	*params[COUNT_PARAMS_LIGHT];


	if (!tokens)
		return ;
	if (ft_lstsize(tokens) != COUNT_PARAMS_LIGHT + 1)
		return ;
	params_from_tokens(tokens, params, COUNT_PARAMS_LIGHT);
	light.light_point = str_to_vec3(params[0]->chunk);
	light.light_brightness = str_to_float(params[1]->chunk);
	/*
	 * At this stage we have all the required parameters to create the light
	 * We need to implement the function to create the light
	 */
}