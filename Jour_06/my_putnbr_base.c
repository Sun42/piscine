/*
** my_putnbr_base.c for my_putnbr_base in /u/epitech_2011s/sarazi_t/cu/rendu/piscine/Jour_06
** 
** Made by tugdual sarazin
** Login   <sarazi_t@epitech.net>
** 
** Started on  Tue Oct 14 09:22:09 2008 tugdual sarazin
** Last update Wed Oct 15 13:47:59 2008 christophe sundas
*/

int	my_putnbr_base(int n, char *base);
int     my_strlen(char *str);
int     my_putchar(char c);

int	my_putnbr_base(int n, char *base)
{
  int	deb;
  int	fin;
  int	len;

  len = my_strlen(base);
  if (n < 0)
    {
      my_putchar('-');
      my_putnbr_base(-n, base);
    }
  else 
    {
      fin = n % len;
      deb = (n - fin) / len;
      if (deb != 0)
	{
	  my_putnbr_base(deb, base);
	  my_putchar(base[fin]);
	}
      else
	{
	  my_putchar(base[fin]);
	}
    }
}

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
