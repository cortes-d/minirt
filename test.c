#include <stdio.h>
#include "libla.h"

int    main(void)
{
	t_mat4    m;
	t_mat3    submatrix;

	// row 0
	m.data[0][0] = 1.0f;
	m.data[0][1] = 2.0f;
	m.data[0][2] = 6.0f;
	m.data[0][3] = 4.0f;
	// row 1
	m.data[1][0] = -5.0f;
	m.data[1][1] = 8.0f;
	m.data[1][2] = -4.0f;
	m.data[1][3] = 3.0f;
	// row 2
	m.data[2][0] = 2.0f;
	m.data[2][1] = 6.0f;
	m.data[2][2] = 4.0f;
	m.data[2][3] = 1.0f;
	// row 3
	m.data[3][0] = 4.0f;
	m.data[3][1] = 8.0f;
	m.data[3][2] = 1.0f;
	m.data[3][3] = 1.0f;

	printf("original matrix :\n");
	mat_print((void *)&m, 4);
	
	printf("\n");
	
	printf("submatrix (1,2) :\n");
	submatrix = mat4_submatrix(&m, 1, 2);
	mat_print((void *)&submatrix, 3);

	return (0);
}
