/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:06:06 by achappui          #+#    #+#             */
/*   Updated: 2024/08/26 14:25:35 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_line(t_scene_data *scene_data, const char *line)
{
	char	**tokens;

	tokens = gc_add(ft_split(line, " \n"), 2);
	if (tokens == NULL)
		exit_error("ERROR: parse_line()\n");
	else if (*tokens == NULL)
	{
		gc_free(tokens);
		return ;
	}
	type_interpreter(tokens, scene_data);
	gc_free(tokens);
}