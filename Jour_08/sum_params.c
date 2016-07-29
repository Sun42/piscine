/*
** sum_params.c for sum params in /u/all/sundas_c/cu/rendu/piscine/Jour_08
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Oct 16 14:09:56 2008 christophe sundas
** Last update Mon Oct 20 17:45:20 2008 christophe sundas
*/

#include <stdlib.h>

int	size_params(int argc, char **argv);

char	*sum_params(int argc, char **argv)
{
  int	i;
  char	*my_string;

  i = 0;
  my_string = malloc(sizeof(*my_string) * size_params(argc, argv));
  if (my_string == NULL)
    {
      return (NULL);
    }
  else
    {
      while (i < argc)
	{
	  my_strncat(my_string, argv[i], my_strlen(argv[i]), 1);
	  i = i + 1;
	  if (i < argc)
	    {
	      my_strncat(my_string,"\n", 1);
	    }
	}
      my_strncat(my_string, "\0", 1);
    }
  return (my_string);
}

int	size_params(int argc, char **argv)
{
  int	i;
  int	sum;

  i = 0;
  sum = 0;
  while (i < argc)
    {
     sum = sum + my_strlen(argv[i]);
     i = i + 1;
    }
  sum = sum + i;
  return (sum);
}
