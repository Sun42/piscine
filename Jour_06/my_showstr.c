/*
** my_showstr.c for my_showstr in /u/epitech_2011s/sundas_c/cu/rendu/piscine/Jour_06
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct 15 09:53:31 2008 christophe sundas
** Last update Wed Oct 15 13:49:21 2008 christophe sundas
*/
int	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_showstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= 32) && (str[i] < 127))
	{
	  my_putchar(str[i]);
	}
      else
	{
	  my_putchar('\\');
	  my_putnbr_base(str[i], "01234567");
	}
      i = i + 1;
    }
}
