/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:03:06 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/26 09:23:55 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_object plane(t_vec4 p_point, t_vec4 v_normal) {
    t_object object;
    float theta_x;
    float theta_z;
    t_mat4 rotation_x;
    t_mat4 rotation_z;
    t_mat4 rotation;
    t_mat4 translation;

    object = plane_default();

    // Modify the plane's point and normal
    object.u_object.plane.p_point = p_point;
    object.u_object.plane.v_normal = v_normal;

    // Calculate the rotation angles
    theta_z = atan2f(v_normal.data[X], v_normal.data[Y]);
    theta_x = atan2f(v_normal.data[Z], sqrtf(v_normal.data[X] * v_normal.data[X] + v_normal.data[Y] * v_normal.data[Y]));

    // Create rotation matrices
    rotation_z = mat4_rotation_z(theta_z);
    rotation_x = mat4_rotation_x(theta_x);

    // Combine the rotations: rotation = rotation_x * rotation_z
    rotation = mat4_mat4_mul(rotation_x, rotation_z);

	vec4_print(p_point);

    // Create translation matrix
    translation = mat4_translation(p_point.data[X], p_point.data[Y], p_point.data[Z]);
	mat4_print(translation);

    // Combine the rotation and translation: transform = translation * rotation
    object.transform = mat4_mat4_mul(translation, rotation);
	mat4_print(object.transform);

    // Calculate the inverse of the transform matrix
    object.transform_inverse = mat4_inv(object.transform);

    return object;
}