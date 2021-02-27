/*
  @autor b-0n3@1337
*/
#pragma once
#ifndef FT_MATRIX_H
#define FT_MATRIX_H
#include <math.h>

#include "try_catch.h"
#include "array_list.h"
#include "stringbuilder.h"

#ifndef DEFINED
extern jmp_buf * __TRY_CATCH_LIB__raise_env;
extern jmp_buf * __TRY_CATCH_LIB__retry_env;
#endif
// ToDo : add more matrix math functions 
typedef struct s_matrix
{
  double **data;
  int cols;
  int rows;
  void (*put)(struct s_matrix *this, int row_index, int col_index, double value);
  double (*get)(struct s_matrix *this, int row_index , int col_index);
  void (*add)(struct s_matrix *this, double n);
  void (*add_matrix)(struct s_matrix *this , struct s_matrix m);
  void (*subtract)(struct s_matrix *this, double n);
  void (*subtract_matrix)(struct s_matrix *this,struct s_matrix m);
  void (*multiply)(struct s_matrix *this,double n);
  void (*multiply_matrix)(struct s_matrix *this, struct s_matrix o);
  void (*map)(struct s_matrix *this, double (*m)(double var));
  void (*map_i)(struct s_matrix *this,double (*m)(double var, int row_index, int col_index));
  void (*for_each_i)(struct s_matrix *this , void (*f)(double var , int row_idex , int col_index));
  void (*for_each)(struct s_matrix *this, void (*f )(double var));
  void (*transpose)(struct s_matrix *this);
  char *(*to_string)(struct s_matrix *this);
  double *(*to_array)(struct s_matrix *this);
  void (*free)(struct s_matrix *this);
}             t_matrix;

// init 
void init_matrix(t_matrix *matrix, int row, int cols);
t_matrix *new_matrix(int row, int cols);
t_matrix *new_matrix_random_values(int row, int cols);
t_matrix *from_array(double *array, int array_size);
t_matrix *from_array_list(t_array_list array);
t_matrix *multiply_matrix_s(t_matrix m1, t_matrix m2);

// crud 
void matrix_put(t_matrix *this, int row_index, int col_index, double value);
double  matrix_get(t_matrix *this, int row_index , int col_index);

// add 
void matrix_add_n(t_matrix *this, double n);
void add_matrix(t_matrix *this, t_matrix n);

// subtract
void matrix_subtract_n(t_matrix *this , double n);
void subtract_matrix(t_matrix *this , t_matrix m);

// multiply
void matrix_multiply_n(t_matrix *this, double n);
void multiply_matrix(t_matrix *this, t_matrix m);

// transpose 
t_matrix *transpose_s(t_matrix m);
void transpose(t_matrix *this);

//map
void matrix_map(t_matrix *this, double (*m)(double var) );
void matrix_map_i(t_matrix *this,double (*m)(double var, int row_index, int col_index));

// forEach
void matrix_for_each_i(t_matrix *this , void (*f)(double var , int row_idex , int col_index));
void matrix_for_each(t_matrix *this, void (*f)(double var));

// conversion
char *matrix_to_string(t_matrix *this);
double *matrix_to_array(t_matrix *this);

//free 
void free_matrix(t_matrix *this);

double frandom();
#endif