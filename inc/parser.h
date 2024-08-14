/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:28:15 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/14 09:21:22 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "libla.h"

// =============================================================================
// Section : Constants and Macros
// =============================================================================

# define ERROR	-1
# define MAX_FLOAT_DIGIT	7

// =============================================================================
// Section : Type Definitions
// =============================================================================

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
int	check_main_arguments(char **argv, int argc);

// --- Highest check ---
int check_ambient_light_tokens(char **tokens);
int check_camera_tokens(char **tokens);
int check_cylinder_tokens(char **tokens);
int check_plane_tokens(char **tokens);
int check_point_light_tokens(char **tokens);
int check_sphere_tokens(char **tokens);

// --- Middle check ---
int check_color_token(const char *str);
int check_float_token(const char *str);
int check_vec3_token(const char *str);

// --- Lowest check ---
int check_float(const char **str);
int check_uchar(const char **str);

// --- Creation ---
int create_ambient_light(char **tokens, t_ambient_light **ambient_lights);
int create_camera(char **tokens, t_camera **cameras);
int create_cylinder(char **tokens, t_list **objects);
int create_plane(char **tokens, t_list **objects);
int create_point_light(char **tokens, t_list **lights);
int create_sphere(char **tokens, t_list **objects);

// --- Extraction ---
t_vec3  extract_color(const char *str);
float   extract_float(const char *str);
t_vec3  extract_vec3(const char *str);

// --- Utility ---
const char  *elem_at_index_n(const char *str, unsigned int n);

// --- Parsing logic ---
int parse_line(t_scene_data *scene_data, const char *line);
int parse_scene(char *file_name, t_scene *scene);
int parsing_loop(t_scene_data *scene_data, int fd);
int scene_data_to_scene(t_scene_data *scene_data, t_scene *scene);
int type_interpreter(char **tokens, t_scene_data *scene_data);

// --- Utility ---
t_scene_data    empty_scene_data();
t_scene 		empty_scene();
void			free_array2d(void **array_2d);
void    		free_scene_data(t_scene_data *scene_data);
void    		free_scene(t_scene *scene);

#endif
