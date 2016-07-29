/*
** is_big_endian.c for is big endian in /u/all/sundas_c/cu/rendu/piscine/Jour_09
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Mon Oct 20 19:51:20 2008 christophe sundas
** Last update Tue Oct 21 15:46:33 2008 christophe sundas
*/

int	is_big_endian(void);

int	is_big_endian(void)
{
  int	nb;
  char	*c;

  nb = 1;
  c = (char *) &nb;
  if (c[0] == 0)
    return (1);
  else
    return (0);
}


int main()
{

  printf("REs ::%d\n", is_big_endian());
}
