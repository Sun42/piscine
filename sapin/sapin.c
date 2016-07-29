
** sapin.c for projet_sapin in /u/all/sundas_c/cu/rendu/piscine/sapin
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Oct 12 20:20:46 2008 christophe sundas
** Last update Thu Oct 16 12:40:54 2008 christophe sundas
*/

void	sapin(int taille);
int	floor_width(int num_floor, int show_line, int base);
int	cut(int num_floor);
void	show_line(int width, int flag_show_line, int base, char form);
void	show_tronc(int taille, int base);

void	sapin(int taille)
{
  int	base;

  if ((taille > 0) && (taille < 2147483647))
    {
      base = floor_width(taille, 0, 0);
      floor_width(taille, 1, base);
      show_tronc(taille, base);
    }
}

int	floor_width(int num_floor, int flag_show_line, int base)
{
  int	width;
  int	i;
  
  if (num_floor == 1)
    {
      width = 1;
    }
  if (num_floor > 1)
    {
      width = (floor_width(num_floor - 1, flag_show_line, base) - cut(num_floor - 1));
    }
  i = 1;
  show_line(width, flag_show_line, base, '*');
  while (i < (num_floor + 3))
    {
      i = i + 1;
      width = width + 2;
      show_line(width, flag_show_line, base, '*');
    }
  return (width);
}

int	cut(int num_floor)
{
  int	cut;
  
  if ((num_floor % 2) == 0)
    {
      cut = num_floor;
    }
  else
    {
      cut = num_floor + 1;
    }
  return (cut);
}

void	show_line(int width, int flag_show_line, int base, char form)
{
  int	i;
  
  if (flag_show_line)
    {
      i = 0;
      while (i < ((base - width) / 2))
	{
	  my_putchar(' ');
	  i = i + 1;
	}
      i = 0;
      while (i < width)
	{
	  my_putchar(form);
	  i = i + 1;
	}
      my_putchar('\n');
    }
}

void	show_tronc(int taille, int base)
{
  int	i;
  
  i = 0;
  while (i < taille)
    {
      if ((taille % 2) == 0)
	{
	  show_line((taille + 1), 1, base, '|');
	}
      else
	{
	  show_line(taille, 1, base, '|');
	}
      i = i + 1;
    }
}
