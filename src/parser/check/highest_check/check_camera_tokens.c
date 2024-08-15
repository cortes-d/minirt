/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_camera_tokens.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:30:44 by achappui          #+#    #+#             */
/*   Updated: 2024/08/15 09:44:56 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//on fait du >= sans utiliser de equalf a voir

int	check_camera_tokens(char **tokens)
{
	t_vec3	vec_3_test;
	float	fov_test;

	if (tokens == NULL)
		return (ERROR);
	if (ft_array2d_size((const void **)tokens) != 4)
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
	if (check_float_token(tokens[3]) == ERROR)
		return (ERROR);
	fov_test = extract_float(tokens[3]);
	if (!(fov_test >= 0 && fov_test <= 180))
		return (ERROR);
	return (0);
}