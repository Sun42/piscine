/*
** my_strcapitalize.c for oituiort in /u/epitech_2011s/sundas_c/cu/rendu/piscine/Jour_06
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Tue Oct 14 23:33:20 2008 christophe sundas
** Last update Tue Oct 14 23:39:21 2008 christophe sundas
*/

#define NULL (void *)0

int	my_strlen(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);

char	*my_strcapitalize(char *str)
{
  int	i;
  int	flag;
  int	lenght;

  my_strlowcase(str);
  i = 0;
  flag = 0;
  lenght = my_strlen(str);
  while (i < lenght)
    {
      if (((str[i] >= 'a') && (str[i] <= 'z')))
        {
	  if (flag == 0)
	    {
	      str[i] = str[i] - 32;
	    }
	  flag = 1;
        }
      else
        {
	  flag = 0;
        }
      i = i + 1;
    }
  str[i] = '\0';
  return (str);
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

char	*my_strlowcase(char *str)
{
  int	i;
  int	lenght;

  i = 0;
  lenght = my_strlen(str);
  while (i < lenght)
    {
      if (( str[i] >= 'A') && (str[i] <= 'Z'))
        {
	  str[i] = str[i] + 32;
        }
      i = i + 1;
    }
  str[i] = '\0';
  return (str);
}
