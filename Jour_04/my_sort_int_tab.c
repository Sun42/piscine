/*
** my_sort_int_tab.c for my_sort_int_tab ex05 jour04 in /u/all/sundas_c/cu/rendu/piscine/Jour_04
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Fri Oct 10 09:15:13 2008 christophe sundas
** Last update Fri Oct 10 15:59:23 2008 christophe sundas
*/

void	my_sort_int_tab(int *tab, int size);
void	my_swap(int *a, int *b);

void    my_sort_int_tab(int *tab, int size)
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

void	my_swap(int *a, int *b)
{
  int	tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}
