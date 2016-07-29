/*
** main.c for main in /u/all/sundas_c/cu/rendu/piscine/Jour_11
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct 22 15:15:20 2008 christophe sundas
** Last update Wed Oct 22 23:14:00 2008 christophe sundas
*/

#include "my.h"
#include <stdlib.h>
#include <string.h>

typedef struct  s_list
{
  char          *data;
  struct s_list *next;

}               t_list;

int             main(int argc, char **argv)
{
  t_list        *begin;

  /* Exo 3 
   begin = my_param_in_list(argc, argv);
    my_show_str_in_list(begin);
   my_list_size(begin);
   my_rev_list(&begin);
   my_show_str_in_list(begin);
  */
  
  /* Exo 4
  ** begin = my_param_in_list(argc, argv);
  ** my_apply_on_list(begin, my_putstr);
  */
  /*
  ** Exo 6
  **begin = my_param_in_list(argc, argv);
  **my_apply_on_eq_in_list(begin, my_putstr, "lol", strcmp);
  */
  /* Exo 7
  t_list	*res;
    begin = my_param_in_list(argc, argv);
   res = my_find_elm_eq_in_list(begin, "./a.out", strcmp);
   my_putstr(res->data);*/
  
  /* Exo 8 
  t_list	*res;
  begin = my_param_in_list(argc, argv);
  res = my_rm_all_eq_from_list(&begin, "./a.out", strcmp);
  my_show_str_in_list(res);*/
  /* Exo 9*/
}
