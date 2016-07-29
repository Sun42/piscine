char *modulo(char *base, char  *operators,char *expr1,char *expr2)
{
  char tmp[2];

  tmp[0] = base[1];
  tmp[1] = '\0';
  while (is_sup(base, expr1, expr2))
    {
      my_strcpy(expr1, soustraction(base, operators, expr1, expr2));
    }
  int	nb;
  int   nb2;
  int   nb3;
  int   nb4;
  int   nb5;
  int   nb6;

  nb = 3%1;
  nb2 = 2%4;
  nb3 = -4%2;
  nb4 = 4%-2;
  nb5 = 2%6;
  nb6 = -4%-4;
  my_putstr("\n 3%1 :: ");
  my_put_nbr(nb);
  /*  my_putstr("\n  2%4;");
  my_put_nbr(nb2);
  my_putstr("\n  -4%2;   ");
  my_put_nbr(nb3);
  my_putstr("\n  4%-2;   ");
  my_put_nbr(nb4);
  my_putstr("\n  2%6;    ");
  my_put_nbr(nb5);
  my_putstr("\n  -4%-4  ");
  my_put_nbr(nb6);*/
  my_putstr("FIN::::::::");
  return (expr1);
}

