/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:48:04 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/13 14:02:16 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_scene_data(t_scene_data *scene_data)
{
	ft_lstclear(scene_data->objects, &free);
	ft_lstclear(scene_data->light, &free);
	ft_lstclear(scene_data->ambient_light, &free);
	ft_lstclear(scene_data->camera, &free);
}
