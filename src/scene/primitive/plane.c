/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:03:06 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/22 13:56:53 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

/*t_object	plane(t_vec4 p_point, t_vec4 v_normal)
{
	t_object	p;
	float		theta_x;
	float		theta_y;
	float		theta_z;

	theta_x = atan2(v_normal.data[Z], v_normal.data[Y]);
	theta_y = atan2(v_normal.data[X], v_normal.data[Z]);
	theta_z = atan2(v_normal.data[Y], v_normal.data[X]);
	p = plane_default();
	add_transform(&p, mat4_rotation_x(theta_x));
	add_transform(&p, mat4_rotation_y(theta_y));
	add_transform(&p, mat4_rotation_z(theta_z));
	add_transform(&p, \
	mat4_translation(p_point.data[X], p_point.data[Y], p_point.data[Z]));
	p.u_object.plane.p_point = p_point;
	p.u_object.plane.v_normal = v_normal;
	return (p);
}*/
/*
t_mat4 mat4_rotation(t_vec4 axis, float angle) {
    t_mat4 mat = mat4_identity();
    float cos_theta = cos(angle);
    float sin_theta = sin(angle);
    float one_minus_cos = 1.0f - cos_theta;

    axis = vec4_normalize(axis);

    mat.data[0][0] = cos_theta + axis.data[X] * axis.data[X] * one_minus_cos;
    mat.data[0][1] = axis.data[X] * axis.data[Y] * one_minus_cos - axis.data[Z] * sin_theta;
    mat.data[0][2] = axis.data[X] * axis.data[Z] * one_minus_cos + axis.data[Y] * sin_theta;

    mat.data[1][0] = axis.data[Y] * axis.data[X] * one_minus_cos + axis.data[Z] * sin_theta;
    mat.data[1][1] = cos_theta + axis.data[Y] * axis.data[Y] * one_minus_cos;
    mat.data[1][2] = axis.data[Y] * axis.data[Z] * one_minus_cos - axis.data[X] * sin_theta;

    mat.data[2][0] = axis.data[Z] * axis.data[X] * one_minus_cos - axis.data[Y] * sin_theta;
    mat.data[2][1] = axis.data[Z] * axis.data[Y] * one_minus_cos + axis.data[X] * sin_theta;
    mat.data[2][2] = cos_theta + axis.data[Z] * axis.data[Z] * one_minus_cos;

    return mat;
}

t_mat4	mat4_align_z_axis(t_vec4 v_normal)
{
    t_vec4	z_axis = vec4(0, 0, 1, 0);
    t_vec4	axis = vec4h_cross_product(z_axis, v_normal);
    float	angle = acos(vec4_dot_product(z_axis, v_normal));
    return mat4_rotation(axis, angle);
}

t_object	plane(t_vec4 p_point, t_vec4 v_normal)
{
    t_object	p;
    t_mat4		rotation_matrix;

    p = plane_default();
    rotation_matrix = mat4_align_z_axis(v_normal);
    add_transform(&p, rotation_matrix);
    add_transform(&p, mat4_translation(p_point.data[X], p_point.data[Y], p_point.data[Z]));
    p.u_object.plane.p_point = p_point;
    p.u_object.plane.v_normal = v_normal;
    return (p);
}
*/

t_object	plane(t_vec4 p_point, t_vec4 v_normal)
{
    t_object	object;
    float		theta_x;
    float		theta_y;
    t_mat4		rotation_x;
    t_mat4		rotation_y;
    t_mat4		rotation;

    object = plane_default();

    // Modify the plane's point and normal
    object.u_object.plane.p_point = p_point;
    object.u_object.plane.v_normal = v_normal;

    // Calculate the rotation angles
    theta_y = atan2f(v_normal.data[X], v_normal.data[Y]);
    theta_x = -asinf(v_normal.data[Z]);

    // Create rotation matrices
    rotation_y = mat4_rotation_y(theta_y);
    rotation_x = mat4_rotation_x(theta_x);

    // Combine the rotations: rotation = rotation_y * rotation_x
    rotation = mat4_mat4_mul(rotation_y, rotation_x);

    // Apply the combined rotation and translation to the object's transform
    object.transform = mat4_mat4_mul(rotation, mat4_translation(p_point.data[X], p_point.data[Z], p_point.data[Y]));

    // Calculate the inverse of the transform matrix
    object.transform_inverse = mat4_inv(object.transform);

    return object;
}
