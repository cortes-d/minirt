/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_raytracer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:22:21 by achappui          #+#    #+#             */
/*   Updated: 2024/08/16 15:34:28 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_raytracer.h"

int	main(void)
{
	char	c;

	printf("TYPE A NUMBER:\n##1## test_phong\n##2## test_red_circle\n##3## test_color_axe\n\n");
	c = getchar();
	if (c == '1')
		test_raytracer_phong();
	else if (c == '2')
		test_raytracer_red_circle();
	else if (c == '3')
		test_raytracer_color_axe();
	return (0);
}