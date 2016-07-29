/*
** my_put_nbr.c for my_put_nbr_proj.c in /u/all/sundas_c/cu/rendu/piscine/Jour_03
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct  8 21:13:07 2008 christophe sundas
** Last update Thu Oct  9 22:31:35 2008 christophe sundas
*/

int     my_put_nbr(int nb);
int	display(int x);
int     is_negative(int nb);

int	my_put_nbr(int nb)
{
  int	base;
  int	flag; 
  int	resultat;

  flag = 0;
  base = 10000000;

  if (is_negative(nb) == 1)
    {
      nb = nb - (nb * 2);
    }
  while (base >= 1)
    {
      resultat=(nb / base) % 10;
      if ((resultat != 0 || flag == 1) || (base == 1 && flag == 0))
	{
	  flag = 1;
	  display(resultat);
	}
      base = base / 10;
    }
  return (0);
} 

int	display(int x)
{
  my_putchar(x + 48);
  return (0);
}

int	is_negative(int nb)
{
  int	bit;

  if (nb < 0)
    {
      my_putchar('-');
      bit = 1;
    }
  if (nb >= 0)
    {
      bit = 0;
    }
  return (bit);
}
