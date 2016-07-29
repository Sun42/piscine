/*
** my_show_tab.c for yshowtab in /u/all/sundas_c/cu/rendu/piscine/Jour_09
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Mon Oct 20 18:46:39 2008 christophe sundas
** Last update Tue Oct 21 16:03:34 2008 christophe sundas
*/

#include <stdlib.h>
#include "my_param_to_tab.h"

int			my_show_tab(struct s_stock_par *par);
struct s_stock_par	*my_param_to_tab(int ac, char **av);
int			my_show_to_wordtab(char **str);

int			my_show_tab(struct s_stock_par *par)
{
  int			i;

  i = 0;
  while ((par + i)->str != NULL)
    {
      my_putstr((par + i)->str);
      my_putchar('\n');
      my_put_nbr((par + i)->size_param);
      my_putchar('\n');
      my_show_to_wordtab((par + i)->tab);
      i = i + 1;
    }
}

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

int			my_show_to_wordtab(char **str)
{
  int			i;

  i = 0;
  while (str[i] != NULL)
    {
      my_putstr(str[i]);
      my_putchar('\n');
      i = i + 1;
    }
  return (0);
}

int	main(int ac, char **argv)
{
  
  my_show_tab(my_param_to_tab(ac, argv));
  return (0);
}
