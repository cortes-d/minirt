/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_pair_init.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:26:59 by dcortes           #+#    #+#             */
/*   Updated: 2024/09/02 10:11:43 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_intersection_pair	init_intersection_pair(void)
{
	t_intersection_pair	pair;

	pair.count = 0;
	pair.t[0] = NO_INTERSECTION;
	pair.t[1] = NO_INTERSECTION;
	return (pair);
}
