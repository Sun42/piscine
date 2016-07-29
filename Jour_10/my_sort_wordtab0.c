/*
** my_sort_wordtab.c for trier un tab de ;ot par char ascii in /u/all/sundas_c/cu/rendu/lib/my
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Tue Oct 21 21:48:14 2008 christophe sundas
** Last update Wed Oct 22 00:33:08 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"

int	my_putnbr_base(int n, char *base);

int	my_sort_wordtab(char **tab)
{
  int	i;

  i = 0;
  while(tab[i] != 0)
    {
      j = 
      printf("%s\n", tab[i]);
      i = i + 1;
    }
}

int	main(int argc, char **argv)
{
  char **tab;

  /*my_show_to_wordtab(my_str_to_wordtab(argv[1]));*/
  printf("%s \n", argv[1]);
  tab = my_str_to_wordtab(argv[1]);
  my_sort_wordtab(tab);
}

int	my_putnbr_base(int n, char *base)
{
  int	deb;
  int	fin;
  int	len;

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
	{
	  my_putnbr_base(deb, base);
	  my_putchar(base[fin]);
	}
   else
	{
	  my_putchar(base[fin]);
	}
    }
}
void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	j;

  i = 0;
  while (i < size)
    {
      j = size - 1;
      while (j > i)
	{
	  if (tab[j] < tab[j - 1])
	    {
	      my_swap((tab + j), (tab + (j - 1)));
	    }
	  j = j - 1;
	}
      i = i + 1;
    }
}
