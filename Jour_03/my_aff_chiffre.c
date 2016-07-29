/*
** my_aff_chiffre.c for exo3 in /u/all/sundas_c/cu/rendu/piscine/Jour_03/exo3
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct  8 13:01:01 2008 christophe sundas
** Last update Thu Oct  9 21:45:42 2008 christophe sundas
*/

int	my_aff_chiffre();

int	my_aff_chiffre()
{
  int	cpt;

  cpt = 0;
  while (cpt  <= 9)
    {
      my_putchar(cpt + 48);
      cpt = cpt + 1;
    }
  return (0);
}
