/*
** my_param_to_tab.c for prend les param et les stock dans un struct in /u/all/sundas_c/cu/rendu/piscine/Jour_09
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Mon Oct 20 13:40:35 2008 christophe sundas
** Last update Mon Oct 20 18:44:36 2008 christophe sundas
*/

#include <stdlib.h>
#include "my_param_to_tab.h"

struct s_stock_par	*my_param_to_tab(int ac, char **av);

struct s_stock_par	*my_param_to_tab(int ac, char **av)
{
  struct s_stock_par	*ptrstruct;
  int			i;

  if (ac == 0)
    return (0);
  ptrstruct = malloc(sizeof(*ptrstruct) * (ac + 1));
  if (ptrstruct == NULL)
    return (0);
  i = 0;
  while (i < ac)
    {
      (ptrstruct + i)->size_param = my_strlen(av[i]);
      (ptrstruct + i)->str = av[i];
      (ptrstruct + i)->copy = malloc(sizeof(char) * my_strlen(av[i]) + 1);
      if ((ptrstruct + i)->copy == NULL)
	return (0);
      my_strcpy((ptrstruct + i)->copy, av[i]);
      (ptrstruct + i)->tab = my_str_to_wordtab(av[i]);
      i = i + 1;
    }
  (ptrstruct + i)->str = 0;
  return (ptrstruct);
}
