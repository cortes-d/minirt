/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:32:27 by dcortes           #+#    #+#             */
/*   Updated: 2024/09/02 10:12:40 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_light_ambient	light_ambient(float ratio, t_vec3 color)
{
	t_light_ambient	new_light_ambient;

	new_light_ambient.ratio = ratio;
	new_light_ambient.color = color;
	return (new_light_ambient);
}
