#include <stdlib.h>
#include "libft.h"

typedef struct s_gc
{
	void	*ptr;
	size_t	dimension;
}	t_gc;


void	*gc_add(void *ptr, size_t dimension)
{
	t_gc	*gc_object;
	t_list	*object;

	if (!ptr)
		return (NULL);
	gc_object = malloc(sizeof(t_gc));
	if (!gc_object)
		return (NULL);
	gc_object->ptr = ptr;
	gc_object->dimension = dimension;
	object = ft_lstnew(gc_object);
	if (!object)
	{
		free(gc_object);
		return (NULL);
	}
	ft_lstadd_back(gc_get(), object);
	return (ptr);
}

static void	gc_free_rec(void *ptr, size_t dimension)
{
	size_t	i;
	void	**dptr;

	if (dimension == 1)
		free(ptr);
	else
	{
		dptr = (void **)ptr;

		i = 0;
		while (dptr[i] != NULL)
		{
			gc_free_rec(dptr[i], dimension - 1);
			i++;
		}
		free(dptr);
	}
}

void	gc_free(void *ptr)
{
	t_list	**gc;
	t_list	*current;
	t_list	*prev;
	t_gc	*gc_object;

	gc = gc_get();
	current = *gc;
	prev = NULL;
	while (current)
	{
		gc_object = (t_gc *)current->content;
		if (gc_object->ptr == ptr)
		{
			gc_free_rec(gc_object->ptr, gc_object->dimension);
			if (prev)
				prev->next = current->next;
			else
				*gc = current->next;

			ft_lstdelone(current, free);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	gc_sweep(void)
{
	t_list	**gc;

	gc = gc_get();
	ft_lstclear(gc, free);
	*gc = NULL;
}
static t_list	**gc_get(void)
{
	static t_list	*gc;
	return (&gc);
}
