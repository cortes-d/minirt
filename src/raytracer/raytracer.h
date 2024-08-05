/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:28:44 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/05 13:31:53 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H
# include "libla.h"

typedef struct s_ray
{
	t_vec4	p_origin;
	t_vec4	v_direction;
}	t_ray;

#endif