/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_from_tokens.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:40:12 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 11:12:31 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	cylinder_from_tokens(t_list *tokens)
{
	t_list	*current;
	t_token	*params[COUNT_PARAMS_CYLINDER];
	t_vec3	cylinder_center;
	t_vec3	cylinder_axis;
	float	cylinder_diameter;
	float   cylinder_height;
	t_vec3	cylinder_color;

	if (!tokens)
		return ;
	if (ft_lstsize(tokens) != COUNT_PARAMS_CYLINDER + 1)
		return ;
	params_from_tokens(tokens, params, COUNT_PARAMS_CYLINDER);
	cylinder_center = str_to_vec3(params[0]->chunk);
	cylinder_axis = str_to_vec3(params[1]->chunk);
	cylinder_diameter = str_to_float(params[2]->chunk);
	cylinder_height = str_to_float(params[3]->chunk);
	cylinder_color = str_to_color(params[4]->chunk);
	/*
	 * At this stage we have all the required parameters to create the cylinder
	 * We need to implement the function to create the cylinder
	 */
}
