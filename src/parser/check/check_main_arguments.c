/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_main_arguments.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:48:07 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/13 15:06:14 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_main_arguments(char **argv, int argc)
{
	unsigned int	i;

	if (argc != 2)
		return (ERROR);
	i = 0;
	while (argv[1][i] != '\0')
		i++;
	if (i < 3)
		return (ERROR);
	if (!(argv[1][i - 3] == '.' && argv[1][i - 2] == 'r' && argv[1][i - 1] == 't'))
		return (ERROR);
	return (0);
}
