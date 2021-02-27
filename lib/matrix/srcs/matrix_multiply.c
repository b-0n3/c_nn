#include "matrix.h"

//* @see https://www.mathsisfun.com/algebra/matrix-multiplying.html
void matrix_multiply_n(t_matrix *this, double n){
    if (this == NULL)
		THROW(NULL_POINTER_EXCEPTION, "NULL POINTER ON MATRIX MULTIPLY N");
    for (int i = 0; i < this->rows; i++)
		for (int j =0; j< this->cols; j++)
			this->data[i][j] *= n;
}

// * @see  https://www.mathsisfun.com/algebra/matrix-multiplying.html
// ! @throws ILLEGAL_ARGUMENT_EXCEPTION 
void multiply_matrix(t_matrix *this, t_matrix m){
	t_matrix *result;
	
	if (this == NULL)
		THROW(NULL_POINTER_EXCEPTION, "null pointer on matrix:: multiply by matrix");
	result = multiply_matrix_s(*this, m);
	if (result != NULL)
	{
		this->free(this);
		free(this);
		this = result;
	}
}

// return new matrix (result of  m1 * m2);
// * @see https://www.mathsisfun.com/algebra/matrix-multiplying.html
// ! @throws ILLEGAL_ARGUMENT_EXCEPTION 
// ! @throws MALLOC_EXCEPTION
t_matrix *multiply_matrix_s(t_matrix m1, t_matrix m2){
	t_matrix *result;
	double sum;

	if (m1.cols != m2.rows )
		THROW(ILLEGAL_ARGUMENT_EXCEPTION, "invalid matrices in multiply by matrix");
	result = new_matrix(m1.rows, m2.cols);
	for(int i = 0; i  < result->rows; i++)
		for(int j = 0; j < result->cols; j++)
		{
			sum = 0;
			for (int k = 0; k < m1.cols; k++)
			sum += m1.get(&m1, i, k) * m2.get(&m2, k, j);
			result->put(result, i , j, sum);
		}
	return result;
}