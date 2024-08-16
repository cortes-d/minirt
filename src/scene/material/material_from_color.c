/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_from_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:58:33 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/16 15:28:06 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_material	material_from_color(float r, float g, float b)
{
	(void)r;
	(void)g;
	(void)b;
	t_material	m;

	m = material_default();
	//material_set_color(&m, r, g, b);
	return (m);
}
