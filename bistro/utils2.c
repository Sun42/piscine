#include "my.h"
#include "bistromathique.h"

int     is_open_parent(char *operators, char *expr_in_tab)
{
  if ((expr_in_tab[0] == operators[OP_OPEN_PARENT_IDX]) && (my_strlen(expr_in_tab) == 1))
    return (1);
  return (0);
}

int     is_close_parent(char *operators, char *expr_in_tab)
{
  if ((expr_in_tab[0] ==  operators[OP_CLOSE_PARENT_IDX]) && (my_strlen(expr_in_tab) == 1))
  return (1);
return (0);
}

int	is_num(char *base, char *operators, char *expr_in_tab)
{
  if (is_nb_pure(base, operators, expr_in_tab))
    return (1);
  if ((expr_in_tab[0] == operators[OP_NEG_IDX]) && (my_strlen(expr_in_tab) > 1))
    return (1);
  return (0);
}

int	is_low_op(char *operators, char *expr_in_tab)
{
  if (is_sub_op(operators, expr_in_tab) == 1)
    return (1);
  if (is_plus_op(operators, expr_in_tab) == 1)
    return (1);
  return (0);
}
int     is_plus_op(char *operators, char *expr_in_tab)
{
  if ((expr_in_tab[0] == operators[OP_PLUS_IDX]) && (my_strlen(expr_in_tab) == 1))
    return (1);
  return (0);
}

int     is_sub_op(char *operators, char *expr_in_tab)                                                                                                                                                        
{                                                                                                                                                                                                            
  if ((expr_in_tab[0] == operators[OP_SUB_IDX]) && (my_strlen(expr_in_tab) == 1))
    return (1);
  return (0);
}
int	is_high_op(char *operators, char *expr_in_tab)
{
  if (is_mod_op(operators, expr_in_tab) == 1)
    {
      return (1);
    }
  if (is_mult_op(operators, expr_in_tab) == 1)
    {
      return (1);
    }
  if (is_div_op(operators, expr_in_tab) == 1)
         return (1);
  return (0);
   }
int     is_mod_op(char *operators, char *expr_in_tab)
{
  if ((expr_in_tab[0] == operators[OP_MOD_IDX]) && (my_strlen(expr_in_tab) == 1))
    return (1);
  return(0);
}

int     is_div_op(char *operators, char *expr_in_tab)
{
  if ((expr_in_tab[0] == operators[OP_DIV_IDX]) && (my_strlen(expr_in_tab) == 1))
    return (1);
  return(0);
}
int     is_mult_op(char *operators, char *expr_in_tab)
{
  if ((expr_in_tab[0] == operators[OP_MULT_IDX]) && (my_strlen(expr_in_tab) == 1))
    return (1);
  return(0);
}

void            depile(t_list **begin)
{
  t_list       *tmp;

  tmp = *begin;
  *begin = (*begin)->next;
  free(tmp);
}

/*
int     is_nb_with_op(char *base, char *operators, char *expr_in_tab)
{
  int   flagnum;
  int   flagop;
  int   val;

  flagnum = 0;
  flagop = 0;
  while (*expr_in_tab != '\0')
    {
      val = is_op_char(base, operators, *expr_in_tab) ;
      if (val  == OP_NUM)
        flagnum = 1;
      if ((val == OP_NEG) || (val == OP_PLUS_IDX))
        flagop = 1;
      expr_in_tab = expr_in_tab + 1;
    }
  return((flagnum && flagop));
}
int     is_pseudo_num(char *base, char *operators, char *expr_in_tab)
{
  int   val;

  while (*expr_in_tab != 0)
    {
      val = is_char_op(base,operators,*expr_in_tab);
      if ((val != OP_NEG_IDX) && (val != OP_NUM))
        return (0);
      expr_in_tab = expr_in_tab + 1;
    }
  return (1);
  }*/
