/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 09:24:11 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 09:27:05 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_ray	ray_transform(t_ray r, const t_object object)
{
	return (ray(mat4_vec4_mul(object.transform_inverse, r.p_origin), \
		mat4_vec4_mul(object.transform_inverse, r.v_direction)));
}
