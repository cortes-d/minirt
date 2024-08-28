/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:34:49 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:34:55 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long long		tab;
	unsigned short	i;

	tab = n;
	i = 1;
	while ((tab >= 10 || tab < 0) && i++)
		tab /= 10;
	tab = (long long)malloc((i + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	((char *)tab)[i] = '\0';
	((char *)tab)[0] = '+';
	if (n < 0)
		((char *)tab)[0] = '-';
	while (n < 0)
	{
		((char *)tab)[--i] = -(n % 10) + 48;
		n /= 10;
	}
	while (n > 0 || (i == 1 && ((char *)tab)[0] != '-'))
	{
		((char *)tab)[--i] = n % 10 + 48;
		n /= 10;
	}
	return ((char *)tab);
}
