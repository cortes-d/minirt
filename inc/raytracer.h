/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 22:18:09 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/14 15:39:34 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

// =============================================================================
// Section : Includes
// =============================================================================

# include "libft.h" // t_list
# include "libla.h"
# include "scene.h"

// =============================================================================
// Section : Constants and Macros
// =============================================================================

// =============================================================================
// Section : Type Definitions
// =============================================================================

// ·············································································
// Sub-section : Forward declarations
// ·············································································

typedef struct s_ray				t_ray;

typedef struct s_intersection_pair	t_intersection_pair;
typedef struct s_intersection		t_intersection;

typedef struct s_shading			t_shading;

// ·············································································
// Sub-section : Ray
// ·············································································

// --- Structure : Ray ---
typedef struct s_ray
{
	t_vec4	p_origin;
	t_vec4	v_direction;
}	t_ray;

// ·············································································
// Sub-section : Intersection
// ·············································································

// --- Structure : Intersection ---
typedef struct s_intersection_pair
{
	int		count;
	float	t[2];
}	t_intersection_pair;

typedef struct s_intersection
{
	float		t;
	t_object	object;
}	t_intersection;

// ·············································································
// Sub-section : Light
// ·············································································

// --- Structure : Shading ---
typedef struct s_shading
{
	t_vec4	eyev;
	t_vec4	normalv;
}	t_shading;

// =============================================================================
// Section : Functions
// =============================================================================

// --- Ray ---
t_ray				ray(t_vec4 p_origin, t_vec4 v_direction);
t_vec4				position(t_ray ray, float t);

// --- Intersection ---
void				intersect(t_ray ray, t_object object, \
						t_list **intersections);
void				intersect_sphere(t_ray ray, t_object object, \
						t_list **intersections);
void				intersect_cylinder(t_ray ray, t_object object, \
						t_list **intersections);
void				intersect_plane(t_ray ray, t_object object, \
						t_list **intersections);
t_intersection_pair	init_intersection_pair(void);
t_intersection		*intersection_create(float t, t_object object);
void				intersection_add_to_list(t_list **intersections, \
						t_intersection *intersection);
t_intersection		*hit(t_list *intersections);

// --- Transformation ---
t_ray				ray_transform(t_ray ray, t_mat4 transformation);
void				set_transform(t_object *object, t_mat4 transformation);
void				add_transform(t_object *object, t_mat4 transformation);

// --- Light ---
t_vec3				lighting(t_material material, t_light_point light, \
						t_vec4 intersection_point, t_shading shading);
t_vec4				normal_at(t_object object, t_vec4 world_point);
t_vec4				reflect(t_vec4 in, t_vec4 normal);

#endif