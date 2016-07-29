/*
** my_sort_params.c for my_sort_params in /u/epitech_2011s/sundas_c/cu/rendu/piscine/Jour_07/my_sort_params
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct 15 21:21:25 2008 christophe sundas
** Last update Wed Oct 15 22:36:44 2008 christophe sundas
*/

int	main(int argc, char **argv)
{
  int	i;
  int	j;

  i = 0;
  while (i < (argc - 1))
    {
      j = argc - 1;
      while (j > i)
	{
	  if (my_strcmp(argv[j], argv[j - 1]) == 1)
	    {
	      my_swap(&argv[j], &argv[j-1]);
	    }
	  j = j - 1;
	}
      i = i + 1;
    }
  i = argc - 1;
  while (i >= 0)
    {
      my_putstr(argv[i]);
      my_putchar('\n');
      i = i - 1;
    }
}
