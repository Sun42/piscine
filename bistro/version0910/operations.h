
#ifndef __OPERATIONS_H__
# define __OPERATIONS_H__

#define OP_OPEN_PARENT_IDX      0
#define OP_CLOSE_PARENT_IDX     1
#define OP_PLUS_IDX             2
#define OP_SUB_IDX              3
#define OP_NEG_IDX              3
#define OP_MULT_IDX             4
#define OP_DIV_IDX              5
#define OP_MOD_IDX              6


/* utils.h */
int     indice_in_base(char *base, char c);
/* utils operations.h*/
void    check_ending_zero(char *base, int retenu, int *i, char *stringfinale);
int     is_sup(char *base,char * expr1,char * expr2);
/*  operations.h*/
char	*operations(char *base, char *operators , char *expr1, char *op, char *expr2);
char	*parse_addition(char *base, char *operators,char *expr1, char *expr2);
char	*ajoute_moins(char *operators, char *expr);
int	*parse_operation(char *base,char *operators,char **expr1,char **expr2);
int	parse_zeros(char *base, char *expr);
char	*parse_soustraction(char *base, char *operators, char *expr1, char *expr2);
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
