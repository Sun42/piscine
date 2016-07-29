/*
** main.c for mult in /u/all/sundas_c/cu/rendu/piscine/bistro/operations/multiplication
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sat Nov  1 04:38:23 2008 christophe sundas
** Last update Sun Nov  2 00:08:48 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"
#include <string.h>

char	*do_inf_mult(char *base, char *expr1, char *expr2);
char	*do_inf_mult2(char *base, char *expr1, char *expr2, int *r);
int	*mk_r(int size);
char	*mk_res(int size);
int	digit_to_val(char *base, char d);

#define DIGIT_TO_VAL(x) (digit_to_val(base, x))
#define VAL_TO_DIGIT(x) (base[x])
#define BASE_LEN(x) (my_strlen(base))

int	digit_to_val(char *base, char d)
{
  int	r;
  
  r = 0;
  while (base[r] != d)
    {
      r = r + 1;
    }
  return (r);
}
int	main(int ac, char **av)
{
  my_putstr(do_inf_mult(av[1], av[2], av[3]));
}

int	*mk_r(int size)
{
  int	*r;

  r = malloc(size * sizeof(*r));
  memset(r,0,size * sizeof(*r));
  return (r);
}

char	*mk_res(int size)
{
  char *res;

  res = malloc(size + 1);
  res[size] = 0;
  return (res);
}

char	*do_inf_mult(char *base, char *expr1, char *expr2)
{
  int	len1;
  int	len2;
  //char	*res;
  int	*r;
  int	i;
  int	j;

  len1 = my_strlen(expr1);
  len2 = my_strlen(expr2);
  r = mk_r(len1 + len2);
  //res = mk_res(len1 + len2);
  i = len1 - 1; 
  while (i >= 0)
    {
      j = len2 - 1;
      while(j >= 0)
        {
          r[i + j + 1] = r[i + j + 1] + (DIGIT_TO_VAL(expr1[i]) * DIGIT_TO_VAL(expr2[j]));
          r[i + j] = r[i + j] + (r[ i + j + 1] / BASE_LEN(base));
          r[i + j + 1] = r[i + j + 1] % BASE_LEN(base);
	  j = j - 1;
        }
      i = i - 1;
    }
  return (do_inf_mult2(base,expr1, expr2, r));
}

char *do_inf_mult2(char *base, char *expr1, char *expr2, int *r)
{
  int	i;
  int	j;
  char  *res;
  int	len1;
  int	len2;

  res = mk_res(len1 + len2);
  i = 0;
  j = 0;
  len1 = my_strlen(expr1);
  len2 = my_strlen(expr2);
  while (i < len1 + len2)
    {
      if (j || r[i] || i == len1 + len2 - 1)
	{
	  res[j] = VAL_TO_DIGIT(r[i]);
	  j = j + 1;
	}
      i = i + 1;
    }
  return (res);
}
