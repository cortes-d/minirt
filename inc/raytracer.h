/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 22:18:09 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/21 15:12:34 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

// =============================================================================
// Section : Includes
// =============================================================================

# include "libft.h" // t_list
# include "libla.h"
# include "graphic.h" // t_image
# include "scene.h"
# include "memory.h"
# include "parser.h"

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

// // --- Structure : Shading ---
// typedef struct s_shading
// {
// 	t_vec4	eyev;
// 	t_vec4	normalv;
// }	t_shading;

// --- Structure : Computation ---
typedef struct s_computation
{
	t_object		object;
	t_vec4			point;
	t_vec4			point_over;
	t_vec4			eyev;
	t_vec4			normalv;
	t_vec4			reflectv;
	t_vec4			lightv;
	float			lightv_dot_normalv;
	float			reflectv_dot_eyev;
}	t_computation;

// =============================================================================
// Section : Functions
// =============================================================================

// --- Ray ---
t_ray				ray(t_vec4 p_origin, t_vec4 v_direction);
t_vec4				position(t_ray ray, float t);
t_ray				ray_transform(t_ray ray, t_mat4 transformation);

// --- Intersection ---
void				intersect(t_ray ray, t_object object, \
						t_list **intersections);
void				intersect_scene(t_ray ray, t_scene scene, \
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

// --- Light ---
t_computation		prepare_computation(t_intersection intersection, \
						t_ray ray, t_light_point lp);
t_vec3				lighting(t_computation c, t_light_point lp, \
						t_light_ambient la, t_material m, int in_shadow);
t_vec4				normal_at(t_object object, t_vec4 world_point);
t_vec4				reflect(t_vec4 in, t_vec4 normal);
int					is_shadowed(t_scene scene, t_vec4 point, \
						t_list **intersections);

// --- Render ---
t_ray				ray_for_pixel(t_camera camera, unsigned int px, unsigned int py);
t_vec3				color_at(t_ray ray, t_scene scene);
t_vec3				shade_hit(t_scene scene, t_computation comps, t_list **intersections);
void				render(t_scene scene, t_image *image);

#endif