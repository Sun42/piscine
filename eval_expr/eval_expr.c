/*
** do-op.c for do op.c in /u/all/sundas_c/cu/rendu/piscine/Jour_10
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Tue Oct 21 01:27:19 2008 christophe sundas
** Last update Tue Oct 28 03:51:22 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"
#include "eval_expr.h"

void    my_string_swap(char **str1, char **str2);

int	main(int ac, char **av)
{
  my_put_nbr(eval_expr(av[1]));
  my_putchar('\n');
  return (0);
}

int		eval_expr(char *str)
{
  int		i;
  char		**tabstring;
  t_list	*op;
  t_list	*nb;
  
  op = 0;
  nb = 0;
  i = 0;
  tabstring = str_to_tab_string(str);
  while (tabstring[i] != 0)
    {
      if (is_operator(tabstring[i]) == 3)
	my_put_in_list(&nb, parenthesis_mode(&i, tabstring));
      if (is_operator(tabstring[i]) == 0)
	my_put_in_list(&nb, tabstring[i]);
      if (is_operator(tabstring[i]) == 1) 
	my_put_in_list(&op, tabstring[i]);
      if (is_operator(tabstring[i]) == 2)
	resolv(&i, tabstring, &op, &nb);
      i = i + 1;
    }
  return (depile_all(op, nb));
}

/*
** fin empilage, on depile et calcul
*/

int	depile_all(t_list *op, t_list *nb)
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
  while (my_list_size(op) > 0)
    {
      nb1 = nb->data;
      depile(&nb);
      if (my_list_size(nb)== 0)
      	{
        my_put_in_list(&nb, "0");
        nb2=nb->data;
        my_string_swap(&nb1,&nb2);
      	}
      else
      {
	 nb2=nb->data;
      }
      depile(&nb);
      operator = op->data;
      depile(&op);
      inew_val = eval(my_getnbr(nb1), *operator, my_getnbr(nb2));
      newval = malloc(sizeof(*newval) * (digit_len(inew_val) + 1));
      my_itoa(inew_val, newval);
      my_put_in_list(&nb, newval);
      free(newval);
    }
  return (my_getnbr(nb->data));
}

void		resolv(int *i, char **tabstring, t_list **op, t_list **nb)
  {
    char	*save;
    int		new_val;
    char	*str;
    my_put_in_list(op, tabstring[*i]);
    *i =*i + 1;
    if  (is_operator(tabstring[*i]) == 0)
      my_put_in_list(nb, tabstring[*i]);
    if (is_operator(tabstring[*i]) == 3) 
      my_put_in_list(nb, parenthesis_mode(i, tabstring));
    //if (is_operator(tabstring[*i]) == 1)
    //{
    //save = malloc(sizeof(*save) * (my_strlen((*nb)->data) + 1));
    //save = (*nb)->data;
    //*i = *i + 1;
    //my_strncat(save,(*nb)->data,my_strlen((*nb)->data));
    // }
    //else 
    //{
	save = malloc(sizeof(*save) * (my_strlen((*nb)->data) + 1));
	save =(*nb)->data;
	//}
    depile(nb);
    if (my_list_size(*(nb)) == 0)
      my_put_in_list(nb, "0");
    new_val = eval(my_getnbr((*nb)->data), *(*op)->data, my_getnbr(save));
    depile(op);
    depile(nb);
    str = malloc(sizeof(*str) * (digit_len(new_val) + 1));
    my_itoa(new_val, str);
    my_put_in_list(nb, str);
    free(save);
  }

void		depile(t_list **begin)
{
   t_list	*tmp;
  
   tmp = *begin;
   *begin = (*begin)->next;
   free(tmp);
 }
void	my_string_swap(char **str1, char **str2)
{
  char *tmp;
  
  tmp = malloc(sizeof(**str1) * (my_strlen(*str1) + 1));
  tmp = *str1;
  *str1 = *str2;
  *str2 = tmp;
  free(tmp);
}
