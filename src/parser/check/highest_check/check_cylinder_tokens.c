/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinder_tokens.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:43:49 by achappui          #+#    #+#             */
/*   Updated: 2024/08/21 11:59:10 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//on fait du >= sans utiliser de equalf a voir

void	check_cylinder_tokens(char **tokens)
{
	t_vec3	vec_3_test;

	if (tokens == NULL)
		exit_error("ERROR: check_cylinder_tokens()\n");
	if (ft_array2d_size((const void **)tokens) != 6)
		exit_error("ERROR: check_cylinder_tokens()\n");
	check_vec3_token(tokens[1]);
	check_vec3_token(tokens[2]);
	vec_3_test = extract_vec3(tokens[2]);
	if (!equalf(vec3_magnitude(vec_3_test), 1))
		exit_error("ERROR: check_cylinder_tokens()\n");
	if (!(vec_3_test.data[X] >= -1 && vec_3_test.data[X] <= 1) || \
		!(vec_3_test.data[Y] >= -1 && vec_3_test.data[Y] <= 1) || \
		!(vec_3_test.data[Z] >= -1 && vec_3_test.data[Z] <= 1))
		exit_error("ERROR: check_cylinder_tokens()\n");
	check_float_token(tokens[3]);
	check_float_token(tokens[4]);
	check_color_token(tokens[5]);
}