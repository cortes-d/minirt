/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:51:06 by achappui          #+#    #+#             */
/*   Updated: 2024/08/20 14:36:10 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char			*test1;
	char			**test2;
	char			*test3;
	unsigned int	i;

	test1 = (char *)gc_add((void *)malloc(5 * sizeof(char)), 1);
	if (!test1)
	{
		printf("NOT GOOD test 1\n");
		return (1);
	}
	test2 = (char **)malloc((2 + 1) * sizeof(char *));
	if (!test2)
	{
		printf("NOT GOOD ptep test 2\n");
		return (1);
	}
	i = 0;
	test2[2] = NULL;
	while (i < 2)
	{
		test2[i] = (char *)malloc(3 * sizeof(char));
		if (!test2[i])
		{
			printf("NOT GOOD prep test 2\n");
			return (1);
		}
		i++;
	}
	if (gc_add(test2, 2) == NULL)
	{
		printf("NOT GOOD add test 2\n");
		return (1);	
	}
	test3 = (char *)gc_add((void *)malloc(7 * sizeof(char)), 1);
	if (!test3)
	{
		printf("NOT GOOD 3\n");
		return (1);
	}
	gc_display();
	gc_free(test1);
	gc_free(test2);
	gc_free(test3);
	
	return (0);
}