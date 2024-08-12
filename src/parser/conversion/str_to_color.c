/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:48:07 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 12:07:23 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_vec3	str_to_color(const char *str)
{
	return (color_rgb_i(\
			ft_atoi(elem_at_index_n(str, 0)), \
			ft_atoi(elem_at_index_n(str, 1)), \
			ft_atoi(elem_at_index_n(str, 2))));
}
