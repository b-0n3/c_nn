#include "test_tools.h"

extern jmp_buf * __TRY_CATCH_LIB__raise_env;
extern jmp_buf * __TRY_CATCH_LIB__retry_env;
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
void no_op(enum mcheck_status status) {}

int check_memory_after_free(void *ptr)
{
  //printf("%d",mcheck(&no_op));

   //assert_eq(!MCHECK_OK, mprobe(ptr));
  return mprobe(ptr);
}