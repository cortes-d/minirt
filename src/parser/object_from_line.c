/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_from_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:29:28 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/11 10:32:50 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
 * Step 1 "Tokenization": Create a token list with the line chunks
 * Each chunk is placed in one token
 * Step 2 "Object creation": Create an object from the token list
 * The first token of the list is the identifier.
 * It determines which object needs to be created.
 */
void    object_from_line(char *line)
{
	t_list	*tokens;
	tokens = tokenize_line(line);
	object_from_tokens(tokens);
	// free tokens
}
