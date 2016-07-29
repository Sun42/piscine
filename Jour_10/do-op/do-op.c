/*
** do-op.c for do op.c in /u/all/sundas_c/cu/rendu/piscine/Jour_10
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Tue Oct 21 01:27:19 2008 christophe sundas
** Last update Tue Oct 21 23:14:34 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"

typedef struct	s_opers
{
  char		oper;
  int		(*f)();
}		t_opers;

t_opers	tab[] = 
  {
    {'*', my_mul},
    {'+', my_add},
    {'-', my_sub},
    {'/', my_div},
    {'%', my_mod},
    {0, 0},
  };

int	main(int argc, char **argv)
{
  if (argc < 4)
    {
      return (0);
    }
  else
    {
      do_op(argv[1], argv[2], argv[3]);
      my_putchar('\n');
    }
  return (0);
}

void	do_op(char *nbr1, char *oper, char *nbr2)
{ 
  int	res;

  if (verif_args(nbr1, oper, nbr2) == 0)
    {
      my_putchar('0');
      exit(-1);
    }
  else
    {
      res = calcul(my_getnbr(nbr1), oper[0], my_getnbr(nbr2));
      my_put_nbr(res);
    }
}

 int	verif_args(char *nbr1, char *oper, char *nbr2)
 {
   int	i;

   i = 0;
   while (tab[i].oper != 0)
     {
       if (tab[i].oper == oper[0])
	 {
	   return (1);
	 }
       i = i + 1;
     }
   return (0);
 }

int	calcul(int nb1, char oper, int nb2)
{
  int	i;

  i = 0;
  while (tab[i].oper != 0)
    {
      if (tab[i].oper == oper)
	return (tab[i].f(nb1, nb2));
      i = i + 1;
    }
}
