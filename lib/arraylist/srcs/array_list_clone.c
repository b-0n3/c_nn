#include "array_list.h"

t_array_list *clone(t_array_list *original)
{
    t_array_list *clone;
    if (this != NULL)
    {
        new_array_list(clone, original->length, original->size_of_object);
        clone->push_all(clone , original);
    }
}
