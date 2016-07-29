/*
** btree.h for headers arbre binaire in /u/all/sundas_c/cu/rendu/piscine/Jour_13
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Oct 23 21:36:29 2008 christophe sundas
** Last update Fri Oct 24 00:06:08 2008 christophe sundas
*/

#ifndef __B_TREE_H__
# define __B_TREE_H__

typedef struct		s_btree
{
  void			*item;
  struct s_btree	*left;
  struct s_btree	*right;
}			t_btree;

t_btree			*new_btree_node(void *item);
t_btree			*sorted_list_to_btree(t_list *l, int size);
#endif
