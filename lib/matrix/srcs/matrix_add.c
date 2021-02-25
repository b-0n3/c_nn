#include "matrix.h"

// * @see https://www.khanacademy.org/math/precalculus/x9e81a4f98389efdf:matrices/x9e81a4f98389efdf:adding-and-subtracting-matrices/a/adding-and-subtracting-matrices
void matrix_add_n(t_matrix *this, double n)
{
  if (this == NULL || this->data  == NULL)
    RAISE(NULL_POINTER_EXCEPTION);
  for(int i = 0; i< this->rows; i++)
    for(int j = 0; j < this->cols; j++)
      this->data[i][j] += n;
}

// * @see https://www.khanacademy.org/math/precalculus/x9e81a4f98389efdf:matrices/x9e81a4f98389efdf:adding-and-subtracting-matrices/a/adding-and-subtracting-matrices
// ! @throws ILLEGAL_ARGUMENT_EXCEPTION 
void add_matrix(t_matrix *this , t_matrix m)
{
    if (this == NULL || m.data == NULL)
      RAISE(NULL_POINTER_EXCEPTION);
    if (this->rows != m.rows || this->cols != m.cols)
      RAISE(ILLEGAL_ARGUMENT_EXCEPTION);
    for(int i = 0; i < this->rows; i++)
      for (int j = 0; j < this->cols; j++)
        this->data[i][j] += m.data[i][j];
}