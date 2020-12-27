#include "try_catch.h"

void  test_try()
{
    jmp_buf * __TRY_CATCH_LIB__raise_env = NULL;
jmp_buf * __TRY_CATCH_LIB__retry_env = NULL;

    TRY(
        printf("inside try \n");
    )
    CATCH(exception > 0,
        printf(" inside catch  it's not working !!!\n");
    );
}

void test_raise()
{
   jmp_buf * __TRY_CATCH_LIB__raise_env = NULL;
jmp_buf * __TRY_CATCH_LIB__retry_env = NULL;


   
        printf("inside raise 1 \n");
        RAISE(ILLEGAL_ARGUMENT_EXCEPTION);
        printf("inside raise 2 \n");
   
}

void test_catch()
{
   jmp_buf * __TRY_CATCH_LIB__raise_env = NULL;
jmp_buf * __TRY_CATCH_LIB__retry_env = NULL;

    TRY(
        printf("inside catch test \n");
        RAISE(NULL_POINTER_EXCEPTION);
        printf("inside catch 1 it's not working \n");
    )
    CATCH(exception > 0,
        printf("exception handled %s" , errors[exception]);
        printf(" inside catch it's  working !!!");

    );
}

int main()
{
    
    test_try();
    test_catch();
    test_raise();

}