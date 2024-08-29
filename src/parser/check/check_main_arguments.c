/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_main_arguments.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:49:32 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/29 08:49:43 by dcortes          ###   ########.ch       */
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
		exit_error("wrong file extension(.rt expected)", \
			"check_main_arguments()");
	if (!(argv[1][i - 3] == '.' && \
		argv[1][i - 2] == 'r' && argv[1][i - 1] == 't'))
		exit_error("wrong file extension(.rt expected)", \
			"check_main_arguments()");
}
