#include "try_catch.h"

void  test_try()
{
    jmp_buf * __TRY_CATCH_LIB__raise_env = NULL;
jmp_buf * __TRY_CATCH_LIB__retry_env = NULL;
int exception = 0;
    TRY(
        printf("inside try \n");
    )
    CATCH(exception > 0,
        printf(" inside catch  it's not working !!!");
    );
}

void test_raise()
{

int exception = 0;
   
        printf("inside try  1 \n");
        RAISE(ILLEGAL_ARGUMENT_EXCEPTION);
        printf("inside try  2 \n");
   
}

void test_catch()
{

}

void test_finally()
{
    
}

int main()
{
    
    test_try();
    test_raise();
    test_catch();
    test_finally();

}