/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_vec3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:11:22 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 12:07:26 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_vec3	str_to_vec3(const char *str)
{
	return (vec3(\
			str_to_float(elem_at_index_n(str, 0)), \
			str_to_float(elem_at_index_n(str, 1)), \
			str_to_float(elem_at_index_n(str, 2))));
}
