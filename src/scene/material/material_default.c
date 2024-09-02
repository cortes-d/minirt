/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_default.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:30:34 by dcortes           #+#    #+#             */
/*   Updated: 2024/09/02 10:13:16 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

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
