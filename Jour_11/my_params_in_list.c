/*
** my_put_in_list.c for fuck off moulinette in /u/all/sundas_c/cu/rendu/piscine/Jour_11
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct 22 00:05:43 2008 christophe sundas
** Last update Wed Oct 22 21:41:58 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"

t_list		*my_params_in_list(int ac, char **av)
{
  int		i;
  t_list	*begin;

  i = 0;
  begin = 0;
  while (i < ac)
    {
      my_put_in_list(&begin, av[i]);
      i = i + 1;
    }
  return (begin);
}
