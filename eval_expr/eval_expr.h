#ifndef __EVAL_EXPR_H8__
# define __EVAL_EXPR_H8__

int	eval_expr(char *str);
void	show_tab_string(char **tabstring);
char	**str_to_tab_string(char *str);
int	is_operator(char *str);
int	number_len(char *str);
int	my_add(int nb1, int nb2);
int	my_sub(int nb1, int nb2);
int	my_mul(int nb1, int nb2);
int	my_div(int nb1, int nb2);
int	my_mod(int nb1, int nb2);
int	eval(int nb1, char oper, int nb2);
int	digit_len(int nbr);
char	*parenthesis_mode(int *i, char **tabstring);
char	*number_alone_in_parenthesis(t_list *op, t_list *nb);
char	*depile_all_parenthesis(t_list *op, t_list *nb);
void	resolv(int *i, char **tabstring, t_list **op, t_list **nb);
void	depile(t_list **begin);
int	depile_all(t_list *op, t_list *nb);

typedef struct  s_opers
{
  char          oper;
  int           (*f)();
}               t_opers;

#endif
