
#include "libft.h"

void  split_that(t_array_list *words , char *line , char ch)
{
  int firstptr;
  int i;
  char *str;

  firstptr = skip(line, 0, ch) ;
  i = skip(line, 0, ch);
  while (line[i] != '\0')
  {
    while (line[i] != ch && line[i ] != '\0')
        i++;
    if (line[i] == ch || line[i] == '\0')
    {
        str = (char *) malloc((firstptr + i) + 1);
        ft_strlcpy(str , line + firstptr , i - firstptr + 1);
        words->push(words, str, sizeof (str));
        firstptr =  skip(line, i , ch) ;
        i = firstptr - 1;
    }
    i++;
  }
}