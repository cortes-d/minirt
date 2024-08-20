/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gclst_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:41:22 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/20 13:48:01 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	gclst_free(t_gclst *node)
{
	gc_free_dimension(node->content, node->dimension);
	free(node);
}
