/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_from_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:58:33 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/08 11:41:18 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_material	material_from_color(float r, float g, float b)
{
	t_material	m;

	m = material();
	material_set_color(&m, r, g, b);
	return (m);
}
