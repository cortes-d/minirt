/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_within_range.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:28:55 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 13:31:16 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	int_within_range(int x, \
	int min_inclusive, int max_inclusive)
{
	return (x >= min_inclusive && x <= max_inclusive);
}
