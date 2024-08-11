/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_from_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:40:02 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/11 11:40:05 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void    params_from_tokens(t_list *tokens, t_token **params, int count)
{
	int		i;
	t_list	*current;

	current = tokens->next;
	i = 0;
	while (i < count)
	{
		params[i] = current->content;
		current = current->next;
		i++;
	}
}
