/*
** my_strdup.c for mystrdup in /u/epitech_2011s/sundas_c/cu/rendu/piscine/Jour_08
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct 15 23:03:39 2008 christophe sundas
** Last update Thu Oct 16 18:29:20 2008 christophe sundas
*/

#include <stdlib.h>

char	*my_strdup(char *str)
{
  char	*newstr;

  newstr = malloc(sizeof(*newstr) * my_strlen(str) + 1);
  if (newstr == NULL)
    {
      return (NULL);
    }
  my_strcpy(newstr, str);
  my_strncat(newstr, "\0", 1);
  return (newstr);
}
