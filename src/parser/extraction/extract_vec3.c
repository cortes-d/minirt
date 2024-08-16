/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_vec3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:11:22 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/16 16:52:10 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_vec3	extract_vec3(const char *str)
{
	return (vec3(\
			ft_strtof(elem_at_index_n(str, 0), NULL), \
			ft_strtof(elem_at_index_n(str, 1), NULL), \
			ft_strtof(elem_at_index_n(str, 2), NULL)));
}
