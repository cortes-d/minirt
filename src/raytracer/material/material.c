/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:51:28 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/05 15:54:09 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_material	material(t_vec3 color, float ambient, float diffuse, float specular)
{
	t_material	material;

	material.color = color;
	material.ambient = ambient;
	material.diffuse = diffuse;
	material.specular = specular;
	return (material);
}
