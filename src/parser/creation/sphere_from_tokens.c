/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_from_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:31:45 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 11:09:59 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "raytracer.h"

void	sphere_from_tokens(t_list *tokens)
{
	t_list		*current;
	t_token		*params[COUNT_PARAMS_SPHERE];
	t_object	s;

	if (!tokens)
		return ;
	if (ft_lstsize(tokens) != COUNT_PARAMS_SPHERE + 1)
		return ;
	params_from_tokens(tokens, params, COUNT_PARAMS_SPHERE);
	s = sphere_from_params(\
		vec3_to_vec4(str_to_vec3(params[0]->chunk), W_POINT), \
		str_to_float(params[1]->chunk));
	set_object_color(&s, str_to_color(params[2]->chunk));
	/*
	 * At this stage we must add the sphere to the world
	 */
}
