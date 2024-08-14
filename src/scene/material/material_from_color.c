/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_from_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:58:33 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/14 16:09:48 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_material	material_from_color(float r, float g, float b)
{
	(void)r;
	(void)g;
	(void)b;
	t_material	m;

	m = material();
	//material_set_color(&m, r, g, b);
	return (m);
}
