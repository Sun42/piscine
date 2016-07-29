/*
** my_evil_str.c for rush!! in /u/all/sundas_c/cu/rendu/piscine/Jour_04
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Fri Oct 10 18:58:44 2008 christophe sundas
** Last update Mon Oct 27 17:25:01 2008 christophe sundas
*/

#include "my.h"

void	my_revstr(char *str);

void	my_revstr(char *str)
{
  int	c;
  int	i;
  int	j;

  i = 0;
  j = my_strlen(str) - 1;
  while (i < j)
    {
      c = str[i];
      str[i] = str[j];
      str[j] = c;
      i = i + 1;
      j = j - 1 ;
    }
}
