/*
** my_str_isupper.c for ny string is upper in /u/epitech_2011s/sundas_c/cu/rendu/piscine/Jour_06
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct 15 00:14:17 2008 christophe sundas
** Last update Wed Oct 15 00:16:24 2008 christophe sundas
*/

int	my_str_isupper(char *str);
int	my_strlen(char *strr);

int	my_str_isupper(char *str)
{
  int	i;
  int	lenght;

  i = 0;
  lenght = my_strlen(str);
  while (i < lenght)
    {
      if ((str[i] < 'A')  || (str[i]>'Z'))
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
