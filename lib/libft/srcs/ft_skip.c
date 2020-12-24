
#include "libft.h"

int skip(char *line , int index, char ch)
{
  if (line == NULL || index < 0)
    return index < 0 ? 0 : index;
  while (line[index] == ch)
      index++;
  return index ;
}