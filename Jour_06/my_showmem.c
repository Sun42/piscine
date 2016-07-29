/*
** my_showmem.c for my_showmem in /u/epitech_2011s/gobert_e/cu/rendu/piscine/Jour_06
** 
** Made by emilien gobert
** Login   <gobert_e@epitech.net>
** 
** Started on  Wed Oct 15 13:35:13 2008 emilien gobert
** Last update Wed Oct 15 14:45:18 2008 emilien gobert
*/

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

my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void	my_put_nbr_base_pad(unsigned int nbr, char *base, int pad)
{
  int	base_len;

  base_len = my_strlen(base);
  if (pad > 0)
    {
      my_put_nbr_base_pad(nbr / base_len, base, pad - 1);
      my_putchar(base[nbr % base_len]);
    }
}

void	print_addr(char *str)
{
  my_put_nbr_base_pad((unsigned int)str, "0123456789abcdef", 8);
  my_putchar(':');
}

void	print_hexa(char *str, int size)
{
  int	i;

  i=0;
  while(i <16)
    {
      if ((i % 2) == 0)
	my_putchar(' ');
      if (i < size)
	my_put_nbr_base_pad(str[i], "0123456789abcdef", 2);
      else
	my_putstr( " ");
      i++;
    }
}

void    print_ascii(char *str, int size)
{
  int	i;

  my_putstr(" ");
  i = 0;
  while ((i < 16) && (i < size))
    {
      if ((str[i] >= 32) && (str[i] < 127))
	my_putchar(str[i]);
      else
	my_putchar('.');
      i++;
    }
}

void	my_showmem16(char *str, int size)
{
  print_addr(str);
  print_hexa(str, size);
  print_ascii(str, size);
  my_putchar('\n');
}

int	my_showmem(char *str, int size)
{
  int	i;

  i = 0;
  while(i < size)
    {
      my_showmem16(&str[i], size -  i);
      i = i + 16;
    }
  return (0);
}
