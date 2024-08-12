/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_color_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:48:07 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 13:57:37 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int	str_to_color_check(const char *str)
{
	if (str_uchar_check(&str) == ERROR)
		return (ERROR);
	if (*str != ',')
		return (ERROR);
	str++;
	if (str_uchar_check(&str) == ERROR)
		return (ERROR);
	if (*str != ',')
		return (ERROR);
	str++;
	if (str_uchar_check(&str) == ERROR)
		return (ERROR);
	if (*str != '\0')
		return (ERROR);
}
