/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:28:15 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/11 11:30:11 by dcortes          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "libla.h"

// =============================================================================
// Section : Constants and Macros
// =============================================================================

// --- Number of parameters required to create the object ---
# define COUNT_PARAMS_CAMERA 3
# define COUNT_PARAMS_AMBIENT 2
# define COUNT_PARAMS_LIGHT 2
# define COUNT_PARAMS_SPHERE 3
# define COUNT_PARAMS_PLANE 3
# define COUNT_PARAMS_CYLINDER 5

// =============================================================================
// Section : Type Definitions
// =============================================================================

// --- Structure : Token ---
typedef struct s_token
{
	char	*chunk;
}	t_token;

// =============================================================================
// Section : Functions
// =============================================================================

// --- Tokenization ---
t_token		*token(char *chunk);
t_list		*tokenize_line(const char *line);

// --- Object creation from tokens ---
void		object_from_tokens(t_list *tokens);
void		params_from_tokens(t_list *tokens, t_token **params, int count);
void		camera_from_tokens(t_list *tokens);
void		light_from_tokens(t_list *tokens);
void		ambient_from_tokens(t_list *tokens);
void		sphere_from_tokens(t_list *tokens);
void		cylinder_from_tokens(t_list *tokens);
void		plane_from_tokens(t_list *tokens);

// --- Conversion utils ---
float		str_to_float(const char *str);
vec3		str_to_vec3(const char *str);
vec3		str_to_color(const char *str);

#endif
