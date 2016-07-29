/*
** my_apply_on_list.c for ny app;y on list in /u/all/sundas_c/cu/rendu/piscine/Jour_11
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct 22 16:42:37 2008 christophe sundas
** Last update Wed Oct 22 18:35:47 2008 christophe sundas
*/

#include "my.h"

int	my_apply_on_list(t_list *begin, int (*f)())
{
  t_list	*tmp;

  tmp = begin;
  while (tmp != 0)
    {
      f(tmp->data);
      tmp = tmp->next;
    } 
}

