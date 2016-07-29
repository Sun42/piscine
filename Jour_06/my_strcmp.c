/*
** my_strcmp.c for mystrcmp in /u/epitech_2011s/sundas_c/cu/rendu/piscine/Jour_06
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Tue Oct 14 22:59:41 2008 christophe sundas
** Last update Tue Oct 14 23:05:55 2008 christophe sundas
*/

int	my_strlen(char *str);
int	my_max_int(int i1, int i2);
int	my_max_chr(char c1, char c2);
int	my_cmp_char(char c1, char c2);

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	lenght;

  i = 0;
  lenght = my_max_int(my_strlen(s1),my_strlen(s2));

  while ((i < lenght - 1) && (*(s1 + i) == *(s2 + i)))
    {
      i = i + 1;
    }
  return (my_cmp_char(*(s1 + i), *(s2 + i)));
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

int	my_max_chr(char c1, char c2)
{
  if (c2 > c1)
    return (c2);
  else
    return (c1);
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
  if (c1 > c2)
    return (1);
  if(c1 < c2)
    return (-1);
  if (c1 == c2)
    return (0);
}
