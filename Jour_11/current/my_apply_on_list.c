/*
** my_apply_on_list.c for ny app;y on list in /u/all/sundas_c/cu/rendu/piscine/Jour_11
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct 22 16:42:37 2008 christophe sundas
** Last update Wed Oct 22 17:58:04 2008 christophe sundas
*/

#include "my.h"

typedef struct	s_list
{
  char		*data;
  struct s_list	*next;

}		t_list;

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

