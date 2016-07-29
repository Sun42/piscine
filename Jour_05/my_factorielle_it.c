/*
** my_factorielle_it.c for my_factorielle_it exo1 jour5 in /u/all/sundas_c/cu/rendu/piscine
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Fri Oct 10 13:40:51 2008 christophe sundas
** Last update Mon Oct 13 09:44:20 2008 christophe sundas
*/

int	my_factorielle_it(int nb);

int	my_factorielle_it(int nb)
{
  int	res;
  
  res = 1;
  if (nb == 0)
    {
      nb = 0;
    }
  if ((nb < 0) || (nb > 12))
    {
      nb = 0;
      res = 0;
    }
  while (nb > 0)
    {
      res = res * nb;
      nb = nb - 1;
    }
  return (res);
}
