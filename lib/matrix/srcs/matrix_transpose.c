#include "matrix.h"

// @return new matrix (result of transpose(m))
// * @see https://mathinsight.org/matrix_transpose
// ! @throws MALLOC_EXCEPTION
t_matrix *transpose_s(t_matrix m){
  t_matrix *m_;
  if (m.cols <= 0 || m.rows <= 0)
    THROW(ILLEGAL_ARGUMENT_EXCEPTION, "invalid matrix in transpose s");
  m_ = new_matrix(m.cols, m.rows);
  for (int i = 0; i < m.cols; i++)
     for(int j = 0; j < m.rows; j++)
        m_->data[i][j] = m.data[j][i];
  
  return m_;
}

/*
  [1,2,6]
  [3,4,5]
  becomes this 
  [3,1]
  [4,2]
  [5,6]
*/
// * @see https://mathinsight.org/matrix_transpose
void transpose(t_matrix *this){
  double **arr;
  int temp;

  if(this == NULL)
    THROW(NULL_POINTER_EXCEPTION,"NULL pointer int matrix transpose");
  arr = (double **)rmalloc(this->cols * sizeof(double *));
  for (int i = 0; i < this->cols; i++)
  {
    arr[i] = rmalloc (this->rows * sizeof(double));
    for(int j = 0; j < this->rows; j++)
      arr[i][j] = this->data[j][i];
  }
  this->free(this);
  this->data = arr;
  temp = this->cols;
  this->cols = this->rows;
  this->rows = temp;
  
}