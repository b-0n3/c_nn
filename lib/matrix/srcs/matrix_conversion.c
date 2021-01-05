#include "matrix.h"
// @return  {rows : this.row \n, cols:this.cols \n, data : \n [ [row 1] \n,..... [ rown]\n,]}
char *matrix_to_string(t_matrix *this){
    char*   str_format;

    str_format = strjoin("rows : ", this->row);
    str_format = ft_strjoin(" \n, cols:", this->cols);
    sprintf(str_format, "rows : %d \n,", this->rows);
    sprintf(str_format + ft_strlen(str_format), "cols : %d \n,", this->cols);
    sprintf(str_format + ft_strlen(str_format), "cols : %d \n,", this->cols);
    sprintf(str_format + ft_strlen(str_format), " data : \n [ ");
    for (int i = 0; i < this->rows; i++)
    {
         sprintf(str_format + ft_strlen(str_format), "[ ");
         for (int j = 0; j < this->cols; j++)
         {
             sprintf(str_format + ft_strlen(str_format), "%f, ", this->data[i][j]);
         }
          sprintf(str_format + ft_strlen(str_format), " ] \n, ");
    }
    sprintf(str_format + ft_strlen(str_format), "\n,]}");
    return (str_format);
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
