#include "matrix.h"

// ! @throws EXCEPTION
void matrix_put
  (t_matrix *this, int row_index, int col_index, double value)
{
    if (this == NULL)
      RAISE(NULL_POINTER_EXCEPTION);
    if(row_index > this->rows || col_index > this->cols)
      RAISE(INDEX_OUT_OF_BOUNDS_EXCEPTION);
    this->data[row_index][col_index] = value;
}

// ! @throws EXCEPTIION
double  matrix_get
  (t_matrix *this, int row_index, int col_index)
{
  if (this == NULL)
    RAISE(NULL_POINTER_EXCEPTION);
  if (row_index > this->rows || this->cols < col_index)
    RAISE(INDEX_OUT_OF_BOUNDS_EXCEPTION);
  return  this->data[row_index][col_index];
}
