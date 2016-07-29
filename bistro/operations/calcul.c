#include "my.h"
#include "bistromathique.h"
#include <stdlib.h>

t_opers tab[] =
  {
    {'*', my_mul},
    {'+', my_add},
    {'-', my_sub},
    {'/', my_div},
    {'%', my_mod},
    {0, 0},
  };

int     eval(int nb1, char oper, int nb2)
{
  int   i;

  i = 0;
  while (tab[i].oper != 0)
    {
      if (tab[i].oper == oper)
        return (tab[i].f(nb1, nb2));
      i = i + 1;
    }
}
int     my_add(int nb1, int nb2)
{
  return (nb1 + nb2);
}

int     my_sub(int nb1, int nb2)
{
  return (nb1 - nb2);
}

int     my_mul(int nb1, int nb2)
{
  return (nb1 * nb2);
}

int     my_div(int nb1, int nb2)
{
  if (nb2 == 0)
    {
      my_putstr("Va t\'acheter des doigts\n");
      exit(-1);
    }
  return (nb1 / nb2);
}

int     my_mod(int nb1, int nb2)
{
  if (nb2 == 0)
    {
      my_putstr("Va t\'acheter des doigts\n");
      exit(-1);
    }
  return (nb1 % nb2);
}
