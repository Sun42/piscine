/*
** my_aff_comb.c for exo6 in /u/all/sundas_c/cu/rendu/piscine/Jour_03
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct  8 13:25:13 2008 christophe sundas
** Last update Thu Oct  9 23:38:23 2008 christophe sundas
*/

int	my_aff_comb2();
int	my_output(int x1, int x2, int y1, int y2);
int	is_last(int x1, int x2, int y1, int y2);
int     verif_inferior(int x1, int x2, int y1, int y2);

int	my_aff_comb2()
{
  int	x1;
  int	x2;
  int	y1;
  int	y2;

  x1 = 0;
  while (x1 <= 9)
    {
      x2 = 0;
      while (x2 <= 9)
	{
	  y1 = 0;	 
	  while (y1 <= 9)
	    {
	      y2 = 0;
	      while (y2 <= 9)
		{
		  verif_inferior(x1, x2, y1, y2);
		  y2 = y2 + 1;
		}
	      y1 = y1 + 1;
	    }
	  x2 = x2 + 1;
	}
     x1 = x1 + 1;
    }
}

int	my_output(int  x1, int  x2, int y1, int y2)
{
  my_putchar(x1 + 48);
  my_putchar(x2 + 48);
  my_putchar(' ');
  my_putchar(y1 + 48);
  my_putchar(y2 + 48);
  is_last(x1, x2 ,y1, y2);
  return (0);
}

int	is_last(int x1,int x2, int y1, int y2)
{
  if (!((x1 == 9) && (x2 == 8) && (y1 == 9) && (y2 == 9)))
    {
      my_putchar(',');
      my_putchar(' ');
    }
  return (0);
}

int	verif_inferior(int x1, int x2, int y1, int y2)
{
  int	number1;
  int	number2;

  number1 = x1 * 10 + x2;
  number2 = y1 * 10 + y2;
  if (number1 < number2)
    {
      my_output(x1, x2, y1, y2);
    }
  return (0);
}

