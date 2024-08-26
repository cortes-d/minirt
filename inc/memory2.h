/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 08:59:51 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/26 09:25:35 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY2_H
# define MEMORY2_H

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
# include "parser.h"

// =============================================================================
// Section : Type Definitions
// =============================================================================

typedef struct s_scene_static
{
	t_scene	scene;
	char	*path;
	int		fd;
}	t_scene_static;

typedef struct s_mlx_static
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_image	*mlx_img;
}	t_mlx_static;

// =============================================================================
// Section : Functions
// =============================================================================

void			exit_error(char *msg);
void			exit_minirt(void);
void			mlx_static_free(void);
t_mlx_static	**mlx_static_get(void);
void			mlx_static_init(void);
void			scene_static_free(void);
t_scene_static	**scene_static_get(void);
void			scene_static_init(char *path);

#endif