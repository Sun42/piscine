/*
** do-op.c for do op.c in /u/all/sundas_c/cu/rendu/piscine/Jour_10
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Tue Oct 21 01:27:19 2008 christophe sundas
** Last update Mon Oct 27 06:03:22 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"
#include "eval_expr.h"

void	resolv(int *i, char **tabstring, t_list **op, t_list **nb);
void	depile(t_list **begin);
char   *parenthesis_mode(int    *i, char ** tabstring);


int	main(int ac, char **av)
{
  my_put_nbr(eval_expr(av[1]));
  my_putchar('\n');
  return (0);
}

int		eval_expr(char *str)
{ 
  int		res;
  int		i;
  char		**tabstring;
  t_list	*op;
  t_list	*nb;
  
  op = 0;
  nb = 0;
  i = 0;
  res = 0;
  tabstring = str_to_tab_string(str);
  show_tab_string(tabstring);

  while (tabstring[i] != 0)
    {
      if (is_operator(tabstring[i]) == 3)
	// le retour de parenthesis mode, on lempile
	my_put_in_list(&nb, parenthesis_mode(&i, tabstring));
      my_putstr("Check ::: on point maintenant vers");
      my_putstr(tabstring[i]);
      my_putstr("\n");
      //si cest un nombre on empile
      if (is_operator(tabstring[i]) == 0)
	{
	  my_put_in_list(&nb, tabstring[i]);
	}
      else 
	if (is_operator(tabstring[i]) == 1)//si cest un operateur de basse priorite on empile
	{
	  my_put_in_list(&op, tabstring[i]);
	}
	  /* Si cest un operateur de priorite on resolv*/
      if ((is_operator(tabstring[i]) == 2) && (is_operator(tabstring[i + 1]) == 0)) 
	    {
	     resolv(&i, tabstring, &op, &nb);
	    }
      // si c un operateur de priorite et que le suivant est une '(' on empile cet operateur                                                                                                               
      if ((is_operator(tabstring[i]) == 2) && (is_operator(tabstring[i + 1]) == 3))
	{
	  //  my_put_in_list(&op, tabstring[i]);
	  resolv(&i, tabstring, &op, &nb);
	}
	i = i + 1;
    }
  if (my_list_size(op) > 0)
    {
      my_rev_list(&op);
      my_rev_list(&nb);
    }
  while (my_list_size(op) > 0) 
    {
      char *operator;
      char *nb1;
      char *nb2;
      char *newval;
      int       inew_val;
      
      nb1 = nb->data;
      //   my_putstr("nb1 :::");
      //my_putstr(nb1);
      //my_putstr("\n");
      depile(&nb);
      nb2=nb->data;
      //my_putstr("nb2 :::");
      //my_putstr(nb2);
      //my_putstr("\n");
      depile(&nb);
      //my_putstr("Operator patator:");
      //my_putstr(op->data);
      //my_putstr("\n");
      operator = op->data;
      depile(&op);
      //my_putstr("PASSASSOR?");
      my_putstr("OPERATION :::::  ");
      my_putstr(nb1);
      my_putstr(operator);
      my_putstr(nb2);
      my_putstr("RESULTAT");
      inew_val = eval(my_getnbr(nb1), *operator, my_getnbr(nb2));
      my_put_nbr(inew_val);
      my_putstr(" et ");
      newval = malloc(sizeof(*newval) * ( digit_len(inew_val) + 1));
      my_itoa(inew_val, newval);
      my_putstr(newval);
      my_putstr("\n");
      my_putstr("TESTICULE\n");
      my_put_in_list(&nb, newval);
      my_putstr("TESTICULE2\n");
    }

  my_putstr("PIle operateurs :\n");
  my_show_str_in_list(op);
  my_putstr("PIle nb\n");
  my_show_str_in_list(nb);
  my_putstr("\nFIN\n");
  res = my_getnbr(nb->data);
  return (res);
 }

