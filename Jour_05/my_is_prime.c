/*
** my_is_prime.c for my_is_prime in /u/epitech_2011s/gobert_e/cu/rendu/piscine/Jour_05
** 
** Made by emilien gobert
** Login   <gobert_e@epitech.net>
** 
** Started on  Mon Oct 13 17:26:53 2008 emilien gobert
** Last update Wed Oct 15 16:21:48 2008 emilien gobert
*/

int     my_square_root(int nb)
{
  int   i;

  i = 0;
  while ((i * i) < nb)
    {
      i = i + 1;
    }
  return (i);
}

int	my_is_prime(int nb)
{
  int	i;

  i = 2;
  while (i <= my_square_root(nb))
    {
      if ((nb %i) == 0)
	return (0);
      i = i + 1;
    }
  return (1);
}
