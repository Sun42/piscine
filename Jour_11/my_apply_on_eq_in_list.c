/*
** my_apply_on_eq_in_list.c for exo 5 jour 11 in /u/all/sundas_c/cu/rendu/piscine/Jour_11
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct 22 17:38:13 2008 christophe sundas
** Last update Wed Oct 22 23:33:23 2008 christophe sundas
*/

#include "my.h"

int		my_apply_on_eq_in_list(t_list *begin, int (*f)(), void *data_ref, int (*cmp)())
{
  t_list	*tmp;

  tmp = begin;
  while (tmp != 0)
    {
      if (cmp(data_ref, tmp->data) == 0)
	{
	  f(tmp->data);
	}
      tmp = tmp->next;
    }
}

