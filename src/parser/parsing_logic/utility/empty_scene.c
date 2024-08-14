/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_color_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:48:07 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 14:13:29 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_scene	empty_scene()
{
	t_scene	new_empty_scene;

	new_empty_scene.camera = NULL;
	new_empty_scene.ambient_light = NULL;
	new_empty_scene.light = NULL;
	new_empty_scene.objects = NULL;
	return (new_empty_scene);
}
