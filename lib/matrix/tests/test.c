
#include "matrix.h"
#include "test_tools.h"

#define ROWS 5
#define COLS 5

t_matrix *g_m;



void test_init()
{
		g_m = new_matrix(ROWS , COLS);
		assert_eq(g_m != NULL, 1);
		assert_eq(g_m->cols == COLS, 1);
		assert_eq(g_m->rows == ROWS, 1);
    print_test_passed("init");
}
void test_put()
{
	assert_eq(g_m != NULL, 1);
	assert_eq(g_m->cols == COLS, 1);
	assert_eq(g_m->rows == ROWS, 1);
	for(int i = 0; i < ROWS; i++)
		for(int j = 0; j < COLS; j++)
			g_m->put(g_m, i, j, i * 12.123);
    print_test_passed("put");
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
			printf("row: %d , cols: %d , value: %.4f\n", i , j, value);
		}
    print_test_passed("get");
}



void  test_add()
{
  double value;

  assert_eq(g_m != NULL, 1);
	assert_eq(g_m->cols == COLS, 1);
	assert_eq(g_m->rows == ROWS, 1);
  g_m->add(g_m, 4);
  for(int i = 0;i <ROWS; i++)
		for(int j = 0; j< COLS; j++)
		{
			value = g_m->get(g_m, i , j);
			assert_eq(value == (i * 12.123 + 4), 1);
			printf("row: %d , cols: %d , value: %.4f\n", i , j, value);
		}
    print_test_passed("add");
}

void for_each(double val)
{
  printf("%0.2f \n", val);
}

void  test_for_each()
{
  assert_eq(g_m != NULL, 1);
	assert_eq(g_m->cols == COLS, 1);
	assert_eq(g_m->rows == ROWS, 1);
  assert_eq(g_m->for_each != NULL, 1);
  g_m->for_each(g_m, &for_each);
  print_test_passed("for_each");
}

void main()
{
    print_sp_line("init");
		test_init();
    print_sp_line("put");
		test_put();
    print_sp_line("get");
		test_get();
    print_sp_line("add");
		test_add();
    print_sp_line("for_each");
		test_for_each();
    print_sp_line("map");
}