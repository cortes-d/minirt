/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:02:26 by achappui          #+#    #+#             */
/*   Updated: 2024/08/07 15:40:09 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_vec3	lighting(t_material material, t_point_light light, \
		t_vec4 intersection_point, t_vec4 eyev, t_vec4 normalv)
{
	t_vec3	effective_color;
	t_vec4	lightv;
	t_vec4	reflectv;
	t_vec3	ambient;
	t_vec3	diffuse;
	t_vec3	specular;
	float	light_dot_normal;
	float	reflect_dot_eye;
	float	factor;

	effective_color = vec3_hadamard_product(material.color, light.color);
	lightv = vec4_normalize(vec4_sub(light.p_origin, intersection_point));
	ambient = vec3_mul(effective_color, material.ambient);
	light_dot_normal = vec4_dot_product(lightv, normalv);
	if (light_dot_normal < 0)
	{
		diffuse = vec3(0, 0, 0);
		specular = vec3(0, 0, 0);
	}
	else
	{
		diffuse = vec3_mul(effective_color, material.diffuse * light_dot_normal);
		reflectv = reflect_vector(vec4_inv(lightv), normalv);
		reflect_dot_eye = vec4_dot_product(reflectv, eyev);
		if (reflect_dot_eye <= 0)
			specular = vec3(0, 0, 0);
		else
		{
			factor = pow(reflect_dot_eye, material.shininess);
			specular = vec3_mul(light.color, material.specular * factor);
		}
		return (vec3_add(ambient, vec3_add(diffuse, specular)));
	}

}
