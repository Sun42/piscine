/*
** my_strcat.c for strcat in /u/epitech_2011s/sundas_c/cu/rendu/piscine
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct 15 14:57:35 2008 christophe sundas
** Last update Thu Oct 16 10:13:03 2008 christophe sundas
*/

char	*my_strcat(char *str1, char *str2);
int	my_strlen(char *str);

char	*my_strcat(char *str1, char *str2)
{
  int	str1_len;
  int	i;
  
  i  = 0;
  str1_len = my_strlen(str1);
  while (str2[i] != '\0')
    {
      str1[(str1_len + i)] = str2[i];
      i = i + 1;
    }
  str1[str1_len + i] = '\0';
  return (str1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
