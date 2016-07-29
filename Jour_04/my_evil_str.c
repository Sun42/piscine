/*
** my_evil_str.c for rush!! in /u/all/sundas_c/cu/rendu/piscine/Jour_04
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Fri Oct 10 18:58:44 2008 christophe sundas
** Last update Fri Oct 10 22:33:06 2008 christophe sundas
*/

char	*my_evil_str(char *str);
int     my_swap(char *a, char *b);
int     my_strlen(char *c);

char	*my_evil_str(char *str)
{
  int	min;
  int	max;

  min = 0;
  max = my_strlen(str) - 1;
  while (min < max)
    {
      my_swap((str + min), (str + max));
      min = min + 1;
      max = max - 1;
    }
  return (str);
}

int	my_swap(char *a, char *b)
{
  char	toto;

  toto = *a;
  *a = *b;
  *b = toto;
  return (0);
}

int     my_strlen(char *c)
{
  int   i;

  i = 0;
  while (c[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
