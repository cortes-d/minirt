/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_data_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:48:04 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/21 14:14:04 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	scene_data_free(t_scene_data *scene_data)
{
	ft_lstclear_plus(&scene_data->objects, &gc_free, &gc_free);
	ft_lstclear_plus(&scene_data->lights, &gc_free, &gc_free);
	ft_lstclear_plus(&scene_data->ambient_lights, &gc_free, &gc_free);
	ft_lstclear_plus(&scene_data->cameras, &gc_free, &gc_free);
}
