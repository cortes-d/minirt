/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:31:06 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/14 15:47:10 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "libla.h"

// =============================================================================
// Section : Constants and Macros
// =============================================================================

# define CAMERA_HSIZE 500
# define CAMERA_VSIZE 500

// =============================================================================
// Section : Type Definitions
// =============================================================================

// --- Structure : Scene ---
typedef struct s_scene
{
	t_camera		*camera;
	t_light_ambient	*light_ambient;
	t_light_point	*light_point;
	t_object		**objects;
}	t_scene;

// ·············································································
// Sub-section : Camera
// ·············································································

typedef struct s_camera
{
	t_mat4			transform;
	unsigned int	hsize;
	unsigned int	vsize;
	float			half_width;
	float			half_height;
	float			pixel_size;
}	t_camera;

// ·············································································
// Sub-section : Forward declarations
// ·············································································

typedef struct s_object			t_object;
typedef enum e_object_type		t_object_type;

typedef struct s_sphere			t_sphere;
typedef struct s_cylinder		t_cylinder;
typedef struct s_plane			t_plane;

typedef struct s_material		t_material;

typedef struct s_light_point	t_light_point;
typedef struct s_world			t_world;

// ·············································································
// Sub-section : Primitive
// ·············································································

// --- Structure : Sphere ---
typedef struct s_sphere
{
	t_vec4	p_origin;
	float	radius;
}	t_sphere;

// --- Structure : Cylinder ---
typedef struct s_cylinder
{
	t_vec4	p_origin;
	t_vec4	v_axis;
	float	height;
	float	diameter;
	float	minimum;
	float	maximum;
}	t_cylinder;

// --- Structure : Plane ---
typedef struct s_plane
{
	t_vec4	p_point;
	t_vec4	v_normal;
}	t_plane;

// --- Enum : Object type ---
typedef enum e_object_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_object_type;

// --- Structure : Material ---
typedef struct s_material
{
	t_vec3	color;
	float	ambient;
	float	diffuse;
	float	specular;
	float	shininess;
}	t_material;

// --- Structure : Object ---
typedef struct s_object
{
	t_object_type	type;
	t_mat4			transform;
	t_mat4			transform_inverse;
	t_material		material;
	union
	{
		t_sphere	sphere;
		t_cylinder	cylinder;
		t_plane		plane;
	}	u_object;

}	t_object;

// ·············································································
// Sub-section : Light
// ·············································································

// --- Structure : Light point ---
typedef struct s_light_point
{
	t_vec4	p_origin;
	float	brightness;
	t_vec3	color;
}	t_light_point;

// --- Structure : Light ambient ---
typedef struct s_light_ambient
{
	t_vec4	p_origin;
	float	lightning_ratio;
	t_vec3	color;
}	t_light_ambient;

// =============================================================================
// Section : Functions
// =============================================================================

// --- Material ---
t_material			material(void);
t_material			material_from_color(float r, float g, float b);
void				set_object_color(t_object *object, t_vec3 color);

// --- Light ---
t_light_point		light_point(t_vec4 position, t_vec3 color);

// --- Primitive ---
t_object			sphere(void);
t_object			sphere_from_params(t_vec4 p_origin, float radius);
t_object			cylinder(void);
t_object			cylinder_from_params(t_vec4 p_origin, \
						t_vec4 v_axis, float diameter, float height);
t_object			plane(void);
t_object			plane_from_params(t_vec4 p_point, t_vec4 v_normal);

// --- World ---
t_world				world(void);

#endif