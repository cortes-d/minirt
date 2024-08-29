/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_default.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:33:52 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/29 08:33:52 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_camera	camera_default(void)
{
	t_camera	camera;
	t_vec4		p_origin;
	t_vec4		v_orientation;
	float		h_fov;

	p_origin = point(0, 0, -5);
	v_orientation = vector(0, 0, 1);
	h_fov = 70;
	camera.p_origin = p_origin;
	camera.v_orientation = v_orientation;
	camera.h_fov = ft_deg_to_rad(h_fov);
	camera.view_transform = view_transform(p_origin, \
	v_orientation, vector(UP_VECTOR_X, UP_VECTOR_Y, UP_VECTOR_Z));
	camera_computation(&camera);
	return (camera);
}
