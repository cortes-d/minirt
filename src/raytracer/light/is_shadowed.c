/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.json                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:48:18 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 10:57:50 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "raytracer.h"
#include "util.h"

int	is_shadowed(t_scene scene, t_vec4 point, t_list **intersections)
{
	t_vec4			v;
	float			distance;
	t_vec4			direction;
	t_ray			r;
	t_intersection	*h;

	v = vec4_sub(scene.light_point->p_origin, point);
	distance = vec4_magnitude(v);
	direction = vec4_normalize(v);
	r = ray(point, direction);
	intersect_scene(r, scene, intersections);
	h = hit(*intersections);
	if (h && h->t < distance)
		return (1);
	return (0);
}
/*#define SHADOW_FACTOR_SCALE 100.0f // Scale the shadow factor to increase its impact

float is_shadowed(t_scene scene, t_vec4 point, t_list **intersections)
{
    t_vec4          v;
    float           distance;
    t_vec4          direction;
    t_ray           r;
    t_intersection  *h;

	return (0.0f);
    v = vec4_sub(scene.light_point->p_origin, point);
    distance = vec4_magnitude(v);
    direction = vec4_normalize(v);
    r = ray(point, direction);
    intersect_scene(r, scene, intersections);
    h = hit(*intersections);
    if (h && h->t < distance)
    {
        // Calculate shadow factor based on the distance to the intersection
        float shadow_factor = h->t / distance;

        // Debugging: Log intersection distance and shadow factor
        //printf("Intersection Distance: %f, Shadow Factor: %f\n", h->t, shadow_factor);
		shadow_factor = clamp(shadow_factor * SHADOW_FACTOR_SCALE, 1.0f);
        return shadow_factor;
    }
    return 0.0f; // No shadow
}
*/