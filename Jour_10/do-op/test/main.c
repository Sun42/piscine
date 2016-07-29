/*
** main.c for main de test in /u/all/sundas_c/cu/rendu/piscine/Jour_10/do-op/test
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sat Oct 25 04:07:33 2008 christophe sundas
** Last update Sat Oct 25 04:13:32 2008 christophe sundas
*/

#include "my.h"
#include "header.h"

int	main(int argc, char **argv)
{
  int	i;

  i = 0;
  while (i < argc)
    {
      affiche(argv[i]);
      i = i + 1;
    }
}
