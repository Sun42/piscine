/*
** convert-base.c for convert base in /u/all/sundas_c/cu/rendu/piscine/Jour_08
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Oct 16 11:04:06 2008 christophe sundas
** Last update Thu Oct 16 18:35:46 2008 christophe sundas
*/

#include <stdlib.h>

char	*convert_base(char *nbr, char *base_from, char *base_to);
int	my_getnbr_base(char *str, char *base);
int	find_pos(char c, char *str);
int	my_size(int n, char *base, int size);
char	*my_putnbr_base(int n, char *base, char *str);

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  char	*str;
  int	nb;
  int	size;

  nb = my_getnbr_base(nbr, base_from);
  size = 0;
  size = my_size(nb, base_to, size);
  str = malloc(sizeof(*str) * size + 1);
  if (str == 0)
    {
      return (NULL);
    }
  else
    {
      my_putnbr_base(nb, base_to, str);
      strncat(str, "\0", 1);
      return (str);
    }
}

char	*my_putnbr_base(int n, char *base, char *str)
{
  int	deb;
  int	fin;
  int	len;

  len = my_strlen(base);
  if (n < 0)
    {
      my_strncat(str, "-", 1);
      my_putnbr_base(-n, base, str);
    }
  else
    {
      fin = n % len;
      deb = (n - fin) / len;
      if (deb != 0)
	{
	  my_putnbr_base(deb, base, str);
	  my_strncat(str, base + fin, 1);
	}
      else
	{
	  my_strncat(str, base + fin, 1);
	}
    }
  return (str);
}

int	find_pos(char c, char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == c)
	return (i);
      i = i + 1;
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
      len_str = len_str - 1;
    }
  return (result);
}
 
int	my_size(int n, char *base, int size)
{
  int	deb;
  int	fin;
  int	len;

  len = my_strlen(base);
  if (n < 0)
    {
      size = size + 1;
      size = my_size(-n, base, size);
    }
  else
    {
      fin = n % len;
      deb = (n - fin) / len;
      if (deb != 0)
        {
	  size = size + 1;
	  size = my_size(deb, base, size);
        }
      else
        {
	  size = size + 1;
        }
    }
  return (size);
}
