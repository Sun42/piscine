/*
** my_factorielle_rec.c for factorielle_recursive ex02 jour5 in /u/all/sundas_c/cu/rendu/piscine
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Fri Oct 10 14:53:46 2008 christophe sundas
** Last update Fri Oct 10 16:25:26 2008 christophe sundas
*/

int	my_factorielle_rec(int nb);

int	my_factorielle_rec(int nb)
{
  if ((nb < 0) || (nb > 12))
    {
      return (0);
    }
  if (nb > 0)
    {
      return (nb * my_factorielle_rec(nb - 1));
    }
      return (1);
}
