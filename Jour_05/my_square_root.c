/*
** my_square_root.c for retourne la racine carre dun no;bre in /u/epitech_2011s/sundas_c/cu/rendu/piscine/Jour_05
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct 15 17:43:32 2008 christophe sundas
** Last update Wed Oct 15 18:13:25 2008 christophe sundas
*/

int	my_square_root(int nb)
{
  int	i;
  
  i = 0;
  while ((i * i) < nb)
    {
      i = i + 1;
    }
  if ((i * i) == nb)
    {
      return (i);
    }
  else
    {
      return (0);
    }
}
