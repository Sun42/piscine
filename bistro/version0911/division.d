#include "my.h"
#include "bistromathique.h"
#include <stdlib.h>

char	*division(char *base, char *operators, char *expr1, char *expr2)
{
  char *res;
  char tmp[2];

  tmp[0] = base[1];
  tmp[1] = '\0';
  if ((res = malloc(sizeof(*res) * my_strlen(expr1) + my_strlen(expr2) + 1)) == 0)
    return (NULL);
  res[0] = base[0];
  res[1] = '\0';
  if (((indice_in_base(base, expr2[0]) == 1))  && (my_strlen(expr2) == 1))
    return (expr1);
  while (is_sup(base, expr1, expr2))
    {
      my_strcpy(expr1, soustraction(base, operators, expr1, expr2));
      my_strcpy(res, addition(base, res, tmp));
    }
  return (res);
}
