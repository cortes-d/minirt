/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_cross_pressed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:20:56 by achappui          #+#    #+#             */
/*   Updated: 2024/08/22 17:04:29 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int	hook_cross_pressed(void *args)
{
	(void)args;
	exit_minirt();
	return (0);
}