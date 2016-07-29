/*
** bistromathique.h for headers pour bistromathique in /u/all/sundas_c/cu/rendu/piscine/bistro
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Oct 30 16:19:22 2008 christophe sundas
** Last update Mon Nov  3 06:36:52 2008 christophe sundas
*/

#ifndef __BISTRO_H__
# define __BISTRO_H__

#define OP_OPEN_PARENT_IDX	0
#define OP_CLOSE_PARENT_IDX	1
#define OP_PLUS_IDX		2
#define OP_SUB_IDX		3
#define OP_NEG_IDX		3
#define OP_MULT_IDX		4
#define OP_DIV_IDX		5
#define OP_MOD_IDX		6
#define OP_NUM			7
#define OP_ELSE			8

#define SYNTAXE_ERROR_MSG	"syntax error"
#define NULL			(void *)0
void				*malloc(unsigned int);


/*
** Main.h
*/
static void			check_base(char *base);
static void			check_ops(char *ops);
static char			*get_expr(unsigned size);



/*
** Eval expr.h
*/
char				*eval_expr(char *base, char *operators, char *expr, int size);
int     my_show_str_in_list(t_list *begin);
char    *depile_all(char *base, char *operators, t_list *op, t_list *nb);
void            resolv(char *base, char *operators, int *i, char **tabexpr, t_list **op, t_list **nb);
char    *parenthesis_mode(char *base, char *operators, int *i, char **tabexpr);
void                            depile(t_list **begin);
char    *depile_all_parenthesis(char *base, char *operators, t_list *op, t_list *nb);
char    *special_case_one_expr_only(char *base, char *operators, char *expr1, char *operator);

/* Format expr.h
*/

int				nb_case(char *base,char *expr, char *operators);// nb cases du tableau de char de l'expr
char				**str_to_tab_string(char *base, char *expr, char *operators);

/*
** Utils.format.h
*/
int				is_char_op(char *base, char *operators, char c);// retourne un int correspondant a sa valeur dans la base// sa priorite
int				is_in_base(char *base, char c); // check si un char est dans la base
int				indice_in_base(char *base , char c);// retourne l'indice du char dans la base
int                             num_with_op_len(char *base,char *expr, char *operators);// longueur d'un nombre avec ses ++++ et ---                                                                         
int                             is_an_operator(char *base,char *expr, char *operators, int cpt_mot);// check si + ou - est un operateur                                                                    
int				only_pm_until_par(char *base, char *expr, char *operators);/*check sil y ya ke des + ou - juska la next (// =>dans ce cas c pa un operateur*/
int                             num_len(char *base, char *expr);// longueur d'un num 
int				nb_char_to_add( char *base, char *expr, char * operators, int cpt);//nombre de char a malloc dans un *tabexpr





/*
**Clean.h
*/
int				is_op_neg(char *operators, char *expr_in_tab);//Cpt le nbr d'oper - ds 1 str et renvoi si le nbr est neg 1 ou pos 0 
int				need_to_clean(char *base, char *operators, char *expr_in_tab);//check si un string est a cleaner
int                             is_nb_pure(char *base, char *operators, char *expr_in_tab);// check si une string ne contient ke des nombres
int				search_number(char *base, char *expr_in_tab);// check si une string contient au moins un nombre
char				*clean_it(char *base, char *operators, char *expr_in_tab);// retourne une chaine clean
char				*clean_it_with_numbers(char *base, char *operators, char *expr_in_tab);// sous fonction de clean_it, retourne une chaine clean quand cest un nombre
/*
utils2.h
 */
//int                             is_string_op(char *base, char *operators, char *expr_in_tab);
int				is_high_op(char *operators, char *expr_in_tab);
int                             is_open_parent(char *operators, char *expr_in_tab);
int				is_num(char *base, char *operators, char *expr_in_tab);
int				is_low_op(char *operators, char *expr_in_tab);// + ou -, op peu prioritaire
int                             is_close_parent(char *operators, char *expr_in_tab);
int                             is_mod_op(char *operators, char *expr_in_tab);
//int                             is_pseudo_num(char *base, char *operators, char *expr_in_tab);
int                             is_sub_op(char *operators, char *expr_in_tab);
int                             is_plus_op(char *operators, char *expr_in_tab);
int				is_div_op(char *operators, char *expr_in_tab);
int				is_mult_op(char *operators, char *expr_in_tab);

/*
** utils3.h
*/

/*
**Provisoire, va falloir rjouter des params base operators etc TT en faire un structure pour els passer en parametre      
*/
//char                            *depile_all_parenthesis(t_list *op, t_list *nb);
//char                            *number_alone_in_parenthesis(t_list *op, t_list *nb);
//void                            my_string_swap(char **str1, char **str2);

typedef struct	s_opers
{
  char          oper;
  int           (*f)();
}               t_opers;

/* utils.h */
int     indice_in_base(char *base, char c);
/* utils operations.h*/
void    check_ending_zero(char *base, int retenu, int *i, char *stringfinale);
int     is_sup(char *base,char * expr1,char * expr2);
/*  operations.h*/
char    *operations(char *base, char *operators , char *expr1, char *op, char *expr2);
char    *parse_addition(char *base, char *operators,char *expr1, char *expr2);
char    *ajoute_moins(char *operators, char *expr);
int     *parse_operation(char *base,char *operators,char **expr1,char **expr2);
int     parse_zeros(char *base, char *expr);
char    *parse_soustraction(char *base, char *operators, char *expr1, char *expr2);
char *parse_multiplication(char *base, char *operators, char *expr1, char *expr2);
char *parse_division(char *base, char *operators, char *expr1, char *expr2);
char *parse_modulo(char *base, char *operators, char *expr1, char *expr2);

/*addition.h */

char     *add(char *base, char *expr1, char *expr2);
char    add_affect(char *base, char nb1, char nb2, int *retenu);
void    check_retenu(char *base, int *res, int *retenu);
char    *addition(char *base, char *expr1, char *expr2);


/*soustraction.h */
char    *soustraction(char *base, char *operators, char *expr1, char *expr2);
char    *sub(char *base, char *operators, char *exprmax, char *exprmin, int flagmin);
char    calcul_res(char *base, int nb1, int nb2, int *retenu);
void    check_flagmin(char *operators, char *stringfinale, int *i, int flagmin);
/*multiplication.h */
char    *do_inf_mult(char *base, char *expr1, char *expr2);
char    *do_inf_mult2(char *base, char *expr1, char *expr2, int *r);
int     *mk_r(int size);
char    *mk_res(int size);
int     digit_to_val(char *base, char d);

#define DIGIT_TO_VAL(x) (digit_to_val(base, x))
#define VAL_TO_DIGIT(x) (base[x])
#define BASE_LEN(x) (my_strlen(base))

/* division.h */
char    *division(char *base, char *operators, char *expr1, char *expr2);

/*Modulo.h */
char *modulo(char *base, char  *operators,char *expr1,char *expr2);

#endif
