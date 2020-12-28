#include "matrix.h"



// ! @throws ILLEGAL_ARGUMENT_EXCEPTION
void free_matrix(t_matrix *this){
    if (this == NULL)
        RAISE(ILLEGAL_ARGUMENT_EXCEPTION);
    for (int i = 0 ; i < this->rows; i++)
    {
        for (int j = 0; j< this->cols;j++)
            free(this->data[i][j]);
        free(this->data[i]);
    }
    free(this->data);
}
