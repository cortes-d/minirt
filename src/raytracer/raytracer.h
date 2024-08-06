/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:28:44 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/06 10:28:01 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H
# include "libla.h"

// =============================================================================
// Section : Constants and Macros
// =============================================================================

// =============================================================================
// Section : Type Definitions
// =============================================================================

// --- Enum ---
typedef enum e_object_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_object_type;

// --- Structure : Ray ---
typedef struct s_ray
{
	t_vec4	p_origin;
	t_vec4	v_direction;
}	t_ray;

// --- Structure : Material ---
typedef struct s_material
{
	t_vec3	color;
	float	ambient;
	float	diffuse;
	float	specular;
}	t_material;

// --- Structure : Object ---
typedef struct s_object
{
	t_object_type	type;
	t_mat4			transform;
	t_material		material;
	union
	{
		t_sphere	sphere;
		//t_plane		plane;
		//t_cylinder	cylinder;
	}	u_object;

}	t_object;

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

// --- Structure : Sphere ---
typedef struct s_sphere
{
	t_vec4	p_origin;
	float	radius;
}	t_sphere;

// --- Structure : Camera ---
typedef struct s_camera
{
	t_mat4			view_transform;
	unsigned int	hsize;
	unsigned int	vsize;
	float			half_width;
	float			half_height;
	float			pixel_size;
}	t_camera;

// =============================================================================
// Section : Functions
// =============================================================================

t_vec4				point(float x, float y, float z);
t_vec4				vector(float x, float y, float z);

// --- Ray ---
t_vec4				position(t_ray ray, float t);

// --- Intersection ---
t_intersection_pair	intersect(t_ray ray, t_object object);
t_intersection		intersection(float t, t_object object);

// --- Color ---
t_vec3				color(float r, float g, float b);

// --- Material ---
t_material			material(t_vec3 color, float ambient, \
						float diffuse, float specular);

// --- Primitive ---
t_object			sphere(t_vec4 p_origin, float radius);

#endif