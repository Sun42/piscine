/*
** 
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sat Oct 19:22:43:40 2008 christophe sundas
** Last update Sun Oct 19 23:44:19 2008 christophe sundas
*/

int     match2(char *str1, char *str2, int i, int j);
int     exist_char(char *str, int i, char c);
int     find_lastpos(char *str, int i, char c);
int	nmatch(char *str1,char *str1);
int	my_strlen(char *str);

int	nmatch(char *str1,char *str2)
{
  int	j;
  int	i;
  int	count;

  i = 0;
  j = 0;
  count = 0;
  while (j < my_strlen(str2))
    {
      i = 0;
      if (str2[j] == '*')
	{
	  count = count + match2(str1, str2);
	  while (i <  my_strlen(str1))
	    {
	      str2[j] = str1[i];
	      count = count + match2(str1, str2);
	      i = i + 1;
	    }
	  str2[j] = '*';
	}
      j = j + 1;
    }
  return (count);
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

int     find_lastpos(char *str, int i, char c)
{
  int   pos;

  pos = my_strlen(str) - 1;
  while ((c != str[pos]))
    {
      pos = pos - 1;
    }
  if (pos >= i)
    return (pos);
  return (0);
}

int     exist_char(char *str, int i, char c)
{
  int   end;

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

int     match2(char *str1, char *str2,int i, int j)
{
  int   str1_max;
  int   str2_max;

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
