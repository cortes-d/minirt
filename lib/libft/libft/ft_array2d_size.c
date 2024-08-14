/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array2d_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:20:18 by achappui          #+#    #+#             */
/*   Updated: 2024/08/13 15:22:55 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_array2d_size(const void **array2d)
{
	unsigned int	i;

	i = 0;
	while (array2d[i] != NULL)
		i++;
	return (i);
}
