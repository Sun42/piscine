/*
** my_show_str_in_list.c for test in /u/all/sundas_c/cu/rendu/piscine/Jour_11
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Fri Oct 24 01:19:12 2008 christophe sundas
** Last update Fri Oct 24 01:23:01 2008 christophe sundas
*/

#include "my.h"

int	my_show_str_in_list(t_list *begin)
{
  while (*begin != 0)
    {
      my_pustr(begin->data);
      my_putstr("\n");
      begin = begin->next;
    }
}
