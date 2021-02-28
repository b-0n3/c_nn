#include "matrix.h"

void matrix_for_each_i(t_matrix *this , void (*f)(double var , int row_idex , int col_index))
{
	if (this == NULL || f == NULL)
		RAISE(NULL_POINTER_EXCEPTION);
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			f(this->data[i][j], i, j);
}

void matrix_for_each(t_matrix *this, void (*f)(double var))
{
	if (this == NULL || f == NULL)
		RAISE(NULL_POINTER_EXCEPTION);
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			f(this->data[i][j]);
}
