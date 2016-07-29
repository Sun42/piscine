
/*
** my_rm_all_eq_from_list.c for my rm from eq in /u/all/sundas_c/cu/rendu/piscine/Jour_11/current
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct 22 19:24:14 2008 christophe sundas
** Last update Wed Oct 22 23:10:57 2008 christophe sundas
*/

#include "my.h"
#include <stdlib.h>
#include <string.h>

typedef struct  s_list
{
  char          *data;
  struct s_list *next;

}		t_list;

t_list	*my_rm_all_eq_from_list(t_list **begin,void *data_ref,int (*cmp)())
{
  t_list		*tmp;
  t_list		*prev;
  t_list		*save;
  
  tmp = *begin;
  prev = tmp;
  while (cmp(data_ref, (*begin)->data) == 0)
    {
      save = (*begin)->next;
      free((*begin)->next);
      (*begin)= save;
    }
  while (tmp != 0)
     {
      if (cmp(data_ref, tmp->data) == 0)
	{
	  prev->next = tmp->next;
	  free(tmp);
	  prev = prev;
	}
      else
	  prev = tmp;
      tmp = (*tmp).next;
    }
   return (*begin);
}

