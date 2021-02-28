#include "matrix.h"

// * @see  https://www.mathstips.com/matrix-subtraction/#:~:text=Subtraction%20of%20matrix%20is%20possible,they%20have%20the%20same%20order.&text=This%20new%20matrix%20is%20the,elements%20of%20the%20given%20matrices.
void matrix_subtract_n(t_matrix *this , double n){
    if (this == NULL)
		RAISE(NULL_POINTER_EXCEPTION);
    for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			this->data[i][j] -= n;
}

 // * @see  https://www.mathstips.com/matrix-subtraction/#:~:text=Subtraction%20of%20matrix%20is%20possible,they%20have%20the%20same%20order.&text=This%20new%20matrix%20is%20the,elements%20of%20the%20given%20matrices.
// ! @throws ILLEGAL_ARGUMENT_EXCEPTION 
void subtract_matrix(t_matrix *this , t_matrix m){
    if (this == NULL || m.data == NULL)
		RAISE(NULL_POINTER_EXCEPTION);
    if (this->rows != m.rows || this->cols != m.cols)
		RAISE(ILLEGAL_ARGUMENT_EXCEPTION);
    for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			this->data[i][j] -= m.data[i][j];
}