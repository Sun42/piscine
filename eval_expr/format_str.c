/*
** do-op.c for do op.c in /u/all/sundas_c/cu/rendu/piscine/Jour_10
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Tue Oct 21 01:27:19 2008 christophe sundas
** Last update Mon Oct 27 21:42:01 2008 christophe sundas
*/
#include "stdlib.h"
#include "my.h"
#include "eval_expr.h"

void	my_revstr2(char *str);

/*
** formatte lexpression sous forme de string en expression sous formre de tableau de string
*/

char	**str_to_tab_string(char *str)
{
  int	i;
  int	j;
  char **tabstring;
  int len;

  i = 0;
  tabstring = malloc(sizeof(*tabstring) * my_strlen(str) + 1); 
  while (*str != 0)
    {
      if (is_operator(str) != 0)//donc un operateur
	{
	  tabstring[i] = malloc(sizeof(*str)  + 1);
	  tabstring[i][0] = *str;
	  tabstring[i][1] = '\0';
	  str = str + 1;
	}
      else //un nombre optentiellement long 
	{
	  len = number_len(str); //calcul sa longueur   
	  tabstring[i]= malloc(sizeof(*str) * (len + 1));//malloc longueur + 1  
	    j = 0;
	  while (j < len)//place le nombre dans notre tab[i] 
	    {
	      tabstring[i][j] = *str;
	      str = str + 1;
	      j = j + 1;
	    }
	    tabstring[i][j] = '\0';
	}
      i = i + 1;
    }
  tabstring[i] = 0;
  return (tabstring);
}

/*
** Retourne
** 0 si nombre
** 1 si operateur de faible priorite
** 2 si operateur de haute priorite
** 3 si parenthese ouvrante
** 4 si parenthese fermante
 */
int	is_operator(char *str)
{
  if ((*str == '+') || (*str == '-'))
    {
      return (1);
    }
  if ((*str == '*') || (*str == '%') || (*str == '/'))
    {
      return (2);
    }
  if ((*str) == '(')
    {
      return (3);
    }
  if ((*str) == ')')
    {
      return (4);
    }
  return (0);
 }

/*
** calcule la taille des premiers caracteres numeriques dans une chaine
*/
int     number_len(char *str)
{
  int   i;

  i = 0;
  while ((str[i] >= '0') && (str[i] <= '9'))
    {
      i = i + 1;
    }
  return (i);
}

/*
** affichage du tableau de string formate, ne pas conserver pour rendu 
*/
void    show_tab_string(char **tabstring)
{
  while (*tabstring != 0)
    {
      my_putstr("\n");
      my_putstr(*tabstring);
      tabstring = tabstring + 1;
    }
}

/* 
** procede au calcul entre deux nombres
*/
t_opers tab[] =
  {
    {'*', my_mul},
    {'+', my_add},
    {'-', my_sub},
    {'/', my_div},
    {'%', my_mod},
    {0, 0},
  };

int     eval(int nb1, char oper, int nb2)
{
  int   i;

  i = 0;
  while (tab[i].oper != 0)
    {
      if (tab[i].oper == oper)
        return (tab[i].f(nb1, nb2));
      i = i + 1;
    }
}

/* 
** calcul le nombre  char dun nombre en vue dun  malloc pour itoa 
*/
int     digit_len(int nbr)
{
  int   ret;

  ret = 0;
  if (nbr < 0)
    ret = ret + 1;
  while (nbr > 0)
    {
      nbr = nbr / 10;
      ret = ret  + 1;
    }
  return (ret);
}
