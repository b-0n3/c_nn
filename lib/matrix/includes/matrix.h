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
  void (*add_matrix)(struct s_matrix *this , struct s_matrix m);
  void (*subtract)(struct s_matrix *this, double n);
  void (*subtract_matrix)(struct s_matrix *this,struct s_matrix m);
  void (*multiply)(struct s_matrix *this,double n);
  void (*multiply_matrix)(struct s_matrix *this, struct s_matrix o);
  double *(*to_array)(struct s_matrix *this);
  void (*transpose)(struct s_matrix *this);
  void (*map)(struct s_matrix *this,(*double)(double var) );
  void (*free)(struct s_matrix *this);
}             t_matrix;

t_matrix *new_matrix(int row, int cols);
t_matrix *from_array(double array, int array_size);
t_matrix *from_array_list(t_array_list array);
t_matrix *multiply_matrix_s(t_matrix m1, t_matrix m2);
t_matrix *transpose_s(t_matrix m);

#endif