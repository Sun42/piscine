/*
** check2.c for filler2 in /u/all/sundas_c/cu/rendu/piscine/rush1
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** retourne vrai si une et une seul etoile recouvre un 0 et si on ne reoucvre pas dobstacles
** Started on  Fri Oct 17 01:23:47 2008 christophe sundas
** Last update Fri Oct 17 03:19:05 2008 christophe sundas
*/

#include <stdlib.h>
#include <stdio.h>

int	check(char **tab, char **piece, int x, int y);
int	hauteur(char **str);
void	cover(char pos_piece, char case_table, int *cpt0, int *cpt_others);
int	valid(int cpt0, int cpt_others);

int	check(char **tab, char **piece, int x, int y)
{
  int	hauteur_p;
  int	hauteur_t;
  int	i;
  int	j;
  int	cpt0;
  int	cpt_others;
  
  hauteur_p = hauteur(piece);
  hauteur_t = hauteur(tab);
  i = 0;
  cpt0 = 0;
  cpt_others = 0;
  if (((x + strlen(*piece)) > strlen(*tab)) || ((y + hauteur_p) > hauteur_t))
    return (0);
  while (piece[i] != NULL)
    {
      j = 0;
      while (piece[i][j] != '\0')
        {
	  cover(piece[i][j],tab[y + i][x + j], &cpt0, &cpt_others);
	  j = j + 1;
        }
      i = i + 1;
    }
  return (valid(cpt0, cpt_others));
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

void	cover(char pos_piece, char case_table, int *cpt0, int *cpt_others)
{
  if (pos_piece == '*')
    {
      if (case_table == '0')
	{
	  *cpt0 = *cpt0 + 1;
	}
      else
	{
	  if (case_table != '.')
	    {
	      *cpt_others = *cpt_others + 1;
	    }
	}
    }
}

int	valid(int cpt0, int cpt_others)
{
  if (cpt0 == 1)
    {
      if (cpt_others == 0)
	return (1);
    }
  return (0);
}
int     main(int argc, char **argv)
{
  char **piece;
  char **tab;
    
  piece = malloc(sizeof(*piece) * 4);
  *(piece) = malloc(sizeof(**piece) * 7);
  *(piece + 1) = malloc(sizeof(**piece) * 7);
  *(piece + 2) = malloc(sizeof(**piece) * 7);
  *(piece) = "*.....";
  *(piece + 1) = "*.....";
  *(piece + 2) = "......";
  *(piece + 3) = NULL;
    
  tab = malloc(sizeof(*tab) * 10);
  int i;
  i = 0;
  while (i <= 10)
    {
      *(tab + i) = malloc(sizeof(**tab) * 11);
      *(tab + i) = "..........";
      i = i + 1;
    }
  *(tab + 0) = "0.........";
  *(tab + 1) = "..........";
  printf("%i\n", check(tab, piece, 0, 0));
  return (0);
}
