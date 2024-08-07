/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:32:10 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/05 13:37:15 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

// ray(vec4_point(0, 0, 0), vec4_vector(2, 5, 6)); 
t_ray	ray(t_vec4 p_origin, t_vec4 v_direction)
{
	t_ray	ray;

	ray.p_origin = p_origin;
	ray.v_direction = v_direction;
	return (ray);
}
