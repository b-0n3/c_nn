#include "matrix.h"
#define ROWS 5
#define COLS 5

t_matrix *g_m;
jmp_buf * __TRY_CATCH_LIB__raise_env = NULL;
jmp_buf * __TRY_CATCH_LIB__retry_env = NULL;


void assert_eq(int eq, int a)
{
	if (eq != a)
		RAISE(TEST_FAILED_EXCEPTION);
}

void test_init()
{
		g_m = new_matrix(ROWS , COLS);
		assert_eq(g_m != NULL, 1);
		assert_eq(g_m->cols == COLS, 1);
		assert_eq(g_m->rows == ROWS, 1);
}
void test_put()
{
	assert_eq(g_m != NULL, 1);
	assert_eq(g_m->cols == COLS, 1);
	assert_eq(g_m->rows == ROWS, 1);
	for(int i = 0; i < ROWS; i++)
		for(int j = 0; j < COLS; j++)
			g_m->put(g_m, i, j, i * 12.123);

}
void test_get()
{
	double value;

		assert_eq(g_m != NULL, 1);
	assert_eq(g_m->cols == COLS, 1);
	assert_eq(g_m->rows == ROWS, 1);
	for(int i = 0;i <ROWS; i++)
		for(int j = 0; j< COLS; j++)
		{
			value = g_m->get(g_m, i , j);
			assert_eq(value == i * 12.123, 1);
			printf("row: %d , cols: %d , value: %.4f", i , j, value);
		}
}

void main()
{
		test_init();
		test_put();
		test_get();
//		test_add();
	//	test_for_eache();
}