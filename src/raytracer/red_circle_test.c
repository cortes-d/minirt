/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_circle_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:33:05 by achappui          #+#    #+#             */
/*   Updated: 2024/08/06 12:36:34 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int	main()
{
	t_object	my_sphere;

	my_sphere = sphere(point(0, 0 ,0), 1);
	my_sphere.material.color = vec3(255, 0, 0);

	t_canva		my_canva;
	




}