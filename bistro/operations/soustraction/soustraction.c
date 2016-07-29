#include "my.h"
#include "soustraction.h"

/*
**  fonction principale
 */
char	*soustraction(char *base, char *operators, char *expr1, char *expr2)
{
  if (is_sup(base, expr1, expr2))
    {
      my_revstr(expr1);
      my_revstr(expr2);
      return (sub(base, operators, expr1, expr2, 0));
    }
  else
    {
      my_revstr(expr1);
      my_revstr(expr2);
      return (sub(base, operators, expr2, expr1, 1));
    }
} 
 
char	*sub(char *base, char *operators, char *exprmax, char *exprmin, int flagmin)
{
  int	i;
  char *stringfinale;
  int	res;
  int	retenu;

  i = 0;
  retenu = 0;
  if ((stringfinale = malloc(sizeof(*stringfinale) * (my_strlen(exprmax) + 2))) == 0)
    return (0);
  while (exprmax[i] != '\0')
    {
      stringfinale[i] = calcul_res(base, indice_in_base(base, exprmax[i]), if_exist_exprmin(base, i, exprmin), &retenu);
      i = i + 1;
    }
  check_ending_zero(base, retenu, &i, stringfinale); 
  check_flagmin(operators, stringfinale, &i, flagmin);
  stringfinale[i] = '\0';
  my_revstr(stringfinale);
  return (stringfinale);
}
/*
** ajoute un moins si le flagmin est a 1 soit si on a inverse les expressions avant lappel de la fonction 
*/

void	check_flagmin(char *operators, char *stringfinale, int *i, int flagmin)
{
  if (flagmin == 1)
    {
      stringfinale[*i] = operators[OP_NEG_IDX];
      *i = *i + 1;
    }
}
/*
** ajoute la derniere retenu si besoin=> inutile en fait il me semble

void check_ending_retenu(char *base, char *stringfinale, int *i, int retenu)
{
  if (retenu == 1)
    {
      stringfinale[*i] = base[retenu];
      *i = *i + 1;
    }
    }*/
/*
** remove les zeros useless!! en fin de calcul 
*/
void	check_ending_zero(char *base, int retenu, int *i, char *stringfinale)
{
  if (retenu == 0)
    {
      while ((*i > 1) && (indice_in_base(base, stringfinale[*i - 1]) == 0))
	{
	  *i = *i - 1;
	}
    }
}

int	if_exist_exprmin(char *base, int i, char *exprmin)
{
  if (i >= my_strlen(exprmin))
    return (0);
  else
    return (indice_in_base(base, exprmin[i]));
}

char	calcul_res(char *base, int nb1, int nb2, int *retenu)
{
  int	res;
  
  res = nb1 - (nb2 + *retenu);
  if (res < 0)
    {
      res = -res;
      res = my_strlen(base) - res;
      *retenu = 1;
    }
  else 
    {
      *retenu = 0;
    }
  return (base[res]);
}
int	is_sup(char *base,char * expr1,char * expr2)
{
  int	nb1;
  int	nb2;
  int	i;
  
  i = 0;
  nb1 = my_strlen(expr1);
  nb2 = my_strlen(expr2);
  if (nb1 > nb2)
    return (1);
  if (nb1 < nb2)
    return (0);
  if (nb1 == nb2)
    {
      while (i < nb1)
	{
	  if (indice_in_base(base, expr1[i]) > indice_in_base(base, expr2[i]))
	    return (1);
	  if (indice_in_base(base, expr1[i]) < indice_in_base(base, expr2[i]))
            return (0);
	  i = i + 1;
	}
    }
  return (1);
 }

int     indice_in_base(char *base, char c)
{
  int   i;

  i = 0;
  while (base[i] != '\0')
    {
      if (base[i] == c)
        return (i);
      i = i + 1;
    }
}
