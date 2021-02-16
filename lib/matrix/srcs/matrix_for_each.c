#include "matrix.h"

void matrix_for_each_i(t_matrix *this , void (*f)(double var , int row_idex , int col_index))
{
  for (int i = 0; i < this->rows; i++)
    for (int j = 0; i < this->cols; j++)
        f(this->data[i][j], i, j);
}

void matrix_for_each(t_matrix *this, void (*f)(double var))
{

}
