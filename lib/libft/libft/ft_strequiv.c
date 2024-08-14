/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequiv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:53:08 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/11 11:54:17 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequiv(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	if (ft_strncmp(s1, s2, ft_strlen(s2)) == 0)
		return (1);
	else
		return (0);
}
