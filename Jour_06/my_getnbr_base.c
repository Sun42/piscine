/*
** my_getnbr_base.c for my_getnbr_base in /u/epitech_2011s/gobert_e/cu/rendu/piscine/Jour_06
** 
** Made by emilien gobert
** Login   <gobert_e@epitech.net>
** 
** Started on  Wed Oct 15 12:27:52 2008 emilien gobert
** Last update Mon Nov 24 21:20:58 2008 christophe sundas
*/

#include "my.h"

int	find_pos(char c, char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == c)
	return (i);
      i++;
    }
  return (-1);
}

int	my_getnbr_base(char *str, char *base)
{
  int	result;
  int	len_base;
  int	len_str;
  int	fact;

  if (str[0] == '-')
    return (-my_getnbr_base(str + 1, base));
  fact = 1;
  len_base = my_strlen(base);
  len_str = my_strlen(str) - 1;
  result = 0;
  while (len_str >= 0)
    {
      result = result + find_pos(str[len_str], base) * fact;
      fact = len_base * fact;
      len_str--;
    }
  return (result);
} 

int	my_putnbr_base(int n, char *base)
{
  int   deb;
  int   fin;
  int   len;

  len = my_strlen(base);
  if (n < 0)
    {
      my_putchar('-');
      my_putnbr_base(-n, base);
    }
  else
    {
      fin = n % len;
      deb = (n - fin) / len;
      if (deb != 0)
        my_putnbr_base(deb, base);
      my_putchar(base[fin]);
    }
}
