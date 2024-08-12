/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:09:36 by achappui          #+#    #+#             */
/*   Updated: 2024/08/12 10:44:39 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
1. liste de token split par space :eyes: fonction split
2. Get le type verifier si c'est un objet unique, ensuite creer le bon objet
3. interpreter les elements dans le bon ordre en remplissant l'objet
4. ajouter a la liste chainee d'objets
5. 
*/

void	parsing_loop(t_list *object_list, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (errno != 0)
		EXIT_ERROR();
	while (line)
	{
		parse_line();
		line = get_next_line(fd);
		if (errno != 0)
			EXIT_ERROR();
	}
}