/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:48:07 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 11:21:58 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_vec3	str_to_color(const char *str)
{
	int		i;
	int		a;
	int		b;
	int		c;
	char	*split;

	split = ft_split(str, ',');
	a = ft_atoi(split[0]);
	b = ft_atoi(split[1]);
	c = ft_atoi(split[2]);
	free(split);
	return (color_rgb_i(a, b, c));
}
