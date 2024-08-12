/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_from_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:40:49 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 13:13:55 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "raytracer.h"

void	plane_from_tokens(t_list *tokens)
{
	t_list		*current;
	t_token		*params[COUNT_PARAMS_PLANE];
	t_object	p;

	if (!tokens)
		return ;
	if (ft_lstsize(tokens) != COUNT_PARAMS_PLANE + 1)
		return ;
	params_from_tokens(tokens, params, COUNT_PARAMS_PLANE);
	p = plane_from_params(\
		vec3_to_vec4(str_to_vec3(params[0]->chunk), W_POINT), \
		vec3_to_vec4(str_to_vec3(params[1]->chunk), W_VECTOR)\
	);
	set_object_color(&p, str_to_color(params[2]->chunk));
}
