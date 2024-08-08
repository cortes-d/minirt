/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:28:44 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/08 10:36:15 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H
# include "libft.h"
# include "libla.h"

// =============================================================================
// Section : Constants and Macros
// =============================================================================

# define CAMERA_HSIZE 500
# define CAMERA_VSIZE 500

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
	float	shininess;
}	t_material;

// --- Structure : Sphere ---
typedef struct s_sphere
{
	t_vec4	p_origin;
	float	radius;
}	t_sphere;

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

// --- Structure : Camera ---
typedef struct s_camera
{
	t_mat4			transform;
	unsigned int	hsize;
	unsigned int	vsize;
	float			half_width;
	float			half_height;
	float			pixel_size;
}	t_camera;

// --- Structure : Point light ---
typedef struct s_light_point
{
	t_vec4	p_origin;
	t_vec3	color;
}	t_light_point;

// --- Structure : World ---
typedef struct s_world
{
	unsigned int	lights_nb;
	t_light_point	*lights;
	unsigned int	objects_nb;
	t_object		*objects;
}	t_world;


// =============================================================================
// Section : Functions
// =============================================================================

// --- Ray ---
t_ray				ray(t_vec4 p_origin, t_vec4 v_direction);
t_vec4				position(t_ray ray, float t);

// --- Intersection ---
t_intersection_pair	intersect(t_ray ray, t_object object);
t_intersection		intersection(float t, t_object object);
void				intersections(t_list **intersections, \
						t_intersection *intersection);
t_intersection		*hit(t_list *intersections);

// --- Transformation ---
t_ray				transform(t_ray ray, t_mat4 transformation);
void				set_transform(t_object *object, t_mat4 transformation);

// --- Color ---
t_vec3				color(float r, float g, float b);

// --- Material ---
t_material			material(t_vec3 color, float ambient, \
						float diffuse, float specular, float shininess);

// --- Light ---
t_light_point		light_point(t_vec4 position, t_vec3 color);
t_vec3				lighting(t_material material, t_light_point light, \
						t_vec4 intersection_point, t_vec4 eyev, t_vec4 normalv);
t_vec4				normal_at(t_object object, t_vec4 world_point);
t_vec4				reflect(t_vec4 in, t_vec4 normal);

// --- Geometry ---
t_vec4				point(float x, float y, float z);
t_vec4				vector(float x, float y, float z);
t_object			sphere(void);

// --- World ---
t_world				world(void);

#endif