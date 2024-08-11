/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_from_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:31:45 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/11 11:31:51 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	sphere_from_tokens(t_list *tokens)
{
	t_list	*current;
	t_token	*params[COUNT_PARAMS_SPHERE];
	vec3	sphere_center;
	float	sphere_diameter;
	color	sphere_color;

	if (!tokens)
		return ;
	if (ft_lstsize(tokens) != COUNT_PARAMS_SPHERE + 1)
		return ;
	params_from_tokens(tokens, params, COUNT_PARAMS_SPHERE);
	sphere_center = str_to_vec3(params[0]->chunk);
	sphere_diameter = str_to_float(params[1]->chunk);
	sphere_color = str_to_color(params[2]->chunk);
	/*
	 * At this stage we have all the required parameters to create the sphere
	 * We need to implement the function to create the sphere
	 */
}
