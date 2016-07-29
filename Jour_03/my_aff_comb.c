/*
** my_aff_comb.c for exo5 in /u/all/sundas_c/cu/rendu/piscine/Jour_03/exo5
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct  8 13:25:13 2008 christophe sundas
** Last update Thu Oct  9 22:00:31 2008 christophe sundas
*/

int     my_output(int  x, int  y, int z);
int	my_aff_comb();
int     is_last(int x, int y, int z);

int	my_aff_comb()
{
  int	x;
  int	y;
  int	z;

  x = 0;

  while (x <= 9)
    {
      y = x + 1;
      while (y <= 9) 
	{
	  z = y + 1;
	  while (z <= 9)
	    {
	      my_output(x, y, z);
	      z = z + 1;
	    }
	  y = y + 1;
	}
      x = x + 1;  
    }
  return (0);
}

int	my_output(int  x, int  y, int z)
{
  my_putchar(x + 48);
  my_putchar(y + 48);
  my_putchar(z + 48);
  is_last(x, y, z);
  return (0);
}

int	is_last(int x, int y, int z)
{
  if (!((x == 7) && (y == 8) && (z == 9)))
    {
      my_putchar(',');
      my_putchar(' ');
    }
  return (0);
}

