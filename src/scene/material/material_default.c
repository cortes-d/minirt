/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_default.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:30:34 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/29 08:30:39 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

#define DEFAULT_COLOR_R 1
#define DEFAULT_COLOR_G 1
#define DEFAULT_COLOR_B 1
#define DEFAULT_AMBIENT 0.1
#define DEFAULT_DIFFUSE 0.9
#define DEFAULT_SPECULAR 0.9
#define DEFAULT_SHININESS 200.0

t_material	material_default(void)
{
	t_material	material;

	material.color = color_rgb_f(\
		DEFAULT_COLOR_R, DEFAULT_COLOR_G, DEFAULT_COLOR_B);
	material.ambient = DEFAULT_AMBIENT;
	material.diffuse = DEFAULT_DIFFUSE;
	material.specular = DEFAULT_SPECULAR;
	material.shininess = DEFAULT_SHININESS;
	return (material);
}
