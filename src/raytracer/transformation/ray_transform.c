/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:05:47 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 14:02:38 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_ray	ray_transform(t_ray ray, t_mat4 transformation)
{
	t_ray	new;

	new.p_origin = mat4_vec4_mul(transformation, ray.p_origin);
	new.v_direction = mat4_vec4_mul(transformation, ray.v_direction);
	return (new);
}
