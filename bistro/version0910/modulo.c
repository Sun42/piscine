char *modulo(char *base, char  *operators,char *expr1,char *expr2)
{
  char tmp[2];

  tmp[0] = base[1];
  tmp[1] = '\0';
  while (is_sup(base, expr1, expr2))
    {
      my_strcpy(expr1, soustraction(base, operators, expr1, expr2));
    }
  return (expr1);
}

