#ifndef STRING_BUILDER_H
#define STRING_BUILDER_H
#include "array_list.h"
#include "try_catch.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#define SB_MAX_LENGTH	4096
#define SB_FAILURE -10


typedef struct s_fragment{
		char *str;
		size_t length;
		size_t lenght_before;
		void (*free)(struct s_fragment *this);
}				t_fragment;

typedef struct s_string_builder{
	size_t			length;
	t_array_list	fragments;
	void		(*empty)(struct s_string_builder *this);
	size_t		(*append)(struct s_string_builder *this, char *str);
	size_t		(*append_formated)(struct s_string_builder *this, char *format, ...);
	char 	*(*to_string)(struct s_string_builder *this);
	void	(*free)(struct s_string_builder *this);
}				t_string_builder;

t_string_builder *new_string_builder(char *str);
t_string_builder *new_string_builder_formated(char *format, ...);
t_string_builder *new_empty_string_builder();
void		sb_empty(t_string_builder *this);
size_t		sb_append(t_string_builder *this, char *str);
size_t		sb_append_formated(t_string_builder *this, char *format, ...);
char 	*sb_to_string(t_string_builder *this);
void	sb_free(t_string_builder *this);

t_fragment *new_fragment(char *str,size_t length, size_t length_before);
void fragment_free(t_fragment *this);
#endif