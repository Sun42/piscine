/*
** my_strisalpha.c for rpoitert in /u/epitech_2011s/sundas_c/cu/rendu/piscine/Jour_06
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Tue Oct 14 23:39:50 2008 christophe sundas
** Last update Wed Oct 15 00:05:52 2008 christophe sundas
*/

int	my_str_isalpha(char *str);
int	my_strlen(char *str);

int	my_str_isalpha(char *str)
{
  int	i;
  int	lenght;

  i = 0;
  lenght = my_strlen(str);
  while (i < lenght)
    {
      if ((((str[i] < 'A') || (str[i] > 'Z'))) && (( str[i] < 'a')  || (str[i] > 'z')))
        {
	  return (0);
        }
      i = i + 1;
    }
  return (1);
}

int	my_strlen(char *c)
{
  int	i;

  i = 0;
  while (c[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
