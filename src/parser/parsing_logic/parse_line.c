/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:50:19 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/29 08:50:19 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_line(t_scene_data *scene_data, const char *line)
{
	char	**tokens;

	tokens = gc_add(ft_split(line, " \n"), 2);
	if (tokens == NULL)
		exit_error("split failed", "parse_line()");
	else if (*tokens == NULL)
	{
		gc_free(tokens);
		return ;
	}
	type_interpreter(tokens, scene_data);
	gc_free(tokens);
}
