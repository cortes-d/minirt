/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:28:15 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/21 15:12:11 by achappui         ###   ########.fr       */
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
# include "memory.h"

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
void				check_main_arguments(char **argv, int argc);

// --- Highest check ---
void				check_light_ambient_tokens(char **tokens);
void				check_camera_tokens(char **tokens);
void				check_cylinder_tokens(char **tokens);
void				check_plane_tokens(char **tokens);
void				check_light_point_tokens(char **tokens);
void				check_sphere_tokens(char **tokens);

// --- Middle check ---
void				check_color_token(const char *str);
void				check_float_token(const char *str);
void				check_vec3_token(const char *str);

// --- Lowest check ---
void				check_float(const char **str);
void				check_uchar(const char **str);

// --- Creation ---
void				create_light_ambient(char **tokens, t_list **ambient_lights);
void				create_camera(char **tokens, t_list **cameras);
void				create_cylinder(char **tokens, t_list **objects);
void				create_plane(char **tokens, t_list **objects);
void				create_light_point(char **tokens, t_list **lights);
void				create_sphere(char **tokens, t_list **objects);

// --- Extraction ---
t_vec3			extract_color(const char *str);
float			extract_float(const char *str);
t_vec3			extract_vec3(const char *str);

// --- Utility ---
const char		*elem_at_index_n(const char *str, unsigned int n);

// --- Parsing logic ---
void				parse_line(t_scene_data *scene_data, const char *line);
void				parse_scene(char *file_name, t_scene *scene);
void				parsing_loop(t_scene_data *scene_data, int fd);
void				scene_data_to_scene(t_scene_data *scene_data, t_scene *scene);
void				type_interpreter(char **tokens, t_scene_data *scene_data);

// --- Utility ---
t_scene_data	scene_data_empty(void);
void			scene_data_free(t_scene_data *scene_data);

#endif
