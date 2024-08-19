/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:41:25 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/19 12:49:04 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

void	*gc_add(void *ptr)
{
	t_list	*object;

	object = ft_lstnew(ptr);
	ft_lstadd_back(gc_get(), object);
	return (ptr);
}
