#include "array_list.h"


// @Author b0n3@1337
// ! if you clone an ArrayList make sure to
// ! pass a suitable free methode even for primitive data types
// @param this  the arrayList you wanna  clone 
// @param __clone a pointer to the methode 
// where you define how to clone your object 
// @Return  a pointer to a newborn arrayList   
t_array_list *clone(struct s_array_list *this,
t_bool is_not_primitive, void *(*__clone)(void *item));
{
    t_array_list *clone;
    
    clone = NULL;
    if (this != NULL)
    {
        new_array_list(clone, original->length, original->size_of_object);
        clone->push_clone(clone , *this, is_not_primitive , __clone);
    }
    return clone;
}
