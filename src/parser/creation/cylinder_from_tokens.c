/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_from_tokens.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:40:12 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 12:58:16 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "raytracer.h"

void	cylinder_from_tokens(t_list *tokens)
{
	t_list		*current;
	t_token		*params[COUNT_PARAMS_CYLINDER];
	t_object	c;

	if (!tokens)
		return ;
	if (ft_lstsize(tokens) != COUNT_PARAMS_CYLINDER + 1)
		return ;
	params_from_tokens(tokens, params, COUNT_PARAMS_CYLINDER);
	c = cylinder_from_params(\
		vec3_to_vec4(str_to_vec3(params[0]->chunk), W_POINT), \
		vec3_to_vec4(str_to_vec3(params[1]->chunk), W_VECTOR), \
		str_to_float(params[2]->chunk), \
		str_to_float(params[3]->chunk) \
	);
	set_object_color(&c, str_to_color(params[4]->chunk));
}
