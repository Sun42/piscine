/*
** my_find_elm_eq_in_list.c for blabla in /u/all/sundas_c/cu/rendu/piscine/Jour_11/current
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct 22 18:40:49 2008 christophe sundas
** Last update Wed Oct 22 23:37:09 2008 christophe sundas
*/

#include <stdlib.h>

t_list		*my_find_node_eq_in_list(t_list *begin, void *data_ref, int (*cmp)())
{
  t_list	*tmp;
  
  tmp = begin;
  while (tmp != 0)
    {
      if (cmp(tmp->data, data_ref) == 0)
	{
	  return (tmp);
	}
      tmp = tmp->next;
    }
  return (NULL);
}
