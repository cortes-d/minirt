/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_released.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:30:12 by dcortes           #+#    #+#             */
/*   Updated: 2024/09/02 13:49:21 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int	hook_key_released(int key, void *args)
{
	(void)args;
	if (key == KEY_ESC)
	{
		exit_minirt();
		return (0);
	}
	else if (key == KEY_R)
	{
		reload_scene();
		return (0);
	}
	return (0);
}
