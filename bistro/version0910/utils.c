/*
** utils.c for groupement dutilitaires pour bistro in /u/all/sundas_c/cu/rendu/piscine/bistro
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Oct 30 16:20:12 2008 christophe sundas
** Last update Fri Oct 31 13:45:37 2008 christophe sundas
*/
#include "my.h"
#include "bistromathique.h"
#include  <stdlib.h>


int     is_char_op(char *base, char *operators, char c)
{
  if (c == operators[OP_OPEN_PARENT_IDX])
    return (OP_OPEN_PARENT_IDX);
  if (c == operators[OP_CLOSE_PARENT_IDX])
    return (OP_CLOSE_PARENT_IDX);
  if (c == operators[OP_PLUS_IDX])
    return (OP_PLUS_IDX);
  if (c == operators[OP_SUB_IDX])
    return (OP_SUB_IDX);
  if (c == operators[OP_MULT_IDX])
    return (OP_MULT_IDX);
  if (c == operators[OP_DIV_IDX])
    return (OP_DIV_IDX);
  if (c == operators[OP_MOD_IDX])
    return (OP_MOD_IDX);
  if (is_in_base(base, c))
    return (OP_NUM);
 return (OP_ELSE);
}

int	is_in_base(char *base , char c)
{
  while (*base != '\0')
    {
      if (c == *base)
	return (1);
      base = base + 1;
    }
  return (0);
}

int	indice_in_base(char *base, char c)
{
  int	i;

  i = 0;
  while (base[i] != '\0')
    {
      if (base[i] == c)
	return (i);
      i = i + 1;
    }
}
/*                                                                                                                                                                                                           
**retourne la longueur dun nombre dans un chaine                                                                                                                                                             
*/
int     num_len(char *base, char *expr)
{
  int   i;

  i = 0;
  while (is_in_base(base, *expr) == 1)
    {
      i = i + 1;
      expr = expr + 1;
    }
  return (i);
}

/*                                                                                                                                                                                                            
** Retourne la longueur dun nombre avec ses plus et moins compris dans une chaine                                                                                                                             
*/
int     num_with_op_len(char *base, char *expr, char *operators)
{
  int   i;

  i = 0;
  while ((is_char_op(base, operators, *expr) == 2) || (is_char_op(base, operators, *expr) == 3))
    {
      i = i + 1;
      expr = expr + 1;
    }
  // on pointe now vers la partie number                                                                                                                                                                      
  i = i + num_len(base, expr);
  return (i);
}

/*                                                                                                                                                                                                            
**CHeck si  un + ou un - est a ajouter au nombre suivant ou si il est a ajouter comme un operateur a part entiere                                                                                      
*/

int             is_an_operator(char *base, char *expr, char *operators, int cpt_mot)
{
  int   prev_val;

  prev_val = is_char_op(base, operators, *(expr - 1));
  // si ya un operateur  ( *  % / derriere => cest  pas un operator, c a  ajouter au nombre                                                                                                                   
  if (cpt_mot == 0)
    return (0);
  if ((prev_val == 0) || ((prev_val >= 2) && (prev_val <= 6)))
    return (0);
  if (only_pm_until_par(base, expr, operators) == 1)
    {
      //    my_putstr("\nONLY PM UNTIL PAR");
      return (0);
    }
  else
    return (1);
}

/*
**
 */
int	only_pm_until_par(char *base, char *expr, char *operators)
{
  int	value;
  
  //my_putstr("\nCA PASSE ???????");
  value = is_char_op(base, operators, *expr);
  while (value != OP_OPEN_PARENT_IDX)
    {
      if ((value != OP_PLUS_IDX) && (value != OP_SUB_IDX))
	{
	  // my_putstr("\nPAS KE DES PLUS ET MOINS");
	  return (0);
	}
      expr = expr + 1;
      value = is_char_op(base, operators, *expr);
    }
  //my_putstr("\nKE DES PLUS OU MOINS");
return (1);
}
