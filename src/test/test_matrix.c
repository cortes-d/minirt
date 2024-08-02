/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:19:14 by achappui          #+#    #+#             */
/*   Updated: 2024/08/02 15:22:27 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libla/libla.h"
#include "../libft/libft.h"


int	main()
{
	t_mat4	matrix_a;

	matrix_a.data[0][0] = 3.14F;
	matrix_a.data[0][1] = 7.89F;
	matrix_a.data[0][2] = -5.67F;
	matrix_a.data[0][3] = 2.45F;
	matrix_a.data[1][0] = -1.23F;
	matrix_a.data[1][1] = 4.56F;
	matrix_a.data[1][2] = 8.90F;
	matrix_a.data[1][3] = -7.34F;
	matrix_a.data[2][0] = 6.78F;
	matrix_a.data[2][1] = -9.01F;
	matrix_a.data[2][2] = 3.21F;
	matrix_a.data[2][3] = 5.43F;
	matrix_a.data[3][0] = -4.56F;
	matrix_a.data[3][1] = 2.34F;
	matrix_a.data[3][2] = -8.76F;
	matrix_a.data[3][3] = 1.98F;

	t_mat4	matrix_b;

	matrix_b.data[0][0] = -2.54F;
	matrix_b.data[0][1] = 5.68F;
	matrix_b.data[0][2] = 9.87F;
	matrix_b.data[0][3] = -3.45F;
	matrix_b.data[1][0] = 6.23F;
	matrix_b.data[1][1] = -7.89F;
	matrix_b.data[1][2] = 4.56F;
	matrix_b.data[1][3] = 2.78F;
	matrix_b.data[2][0] = -1.12F;
	matrix_b.data[2][1] = 3.45F;
	matrix_b.data[2][2] = -6.78F;
	matrix_b.data[2][3] = 7.09F;
	matrix_b.data[3][0] = 5.67F;
	matrix_b.data[3][1] = -8.90F;
	matrix_b.data[3][2] = 2.34F;
	matrix_b.data[3][3] = -4.56F;

	t_mat4	matrix_a_transpo;

    matrix_a_transpo.data[0][0] = 3.14F;
    matrix_a_transpo.data[0][1] = -1.23F;
    matrix_a_transpo.data[0][2] = 6.78F;
    matrix_a_transpo.data[0][3] = -4.56F;
    matrix_a_transpo.data[1][0] = 7.89F;
    matrix_a_transpo.data[1][1] = 4.56F;
    matrix_a_transpo.data[1][2] = -9.01F;
    matrix_a_transpo.data[1][3] = 2.34F;
    matrix_a_transpo.data[2][0] = -5.67F;
    matrix_a_transpo.data[2][1] = 8.90F;
    matrix_a_transpo.data[2][2] = 3.21F;
    matrix_a_transpo.data[2][3] = -8.76F;
    matrix_a_transpo.data[3][0] = 2.45F;
    matrix_a_transpo.data[3][1] = -7.34F;
    matrix_a_transpo.data[3][2] = 5.43F;
    matrix_a_transpo.data[3][3] = 1.98F;

    t_mat4 matrix_a_inverse;

    matrix_a_inverse.data[0][0] = -0.01107327971F;
    matrix_a_inverse.data[0][1] = -0.7336275148F;
    matrix_a_inverse.data[0][2] = -0.6329396558F;
    matrix_a_inverse.data[0][3] = -0.9701182284F;
    matrix_a_inverse.data[1][0] = 0.1333747446F;
    matrix_a_inverse.data[1][1] = 0.4742507263F;
    matrix_a_inverse.data[1][2] = 0.385203472F;
    matrix_a_inverse.data[1][3] = 0.5366552291F;
    matrix_a_inverse.data[2][0] = 0.08339546588F;
    matrix_a_inverse.data[2][1] = 0.7881700078F;
    matrix_a_inverse.data[2][2] = 0.703143999F;
    matrix_a_inverse.data[2][3] = 0.89029144F;
    matrix_a_inverse.data[3][0] = 0.1858349613F;
    matrix_a_inverse.data[3][1] = 1.237010657F;
    matrix_a_inverse.data[3][2] = 1.197959836F;
    matrix_a_inverse.data[3][3] = 1.575475079F;

    t_mat4 matrix_a_times_matrix_b;

    matrix_a_times_matrix_b.data[0][0] = 61.421F;
    matrix_a_times_matrix_b.data[0][1] = -85.7834F;
    matrix_a_times_matrix_b.data[0][2] = 111.1458F;
    matrix_a_times_matrix_b.data[0][3] = -40.2711F;
    matrix_a_times_matrix_b.data[1][0] = -20.0528F;
    matrix_a_times_matrix_b.data[1][1] = 53.0662F;
    matrix_a_times_matrix_b.data[1][2] = -68.8641F;
    matrix_a_times_matrix_b.data[1][3] = 113.4917F;
    matrix_a_times_matrix_b.data[2][0] = -46.1606F;
    matrix_a_times_matrix_b.data[2][1] = 72.3468F;
    matrix_a_times_matrix_b.data[2][2] = 16.7754F;
    matrix_a_times_matrix_b.data[2][3] = -50.4407F;
    matrix_a_times_matrix_b.data[3][0] = 47.1984F;
    matrix_a_times_matrix_b.data[3][1] = -92.2074F;
    matrix_a_times_matrix_b.data[3][2] = 29.6892F;
    matrix_a_times_matrix_b.data[3][3] = -48.9F;

	double	matrix_a_det;

	matrix_a_det = 582.3434582399991F;

	t_vec4	vec_test;

	vec_test.data[X] = 7.15;
	vec_test.data[Y] = 8.13;
	vec_test.data[Z] = 9.52;
	vec_test.data[W] = 1.45;

	t_vec4	vec_mul_result;

	vec_mul_result.data[X] = 36.1708;
	vec_mul_result.data[Y] = 102.3633;
	vec_mul_result.data[Z] = 13.6584;
	vec_mul_result.data[W] = -94.104;

	t_mat4	test_transpo;
	t_mat4	test_inversion;
	double	test_det;
	t_mat4	test_matrix_multiplication;
	t_vec4	test_vector_multiplication;

	test_det = mat4_det(&matrix_a);
	printf("%.8F\n", test_det);
	if (equalf(test_det, matrix_a_det))
		printf("det: OK\n");
	else
		printf("det: KO\n");
	test_transpo = mat4_transpose(&matrix_a);
	mat_print(&test_transpo, 4);
	if (mat4_equal(&matrix_a_transpo, &test_transpo))
		printf("Transpo: OK\n");
	else
		printf("Transpo: KO\n");
	test_inversion = mat4_inv(&matrix_a);
	mat_print(&test_inversion, 4);
	if (mat4_equal(&matrix_a_inverse, &test_inversion))
		printf("inversion: OK\n");
	else
		printf("inversion: KO\n");
	test_matrix_multiplication = mat4_mat4_mul(&matrix_a, &matrix_b);
	mat_print(&test_matrix_multiplication, 4);
	if (mat4_equal(&matrix_a_times_matrix_b, &test_matrix_multiplication))
		printf("matrix_multiplication: OK\n");
	else
		printf("matrix_multiplication: KO\n");
	test_vector_multiplication = mat4_vec4_mul(&matrix_a, &vec_test);
	vec_print(&test_vector_multiplication, 4);
	if (vec4_equal(&vec_mul_result, &test_vector_multiplication))
		printf("vector_multiplication: OK\n");
	else
		printf("vector_multiplication: KO\n");
	return (0);
}