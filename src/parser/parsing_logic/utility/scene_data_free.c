/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_data_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:48:04 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/16 16:52:45 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	scene_data_free(t_scene_data *scene_data)
{
	ft_lstclear(&scene_data->objects, &free);
	ft_lstclear(&scene_data->lights, &free);
	ft_lstclear(&scene_data->ambient_lights, &free);
	ft_lstclear(&scene_data->cameras, &free);
}
