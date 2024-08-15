/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libla.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:05:00 by achappui          #+#    #+#             */
/*   Updated: 2024/08/15 09:10:43 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_LIBLA_H
# define TEST_LIBLA_H

// =============================================================================
// Section : Includes
// =============================================================================
# include "libft.h"
# include "libla.h"

// =============================================================================
// Section : Constants and Macros
// =============================================================================

// =============================================================================
// Section : Type Definitions
// =============================================================================

// =============================================================================
// Section : Functions
// =============================================================================

int	test_matrix();
int	test_vector();

// ·············································································
// Sub-section : Vector
// ·············································································

void	test_vec4_add();
void	test_vec4_cross_product();
void	test_vec4_div();
void	test_vec4_mul();
void	test_vec4_sub();
void	test_vec4_dot_product();
void	test_vec4_equal();
void	test_vec4_inv();
void	test_vec4_magnitude();
void	test_vec4_normalize();
void	test_vec3_equal();
void	test_vec3_sub();
void	test_vec3_add();
void	test_vec3_mul();
void	test_vec3_hadamard_product();

// ·············································································
// Sub-section : Matrix
// ·············································································

void	test_mat_determinant(void);
void	test_mat_identity(void);
void	test_mat_inversion(void);
void	test_mat_multiplication(void);
void	test_mat_transposition(void);
void	test_mat_submatrix(void);

#endif