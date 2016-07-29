/*
** my_str_to_wordtab.c for my_str_to_wordtab in /u/all/sarazi_t/cu/rendu/piscine/Jour_08
** 
** Made by tugdual sarazin
** Login   <sarazi_t@epitech.net>
** 
** Started on  Thu Oct 16 15:45:00 2008 tugdual sarazin
** Last update Fri Oct 24 19:06:54 2008 christophe sundas
*/

int	str_isalnu(char c)
{
  if (c >= 'a' && c <= 'z')
    return (1);
  else if (c >= 'A' && c <= 'Z')
    return (1);
  else if (c >= '0' && c <= '9')
    return (1);
  else
    return (0);
}

int	sizetab(char *str)
{
  int	i;
  int	size;

  size = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str_isalnu(str[i + 1]) != 1 && str_isalnu(str[i]) == 1)
	size = size + 1;
      i = i + 1;
    }
  return (size + 1);
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	k;
  int	oldi;
  int	size;
  char	**tab;

  tab = malloc(sizeof(str) * sizetab(str));
  k = 0;
  i = 0;
  oldi = 0;
  while (str[i] != 0)
    {
      if (str_isalnu(str[i + 1]) != 1 && str_isalnu(str[i]) == 1)
	{
	  tab[k] = malloc(sizeof(str) * (i - oldi + 1));
	  strncpy(tab[k], str + oldi, i - oldi + 1);
	  k = k + 1;
	}
      if (str_isalnu(str[i]) != 1)
	oldi = i + 1;
      i = i + 1;
    }
  tab[k] = '\0';
  return (tab);
}
