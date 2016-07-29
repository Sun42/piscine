/*
** my_strstr.c for mystrstr in /u/epitech_2011s/sundas_c/cu/rendu/piscine/Jour_06
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Tue Oct 14 22:46:56 2008 christophe sundas
** Last update Tue Oct 14 22:56:23 2008 christophe sundas
*/

#define NULL (void *)0

int	my_strncmp(char *s1, char *s2, int n);
int	my_strlen(char *str);
int	my_max_int(int i1, int i2);
int	my_cmp_char(char c1, char c2);
char	*my_strstr(char *str, char *to_find);

char	*my_strstr(char *str, char *to_find)
{
  int	i;

  i = 0;
  if (!my_strlen(to_find))
    return (str);
  while ((i < my_strlen(str)))
    {
      if ((strncmp((str + i), to_find, my_strlen(to_find))) == 0)
        {
	  return (str + i);
        }
      i = i + 1;
    }
  return (NULL);
}

int	my_strncmp(char *s1, char *s2,int n)
{
  int	i;
  int	lenght;

  i = 0;
  lenght = my_max_int(my_strlen(s1), my_strlen(s2));

  while ((i < lenght - 1) && (*(s1 + i) == *(s2 + i)) && (i < (n - 1)))
    {
      i = i + 1;
    }
  return (my_cmp_char(*(s1 + i), *(s2 + i)));
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

int	my_max_int(int i1, int i2)
{
  if (i2 > i1)
    return (i2);
  else
    return (i1);
}

int	my_cmp_char(char c1, char c2)
{
  if (c1> c2)
    return (1);
  if (c1 < c2)
    return (-1);
  if (c1 == c2)
    return (0);
}
