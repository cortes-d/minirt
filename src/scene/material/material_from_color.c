/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_from_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:31:02 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/29 08:32:32 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_material	material_from_color(float r, float g, float b)
{
	t_material	m;

	m = material_default();
	m.color = color_rgb_f(r, g, b);
	return (m);
}
