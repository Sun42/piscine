/*
** my_is_prime.c for my_is_prime in /u/epitech_2011s/gobert_e/cu/rendu/piscine/Jour_05
** Made by sundas christophe
** Login   <sundas_c@epitech.net> 
**
** Started on  Mon Oct 13 17:26:53 2008 emilien gobert
** Last update Sun Oct 19 23:36:29 2008 christophe sundas
**
*/

int	match(char *str1, char *str2);
int	match2(char *str1, char *str2, int i, int j);
int	exist_char(char *str, int i, char c);
int	find_lastpos(char *str, int i, char c);
int	my_strlen(char *str);

int	match(char *str1, char *str2)
{
  int	i;
  int	j;
  
  i = 0;
  j = 0;
  return (match2(str1, str2, i, j));
}

int	match2(char *str1, char *str2,int i, int j)
{
  int	str1_max;
  int	str2_max;

  str1_max = my_strlen(str1) - 1;
  str2_max = my_strlen(str2) - 1;
  if (i == str1_max)
    {
      if ((str1[i] == str2[j]) || (str2[j] == '*'))
	return (1);
      return (0);
    }
  if (str1[i] == str2[j] && (str1[i] != '*'))
    return (match2(str1, str2, i + 1, j + 1));
  if (str2[j] != '*')
    return (0);
  if (j == str2_max)
    return (1);
  if (str2[j + 1] == '*')
    return (match2(str1, str2, i + 1, j + 1));
  if (exist_char(str1, i, str2[j + 1]) == 0)
    return (0);
  if (str2[j + 1] == str1[i])
    {
      return (match2(str1, str2, i, j + 1));
    }
  return (match2(str1, str2, i + 1, j));
}

int	find_lastpos(char *str, int i, char c)
{
  int	pos;

  pos = my_strlen(str) - 1;
  while ((c != str[pos]))
    {
      pos = pos - 1;
    }
  if (pos >= i)
    return (pos);
  return (0);
}

int	exist_char(char *str, int i, char c)
{
  int	end;
  
  end = my_strlen(str) - 1;
  while (i <= end)
    {
      if (str[i] == c)
	{
	  return (1);
	}
      i = i + 1;
    }
  return (0);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while(str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
