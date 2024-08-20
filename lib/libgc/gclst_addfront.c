/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gclst_addfront.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:21:41 by achappui          #+#    #+#             */
/*   Updated: 2024/08/20 13:46:48 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	gclst_addfront(t_gclst **lst, t_gclst *node)
{
	node->next = *lst;
	*lst = node;
}
