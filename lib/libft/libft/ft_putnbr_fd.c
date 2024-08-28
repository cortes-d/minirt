/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:34:17 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:34:26 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			tab[11];
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
