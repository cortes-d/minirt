/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_plane_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:44:02 by achappui          #+#    #+#             */
/*   Updated: 2024/08/14 10:19:18 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//on fait du >= sans utiliser de equalf a voir

int	check_plane_tokens(char **tokens)
{
	t_vec3	vec_3_test;

	if (tokens == NULL)
		return (ERROR);
	if (array_2d_size(tokens) != 4)
		return (ERROR);
	if (check_vec3_token(tokens[1]) == ERROR)
		return (ERROR);
	if (check_vec3_token(tokens[2]) == ERROR)
		return (ERROR);
	vec_3_test = extract_vec3(tokens[2]);
	if (!equalf(vec3_magnitude(vec_3_test), 1))
		return (ERROR);
	if (!(vec_3_test.data[X] >= -1 && vec_3_test.data[X] <= 1) || \
		!(vec_3_test.data[Y] >= -1 && vec_3_test.data[Y] <= 1) || \
		!(vec_3_test.data[Z] >= -1 && vec_3_test.data[Z] <= 1))
		return (ERROR);
	if (check_color_token(tokens[3]) == ERROR)
		return (ERROR);
	return (0);
}