/*
** my_isneg.c for my_isneg in /u/all/sarazi_t/cu/rendu/piscine/Jour_03
** 
** Made by tugdual sarazin
** Login   <sarazi_t@epitech.net>
** 
** Started on  Wed Oct  8 11:29:23 2008 tugdual sarazin
** Last update Thu Oct  9 00:14:55 2008 tugdual sarazin
*/

int     my_put_nbr(int n)
{
  char num;
  int i;
  int flag;

  flag = 0;
  i = 100000000;
  if (n < 0)
    {
      n = -n;
      my_putchar('-');
    }
  while (i >=1)
    {
      num = (n / i) % 10 + 0x30;
      if ((num != '0' || flag == 1) || (i == 1 && flag == 0))
	{
	  flag = 1;
	  my_putchar(num);
	}
      i = i / 10;
    }
}
