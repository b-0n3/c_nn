#include "stringbuilder.h"
t_fragment *new_fragment(char *str, size_t length, size_t length_before){
  t_fragment *fragment;
  if (str == NULL)
    THROW(NULL_POINTER_EXCEPTION , "INIT fragment with null str");
  fragment = (t_fragment *) malloc(sizeof(t_fragment));
  if (fragment == NULL)
    return NULL;
  fragment->str = (char *)malloc(length);
  if (fragment->str == NULL)
  {
    free(fragment);
    return NULL;
  }
  memcpy(fragment->str, str, length);
  fragment->lenght_before = length_before;
  fragment->length = length;
  fragment->free = &fragment_free;
  return fragment;
}

void fragment_free(t_fragment *this){
  if (this == NULL)
    THROW(NULL_POINTER_EXCEPTION, "null pointer exception at fragment_free");
  free(this->str);
  free(this);
}