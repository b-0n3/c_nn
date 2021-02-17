#include "array_list.h"

t_array_list *array;
jmp_buf * __TRY_CATCH_LIB__raise_env = NULL;
jmp_buf * __TRY_CATCH_LIB__retry_env = NULL;
void test_new_array()
{
   new_array_list(array ,4,sizeof(int));
  if (array == NULL)
    RAISE(NULL_POINTER_EXCEPTION);
}

int main(){

}#pragma once
