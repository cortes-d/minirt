/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:56:59 by achappui          #+#    #+#             */
/*   Updated: 2024/08/14 16:58:08 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_parser.h"

int	main(void)
{
	t_scene	scene;

	scene = scene_empty();
	if (parse_scene("test_scene.rt", &scene) == ERROR)
	{
		printf("ERROR something went wrong\n");
		return (ERROR);
	}
	print_scene(&scene);
	return (0);
}

