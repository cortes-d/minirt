/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:28:44 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/05 15:58:59 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H
# include "libla.h"

// =============================================================================
// Section : Constants and Macros
// =============================================================================

# define COLOR_DEFAULT 0.8

// =============================================================================
// Section : Type Definitions
// =============================================================================

// --- Enum ---
typedef enum e_object_type
{
	SPHERE,
	CUBE,
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
		//t_cube		cube;
		//t_plane		plane;
		//t_cylinder	cylinder;
	}	u_object;

}	t_object;

// --- Structure : Sphere ---
typedef struct s_sphere
{
	t_vec4	p_origin;
	float	radius;
}	t_sphere;

// =============================================================================
// Section : Functions
// =============================================================================

t_vec4		point(float r, float g, float b);
t_vec4		vector(float x, float y, float z);

// --- Ray ---
t_vec4		position(t_ray ray, float t);

// --- Color ---
t_vec3		color(float r, float g, float b);

// --- Material ---
t_material	material(t_vec3 color, float ambient, \
				float diffuse, float specular);

// --- Primitive ---
t_object	sphere(t_vec4 p_origin, float radius);

#endif