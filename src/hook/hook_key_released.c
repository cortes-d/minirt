/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_released.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:30:12 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/29 08:30:12 by dcortes          ###   ########.ch       */
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
