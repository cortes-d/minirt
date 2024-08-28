/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_main_arguments.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:48:07 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/28 11:18:34 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_main_arguments(char **argv, int argc)
{
	unsigned int	i;

	if (argc != 2)
		exit_error("you must enter only 1 map", "check_main_arguments()");
	i = 0;
	while (argv[1][i] != '\0')
		i++;
	if (i < 3)
		exit_error("wrong file extension(.rt expected)", "check_main_arguments()");
	if (!(argv[1][i - 3] == '.' && argv[1][i - 2] == 'r' && argv[1][i - 1] == 't'))
		exit_error("wrong file extension(.rt expected)", "check_main_arguments()");
}
