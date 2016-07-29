/*
** my_aff_alpha.c for jour01exo1 in /u/all/sundas_c/cu/rendu/piscine/Jour_03
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct  8 09:32:39 2008 christophe sundas
** Last update Thu Oct  9 21:35:17 2008 christophe sundas
*/

int	my_aff_alpha();

int	my_aff_alpha()
{
  int	cpt;

  cpt = 0;
  while (cpt < 26)
    {
      my_putchar(cpt + 97);
      cpt = cpt + 1;
    }
  return (0);
}
