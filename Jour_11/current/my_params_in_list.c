/*
** my_put_in_list.c for fuck off moulinette in /u/all/sundas_c/cu/rendu/piscine/Jour_11
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct 22 00:05:43 2008 christophe sundas
** Last update Sat Oct 25 00:18:33 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"

typedef struct	s_list
{
  char		*data;
  struct s_list	*next;

}		t_list;

int		my_put_in_list(t_list **begin, char *data)
{
  t_list	*new_elem;

  new_elem = malloc(sizeof(*new_elem));
  new_elem->data = data;
  new_elem->next = *begin;
  *begin = new_elem;
}

int		my_show_str_in_list(t_list *begin)
{
  while (begin != 0)
    {
      my_putstr(begin->data);
      my_putstr("\n");
      begin = begin->next;
    }
}

t_list		*my_param_in_list(int ac, char **av)
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
