/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 22:20:37 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 14:29:48 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "raytracer.h"

static t_vec3	lighting_ambient(t_material material, t_light_point light)
{
	return (vec3_mul(vec3_hadamard_product(material.color, light.color), \
		material.ambient));
}

static t_vec3	lighting_diffuse(t_material material, t_light_point light, \
	t_vec4 lightv, t_vec4 normalv)
{
	float	light_dot_normal;

	/*printf("Diffuse - Material Diffuse: %f\n", material.diffuse);
    printf("Diffuse - Light Color: (%f, %f, %f)\n", light.color.data[0], light.color.data[1], light.color.data[2]);
    printf("Diffuse - Light Vector: (%f, %f, %f, %f)\n", lightv.data[0], lightv.data[1], lightv.data[2], lightv.data[3]);*/
    //printf("Diffuse - Normal Vector: (%f, %f, %f, %f)\n", normalv.data[0], normalv.data[1], normalv.data[2], normalv.data[3]);

	light_dot_normal = vec4_dot_product(lightv, normalv);
	if (light_dot_normal < 0)
		return (color_rgb_f(0, 0, 0));
	return (vec3_mul(vec3_hadamard_product(material.color, light.color), \
		material.diffuse * light_dot_normal));
}

static t_vec3	lighting_specular(t_material material, t_light_point light, \
	t_vec4 lightv, t_shading shading)
{
	t_vec4	reflectv;
	float	reflect_dot_eye;
	float	factor;

	/*printf("Specular - Material Specular: %f\n", material.specular);
    printf("Specular - Light Color: (%f, %f, %f)\n", light.color.data[0], light.color.data[1], light.color.data[2]);
    printf("Specular - Light Vector: (%f, %f, %f, %f)\n", lightv.data[0], lightv.data[1], lightv.data[2], lightv.data[3]);*/
    //printf("Specular - Shading Normal Vector: (%f, %f, %f, %f)\n", shading.normalv.data[0], shading.normalv.data[1], shading.normalv.data[2], shading.normalv.data[3]);
    //printf("Specular - Shading Eye Vector: (%f, %f, %f, %f)\n", shading.eyev.data[0], shading.eyev.data[1], shading.eyev.data[2], shading.eyev.data[3]);

	reflectv = reflect(vec4_inv(lightv), shading.normalv);
	reflect_dot_eye = vec4_dot_product(reflectv, shading.eyev);
	if (reflect_dot_eye <= 0)
		return (color_rgb_f(0, 0, 0));
	factor = pow(reflect_dot_eye, material.shininess);
	return (vec3_mul(light.color, material.specular * factor));
}

t_vec3	lighting(t_material material, t_light_point light, \
	t_vec4 intersection_point, t_shading shading)
{
	t_vec4	lightv;
	t_vec3	ambient;
	t_vec3	diffuse;
	t_vec3	specular;
	t_vec3	color;

	lightv = vec4_normalize(vec4_sub(light.p_origin, intersection_point));
	ambient = lighting_ambient(material, light);
	diffuse = lighting_diffuse(material, light, lightv, shading.normalv);
	specular = lighting_specular(material, light, lightv, shading);
	color = vec3_add(ambient, vec3_add(diffuse, specular));
	color.data[X] = ft_clamp(color.data[X], 1);
	color.data[Y] = ft_clamp(color.data[Y], 1);
	color.data[Z] = ft_clamp(color.data[Z], 1);
	return (color);
}


/*t_vec3	lighting(t_material material, t_light_point light, \
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
		reflectv = reflect(vec4_inv(lightv), normalv);
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

}*/
