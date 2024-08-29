/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_camera_tokens.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:48:50 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/29 08:48:50 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_camera_tokens(char **tokens)
{
	float	fov_test;

	if (tokens == NULL)
		exit_error("NULL parameter", "check_camera_tokens()");
	if (ft_array2d_size((const void **)tokens) != 4)
		exit_error("camera has incorrect number of arguments", \
		"check_camera_tokens()");
	check_vec3_token(tokens[1]);
	check_vec3_token(tokens[2]);
	check_float_token(tokens[3]);
	fov_test = extract_float(tokens[3]);
	if (!(fov_test >= 0 && fov_test <= 180))
		exit_error("camera fov must be between 0 and 180", \
		"check_camera_tokens()");
}
