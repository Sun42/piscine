/*
** my_power_it.c for my_power_it in /u/all/sundas_c/cu/rendu/piscine/Jour_05
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Fri Oct 10 16:10:33 2008 christophe sundas
** Last update Mon Oct 13 09:48:43 2008 christophe sundas
*/

int	my_power_it(int nb, int power);

int	my_power_it(int nb, int power)
{
  int	i;
  int	res;
  
  i = 0;
  if (power < 0)
    {
      return (0);
    }
  if (power == 0)
    {
      return (1);
    }
  while (i < power)
    {
      res = res * nb;
      i = i + 1;
    }
  return (res);
}
