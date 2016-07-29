/*
** colle2.c for colle2 projet in /u/all/sundas_c/cu/rendu/piscine/colle1
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sat Oct 11 16:35:18 2008 christophe sundas
** Last update Sat Oct 11 16:58:52 2008 christophe sundas
*/
#include <stdio.h>
#include <unistd.h>

void my_putchar(char c)
{
  write(1, &c, 1);
}
void    colle(int x, int y)
{
  if ((x <= 0) ||  (x > 2147483647) || (y <= 0) || (y > 2147483647)) 
    {
      exit(0);
    }
  int   i;
  int   j;

  j = 0;
  while (j < y)
    {
      i = 0;
      while (i < x)
        {
          my_putchar('*');
          i =  i + 1;
        }
      printf("\n");
      j = j + 1;
    }
}

int	check_param(x, y)
{

}

int      main()
{
  colle(1, 1);
  return (0);
}

