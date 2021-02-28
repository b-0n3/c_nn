#ifndef __DYNAMIC_ARRAY_H__
# define __DYNAMIC_ARRAY_H__

# define DEFAULT_CAPACITY 1 << 4
# define INDEX_OUT_OF_RANGE NULL

// Necessary includes
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

/**
 * @description {*} The dynamic array data structure
 * @params {*} items, size, capacity
 **/
typedef struct dynamic_array {
	void **items;
	unsigned int size;
	unsigned int capacity;
}				dynamic_array_t;

/**
 * @description {*} function definition of the data struture
 * @params {*} NONE
 **/
extern dynamic_array_t *init_new_dynamic_array();
extern void				*add(dynamic_array_t *dyArr, const void *value);
extern void				*put(dynamic_array_t *dyArr, const void *value, unsigned int index);
extern void				*get(dynamic_array_t *dyArr, const unsigned int index);
extern void				delete(dynamic_array_t *dyArr, const unsigned int index);
unsigned				contains(const unsigned size, const unsigned index);
extern void				*get_copy_of_value(const void *value);

#endif
