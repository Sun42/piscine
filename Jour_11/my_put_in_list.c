/*
** my_put_in_list.c for fuck off moulinette in /u/all/sundas_c/cu/rendu/piscine/Jour_11
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct 22 00:05:43 2008 christophe sundas
** Last update Thu Oct 23 23:21:22 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"

int		my_put_in_list(t_list **begin, char *data)
{
  t_list	*new_elem;

  new_elem = malloc(sizeof(*new_elem));
  new_elem->data = data;
  new_elem->next = *begin;
  *begin = new_elem;
}
