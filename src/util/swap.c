/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< Updated upstream:src/util/swap.c
/*   Created: 2024/08/13 14:48:00 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/13 14:50:45 by dcortes          ###   ########.fr       */
=======
/*   Created: 2024/08/11 11:40:02 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 14:56:05 by dcortes          ###   ########.fr       */
>>>>>>> Stashed changes:src/parser/creation/params_from_tokens.c
/*                                                                            */
/* ************************************************************************** */

void	swap(float *a, float *b)
{
	float	tmp;

<<<<<<< Updated upstream:src/util/swap.c
	tmp = *b;
	*b = *a;
	*a = tmp;
=======
	current = tokens->next;
	i = 1;
	while (i < count)
	{
		params[i] = current->content;
		current = current->next;
		i++;
	}
>>>>>>> Stashed changes:src/parser/creation/params_from_tokens.c
}

