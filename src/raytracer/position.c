/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:50:04 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/05 15:49:41 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_vec4	position(t_ray ray, float t)
{
	return (vec4_add(ray.p_origin, vec4_mul(ray.v_direction, t)));
}
