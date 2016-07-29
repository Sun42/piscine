/*
** my_aff_params.c for my_aff_param in /u/epitech_2011s/sundas_c/cu/rendu/piscine/Jour_07/my_aff_params
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct 15 20:59:51 2008 christophe sundas
** Last update Wed Oct 15 21:09:26 2008 christophe sundas
*/

int	main(int argc, char **argv)
{
  int	i;
  
  i = 0;
  while (i < argc)
    {
      my_putstr(argv[i]);
      my_putstr("\n");
      i = i + 1;
    }
  return (0);
}
