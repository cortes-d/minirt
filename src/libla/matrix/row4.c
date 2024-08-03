/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian-cortes <damian-cortes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:53:52 by damian-cort       #+#    #+#             */
/*   Updated: 2024/08/03 11:54:42 by damian-cort      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libla.h"

t_row4	row4(double a, double b, double c, double d)
{
	t_row4	row;

	row.data[0] = a;
	row.data[1] = b;
	row.data[2] = c;
	row.data[3] = d;
	return (row);
}
