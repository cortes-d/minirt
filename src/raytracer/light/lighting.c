/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:35:12 by dcortes           #+#    #+#             */
/*   Updated: 2024/09/02 12:58:36 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_vec3	lighting(t_computation c, t_light_point lp, t_light_ambient la, \
				t_material m)
{
	t_context_lighting	ctx;

	ctx.ambient = vec3_mul(vec3_hadamard_product(m.color, \
	vec3_mul(la.color, la.ratio)), m.ambient);
	if (c.lightv_dot_normalv < 0)
		ctx.diffuse = color_rgb_f(0, 0, 0);
	else
		ctx.diffuse = vec3_mul(vec3_hadamard_product(m.color, \
		vec3_mul(lp.color, lp.ratio)), m.diffuse * c.lightv_dot_normalv);
	if (c.reflectv_dot_eyev <= 0)
		ctx.specular = color_rgb_f(0, 0, 0);
	else
		ctx.specular = vec3_mul(vec3_mul(lp.color, lp.ratio), \
		m.specular * pow(c.reflectv_dot_eyev, m.shininess));
	if (c.in_shadow)
	{
		ctx.diffuse = vec3_mul(ctx.diffuse, SHADOW_OPACITY);
		ctx.specular = vec3_mul(ctx.specular, SHADOW_OPACITY);
		ctx.color = vec3_add(ctx.ambient, vec3_add(ctx.diffuse, ctx.specular));
	}
	else
		ctx.color = vec3_add(ctx.ambient, vec3_add(ctx.diffuse, ctx.specular));
	ctx.color = vec3_clamp(ctx.color, 1);
	return (ctx.color);
}
