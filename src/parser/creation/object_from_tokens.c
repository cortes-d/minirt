/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_from_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:25:31 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/11 11:26:07 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	object_from_tokens(t_list *tokens)
{
	t_token	*token;

	token = tokens->content;
	if (!token)
		return ; // line with error in the rt file : we should display an error
	if (ft_strequiv(token->chunk, "A"))
		ambient_from_tokens(tokens); // create light ambient from tokens
	else if (ft_strequiv(token->chunk, "L"))
		light_from_tokens(tokens); // create light from tokens
	else if (ft_strequiv(token->chunk, "C"))
		camera_from_tokens(tokens); // create camera from tokens
	else if (ft_strequiv(token->chunk, "sp"))
		sphere_from_tokens(tokens); // create sphere from tokens
	else if (ft_strequiv(token->chunk, "pl"))
		plane_from_tokens(tokens); // create plane from tokens
	else if (ft_strequiv(token->chunk, "cy"))
		cylinder_from_tokens(tokens); // create cylinder from tokens
	else
		return ; // line with error in the rt file : we should display an error
}