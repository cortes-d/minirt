/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:49:52 by achappui          #+#    #+#             */
/*   Updated: 2024/08/08 09:57:10 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_vec4	reflect(t_vec4 in, t_vec4 normal)
{
	return (vec4_sub(in, vec4_mul(normal, 2 * vec4_dot_product(in, normal))));
}
