/*
** match.c for match in /u/all/duplei_m/cu/rendu/piscine/match-nmatch
** 
** Made by mathieu dupleix
** Login   <duplei_m@epitech.net>
** 
** Started on  Fri Oct 17 14:08:48 2008 mathieu dupleix
** Last update Sun Oct 19 20:34:59 2008 mathieu dupleix
*/

int	match(char *s1, char *s2)
{
  if (*s2 == '*')
    {
      if (*(s2 + 1) != '\0')
	return (match(s1, (s2 + 1)));
      else
	return (1);
    }
  if (*s1 == *s2)
    {
      if ((*(s1 + 1) == '\0'))
	return (1);
      else
	return (match((s1 + 1), (s2 + 1)));
    }
  else
    if (*(s1 + 1) == '\0')
      {
	return (0);
      }
    else
      return (match(s1 + 1, s2));
}

int	main(int ac, char **av)
{
  int a;

  a = match(av[1],av[2]);
  printf("%d", a);
}