/* Si cest un operateur de priorite on empile, loperateur, le nombre suivant, puis resoud loperation,puis on depile loperateur, les deux nombres resolus   puis on empile le resultat*/
/*appel les fonctions de depilage, calcul, et rempilage du nouveau nombre */
 void		resolv(int *i, char **tabstring, t_list **op, t_list **nb)
  {
    char	*save;
    int		new_val;
    char	*str;
    
    my_put_in_list(op, tabstring[*i]);
    *i =*i + 1;
    if  (is_operator(tabstring[*i]) == 0 )
      {
	my_put_in_list(nb, tabstring[*i]);
      }
    if (is_operator(tabstring[*i]) == 3) 
      {
	my_putstr("CAS CHELOU!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	my_put_in_list(nb, parenthesis_mode(i, tabstring));
      }
    
    //malloc();
    save =(*nb)->data;
    //my_putstr("Save:::::::::");    
    //my_putstr(save);
    //my_putstr("\n");
    depile(nb);
    new_val = eval(my_getnbr((*nb)->data), *(*op)->data, my_getnbr(save));
    depile(op);
    depile(nb);
    str = malloc(sizeof(*str) * (digit_len(new_val) + 1));
    my_putstr("New val");
    my_put_nbr(new_val);
    my_putstr("\n");
    my_itoa(new_val, str);
    my_putstr("resultat itoa");
    my_putstr(str);
    my_putstr("\n");
    my_put_in_list(nb, str);
  }
/*
** Depile une pile
*/
void	depile(t_list **begin)
{
  //my_putstr("avant::::::");
  //my_putstr((*begin)->data);
  t_list *tmp;
  
  tmp = *begin;
  *begin = (*begin)->next;
  free(tmp);
  //my_putstr("apres::::::");
  //my_putstr((*begin)->data);
  //my_putstr("\n");
}

char 	*parenthesis_mode(int	*i, char ** tabstring)
{
  // calcul TOUT ce que contient des parentheses
  //si on rencontre un parenthese il suffit de rappeler la fonction
  // attention a l'indice de la chaine et cest gg np no re
    //retournera un int du resultat
  t_list        *op;
  t_list        *nb;

  op = 0;
  nb = 0;
  my_putstr("Welcome to parenthesis mode");
 // pour skip la pranenthesehese de debut, 
  *i = (*i) + 1;
  while (is_operator(tabstring[*i]) != 4)
    {
      ///si on rencontre une autre parenthese => autre instance on place juste le resultat dans list nb, on ncremente i ki va bien et gg
      if (is_operator(tabstring[*i]) == 3)
	my_put_in_list(&nb, parenthesis_mode(i, tabstring));
      if (is_operator(tabstring[*i]) == 0)
	{
	  my_put_in_list(&nb, tabstring[*i]);
	}
      else
	{ /* Si cest un operateur de priorite on resolv et que le suivant est un nombre*/
          if ((is_operator(tabstring[*i]) == 2) && (is_operator(tabstring[*i + 1]) == 0))
            {
	      resolv(i, tabstring, &op, &nb);
            }
	  // si c un operateur de priorite et que le suivant est une '(' on empile cet operateur
	  if ((is_operator(tabstring[*i]) == 2) && (is_operator(tabstring[*i + 1]) == 3))
	    {
	      //my_put_in_list(&op, tabstring[*i]);
	      //  resolv(i, )
		resolv(i, tabstring, &op, &nb);
	    }
	  //if (tabstring[i] == "-") &&
	  //si c un operateur de faible priorite on empile
	  if (is_operator(tabstring[*i]) == 1)
	    {
	      my_put_in_list(&op, tabstring[*i]);
	    }
	}
      *i = *i + 1;
      }
  //my_putstr("indice chaine ====");
  //my_put_nbr(*i);
  //my_putstr("\n");
  //my_putstr("Empilage fini parenthesis mode\n");
  // pense a incrementer i pour skip la prenthese de fin hehe
  //if ((is_operator(tabstring[*i]) == 4) && (tabstring[*i + 1] != '\0'))
  //*i = *i + 1;
  //une fois tout empile on resout tout
  // my_put_nbr(my_list_size(nb));

  if (my_list_size(op) > 0) 
    {
      my_rev_list(&op);
      my_rev_list(&nb);
    }
  if (my_list_size(nb) == 1)
    {
      my_putstr("CAS TRES CHELOU");
      char *ret2;
      my_putstr(op->data);
      if (op->data[0] == '-')
	{
	  
	  my_putstr("CAS TRES TRES CHELOU");
	  ret2 = malloc(sizeof(*ret2) * (my_strlen(nb->data) + 2));
	  my_itoa(-my_getnbr(nb->data), ret2);
	  depile(&nb);
	  depile(&op);
	    return (ret2);   
	}
      if (op->data[0] == '+')
	{
	  my_putstr("CAS TRES TRES CHELOU+++");
	  ret2 = malloc(sizeof(*ret2) * (my_strlen(nb->data) + 1));
	  my_itoa(my_getnbr(nb->data), ret2);
	  depile(&nb);
          depile(&op);
	  return (ret2);
        }
    }
else
  while (my_list_size(op) > 0)
    {
      char *operator;
      char *nb1;
      char *nb2;
      char *newval;
      int	inew_val;
      my_putstr("why???");
      my_show_str_in_list(op);
      my_putstr("Operator patator:");
      my_putstr(op->data);
      my_putstr("\n");
      my_putstr("\n");
      nb1 = nb->data;
      my_putstr("nb1 :::");
      my_putstr(nb1);
      my_putstr("\n");
      depile(&nb);
      nb2=nb->data;
      my_putstr("nb2 :::");
      my_putstr(nb2);
      my_putstr("\n");
      depile(&nb);
      my_putstr("Operator patator:");
      my_putstr(op->data);
      my_putstr("\n");
      operator = op->data;
      depile(&op);
      my_putstr("PASSASSOR?");
      inew_val = eval(my_getnbr(nb1), *operator, my_getnbr(nb2));
      newval = malloc(sizeof(*newval) * ( digit_len(inew_val) + 1));
      my_itoa(inew_val, newval);
      my_putstr(newval);
      my_put_in_list(&nb, newval);
    }
  my_putstr("\n");
  my_putstr("REturn du pqrenthsis mode :::::");
  my_putstr(nb->data);
  my_putstr("\n");
  return(nb->data);
}

/*
int             my_put_in_list(t_list **begin, char *data)
{
  t_list        *new_elem;

  new_elem = malloc(sizeof(*new_elem));
  new_elem->data = data;
  new_elem->next = *begin;
  *begin = new_elem;
}

int     my_show_str_in_list(t_list *begin)
{
  while (*begin != 0)
    {
      my_pustr(begin->data);
      my_putstr("\n");
      begin = begin->next;
    }
    }

int             my_list_size(t_list *begin)
{
  int           i;

  i = 0;
  while (begin != 0)
    {
      begin = begin->next;
      i = i + 1;
    }
  return (i);
}
*/
