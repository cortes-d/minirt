/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:41:56 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/20 14:15:31 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H

// =============================================================================
// Section : Includes
// =============================================================================

# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

// =============================================================================
// Section : Type Definitions
// =============================================================================

// ·············································································
// Sub-section : Structure t_gc
// ·············································································

typedef struct s_gclst
{
	void			*content;
	unsigned short	dimension;
	struct s_gclst	*next;
}	t_gclst;

// =============================================================================
// Section : Functions
// =============================================================================

void	gclst_addfront(t_gclst **lst, t_gclst *node);
void	gclst_clear(t_gclst **lst);
t_gclst	*gclst_new(void *content, unsigned short dimension);
t_gclst	**gc_get(void);
void	gclst_free(t_gclst *node);
t_gclst	**gc_search_node(t_gclst **lst, void *content);
void	gc_free_dimension(void *ptr, unsigned short dimension);

#endif
