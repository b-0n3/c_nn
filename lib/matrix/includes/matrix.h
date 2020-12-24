/*
  @autor b-0n3@1337
*/
#ifndef FT_MATRIX_H
#define FT_MATRIX_H
#include <math.h>
#include "array_list.h"
#include "try_catch.h"
typedef struct s_matrix
{
  double **data;
  int cols;
  int rows;
  void (*add)(struct s_matrix *this, double n);
  void (*add_matrix)(struct s)
  void (*sub)(struct s_matrix *this, double n);
}             t_matrix;

t_matrix *new_matrix(int row, int cols);
t_matrix *from_array(double array, int array_size);
t_matrix *from_array_list(t_array_list array);
#endif