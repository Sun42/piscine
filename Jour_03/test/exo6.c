/*
** my_aff_comb2.c for my_aff_comb2 in /u/all/sarazi_t/cu/rendu/piscine/Jour_03
** 
** Made by tugdual sarazin
** Login   <sarazi_t@epitech.net>
** 
** Started on  Wed Oct  8 16:35:51 2008 tugdual sarazin
** Last update Thu Oct  9 23:29:59 2008 christophe sundas
*/
int my_putchar(char c);

int	main()
{
  my_aff_comb2();
}
int     my_put_nbr(int n)
{
  char	num;
  int	i;
  int	flag;

  flag = 0;
  i = 10;
  while (i >= 1)
    {
      num = (n / i) % 10 + 0x30;
      my_putchar(num);
      i = i / 10;
    }
}

int     my_put_aff(int a, int b)
{
  my_put_nbr(a);
  my_putchar(' ');
  my_put_nbr(b);
  if (a != 98 || b != 99)
    {
      my_putchar(',');
      my_putchar(' ');
    }
}

int     my_aff_comb2()
{
  int a;
  int b;

  a = 0;
  while (a <= 99)
    {
      b = a + 1;
      while (b <= 99)
        {
	  my_put_aff(a, b);
	  b = b + 1;
        }
      a = a + 1;
    }
}
int my_putchar(char c)
{
  write(1, &c, 1);
}
