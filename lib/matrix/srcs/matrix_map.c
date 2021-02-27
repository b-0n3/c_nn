#include "matrix.h"

void matrix_map(t_matrix *this, double (*m)(double var) )
{
	if (this == NULL || m == NULL)
		RAISE(NULL_POINTER_EXCEPTION);
	for (int  i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			this->data[i][j] = m(this->data[i][j]);
}


void matrix_map_i
	(t_matrix *this,double (*m)(double var, int row_index, int col_index))
{
	if (this == NULL || m == NULL)
		RAISE(NULL_POINTER_EXCEPTION);
	for (int  i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			this->data[i][j] = m(this->data[i][j], i, j);
}
