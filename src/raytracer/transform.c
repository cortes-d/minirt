/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:05:47 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/06 11:10:16 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_ray	transform(t_ray ray, t_mat4 transformation)
{
	return (mat4_vec4_mul(transformation, ray.v_direction));
}
