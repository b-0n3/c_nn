#include "../includes/dynamic_array.h"

/**
 * @description {*} Initialize a new dynamic Array
 * @params {*} NONE
 * @returns {*dynamic_array_t} A pointer to the created Dynamic Array
 */
dynamic_array_t		*init_new_dynamic_array()
{
	dynamic_array_t *dyArr;

	if (!(dyArr = malloc(sizeof(dynamic_array_t))))
		return NULL;
	dyArr->items = calloc(DEFAULT_CAPACITY, sizeof(void *));
	dyArr->capacity = DEFAULT_CAPACITY;

	return dyArr;
}

/**
 * @description {*} Add a new element to the given Dynamic Array
 * @params {*DyArr, value} A pointer to the dyArr and the value
 * @returns {*} pointer to the newOne
 **/
void	*add(dynamic_array_t *dyArr, const void *value)
{
	if (dyArr->size >= dyArr->capacity) {
		void **newItems = realloc(dyArr->items, (dyArr->capacity <<= 1) * sizeof(void **));
		// I thin this might be a leak !!!
		// free(dyArr->items);

		dyArr->items = newItems;
	}

	void *valueCopy = get_copy_of_value(value);
	dyArr->items[dyArr->size++] = valueCopy;

	return dyArr;
}

/**
 * @description {*} Change the value of an element at a given index
 * @params {*DyArr, value, index} A pointer to the dyArr, the value to
 *			change with and the index of the element
 * @returns {*} pointer to the new changed one
 **/
void	*put(dynamic_array_t *dyArr, const void *value, const unsigned int index)
{
	if(!contains(dyArr->size, index))
		return INDEX_OUT_OF_RANGE;

	free(dyArr->items[index]);
	void *copyValue = get_copy_of_value(value);
	dyArr->items[index] = copyValue;

	return copyValue;
}

/**
 * @description {*} Give the value at the given index
 * @params {*DyArr, index} A pointer to the dyArr, the wanted index
 * @returns {*} The value at the index if it exists
 **/
void	*get(dynamic_array_t *dyArr, const unsigned int index)
{
	if (!(contains(dyArr->size, index)))
		return INDEX_OUT_OF_RANGE;

	return dyArr->items[index];
}

/**
 * @description {*} delete the value at the given index
 * @params {*DyArr, index} A pointer to the dyArr, the wanted index
 * @returns {*} NONE
 **/
void delete(dynamic_array_t *dyArr, const unsigned index)
{
	if (!contains(dyArr->size, index))
		return;

	for (unsigned int i = index; i < dyArr->size; i++) {
		dyArr->items[i] = dyArr->items[i + 1];
	}

	dyArr->size--;

	free(dyArr->items[dyArr->size]);
}

/**
 * @description {*} Check if the range does exists in the Array
 * @params {size, index} the actual size of the DyArr and the index
 * @returns {*} BOOLEAN
 **/
unsigned	contains(const unsigned size, const unsigned index)
{
	if (size >= 0 && index < size)
		return 1;

	printf("index [%d] out of range!\n", index);
	return 0;
}

/**
 * @description {*} Get the given value and return a copy of it
 * @params {value} The value to be copied
 * @returns Pointer to the copyValue
 **/
void *get_copy_of_value(const void *value)
{
	void *value_copy;

	if (!(value_copy = malloc(sizeof(void *))))
		return NULL;

	// TODO: Move it to ft_memcpy
	memcpy(value_copy, value, sizeof(void *));
	return value_copy;
}
