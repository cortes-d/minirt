/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:53:38 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/05 16:57:48 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_intersection	intersection(float t, t_object object)
{
	t_intersection	intersection;

	intersection.t = t;
	intersection.object = object;
	return (intersection);
}
