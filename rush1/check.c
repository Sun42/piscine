

/*
** getentry.c for try de get entry in /u/all/sundas_c/cu/rendu/piscine/rush1
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Oct 16 22:01:10 2008 christophe sundas
** Last update Fri Oct 17 01:11:54 2008 christophe sundas
*/

#include <stdlib.h>
#include <stdio.h> 

int	check(char **tab, char **piece, int x, int y);
int	hauteur(char **str);

int	check(char **tab, char **piece, int x, int y)
{
  int	hauteur_p;
  int	hauteur_t;
  int	i;
  int	j;
 
  hauteur_p = hauteur(piece);
  hauteur_t = hauteur(tab); 
  i = 0;
  if (((x + strlen(*piece)) > strlen(*tab)) || ((y + hauteur_p) > hauteur_t))
      return (0);
  while (piece[i] != NULL)
    {
      j = 0;
      while (piece[i][j] != '\0')
	{
	  if (piece[i][j] != '.' && tab[y + i][x + j] != '.')
	    return (0);
	  j = j + 1;
	}
      i = i + 1;
    }
  return (1);
}

int	hauteur(char **str)
{
  int	i;
  
  i = 0;
  while (*(str + i) != NULL)
    {
      i = i + 1;
    }
  return (i);
}
