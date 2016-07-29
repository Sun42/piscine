/*
** my_list_size.c for fuck off moulinette in /u/all/sundas_c/cu/rendu/piscine/Jour_11
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct 22 00:05:43 2008 christophe sundas
** Last update Wed Oct 22 17:47:43 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"

int		my_rev_list(t_list **begin)
{
  t_list	*next;
  t_list	*prec;

  next = 0;
  prec = begin[0]->next;
  while (prec != 0)
    {
      begin[0]->next = next;
      next = *begin;
      *begin = prec;
      prec = begin[0]->next;
    }
  begin[0]->next = next;
}
