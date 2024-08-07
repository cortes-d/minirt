/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:49:52 by achappui          #+#    #+#             */
/*   Updated: 2024/08/07 13:52:44 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_vec4	reflect_vector(t_vec4 in, t_vec4 normal)
{
	return (vec4_sub(in, vec4_mul(normal, 2 * vec4_dot_product(in, normal))));
}