/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:31:06 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 13:34:46 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "libla.h"
# include "libft.h"
# include "math.h"

// =============================================================================
// Section : Constants and Macros
// =============================================================================

# define CAMERA_HSIZE	500
# define CAMERA_VSIZE	500
# define UP_VECTOR_X	0
# define UP_VECTOR_Y	1
# define UP_VECTOR_Z	0

// =============================================================================
// Section : Type Definitions
// =============================================================================

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

typedef struct s_camera			t_camera;

typedef struct s_scene			t_scene;

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
	int		closed;
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
	float	ratio;
	t_vec3	color;
}	t_light_point;

// --- Structure : Light ambient ---
typedef struct s_light_ambient
{
	t_vec4	p_origin;
	float	ratio;
	t_vec3	color;
}	t_light_ambient;

// ·············································································
// Sub-section : Camera
// ·············································································

typedef struct s_camera
{
	t_vec4			p_origin;
	t_vec4			v_orientation;
	float			h_fov;
	t_mat4			view_transform;
	unsigned int	hsize;
	unsigned int	vsize;
	float			half_width;
	float			half_height;
	float			pixel_size;
}	t_camera;

// ·············································································
// Sub-section : Scene
// ·············································································

// --- Structure : Scene ---
typedef struct s_scene
{
	t_camera		*camera;
	t_light_ambient	*light_ambient;
	t_light_point	*light_point;
	t_object		**objects;
}	t_scene;

// =============================================================================
// Section : Functions
// =============================================================================

// --- Camera ---
t_camera	camera_default(void);
t_camera	camera(t_vec4 p_origin, t_vec4 v_orientation, float h_fov);
void		camera_computation(t_camera *camera);
t_mat4		view_transform(t_vec4 p_origin, t_vec4 forward, t_vec4 up);


// --- Material ---
t_material			material_default(void);
t_material			material_from_color(float r, float g, float b);
void				set_object_color(t_object *object, t_vec3 color);

// --- Light ---
t_light_point		light_point(t_vec4 position, float ratio, t_vec3 color);
t_light_ambient		light_ambient(float ratio, t_vec3 color);

// --- Primitive ---
t_object			cylinder_default(void);
t_object			plane_default(void);
t_object			sphere_default(void);
t_object			cylinder(t_vec4 p_origin, \
					t_vec4 v_axis, float diameter, float height);
t_object			plane(t_vec4 p_point, t_vec4 v_normal);
t_object			sphere(t_vec4 p_origin, float radius);

// --- Transformation ---
void				set_transform(t_object *object, t_mat4 transformation);
void				add_transform(t_object *object, t_mat4 transformation);

// --- Scene ---
t_scene				scene_empty(void);
t_scene				scene_default(void);
void				scene_free(t_scene *scene);

#endif