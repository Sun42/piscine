/*
** my_strcpy.c for my string copy in /u/epitech_2011s/sundas_c/cu/rendu/piscine/Jour_06
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Tue Oct 14 18:58:14 2008 christophe sundas
** Last update Wed Oct 15 14:49:54 2008 christophe sundas
*/

char	*my_strcpy(char *dest, char *src);
int	my_strlen(char *str);

char	*my_strcpy(char *dest, char *src)
{
  int	i;
  int	lenght;

  i = 0;
  lenght = my_strlen(src);
  while (i <= lenght)
    {
      *(dest + i) = src[i];
      i = i + 1;
    }
  return (dest);
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
