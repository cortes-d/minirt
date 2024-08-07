/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:27:03 by achappui          #+#    #+#             */
/*   Updated: 2024/08/02 16:13:09 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	tab[11];
	unsigned short	i;

	i = sizeof(tab);
	if (n < 0)
	{
		while (n < 0)
		{
			tab[--i] = -(n % 10) + 48;
			n /= 10;
		}
		tab[--i] = '-';
	}
	while (n > 0 || i == sizeof(tab))
	{
		tab[--i] = n % 10 + 48;
		n /= 10;
	}
	write(fd, tab + i, sizeof(tab) - i);
}
