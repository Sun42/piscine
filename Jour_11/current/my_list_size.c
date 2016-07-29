/*
** my_list_size.c for fuck off moulinette in /u/all/sundas_c/cu/rendu/piscine/Jour_11
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct 22 00:05:43 2008 christophe sundas
** Last update Wed Oct 22 15:21:55 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"

typedef struct	s_list
{
  char		*data;
  struct s_list	*next;

}               t_list;

int		my_list_size(t_list *begin)
{
  int		i;
  
  i = 0;
  while (begin != 0)
    {
      begin = begin->next;
      i = i + 1;
    }
  return (i);
}
