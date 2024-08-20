/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 22:20:37 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/20 13:50:13 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "raytracer.h"
#include "util.h"

t_vec3	lighting(t_computation c, t_light_point lp, t_light_ambient la, t_material m)
{
	t_vec3	ambient;
	t_vec3	diffuse;
	t_vec3	specular;
	t_vec3	color;

	ambient = vec3_mul(vec3_hadamard_product(m.color, \
	vec3_mul(la.color, la.ratio)), m.ambient);
	if (c.lightv_dot_normalv < 0)
		diffuse = color_rgb_f(0, 0, 0);
	else
		diffuse = vec3_mul(\
		vec3_hadamard_product(m.color, vec3_mul(lp.color, lp.ratio)), \
		m.diffuse * c.lightv_dot_normalv);
	if (c.reflectv_dot_eyev <= 0)
		specular = color_rgb_f(0, 0, 0);
	else
		specular = vec3_mul(\
		lp.color, m.specular * pow(c.reflectv_dot_eyev, m.shininess));
	color = vec3_add(ambient, vec3_add(diffuse, specular));
	color.data[X] = clamp(color.data[X], 1);
	color.data[Y] = clamp(color.data[Y], 1);
	color.data[Z] = clamp(color.data[Z], 1);
	return (color);
}
