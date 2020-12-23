#include "array_list.h"

int  partition (t_array_list *this, int  low, int  high, int (*cond)(void *item1, void *item2)) 
{ 
	void *pivot;
	int i;
	int  j;

	pivot = this->arr[high];
	i = (low - 1) ;  
	j = low ;
	while (j <= high - 1) 
	{ 
		if (cond(this->arr[j] , pivot) == 1) 
		{ 
			i++;   
			this->swap(&(this->arr[i]),&(this->arr[j])); 
		} 
		j++;
	} 
	this->swap(&(this->arr[i + 1]), &(this->arr[high])); 
	return (i + 1); 
} 

void sort(t_array_list *this, int (*cond)(void *item1 , void *item2), int  l, int  r)
{
	if (l < r) 
	{ 
		int pi = partition(this, l, r, cond);
		this->sort(this ,cond, l , (pi - 1)); 
		this->sort(this,cond, (pi + 1) , r ); 
	} 

}
