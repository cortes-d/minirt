/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equalf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:38:47 by achappui          #+#    #+#             */
/*   Updated: 2024/07/31 15:38:47 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libla.h"

float    vec4_magnitude(t_vec4 v)
{
      return(sqrt(v.data[X] * v.data[X] + \
                  v.data[Y] * v.data[Y] + \
                  v.data[Z] * v.data[Z] + \
                  v.data[W] * v.data[W]));
}
