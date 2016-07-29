/*
** my_isneg.c for exo4 in /u/all/sundas_c/cu/rendu/piscine/Jour_03/exo4
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct  8 13:11:32 2008 christophe sundas
** Last update Thu Oct  9 22:22:22 2008 christophe sundas
*/

int     my_isneg(int n);

int	my_isneg(int n)
{
  if (n >= 0)
    {
      my_putchar('P');
    }
  if (n < 0)
    {
      my_putchar('N');
    }
  return (0);
}
