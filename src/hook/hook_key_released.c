/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_released.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:01:59 by achappui          #+#    #+#             */
/*   Updated: 2024/08/22 17:06:17 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "stdio.h"
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