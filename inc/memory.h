/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 08:59:51 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/21 15:38:20 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

// =============================================================================
// Section : Includes
// =============================================================================

# include "libgc.h"
# include "graphic.h"
# include "libgc.h"
# include "mlx.h"
# include <stdlib.h>
# include "scene.h"
# include "minirt.h"

// =============================================================================
// Section : Type Definitions
// =============================================================================

typedef struct s_mlx_data
{
	void	*ptr;
	void	*win;
	t_image	img;
}	t_mlx_data;

// =============================================================================
// Section : Functions
// =============================================================================

void		exit_error(char *msg);
void		exit_minirt(void);
void		mlx_data_init(void);
t_mlx_data	**mlx_data_get(void);
void		mlx_data_free(void);

#endif