/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_vec3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:11:22 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 11:22:10 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_vec3	str_to_vec3(const char *str)
{
	int		i;
	float	a;
	float	b;
	float	c;
	char	*split;

	split = ft_split(str, ',');
	a = str_to_float(split[0]);
	b = str_to_float(split[1]);
	c = str_to_float(split[2]);
	free(split);
	return (vec3(a, b, c));
}
