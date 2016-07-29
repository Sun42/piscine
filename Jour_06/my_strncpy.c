/*
** my_strncpy.c for my string lenght copy in /u/epitech_2011s/sundas_c/cu/rendu/piscine/Jour_06
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Tue Oct 14 19:04:50 2008 christophe sundas
** Last update Tue Oct 14 22:40:22 2008 christophe sundas
*/

char	*my_strncpy(char *dest, char *src, int n);
int	my_strlen(char *str);

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;
  int	lenght;

  i = 0;
  lenght = strlen(src);
  while (i < n)
    {
      if (i >= lenght)
	{
	  *(dest + i) = '\0';
	}
      else
	{
	  *(dest + i) = src[i];
	}
      i = i + 1;
    }
  return (dest);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (c[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

