/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_vec3_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:11:22 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 13:57:46 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int	str_to_vec3_check(const char *str)
{
	if (str_float_check(&str) == ERROR)
		return (ERROR);
	if (*str != ',')
		return (ERROR);
	str++;
	if (str_float_check(&str) == ERROR)
		return (ERROR);
	if (*str != ',')
		return (ERROR);
	str++;
	if (str_float_check(&str) == ERROR)
		return (ERROR);
	if (*str != '\0')
		return (ERROR);
}
