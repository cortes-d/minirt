/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:16:32 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/11 10:17:44 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_list	*tokenize_line(const char *line)
{
	t_list	*tokens;
	t_token	*t;
	int		i;
	int		len;

	tokens = NULL;
	i = 0;
	while (line[i])
	{
		while (line[i] && line[i] == ' ') // skip whitespaces
			i++;
		len = 0;
		while (line[i + len] && line[i + len] != ' ') // handle chunk
			len++;
		t = token(ft_subline(line, i, len)); // add token to linked list
		ft_lstadd_back(&tokens, ft_lstnew(t));
		//printf("chunk : '%s'\n", chunk);
		i += len;
	}
	return (tokens);
}