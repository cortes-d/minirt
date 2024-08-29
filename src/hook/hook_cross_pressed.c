/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_cross_pressed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:30:02 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/29 08:30:02 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int	hook_cross_pressed(void *args)
{
	(void)args;
	exit_minirt();
	return (0);
}
