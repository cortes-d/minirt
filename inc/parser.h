/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:28:15 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/16 16:48:35 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

// =============================================================================
// Section : Includes
// =============================================================================

# include "libft.h"
# include "libla.h"
# include "scene.h"
# include "errno.h"

// =============================================================================
// Section : Constants and Macros
// =============================================================================

# define ERROR	-1
# define MAX_FLOAT_DIGIT 7

// =============================================================================
// Section : Type Definitions
// =============================================================================

// ·············································································
// Sub-section : Forward declarations
// ·············································································

typedef struct s_scene_data	t_scene_data;

// --- Scene ---
typedef struct s_scene_data
{
	t_list		*objects;
	t_list		*lights;
	t_list		*cameras;
	t_list		*ambient_lights;
}	t_scene_data;

// =============================================================================
// Section : Functions
// =============================================================================

// --- Check ---
int				check_main_arguments(char **argv, int argc);

// --- Highest check ---
int				check_light_ambient_tokens(char **tokens);
int				check_camera_tokens(char **tokens);
int				check_cylinder_tokens(char **tokens);
int				check_plane_tokens(char **tokens);
int				check_light_point_tokens(char **tokens);
int				check_sphere_tokens(char **tokens);

// --- Middle check ---
int				check_color_token(const char *str);
int				check_float_token(const char *str);
int				check_vec3_token(const char *str);

// --- Lowest check ---
int				check_float(const char **str);
int				check_uchar(const char **str);

// --- Creation ---
int				create_light_ambient(char **tokens, t_list **ambient_lights);
int				create_camera(char **tokens, t_list **cameras);
int				create_cylinder(char **tokens, t_list **objects);
int				create_plane(char **tokens, t_list **objects);
int				create_light_point(char **tokens, t_list **lights);
int				create_sphere(char **tokens, t_list **objects);

// --- Extraction ---
t_vec3			extract_color(const char *str);
float			extract_float(const char *str);
t_vec3			extract_vec3(const char *str);

// --- Utility ---
const char		*elem_at_index_n(const char *str, unsigned int n);

// --- Parsing logic ---
int				parse_line(t_scene_data *scene_data, const char *line);
int				parse_scene(char *file_name, t_scene *scene);
int				parsing_loop(t_scene_data *scene_data, int fd);
int				scene_data_to_scene(t_scene_data *scene_data, t_scene *scene);
int				type_interpreter(char **tokens, t_scene_data *scene_data);

// --- Utility ---
t_scene_data	scene_data_empty(void);
void			scene_data_free(t_scene_data *scene_data);

#endif
