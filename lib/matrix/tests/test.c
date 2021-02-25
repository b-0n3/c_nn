
#include "matrix.h"
#include "test_tools.h"
 #include <fcntl.h>

#define ROWS 5
#define COLS 5

t_matrix *g_m;

jmp_buf * __TRY_CATCH_LIB__raise_env=NULL;
// used by macros for RETRY
jmp_buf * __TRY_CATCH_LIB__retry_env = NULL;

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
void test_to_string()
{
  char final_string[394];
  int size;
  int fd;

  assert_eq(g_m != NULL, 1);
	assert_eq(g_m->cols == COLS, 1);
	assert_eq(g_m->rows == ROWS, 1);
  assert_eq(g_m->to_string != NULL, 1);
  char *line = g_m->to_string(g_m);
  assert_eq(line != NULL, 1);
   fd = open("./tests/toString.txt",O_RDONLY );
   if (fd < 1)
    printf("___file toString not found__\n");
  size = read(fd,final_string,392);
  final_string[size]= '\0';

  assert_eq(strcmp(line, final_string),0);
 free(line);
  print_test_passed("to_string");
  
}
void test_to_array(){
  double *arr;
  void *final_test;

   assert_eq(g_m != NULL, 1);
	assert_eq(g_m->cols == COLS, 1);
	assert_eq(g_m->rows == ROWS, 1);
  assert_eq(g_m->to_array != NULL, 1);
  arr = g_m->to_array(g_m);
  assert_eq(arr != NULL, 1);
  int size = arr[0];
int   fd = open("./tests/toarray.txt", O_RDONLY);
  if (fd < 1)
    printf("___file to_array not found__\n");
  final_test = malloc(sizeof(double) * (size + 2));
  printf("%p %p",&arr[0],&arr[size]);
 read(fd ,final_test, sizeof(double) *(size + 1));
  assert_eq(memcmp(arr, final_test, sizeof(double) * (size)), 0);
  free(arr);
  free(final_test);
   print_test_passed("to_array");
}
void test_transpose()
{
  char *line;

  assert_eq(g_m != NULL, 1);
	assert_eq(g_m->cols == COLS, 1);
	assert_eq(g_m->rows == ROWS, 1);
  assert_eq(g_m->to_array != NULL, 1);
  g_m->transpose(g_m);
  line = g_m->to_string(g_m);
  printf("{%s}\n",line);
  free(line);
  
}
void test_multiply(){
  t_matrix *m1;
  t_matrix *result;
  
  m1 = new_matrix(5,8);
  for (int i =0;i < m1->rows;i++)
    for (int j = 0; j < m1->cols; j++)
      m1->put(m1, i, j, frandom());
    
  result = multiply_matrix_s(*g_m, *m1);
  char *line = result->to_string(result);
  printf("{%s}\n",line);
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
    print_sp_line("tostring");
    test_to_string();
    print_sp_line("to_array");
    test_to_array();
    print_sp_line("transpose");
    test_transpose();
    print_sp_line("multiply");
    test_multiply();


} 