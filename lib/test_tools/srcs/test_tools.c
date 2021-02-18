#include "test_tools.h"

void assert_eq(int eq, int a)
{
	if (eq != a)
		THROW(TEST_FAILED_EXCEPTION,"TEST FAILED");
}

void print_test_passed(char *l)
{
  printf("test %s \033[32;1m passed !\033[0;1m\n", l);
}

void print_sp_line(char *l)
{
    printf("\n++++++++ testing %s +++++++++++++\n",l);
}