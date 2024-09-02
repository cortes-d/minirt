/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:23:35 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/20 15:14:00 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	clamp(float input, float max_value)
{
	if (input > max_value)
		return (max_value);
	return (input);
}
