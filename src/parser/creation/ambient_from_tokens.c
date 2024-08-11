/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_from_tokens.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:43:39 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/11 11:45:42 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ambient_from_tokens(t_list *tokens)
{
	t_list	*current;
	t_token	*params[COUNT_PARAMS_AMBIENT];
    float   ambient_ratio;
    vec3	ambient_color;

	if (!tokens)
		return ;
	if (ft_lstsize(tokens) != COUNT_PARAMS_AMBIENT + 1)
		return ;
	params_from_tokens(tokens, params, COUNT_PARAMS_AMBIENT);
	ambient_ratio = str_to_float(params[0]->chunk);
	ambient_color = str_to_color(params[1]->chunk);
	/*
	 * At this stage we have all the required parameters to create the ambient light
	 * We need to implement the function to create the ambient light
	 */
}