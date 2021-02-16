#include "matrix.h"
// @return  {rows : this.row \n, cols:this.cols \n, data : \n [ [row 1] \n,..... [ rown]\n,]}
char *matrix_to_string(t_matrix *this){
    t_array_list string_builder;

    new_array_list(&string_builder, 5,sizeof(char *));
    if (this == NULL)
      RAISE(NULL_POINTER_EXCEPTION)
}

// @param this :
//          this->data :
//                      [ row1]
//                      ....
//                      [row n]
// @return  array[ this->rows * this->cols] data  [ row 1 , .... , row n] 
// ! @throw MALLOC_EXCEPTION
double *matrix_to_array(t_matrix *this){

}
