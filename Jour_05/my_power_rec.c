/*
** my_power_rec.c for myPower_rec in /u/all/sundas_c/cu/rendu/piscine/Jour_05
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Fri Oct 10 16:57:13 2008 christophe sundas
** Last update Mon Oct 13 09:51:02 2008 christophe sundas
*/

int	my_power_rec(int nb, int power);

int	my_power_rec(int nb, int power)
{
  if (power == 0)
    {
      return (1);
    }
  if (power < 0)
    {
      return (0);
    }
  if (power > 0)
    {
      return (nb * my_power_rec(nb, power - 1));
    }
}
