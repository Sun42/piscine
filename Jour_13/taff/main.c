/*
** main.c for main du jour 13 in /u/all/sundas_c/cu/rendu/piscine/Jour_13
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Oct 23 21:57:02 2008 christophe sundas
** Last update Fri Oct 24 01:08:19 2008 christophe sundas
*/

#include "my.h"
#include "btree.h"

int             main(int argc, char **argv)
{
  /*Exo 1
  char		*data;
  t_btree	*resnode;

  data = "Myitem";
  (*resnode) = (*new_btree_node(data));
  printf("%s", resnode->item);
  */
  /*Exo 2 */
  t_list	*begin;
  begin = my_params_in_list(argc, argv);
  my_show_str_in_list(begin);
  my_list_size(begin);
  my_rev_list(&begin);
  my_show_str_in_list(begin);
}
