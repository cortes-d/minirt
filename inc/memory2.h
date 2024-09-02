/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:57:40 by dcortes           #+#    #+#             */
/*   Updated: 2024/09/02 13:21:47 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY2_H
# define MEMORY2_H

// =============================================================================
// Section : Includes
// =============================================================================

# include "scene.h"
# include "graphic.h"
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

void			exit_error(char *msg, char *function_name);
void			exit_minirt(void);
void			mlx_static_free(void);
t_mlx_static	**mlx_static_get(void);
void			mlx_static_init(void);
void			scene_static_free(void);
t_scene_static	**scene_static_get(void);
void			scene_static_init(char *path);

#endif