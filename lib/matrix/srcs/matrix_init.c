#include "matrix.h"


extern jmp_buf * __TRY_CATCH_LIB__raise_env;
// used by macros for RETRY
extern jmp_buf * __TRY_CATCH_LIB__retry_env;

 // ! @see lib/matrix/includes/matrix.h
// @return new matrix 
// ! @throws ILLEGAL_ARGUMENT_EXCEPTION if row < 1 || cols < 1
// ! @throws MALLOC_EXCEPTION
t_matrix *new_matrix(int row, int cols){
    if (row < 1 || cols < 1)
        RAISE(ILLEGAL_ARGUMENT_EXCEPTION);
    t_matrix *matrix =(t_matrix *) rmalloc(sizeof(t_matrix));
    matrix->rows = row;
    matrix->cols = cols;
    matrix->data = rmalloc( matrix->rows * sizeof(double *));
    for (int i =0;i < matrix->rows ; i++)
        matrix->data[i] = rmalloc(matrix->cols * sizeof(double));
    matrix->put = &matrix_put;
    matrix->get = &matrix_get;
    matrix->add = &matrix_add_n;
    matrix->add_matrix = &add_matrix;
    matrix->subtract = &matrix_subtract_n;
    matrix->subtract_matrix = &subtract_matrix;
    matrix->multiply = &matrix_multiply_n;
    matrix->multiply_matrix = &multiply_matrix;
    matrix->map = &matrix_map;
    matrix->map_i = &matrix_map_i;
    matrix->for_each_i = &matrix_for_each_i; 
    matrix->for_each = &matrix_for_each;
    matrix->transpose = &transpose;
    matrix->to_string  = &matrix_to_string;
    matrix->to_array = &matrix_to_array;
    matrix->free = &free_matrix;

}
//@retrun new matrix with random values between -1 and 1
t_matrix *new_matrix_random_values(int row, int cols){
  t_matrix *matrix;
  matrix = new_matrix(row, cols);
  for(int i = 0; i < matrix->rows; i++)
    for(int j = 0; j < matrix->cols; j++)
      matrix->put(matrix , i , j, frandom());
}

// @param array :data
// @param array_size : array size in bytes
// *  call new_matrix with array_size cols and 1 row 
// * and then copy all array values into the new matrix.data
// @return new matrix 
// ! @throws ILLEGAL_ARGUMENT_EXCEPTION if array == NULL || array_size <=0
// ! @throws MALLOC_EXCEPTION
t_matrix *from_array(double *array, int array_size){
  t_matrix *matrix;

  if (array == NULL)
    RAISE(NULL_POINTER_EXCEPTION);
  matrix = new_matrix(1,array_size);
  for (int i = 0; i < array_size; i++)
    matrix->put(matrix, 0, i, array[i]);
  return matrix;
}

// ! @see  /lib/arraylist/includes/array_list.h 
//  @param  array : arrayList contains list of data
//  array length is stored in array.index 
// *just allocate a new matrix with array.index cols and 1 row 
// * and then copy array data into the new matrix.data
// @return new matrix
// ! @throws NULL_POINTER_EXCEPTION if array == NULL
// ! @throws ILLEGAL_ARGUMENT_EXCEPTION if  array.index <= 0
// ! @throws MALLOC_EXCEPTION
t_matrix *from_array_list(t_array_list array){
    t_matrix *matrix;

    if (array.arr == NULL)
      RAISE(NULL_POINTER_EXCEPTION);
    if (array.size_of_object != sizeof(double))
      RAISE(ILLEGAL_ARGUMENT_EXCEPTION);
    matrix = new_matrix(1, array.index);
    for (int i = 0; i < array.index; i++)
      matrix->put(matrix, 0, i, *((double *)(array.get(&array, i))));
}




