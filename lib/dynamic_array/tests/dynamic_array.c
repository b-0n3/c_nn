#include "../includes/dynamic_array.h"

int main()
{
    dynamic_array_t *dyArr = init_new_dynamic_array();

    for (int i = 1; i <= 50; i++) {
        add(dyArr, &i);
    }

    delete (dyArr, 10);

    int value = 1000;

	// Put the value at the index 0
    put(dyArr, &value, 0);

    value = 5000;

    int another_value = 7000;

    add(dyArr, &another_value);

    for (int i = 0; i < dyArr->size; i++) {
        printf("value %d\n", *(int *)get(dyArr, i));
    }

    int value_for_invalid_index = 10000;

	// this should cause an out of range Error
    put(dyArr, &value_for_invalid_index, 150);
    return 0;
}
