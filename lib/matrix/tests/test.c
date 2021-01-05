#include "matrix.h"

t_matrix *matrix;
jmp_buf * __TRY_CATCH_LIB__raise_env = NULL;
jmp_buf * __TRY_CATCH_LIB__retry_env = NULL;

void test_new_matrix()
{
  matrix = new_matrix(2, 2);
  matrix->data[0][0] = 2;
  matrix->data[0][1] = 1;
  matrix->data[1][0] = 0;
  matrix->data[1][1] = 5;
  printf(matrix_to_string(matrix));
  if (matrix == NULL)
    RAISE(NULL_POINTER_EXCEPTION);
}

int main(){
  test_new_matrix();
}