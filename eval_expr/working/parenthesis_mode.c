/*
** parenthesis_mode.c for cas parenthese in /u/all/sundas_c/cu/rendu/piscine/eval_expr/working
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Mon Oct 27 23:16:22 2008 christophe sundas
** Last update Mon Oct 27 23:24:46 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"
#include "eval_expr.h"

char		*parenthesis_mode(int *i, char **tabstring)
{
  t_list	*op;
  t_list	*nb;

  op = 0;
  nb = 0;
  *i = (*i) + 1;
  while (is_operator(tabstring[*i]) != 4)
    {
      if (is_operator(tabstring[*i]) == 3)
        my_put_in_list(&nb, parenthesis_mode(i, tabstring));
      if (is_operator(tabstring[*i]) == 0)
        my_put_in_list(&nb, tabstring[*i]);
      if ((is_operator(tabstring[*i]) == 2) && (is_operator(tabstring[*i + 1]) == 0))
        resolv(i, tabstring, &op, &nb);
      if ((is_operator(tabstring[*i]) == 2) && (is_operator(tabstring[*i + 1]) == 3))
        resolv(i, tabstring, &op, &nb);
      if (is_operator(tabstring[*i]) == 1)
        my_put_in_list(&op, tabstring[*i]);
      *i = *i + 1;
    }
  return (depile_all_parenthesis(op, nb));
}

char	*depile_all_parenthesis(t_list *op, t_list *nb)
{
  char	*operator;
  char	*nb1;
  char	*nb2;
  char	*newval;
  int	inew_val;

  if (my_list_size(op) > 0)
    {
      my_rev_list(&op);
      my_rev_list(&nb);
    }
  if (my_list_size(nb) == 1)
    return (number_alone_in_parenthesis(op, nb));
  while (my_list_size(op) > 0)
    {
      nb1 = nb->data;
      depile(&nb);
      nb2 = nb->data;
      depile(&nb);
      operator = op->data;
      depile(&op);
      inew_val = eval(my_getnbr(nb1), *operator, my_getnbr(nb2));
      newval = malloc(sizeof(*newval) * (digit_len(inew_val) + 1));
      my_itoa(inew_val, newval);
      my_put_in_list(&nb, newval);
    }
  return(nb->data);
}

char	*number_alone_in_parenthesis(t_list *op, t_list *nb)
{
  char	*ret;

  if (my_list_size(op) == 0)
    return (nb->data);
  if (op->data[0] == '-')
    {
      ret = malloc(sizeof(*ret) * (my_strlen(nb->data) + 2));
      my_itoa(-my_getnbr(nb->data), ret);
      depile(&nb);
      depile(&op);
      return (ret);
    }
  if (op->data[0] == '+')
    {
      ret = malloc(sizeof(*ret) * (my_strlen(nb->data) + 1));
      my_itoa(my_getnbr(nb->data), ret);
      depile(&nb);
      depile(&op);
      return (ret);
    }
}
