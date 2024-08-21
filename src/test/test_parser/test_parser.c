/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:56:59 by achappui          #+#    #+#             */
/*   Updated: 2024/08/21 12:59:20 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_parser.h"

int	main(void)
{
	t_scene	scene;

	scene = scene_empty();
	printf("A 0.200 255,255,255\nC -50,0,20 0,0,1 70.000\nL -40,0,30 0.700 255,255,255\npl 0,0,0 0,1.0,0 255,0,225\nsp 0,0,20 20.000 255,0,0\ncy 50,0,20.6 0,0,1.0 14.200 21.4200 10,0,255\n");
	printf("\n");
	parse_scene("src/test/test_parser/test_scene.rt", &scene);
	test_print_scene(&scene);
	return (0);
}

