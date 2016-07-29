/*
** my_aff_revalpha.c for ex02 in /u/all/sundas_c/cu/rendu/piscine/Jour_03/exo2
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct  8 12:38:46 2008 christophe sundas
** Last update Thu Oct  9 22:19:07 2008 christophe sundas
*/

int      my_aff_revalpha();

int	 my_aff_revalpha()
{
  int	cpt;

  cpt = 25;
  while (cpt >= 0)
    {
      my_putchar(cpt + 97);
      cpt = cpt - 1;
    }
  return (0); 
}
