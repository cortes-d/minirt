/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:23:35 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/12 14:24:52 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_clamp(float input, float max_value)
{
	if (input > max_value)
	{
		return (max_value);
	}
	return (input);
}
