;/*
** calcul.c for operations brutes in /u/all/sundas_c/cu/rendu/piscine/Jour_10
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Tue Oct 21 17:08:32 2008 christophe sundas
** Last update Fri Oct 24 02:32:48 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"

int	my_add(int nb1, int nb2)
{
  return (nb1 + nb2);
}

int	my_sub(int nb1, int nb2)
{
  return (nb1 - nb2);
}

int	my_mul(int nb1, int nb2)
{
  return (nb1 * nb2);
}

int	my_div(int nb1, int nb2)
{
  if (nb2 == 0)
    {
      my_putstr("Va t\'acheter des doigts\n");
      exit(-1);
    }
  return (nb1 / nb2);
}

int	my_mod(int nb1, int nb2)
{
  if (nb2 == 0)
    {
      my_putstr("Va t\'acheter des doigts\n");
      exit(-1);
    }
  return (nb1 % nb2);
}
