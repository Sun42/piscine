/*
** new_btree_node.c for ajout de noeuds dans un arbre in /u/all/sundas_c/cu/rendu/piscine/Jour_13
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Oct 23 21:40:50 2008 christophe sundas
** Last update Thu Oct 23 22:45:23 2008 christophe sundas
*/

#include "my.h"
#include "btree.h"

t_btree		*new_btree_node(void *item)
{
  t_btree	*newnode;
  
  newnode = malloc(sizeof(*newnode));
  newnode->item = item;
    return (newnode);
}
