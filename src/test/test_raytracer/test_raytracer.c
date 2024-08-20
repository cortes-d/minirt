/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_raytracer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:22:21 by achappui          #+#    #+#             */
/*   Updated: 2024/08/20 11:27:58 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_raytracer.h"

int	main(void)
{
	char	c;

	printf("TYPE A NUMBER:\n\
		##1## test_phong\n\
		##2## test_red_circle\n\
		##3## test_color_axe\n\
		##4## test_scene\n\
		##5## test_scene_camera\n\
		\n");
	c = getchar();
	if (c == '1')
		test_raytracer_phong();
	else if (c == '2')
		test_raytracer_red_circle();
	else if (c == '3')
		test_raytracer_color_axe();
	else if (c == '4')
		test_raytracer_scene();
	else if (c == '5')
		test_raytracer_scene_camera();
	return (0);
}
