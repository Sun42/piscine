#ifndef __SOUSTRACTION_H__
#define __SOUSTRACTION_H__
#define OP_NEG_IDX 3

int     indice_in_base(char *base, char c);
char    *soustraction(char *base, char *operators, char *expr1, char *expr2);
char    *sub(char *base, char *operators, char *exprmax, char *exprmin, int flagmin);
int     is_sup(char *base, char * expr1, char * expr2);
char    calcul_res(char *base, int nb1, int nb2, int *retenu);
void check_ending_zero(char *base, int retenu, int *i,char *stringfinale);
void    check_flagmin(char *operators, char *stringfinale, int *i, int flagmin);

#endif
