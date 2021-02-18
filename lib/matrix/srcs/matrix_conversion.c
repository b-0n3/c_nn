#include "matrix.h"
// @return  {rows : this.row \n, cols:this.cols \n, data : \n [ [row 1] \n,..... [ rown]\n,]}
char *matrix_to_string(t_matrix *this){
		char *line;

		if (this == NULL)
			RAISE(NULL_POINTER_EXCEPTION)
	
		return NULL;
}

// @param this :
//          this->data :
//                      [ row1]
//                      ....
//                      [row n]
// @return  array[ this->rows * this->cols] data  [ row 1 , .... , row n] 
// ! @throw MALLOC_EXCEPTION
double *matrix_to_array(t_matrix *this){
	double *array;

	array = NULL;
	if (this == NULL)
		RAISE(NULL_POINTER_EXCEPTION);

	return array;
}
