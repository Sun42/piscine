/*
** my_strupcase.c for mystrupcase in /u/epitech_2011s/sundas_c/cu/rendu/piscine/Jour_06
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Tue Oct 14 23:15:25 2008 christophe sundas
** Last update Wed Oct 15 15:55:38 2008 christophe sundas
*/

char	*my_strupcase(char *str);

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (( str[i] >= 'a') && (str[i] <= 'z'))
        {
	  str[i] = str[i] - 32;
        }
      i = i + 1;
    }
  return (str);
}
