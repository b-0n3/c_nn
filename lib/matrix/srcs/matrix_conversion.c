#include "matrix.h"
// @return  {rows : this.row \n, cols:this.cols \n, data : \n [ [row 1] \n,..... [ rown]\n,]}
char *matrix_to_string(t_matrix *this){
    t_string_builder *sb;
    char *line;

		if (this == NULL)
			RAISE(NULL_POINTER_EXCEPTION)
    sb = new_string_builder_formated("{rows: %d\n, cols: %d \n,data:",this->rows, this->cols);
    for(int i = 0; i < this->rows;i++)
    {
      sb->append_formated(sb,"row index : %d \n [", i);
      for(int j = 0; j < this->cols; j++)
      {
        sb->append_formated(sb, " %.6f", this->data[i][j]);
        if (j < this->cols - 1)
          sb->append(sb, ",");
      }
      sb->append(sb,"]\n");
      if (i < this->rows - 1)
          sb->append(sb, ",");
    }
    sb->append(sb,"}\n");
    line = sb->to_string(sb);
  	sb->free(sb);
    return line;
}

// @param this :
// !           [array_size]
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
  array = rmalloc(sizeof(double) * ((this->rows * this->cols) + 2));
  array[0] = this->rows * this->cols + 1;
  for(int i = 0; i < this->rows;i++)
    for(int j = 0; j < this->cols; j++)
    {
      // add one to index cause index 0 resreved to array_size
      array[(j + i * this->rows) + 1] =  this->data[i][j];
    }
	return array;
}
