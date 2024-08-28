/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:59:02 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:02:29 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "raytracer.h"
#include "util.h"

#define SHADOW_OPACITY 0.4f

/*t_vec3	lighting(t_computation c, t_light_point lp, t_light_ambient la, \
	t_material m, int in_shadow)
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
		vec3_mul(lp.color, lp.ratio), m.specular * pow(c.reflectv_dot_eyev, m.shininess));
	color = vec3_add(ambient, vec3_add(diffuse, specular));
	color.data[X] = clamp(color.data[X], 1);
	color.data[Y] = clamp(color.data[Y], 1);
	color.data[Z] = clamp(color.data[Z], 1);
    // Apply shadow to diffuse and specular components only
    if (in_shadow)
    {
        diffuse = vec3_mul(diffuse, SHADOW_OPACITY);
        specular = vec3_mul(specular, SHADOW_OPACITY);
        color = vec3_add(ambient, vec3_add(diffuse, specular));
    }
	return (color);
}*/

#include "libft.h"
#include "raytracer.h"
#include "util.h"

#define SHADOW_OPACITY 0.4f

t_vec3 lighting(t_computation c, t_light_point lp, t_light_ambient la, t_material m, int in_shadow)
{
    t_vec3 ambient;
    t_vec3 diffuse;
    t_vec3 specular;
    t_vec3 color;

    // Calculate ambient component
    ambient = vec3_mul(vec3_hadamard_product(m.color, vec3_mul(la.color, la.ratio)), m.ambient);

    // Calculate diffuse component
    if (c.lightv_dot_normalv < 0)
        diffuse = color_rgb_f(0, 0, 0);
    else
        diffuse = vec3_mul(vec3_hadamard_product(m.color, vec3_mul(lp.color, lp.ratio)), m.diffuse * c.lightv_dot_normalv);

    // Calculate specular component
    if (c.reflectv_dot_eyev <= 0)
        specular = color_rgb_f(0, 0, 0);
    else
        specular = vec3_mul(vec3_mul(lp.color, lp.ratio), m.specular * pow(c.reflectv_dot_eyev, m.shininess));

    // Combine components
    color = vec3_add(ambient, vec3_add(diffuse, specular));

    // Clamp color values
    color.data[X] = clamp(color.data[X], 1);
    color.data[Y] = clamp(color.data[Y], 1);
    color.data[Z] = clamp(color.data[Z], 1);

    // Apply shadow to diffuse and specular components only if in shadow
    if (in_shadow)
    {
        diffuse = vec3_mul(diffuse, SHADOW_OPACITY);
        specular = vec3_mul(specular, SHADOW_OPACITY);
        color = vec3_add(ambient, vec3_add(diffuse, specular));
    }

    return color;
}
